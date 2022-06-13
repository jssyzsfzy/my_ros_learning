#include "ros/ros.h"
#include "rosbag/bag.h"
#include "std_msgs/String.h"

/*
    使用rosbag向磁盘写文件(话题+消息)
    流程:
        1.导入
        2.初始化
        3.创建rosbag对象
        4.打开文件流
        5.写数据并关闭
*/

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    // 2.初始化
    ros::init(argc, argv, "write_bag");
    ros::NodeHandle nh;
    // 3.创建rosbag对象
    rosbag::Bag bag;
    // 4.打开文件流
    bag.open("/home/fuhua/desktop/hello.bag", rosbag::BagMode::Write);
    // 5.写数据并关闭
    std_msgs::String msg;
    msg.data = "haha";
    /*
        参数设置:
        1.  话题名
        2.  时间戳
        3.  数据
    */
    bag.write("/chat",ros::Time::now(), msg);
    bag.close();
}