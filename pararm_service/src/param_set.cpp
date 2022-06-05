#include "ros/ros.h"

/*
实现参数的新增与修改
需求：首先设置机器人共享参数例如类型，半径(0.15)
再修改半径(0.2)

实现：
    ros::NodeHandle
        setParam
    ros::param
        setParam
*/

int main(int argc, char *argv[])
{
    // 初始化ros节点
    ros::init(argc, argv, "set_param_c");
    // 创建ros节点句柄
    ros::NodeHandle nh;
    // 实现参数的操作
    // 参数增加 ---------------------------------
    // 方法1: nh
    nh.setParam("type", "waimai");
    nh.setParam("radius", 0.1);
    // 方法2: ros::param
    ros::param::set("center_x",2);
    ros::param::set("center_y",1);
    // 参数修改  ----------------------------------
    // 方法1: nh
    nh.setParam("type", "kuaidi");
    nh.setParam("radius", 0.2);
    // 方法2: ros::param
    ros::param::set("center_x",3);
    ros::param::set("center_y",4);
    return 0;
}