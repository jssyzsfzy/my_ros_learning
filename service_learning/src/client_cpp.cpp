#include "ros/ros.h"
#include "std_msgs/String.h"
#include "service_learning/addint.h"


/*
客户端实现：提供两个整数，并处理响应的结果
1。导入包
2。初始化ros节点
3。创建节点句柄
4。创建客户端对象
5。提交请求并处理响应

实现参数的动态提交：
1.格式：rosrun *****  *****  12 32
2.节点执行时需要获取命令中的参数，并组织进request


如果先启动客户端，会请求异常，若必须先启动客户端
先挂起，再等待服务器启动，再正常启动
1.内置相关函数，可以让客户端启动后挂起等待服务器
*/

// argc 3个 argv[]参数是 1 文件名    2 第一个参数   3 第二个参数 
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");

    // 优化实现，获取命令中的参数
    if(argc != 3){
        ROS_INFO("参数个数不对");
        return 1;
    }
    
    // 2。初始化ros节点
    ros::init(argc, argv, "give_data");
    // 3。创建节点句柄
    ros::NodeHandle nh;
    // 4。创建客户端对象
    ros::ServiceClient client = nh.serviceClient<service_learning::addint>("addints");
    // 5。提交请求并处理响应
    // 5.1组织请求
    service_learning::addint add;
    add.request.num1 = atoi(argv[1]);
    add.request.num2 = atoi(argv[2]);

    // 5.2处理响应
    // 调用判断服务器状态函数
    // 函数1：
    // client.waitForExistence();
    // 函数2：
    ros::service::waitForService("addints");
    bool ans = client.call(add);
    if (ans == true)
    {
        ROS_INFO("响应成功:数据是：%d", add.response.sum);
    }
    else{
        ROS_INFO("失败了……");
    }
    // 6。spin()
    return 0;
}