#include "ros/ros.h"

/*
参数删除：
1.NodeHandle实现——————————
    nh.deleteParam(键)
2.ros::param    实现—————————— 
*/

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc, argv, "param_del_c");
    ros::NodeHandle nh;
    // 删除：NodeHandle实现——————————
    bool result = nh.deleteParam("center_x");
    if(result){
        ROS_INFO("center_x删除成功");
    }
    else{
        ROS_INFO("center_x删除失败");
    }

    // 使用ros::param        实现—————————— 
    result = ros::param::del("center_y");
    if(result){
        ROS_INFO("center_y删除成功");
    }
    else{
        ROS_INFO("center_y删除失败");
    }
    return 0;
}

