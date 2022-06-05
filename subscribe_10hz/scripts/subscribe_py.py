#!/usr/bin/env python

import rospy
from std_msgs.msg import String 


"""
订阅：
使用python的方法：
    1.导入包
    2.初始化ros节点
    3.创建订阅对象
    4.回调函数处理数据
    5.spin()
"""
def get_data(msg):
    rospy.loginfo("订阅到的数据： %s", msg.data)
    print(msg.data)


if __name__ == "__main__":
    # 2.初始化ros节点
    rospy.init_node("meinv")
    # 3.创建订阅对象
    sub = rospy.Subscriber("che", String, callback=get_data, queue_size=10)
    # 4.回调函数处理数据
    # 5.spin()
    rospy.spin()













