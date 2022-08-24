#include "ros/ros.h"
// 静态坐标导入器
#include "tf2_ros/transform_listener.h"
// 导入接收头文件 订阅数据
#include "geometry_msgs/TransformStamped.h"
// 缓存数据
#include "tf2_ros/buffer.h"
// 导入点的数据类型头文件
#include "geometry_msgs/PointStamped.h"
// tf2转换的头文件
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"

/*
    订阅坐标系之间的变换关系，传入坐标点，使用tf进行转换
    流程：
    1.  包含头文件
    2.  编码，初始化nh
    3.  创建订阅对象
    4.  组织一个点数据，
    5.  转换算法实现，使用tf内置实现
    6.  输出
*/

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    // 2.  编码，初始化nh
    ros::init(argc, argv, "static_sub");
    ros::NodeHandle nh;
    // 3.  创建订阅对象
    // 3.1创建一个buffer缓存
    tf2_ros::Buffer buffer;
    // 创建接收对象,将订阅数据存入buffer
    tf2_ros::TransformListener listener(buffer);
    // 4.  组织一个点数据
    geometry_msgs::PointStamped ps;
    // 参考坐标系
    ps.header.frame_id="turtle1";
    // 时间戳需要修改
    ps.header.stamp = ros::Time(0.0);
    ps.point.x = 2.0;
    ps.point.y = 3.0;
    ps.point.z = 5.0;
    // 添加休眠
    // ros::Duration(2).sleep();

    // 5.  转换算法实现，使用tf内置实现
    ros::Rate rate(10);
    while (ros::ok())
    {
        
        /*
            调用了 buffer 的转换函数 transform
            参数1：被转换的坐标点
            参数2：目标坐标系
            返回值：输出的坐标点

            ps1:调用时必须包含头文件    #include "tf2_geometry_msgs/tf2_geometry_msgs.h"
            ret：运行时会抛出一场：base_link坐标系找不到，可能buffer未缓存好，订阅数据是一个耗时操作
                    调用transform时，坐标系转换关系还没有订阅到，出现异常
                    1。转换前休眠
                    2。进行异常处理，异常捕获进行循环，知道捕获base_link
        */
       try{
           // 核心实现 ---->将ps点转化为base_link坐标点
            geometry_msgs::PointStamped ret =  buffer.transform(ps, "world");

            ROS_INFO("x:%.2f, y:%.2f, z:%.2f, 参考坐标系是%s", ret.point.x,ret.point.y,ret.point.z,ret.header.frame_id.c_str());
            rate.sleep();
            ros::spinOnce();
       }
       catch(const std::exception& e)
       {
            // continue;
            std::cerr << e.what() << '\n';
            // ROS_INFO("异常消息：%s", e.what());
       }
       
    }
    return 0;
}
