#include "ros/ros.h"
#include "turtlesim/Spawn.h"

/*
向服务端发送生成乌龟的请求

    服务：生成乌龟
        // rosservice list
        /spawn
    
        // rosservice info /spawn
        Node: /turtle1
        Type: turtlesim/Spawn
        Args: x y theta name

        rossrv info turtlesim/Spawn
        float32 x
        float32 y
        float32 theta
        string name
        ---
        string name

    命令行实现
    rosservice call /spawn "x: 2.0
    y: 3.0
    theta: 1.0
    name: 'turtle_new'" 

    实现：
    1.包含头文件
    2.初始化ros节点
    3.创建节点句柄
    4.创建服务对应客户端对象
    5.组织数据发送
    6.处理响应
*/

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    // 2.初始化ros节点
    ros::init(argc, argv, "create_turtle_cpp");
    // 3.创建节点句柄
    ros::NodeHandle nh;
    // 4.创建服务对应客户端对象
    ros::ServiceClient client = nh.serviceClient<turtlesim::Spawn>("/spawn");
    // 5.组织数据发送
    // 5.1组织请求数据
    turtlesim::Spawn spawn;
    spawn.request.x = 2.0;
    spawn.request.y = 3.0;
    spawn.request.theta = 0.0;
    spawn.request.name = "turtle_new";
    // 5.2发送请求
    // 判断服务器状态
    // ros::service::waitForService("/spawn");
    client.waitForExistence();
    client.call(spawn);
    ROS_INFO("返回的参数是：%s", spawn.response.name.c_str());
    // 6.处理响应

    return 0;
}