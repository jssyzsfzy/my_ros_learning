#include "ros/ros.h"
#include "exp3_own_src/hello.h"



int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv,"hello_node");
    hello_ns::my_hello hihi;
    hihi.run();
    return 0;
}