#include "ros/ros.h"
#include "exp3_own_file/hello.h"

namespace hello_ns  {

    void my_hello1::run(){
        ROS_INFO("run函数执行");
}
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "hello_node");
    hello_ns::my_hello1 myhello;
    myhello.run();
    return 0;
}

