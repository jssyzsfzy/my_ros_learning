#include "ros/ros.h"
// 乌龟的位姿数据
#include "turtlesim/Pose.h"
// tf的发布头文件
#include "tf2_ros/transform_broadcaster.h"
// 发布被发布的位置数据
#include "geometry_msgs/TransformStamped.h"
// 欧拉转四元数
#include "tf2/LinearMath/Quaternion.h"

// 声明变量接收传递参数
std::string turtle_name;

void turtle_pose(const turtlesim::Pose::ConstPtr &pose){
    // 获取位姿信息, 转化为坐标系相对关系, 发布
    // 1.创建发布对象
    // 防止每次回调都创建,建立静态发布对象
    static tf2_ros::TransformBroadcaster tf_trans;
    // 2.组织发布数据
    geometry_msgs::TransformStamped ts;
    ts.header.frame_id = "world";
    ts.header.stamp = ros::Time::now();
    ts.child_frame_id = turtle_name;
    // 坐标系偏移量
    // 动态传入的
    ts.transform.translation.x = pose->x;
    ts.transform.translation.y = pose->y;
    ts.transform.translation.z = 0.0;
    // 坐标系四元数设置
    // pose含有偏航角度,无翻滚与俯仰角度
    tf2::Quaternion qtn;
    qtn.setRPY(0,0,pose->theta);
    ts.transform.rotation.x = qtn.getX();
    ts.transform.rotation.z = qtn.getZ();
    ts.transform.rotation.y = qtn.getY();
    ts.transform.rotation.w = qtn.getW();
    // 3.发布数据
    tf_trans.sendTransform(ts);
}


int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    // 解析launch文件，args传入的参数
    if(argc != 4)
    {
        ROS_INFO("num = %d", argc);
        for(int i=0;i<argc;i++)
        {
            ROS_INFO("第%d个参数是%s", i, argv[i]);
        }
        ROS_ERROR("传入参数错误，应该传入两个");
    }
    else{
            turtle_name = argv[1];
    }
    
    // 2.  各种初始化
    ros::init(argc, argv, "dynamic_pub_cpp");
    ros::NodeHandle nh;
    // 3.  创建订阅对象(订阅/turtle1/pose )
    // 订阅的话题名称 turtle1 turtle2 动态传入的参数
    ros::Subscriber sub = nh.subscribe("/"+turtle_name + "/pose",20,turtle_pose);
    // 4.  回调函数处理订阅消息：将位姿信息转化为坐标相对关系发布
    // 5.  spin
    ros::spin();
    return 0;
}







