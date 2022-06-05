#include "ros/ros.h"

/*
1.首先我们需要知道关于背景的param参数
    rosrun turtlesim turtlesim_node
        /rosdistro
        /roslaunch/uris/host_fuhua_legion_y7000p_2019_pg0__35657
        /rosversion
        /run_id
        /turtlesim/background_b
        /turtlesim/background_g
        /turtlesim/background_r
2.得到目前背景的rgb值
    rosparam get /turtlesim/background_b
3.设置rgb值
    rosparam set /turtlesim/background_g 0
    需要关闭窗口后才能看到效果

cpp修改颜色方法：
1.初始化节点
2.不一定需要创建节点句柄(与后续api有关)
3.修改参数
*/

int main(int argc, char *argv[])
{
    // 1.初始化节点
    ros::init(argc, argv,"change_back");
    // 2.不一定需要创建节点句柄(与后续api有关)
    ros::NodeHandle nh("turtlesim");
    // 3.修改参数
    // 如果调用ros::param 不需要创建节点句柄
    // ros::param::set("/turtlesim/background_b", 255);
    // ros::param::set("/turtlesim/background_r", 255);
    // ros::param::set("/turtlesim/background_g", 255);

    // 使用NodeHandle进行修改
    nh.setParam("background_g", 0);
    nh.setParam("background_b", 0);
    nh.setParam("background_r", 0);
    return 0;
}