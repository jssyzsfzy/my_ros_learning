#include "ros/ros.h"
#include "person_define_msg/person.h"

/*
发布者发布自定义人的信息
1.包含头文件
2.初始化ros节点
3.创建ros节点句柄
4.创建发布对象
5.创建发布逻辑和发布数据
*/

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    // 2.初始化ros节点
    ros::init(argc, argv,"msg_data");
    // 3.创建ros节点句柄
    ros::NodeHandle nh;
    // 4.创建发布对象
    ros::Publisher pub = nh.advertise<person_define_msg::person>("chat", 10);
    // 5.创建发布逻辑和发布数据
    // 1.创建发布数据
    person_define_msg::person fzy;
    fzy.name = "傅振洋";
    fzy.age = 18;
    fzy.height = 170.0;
    // 2.设置发布频率
    ros::Rate rate(0.8);
    // 3.循环发布
    while (ros::ok())
    {
        
        //数据发布
        pub.publish(fzy);
        rate.sleep();
        ROS_INFO("发布消息：名字：%s，年龄：%d，身高：%f", fzy.name.c_str(),fzy.age, fzy.height );
        fzy.height+=1;
        ros::spinOnce();
    }
    return 0;
}

