#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sstream"
/*
    发布方实现：
    1.包含头文件
        文本文件 ---->std_msgs/String.h
    2.初始化ros节点
    3.创建节点句柄
    4.创建发布者对象
    5.编写发布者逻辑并发送数据

*/

int main(int argc, char *argv[]){
    // 设置中文
    setlocale(LC_ALL,"");
    // 2.初始化ros节点
    ros::init(argc, argv, "goudan");
    // 3.创建节点句柄
    ros::NodeHandle nh;
    // 4.创建发布者对象
    ros::Publisher pub = nh.advertise<std_msgs::String>("fang", 10);
    // 5.编写发布者逻辑并发送数据
    // 创建被发布的消息
    std_msgs::String msg;
    // 发布频率
    ros::Rate rate(1);
    // 设置编号
    int count=0;
    // 等待一会儿 发布者注册还未结束已经发布多条信息
    ros::Duration(0.5).sleep();
    // 循环发布消息
    while (ros::ok())
    {
        count++;
        // msg.data="hello world";
        std::stringstream(ss);
        ss << "hello " << count;
        msg.data=ss.str();
        pub.publish(msg);
        ROS_INFO("发布的数据:%s", ss.str().c_str());
        rate.sleep();
        /* code */
    }
    
    return 0;
}

