#include "ros/ros.h"
#include "turtlesim/Pose.h"

/*
    需求：
        订阅乌龟的位姿并输出

    话题：
        // rostopic list
        /turtle1/pose

    消息：
        // rostopic info /turtle1/pose
        turtlesim/Pose
        消息格式：
        // rosmsg info turtlesim/Pose
        float32 x
        float32 y
        float32 theta
        float32 linear_velocity
        float32 angular_velocity

    需要turtlesim的包，直接再xml和cmake改

    1.包含头文件
    2.初始化ros节点
    3.创建节点句柄
    4.创建订阅对象
    5.处理订阅数据(回调函数)
    6.spin()
*/
void dopose(const turtlesim::Pose::ConstPtr & pose)
{
    ROS_INFO("乌龟的位姿信息坐标x:%.2f, y:%.2f, theta:%.2f, linear_velocity:%.2f, angular_velocity:%.2f",
    pose->x, pose->y,pose->theta, pose->linear_velocity, pose->angular_velocity);
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    // 2.初始化ros节点
    ros::init(argc, argv, "get_pose");
    // 3.创建节点句柄
    ros::NodeHandle nh;
    // 4.创建订阅对象
    ros::Subscriber sub = nh.subscribe("/turtle1/pose", 10, dopose);
    // 5.处理订阅数据(回调函数)
    // 6.spin()
    ros::spin();
    
    return 0;
}


