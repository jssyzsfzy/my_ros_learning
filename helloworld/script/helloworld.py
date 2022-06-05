#!/usr/bin/env python
import rospy
import os
import sys
# sys.path.insert(0, "/home/fuhua/desktop/ros/demo01/src/helloworld/script")
# 防止路径写死，影响可移植性
# 优化，动态获取路径
path = os.path.abspath(".")
sys.path.insert(0, path+"/src/helloworld/script")

import toolos
if __name__ == "__main__":
    print(os.path.abspath("."))
    rospy.init_node("Hello")
    rospy.loginfo("Hello World!!!!")
    x = toolos.get_hx(2)
    rospy.loginfo("tools得到的数据是：%.4f, 原来的num是：%.2f", x, toolos.num)
