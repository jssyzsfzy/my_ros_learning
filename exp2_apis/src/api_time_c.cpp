#include "ros/ros.h"

/*
    对时间的操作：
        获取当前的时刻+设定指定时刻
    实现：
        1.  准备(头文件，节点，node创建等……)
        2.  获取当前时刻
        3.  设定制定时刻
        4.  程序停顿  5 s
*/
void do_timer(const ros::TimerEvent event)
{
    ROS_INFO("");
    ROS_INFO("函数被调用的时刻：%.2f", event.current_real.toSec());
}


int main(int argc, char *argv[]){
    setlocale(LC_ALL,"");
    // 1.  准备(头文件，节点，node创建等……)
    ros::init(argc, argv, "time_node");
    ros::NodeHandle nh;     // 管理节点的内部引用
    // 2.  获取当前时刻
    // 返回当前时刻
    // 参考系：1970:01:01:00:00::00
    ros::Time time_now = ros::Time::now();
    ROS_INFO("当前的时间是：%.2f", time_now.toSec());
    ROS_INFO("当前的时间是：%d", time_now.sec);
    
    // 3.  设定制定时刻
    ros::Time t1(20, 31254155);     // 第一个是秒，第二个是纳秒
    ros::Time t2(20.31);     // 秒不过带小数
    ROS_INFO("t1:%.2f", t1.toSec());        
    ROS_INFO("t2:%.2f", t2.toSec());        

    ROS_INFO("------------------------------------------------------------");
    // 程序停顿  5 s
    // 创建时间对象
    // 设置停顿时间
    ros::Time start = ros::Time::now();
    ROS_INFO("start");     
    ros::Duration du(1.5);  // 停顿4.5s时序
    du.sleep();         //  休眠4.5s
    ros::Time end = ros::Time::now();
    ROS_INFO("时间长度：%.4f",end.toSec() - start.toSec());        
    ROS_INFO("休眠停止"); 

    ROS_INFO("------------------------------------------------------------");
    /*
    定时器的使用
    每隔1s再控制台输出一段文本
    实现：
        策略1：ros::Rate()
        策略2：定时器
    */
   /*
   Create a timer which will call a callback at the specified rate. 
   This variant takes a class member function, 
   and a bare pointer to the object to call the method on. 
   When the Timer (and all copies of it) returned goes out of scope, 
   the timer will automatically be stopped, and the callback will no longer be called.

   r – The rate at which to call the callback
    callback – The method to call
    obj – The object to call the method on
    oneshot – If true, this timer will only fire once
    autostart – If true (default), return timer that is already started
   */
    // ros::Timer timer1 = nh.createTimer(ros::Duration(1), do_timer);
    ros::Timer timer1 = nh.createTimer(ros::Duration(1), do_timer,true,false);
    timer1.start();
    ros::spin();
    return 0;
}

