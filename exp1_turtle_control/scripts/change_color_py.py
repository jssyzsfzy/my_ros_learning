#! /usr/bin/env python3

import rospy

"""
修改gui背景颜色
1.初始化ros节点
2.设置参数

"""

if __name__ == "__main__":
    rospy.init_node("change_color_py")
    rospy.set_param("/turtlesim/background_g", 100)
    rospy.set_param("/turtlesim/background_b", 125)
    rospy.set_param("/turtlesim/background_r", 125)


