#include "ros/ros.h"

/*
    演示ros日志的内容：
        ROS_DEBUG("调试：");    // 不会输出再现实台
        ROS_INFO("一般信息");    
        ROS_ERROR("错误信息");
        ROS_FATAL("严重错误");
*/

int main(int argc, char * argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc, argv, "log");
    ros::NodeHandle nh;

    // 日志输出：
    ROS_DEBUG("调试：");    // 不会输出再现实台
    ROS_INFO("一般信息");    
    ROS_WARN("警告");
    ROS_ERROR("错误信息");
    ROS_FATAL("严重错误");
    return 0;
}
