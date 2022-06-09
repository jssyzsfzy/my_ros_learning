#include "ros/ros.h"


/*
    需求：发布方实现，同时订阅乌龟的位姿信息，转化为base_link的坐标关系并发布
    准备：
        话题
            rostopic list ：
                /rosout
                /rosout_agg
                /turtle1/cmd_vel
                /turtle1/color_sensor
                /turtle1/pose
        查看话题数据类型：
            rostopic info /turtle1/cmd_vel
                Type: geometry_msgs/Twist
            rostopic info /turtle1/pose 
                Type: turtlesim/Pose
        查看数据类型具体内容：
            rosmsg info turtlesim/Pose
                float32 x
                float32 y
                float32 theta
                float32 linear_velocity
                float32 angular_velocity

    流程：
    1.  包含头文件
    2.  各种初始化
    3.  创建订阅对象(订阅/turtle1/pose )
    4.  回调函数处理订阅消息：将位姿信息转化为坐标相对关系发布
    5.  spin
*/
void turtle_pose(){
    
}


int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    // 2.  各种初始化
    ros::init(argc, argv, "dynamic_pub_cpp");
    ros::NodeHandle nh;
    // 3.  创建订阅对象(订阅/turtle1/pose )
    ros::Subscriber sub = nh.subscribe("/turtle1/pose",10,turtle_pose);
    // 4.  回调函数处理订阅消息：将位姿信息转化为坐标相对关系发布
    // 5.  spin
    ros::spin();
    return 0;
}







