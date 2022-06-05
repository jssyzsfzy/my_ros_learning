#! /usr/bin/env python3

from re import T

from numpy import rate
import rospy
from geometry_msgs.msg import Twist

"""
发布方实现：发布速度消息
    话题：
        /turtle1/cmd_vel
    消息：
        geometry_msgs/Twist
    
    1.导入包
    2.初始化 ROS 节点
    3.创建发布者对象
    4.循环发布运动控制消息
"""

if __name__ == "__main__":
    # 2.初始化 ROS 节点
    rospy.init_node("turtle_control_py")
    # 3.创建发布者对象
    pub = rospy.Publisher("/turtle1/cmd_vel", Twist, queue_size=10)
    # 4.循环发布运动控制消息
    # 设置发布频率
    rate = rospy.Rate(10)
    # 创建速度消息
    twist = Twist()
    twist.linear.x = 1.0
    twist.linear.y = 0.0
    twist.linear.z = 0.0
    twist.angular.x = 0.0
    twist.angular.y = 0.0
    twist.angular.z = 1.0
    # 循环发布
    while not rospy.is_shutdown():
        pub.publish(twist)
        rate.sleep()




