#include "ros/ros.h"
#include "std_msgs/String.h"


/*
    订阅方实现：
    1.包含头文件
        文本文件 ---->std_msgs/String.h
    2.初始化ros节点
    3.创建节点句柄
    4.创建订阅者对象
    5.处理订阅的数据

*/


// 回调函数相当于一个中断
void do_msg(const std_msgs::String::ConstPtr &msg)
{
    // 功过msg获取并处理订阅到的数据
    ROS_INFO("翠花订阅的数据：%s", msg->data.c_str());

}

int main(int argc, char *argv[])
{
    // 设置中文
    setlocale(LC_ALL,"");
    // 2.初始化ros节点
    ros::init(argc, argv, "cuihua_subscribe");
    // 3.创建节点句柄
    ros::NodeHandle nh;
    // 4.创建订阅者对象
    ros::Subscriber sub = nh.subscribe("fang",10, do_msg);
    // 5.处理订阅的数据
    //ros::spinOnce();
    ros::spin();    // 订阅得到即回调 处理回调函数
    return 0;
}

