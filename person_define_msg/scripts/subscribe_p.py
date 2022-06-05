#!/usr/bin/env python3

import rospy
import numpy as np
from person_define_msg.msg import person

"""
1.导入包
2.初始化ros节点
3.初始化接收对象
4.回调函数处理数据
"""
def check_data(p):
    print("接收", p.name, p.age, p.height)

if __name__ == "__main__":
    # 2.初始化ros节点
    rospy.init_node("man")
    # 3.初始化接收对象
    sub = rospy.Subscriber("si", person, check_data)
    # 4.回调函数处理数据
    rospy.spin()
