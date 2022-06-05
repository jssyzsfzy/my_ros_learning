#!/usr/bin/env python

from ast import Str
import imp
from readline import write_history_file
from turtle import st
import rospy
from std_msgs.msg import String
"""
使用python的方法：
    1.导入包
    2.初始化ros节点
    3.创建发布者对象
    4.编写发布逻辑并发布数据
"""

if __name__ == "__main__":

    # 2.初始化ros节点
    rospy.init_node("gouzi")   # 初始化节点名称
    # 3.创建发布者对象
    pub = rospy.Publisher("che", String, queue_size=10)
    # 4.编写发布逻辑并发布数据
    # 创建数据
    msg = String()
    # 指定发布频率
    rate = rospy.Rate(1)
    # 数据编号
    count = 0
    # 循环发布数据
    rospy.sleep(1)
    while not rospy.is_shutdown():
        msg.data = "hello num: " + str(count)
        count += 1
        pub.publish(msg)
        rospy.loginfo("发布数据的数据：%s",msg.data)
        rate.sleep()
        






