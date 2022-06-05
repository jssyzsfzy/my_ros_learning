#include "ros/ros.h"
#include "person_define_msg/person.h"


/*
订阅者接收自定义人的信息
1.包含头文件
2.初始化ros节点
3.创建ros节点句柄
4.创建订阅对象
5.创建回调函数处理数据
6.spin()
*/

void do_person_msg(const person_define_msg::person::ConstPtr& fzy)
{
    ROS_INFO("收到消息：名字：%s，年龄：%d，身高：%f", fzy->name.c_str(),fzy->age, fzy->height);
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    // 2.初始化ros节点
    ros::init(argc,argv, "meinv");
    // 3.创建ros节点句柄
    ros::NodeHandle nh;
    // 4.创建订阅对象
    ros::Subscriber sub = nh.subscribe("chat", 10,do_person_msg);
    // 5.创建回调函数处理数据

    // 6.spin()
    ros::spin();
    return 0;
}







