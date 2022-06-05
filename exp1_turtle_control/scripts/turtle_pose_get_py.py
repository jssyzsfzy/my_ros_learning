#! /usr/bin/env python3

from turtle import pos
import rospy
from turtlesim.msg import Pose

"""
    1.包含头文件
    2.初始化ros节点
    3.创建订阅对象
    4.处理订阅数据(回调函数)
    5.spin()
"""

def dopose(pose):
    rospy.loginfo("乌龟的位姿信息坐标x:%.2f, y:%.2f, theta:%.2f, linear_velocity:%.2f, angular_velocity:%.2f",
    pose.x, pose.y,pose.theta, pose.linear_velocity, pose.angular_velocity)

if __name__ == "__main__":
    # 2.初始化ros节点
    rospy.init_node("sub_ros_p")
    # 3.创建订阅对象
    sub = rospy.Subscriber("/turtle1/pose", Pose, dopose, queue_size=10)
    # 4.处理订阅数据(回调函数)
    # 5.spin()
    rospy.spin()  

