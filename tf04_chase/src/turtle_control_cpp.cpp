#include "ros/ros.h"
// 导入订阅包
#include "tf2_ros/transform_listener.h"
// 导入缓存包
#include "tf2_ros/buffer.h"
// 点的创建依赖包
#include "geometry_msgs/PointStamped.h"
// 
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"
//  包含位置变换头文件
#include "geometry_msgs/Twist.h"

/*
1.换算turtle1相对turtle2关系
2.由距离计算角速度和线速度
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
    // 创建速度发布对象
    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/turtle_new/cmd_vel", 10);

    // 创建坐标点
    while (ros::ok())
    {
        // 
        try{
            // 计算son1和son2的相对关系
            geometry_msgs::TransformStamped son1toson2 = buffer.lookupTransform("turtle_new", "turtle1", ros::Time(0.0));
            // ROS_INFO("son1 相对 son2的信息：父级：%s, 子级：%s,偏移量：x:%.2f, y:%.2f, z:%.2f",
            // son1toson2.header.frame_id.c_str(), son1toson2.child_frame_id.c_str(),son1toson2.transform.translation.x, son1toson2.transform.translation.y,son1toson2.transform.translation.z);
            // 计算速度与角速度的值
            geometry_msgs::Twist twist;
            /*
                速度关系：
                线速度只有x轴上速度             x = sqrt(x^2 + y^2) * a
                角速度只有z轴的旋转速度     z = atan(y/x) * b
            */
           if(son1toson2.transform.translation.x != 0){
                twist.linear.x = 0.5*sqrt(pow(son1toson2.transform.translation.y, 2)+pow(son1toson2.transform.translation.x, 2));
                twist.angular.z = 4  * atan2(son1toson2.transform.translation.y,son1toson2.transform.translation.x);
           }
           else{
                twist.linear.x = 0.5*sqrt(pow(son1toson2.transform.translation.y, 2)+pow(son1toson2.transform.translation.x, 2));
                twist.angular.z = 0.5 * atan2(son1toson2.transform.translation.y,son1toson2.transform.translation.x+0.01);
           }
                        // 发布速度与角速度
            pub.publish(twist);
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




