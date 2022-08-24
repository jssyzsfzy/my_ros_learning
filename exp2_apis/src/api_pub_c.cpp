#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sstream"
/*
    发布方实现：
    1.包含头文件
        文本文件 ---->std_msgs/String.h
    2.初始化ros节点
    3.创建节点句柄
    4.创建发布者对象
    5.编写发布者逻辑并发送数据

*/

int main(int argc, char *argv[]){
    // 设置中文
    setlocale(LC_ALL,"");
    // 2.初始化ros节点
    /*
        初始化ros节点：
            作用：ros初始化作用

            参数：一共四个参数
                1.argc
                    封装实参个数：n+1
                2.argv
                    封装参数的数组(第一个参数是文件名,字符串)
                3.name
                    为节点命名
                    需要保证唯一性
                4.options
                    节点启动选项
                返回值：void
            
            使用：
                1.argc 和 argv 的使用
                    可以再命令行输入实参
                    如果按照ros中的特定格式传入实参，那么ros可以加以使用，比如用来设置全局参数，给节点命名
                2.options的使用
                    节点名称唯一性：同一节点不能重复启动
                        第二次启动同名节点会覆盖第一次节点
                    需求：特定场景下需要一个结点多次启动且能正常运行
                    解决：
                    ros::init(argc, argv, "goudan",ros::init_options::AnonymousName);
                        ros::init_options::AnonymousName
                            表示再goudan基础上加上一个随机数以保证能够正常运行
                            /goudan_1654306888073666974
                            /goudan_1654306901888161569
    */
    ros::init(argc, argv, "goudan",ros::init_options::AnonymousName);
    // 3.创建节点句柄
    ros::NodeHandle nh;
    // 4.创建发布者对象
    /*
        advertise介绍：
        作用：创建发布者对象
        模板：被发布消息的类型
        参数：
            1.  话题名称
                节点之间能够通信的基础
            2.  对列长度
                防止堆叠
            3.  latch(可选)
                如果为true，会保存发布方的最后一条消息，当新连接建立时，
                发布方会发送这一消息
                默认值false，不保存最后一条，直接重新发送
        使用：
            latch设置为true的作用
            以静态地图发布为例：
                方案一：
                    以固定频率发布，效率低下，占用资源
                方案二：
                    只发送一次，latch设置为true，下一次连接时发送一次
    */
    ros::Publisher pub = nh.advertise<std_msgs::String>("fang", 10,true);
    // 5.编写发布者逻辑并发送数据
    // 创建被发布的消息
    std_msgs::String msg;
    // 发布频率
    ros::Rate rate(1);
    // 设置编号
    int count=0;
    // 等待一会儿 发布者注册还未结束已经发布多条信息
    ros::Duration(0.5).sleep();
    // 循环发布消息
    while (ros::ok())
    {
        count++;
        // msg.data="hello world";
        std::stringstream(ss);
        ss << "hello " << count;
        msg.data=ss.str();
        if(count<=10)
        {
            pub.publish(msg);
            ROS_INFO("发布的数据:%s", ss.str().c_str());
        }
        if (count>=15)
        {
            ros::shutdown();
        }
        rate.sleep();
        /* code */
    }
    
    return 0;
}

