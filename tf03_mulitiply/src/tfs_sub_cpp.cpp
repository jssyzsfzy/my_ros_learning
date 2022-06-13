#include "ros/ros.h"
// 导入订阅包
#include "tf2_ros/transform_listener.h"
// 导入缓存包
#include "tf2_ros/buffer.h"
// 点的创建依赖包
#include "geometry_msgs/PointStamped.h"
// 
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"
/*
订阅实现：
1.  计算son1 son2的相对关系
2.  计算son1的某个坐标点在son2的坐标值

1.  包含头文件
2.  编码初始化
3.  创建订阅对象
4.  编写解析逻辑
5.  spinOnce()
*/


int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    // 2.  编码初始化
    ros::init(argc, argv, "tfs_sub");
    ros::NodeHandle nh;
    // 3.  创建订阅对象
    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener sub(buffer);
    // 4.  编写解析逻辑
    ros::Rate rate(10);
    geometry_msgs::PointStamped son1;
    son1.header.stamp = ros::Time::now();
    son1.header.frame_id = "son1";
    son1.point.x = 1;
    son1.point.y = 2;
    son1.point.z = 3;

    // 创建坐标点
    while (ros::ok())
    {
        // 
        try{
            // 计算son1和son2的相对关系
            geometry_msgs::TransformStamped son1toson2 = buffer.lookupTransform("son2", "son1", ros::Time(0.0));
            ROS_INFO("son1 相对 son2的信息：父级：%s, 子级：%s,偏移量：x:%.2f, y:%.2f, z:%.2f",
            son1toson2.header.frame_id.c_str(), son1toson2.child_frame_id.c_str(),son1toson2.transform.translation.x, son1toson2.transform.translation.y,son1toson2.transform.translation.z);
            // 计算son1的点在son2下的坐标值
            geometry_msgs::PointStamped ps_son2 = buffer.transform(son1, "son2");
            ROS_INFO("点的信息x:%.2f, y:%.2f, z:%.2f", ps_son2.point.x, ps_son2.point.y, ps_son2.point.z);
        }
        catch(const std::exception &e){
            ROS_INFO("错误%s", e.what());
        }
        rate.sleep();
        ros::spinOnce();
        /* code */
    }
    
    // 5.  spinOnce()
    return 0;
}




