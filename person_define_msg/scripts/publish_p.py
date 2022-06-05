#!/usr/bin/env python3

import rospy
import numpy as np
from person_define_msg.msg import person
import cv2

"""
1.导入包
2.初始化ros节点
3.初始化发布对象
4.组织发布逻辑并发布
"""

if __name__ == "__main__":
    # 2.初始化ros节点
    rospy.init_node("breast")
    # 3.初始化发布对象
    pub = rospy.Publisher("si", person,queue_size=10)
    # 4.组织发布逻辑并发布
    # 1.创建person数据
    p = person()
    p.name =  "hei"
    p.age = 18
    p.height = 18.2
    # 2.设置rate
    rate = rospy.Rate(1)
    # 3.循环发布
    while not rospy.is_shutdown():
        pub.publish(p)
        print(p)
        rate.sleep()