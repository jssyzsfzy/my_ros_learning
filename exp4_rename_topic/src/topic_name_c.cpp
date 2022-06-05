#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "hello");
    // ros::NodeHandle nh;
    /*
    设置不同类型的话题：
    1.  全局

    2.  相对
        rosrun exp4_rename_topic rename_cpp_node __ns:xxx
        rosnode list:
            /rosout
            /xxx/hello
        rostopic list:
            /rosout
            /rosout_agg
            /xxx/chat_x

    3.  私有
        rosrun exp4_rename_topic rename_cpp_node __ns:xxx
        rosnode list 
            /rosout
            /xxx/hello
        rostopic list 
            /rosout
            /rosout_agg
            /xxx/hello/chat_p

    */
    // 1.  全局     以 / 开头，与节点没有任何关系(也可以设置自己的命名空间)
    // ros::Publisher pub = nh.advertise<std_msgs::String>("/yyy/chat", 10);
    // 2.  相对     非 / 开头，
    // ros::Publisher pub1 = nh.advertise<std_msgs::String>("chat_x", 10);
    // 3.  私有     需要创建特定的NodeHandle
    // 如果私有的nh以 / 开头，生成的是全局非私有
    // 全局优先级更高
    
    ros::NodeHandle nh("~");
    ros::Publisher pub2 = nh.advertise<std_msgs::String>("chat_p", 10);
    while (ros::ok())
    {
        // ROS_INFO("");
        /* code */
    }
    return 0;
}