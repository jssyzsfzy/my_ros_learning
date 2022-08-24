#include "ros/ros.h"

/*
// 1.全局
    ros::param::set("/radius1", 1.2);
// 2.相对
    ros::param::set("radius2", 0.8);
// 3.私有   
    ros::param::set("~radius3", 0.9);

rosrun exp4_rename_param rename_param_node __ns:=xxx

rosparam list 
    /radius1
    /rosdistro
    /roslaunch/uris/host_fuhua_legion_y7000p_2019_pg0__34103
    /rosversion
    /run_id
    /xxx/param/radius3
    /xxx/radius2

*/


int main(int argc, char *argv[])
{
    ros::init(argc, argv, "param");
    ros::NodeHandle nh;
    // 使用rosparam
    // 1.全局
    ros::param::set("/radius1", 1.2);
    // 2.相对
    ros::param::set("radius2", 0.8);
    // 3.私有   
    ros::param::set("~radius3", 0.9);


    /*
        使用NodeHandle创建
        rosrun exp4_rename_param rename_param_node __ns:=xxx
        rosparam list 
            /radius1
            /radius_a
            /xxx/param/radius3
            /xxx/param/radius_nh_p
            /xxx/radius2
            /xxx/radius_b

    */
    // 全局
    nh.setParam("/radius_a", 0.1);
    // 相对
    nh.setParam("radius_b", 0.2);
    // 私有   
    // nh.setParam("~radius_c", 0.3);   错误
    ros::NodeHandle nh_private("~");
    nh_private.setParam("radius_nh_p", 0.3);
   while (ros::ok())
   {
       /* code */
   }
   return 0;
}
