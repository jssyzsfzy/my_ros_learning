#!/usr/bin/env python3

from ast import Str
from readline import write_history_file
from turtle import st
import rospy
from std_msgs.msg import String
"""
使用python的方法:
    1.导入包
    2.初始化ros节点
    3.创建发布者对象
    4.编写发布逻辑并发布数据
"""

if __name__ == "__main__":

    # 2.初始化ros节点
    """
        作用：初始化
        参数：
            name ----  节点名称
            argv=None ---- 设置节点调用时的传递参数
            annymous=false ---- 为节点名称增加随即后缀
        使用：
            1.argv使用
                可以按照ros指定语法格式传入参数, ros解析与使用
            2.annoymous
    """
    rospy.init_node("gouzi",anonymous=True)   # 初始化节点名称
    # 3.创建发布者对象
    """
    内容：latch
        bool值，最初为false
    作用：将最后一条信息保存，发给新订阅者
    使用：
    """
    pub = rospy.Publisher("che", String, queue_size=10, latch=True)
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
        count += 1
        if count<=10:
            msg.data = "hello num: " + str(count)
            pub.publish(msg)
            rospy.loginfo("发布数据的数据：%s",msg.data)
        rate.sleep()
        