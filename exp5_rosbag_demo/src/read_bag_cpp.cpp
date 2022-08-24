#include "ros/ros.h"
#include "rosbag/bag.h"
#include "std_msgs/String.h"
#include "rosbag/view.h"
/*
    使用rosbag向磁盘读文件(话题+消息)
    流程:
        1.导入
        2.初始化
        3.创建rosbag对象
        4.打开文件流(读取方式打开)
        5.读数据并关闭
*/

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    // 2.初始化
    ros::init(argc, argv, "read_bag");
    ros::NodeHandle nh;
    // 3.创建rosbag对象
    rosbag::Bag bag;
    // 4.打开文件流(读取方式打开)
    bag.open("/home/fuhua/desktop/hello.bag", rosbag::BagMode::Read);
    // 5.读数据并关闭
    // 取出话题，时间戳，数据
    // 可以先取消息的集合，再取出消息的字段
    for (auto &&m : rosbag::View(bag)){
        // 解析
        std::string topic = m.getTopic();
        ros::Time t = m.getTime();
        std_msgs::StringPtr data = m.instantiate<std_msgs::String>();
        ROS_INFO("解析的内容，话题：%s, 时间戳%.2f, 数据是:%s", topic.c_str(), t.toSec(), data->data.c_str());
    }
    bag.close();
}