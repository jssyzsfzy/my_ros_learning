#include "ros/ros.h"
#include "std_msgs/String.h"
#include "service_learning/addint.h"

/*
服务端实现：解析客户端提供的数据，并运算再产生响应
1。导入包
2。初始化ros节点
3。创建节点句柄
4。创建服务对象
5。处理并请求并产生响应
6。spin()
*/

bool num_add(service_learning::addint::Request &request,
                                service_learning::addint::Response &response )
{
    // 1。处理请求
    int num1 = request.num1;
    int num2 = request.num2;
    ROS_INFO("受到的数据：%d, %d", num1, num2);
    // 2。组织响应
    response.sum = num1+num2;
    ROS_INFO("求和结果和为%d", response.sum);
    return true;
}


int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    // 2。初始化ros节点
    ros::init(argc, argv, "company");
    // 3。创建节点句柄
    ros::NodeHandle nh;
    ROS_INFO("以启动");
    // 4。创建服务对象
    ros::ServiceServer server = nh.advertiseService("addints", num_add);
    // 5。处理并请求并产生响应
    // 6。spin()
    ros::spin();
    return 0;
}






