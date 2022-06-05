#!/usr/bin/env python3

import rospy


"""
参数的新增与修改
要求：在参数服务器中设置机器人属性
实现：
    rospy.set_param()
"""

if __name__ == "__main__":
    rospy.init_node("param_set_py")
    # 新增参数
    rospy.set_param("center_p_x", 10)
    rospy.set_param("center_p_y", 5)
    rospy.set_param("audius", 0.1)

    # 修改参数
    rospy.set_param("audius", 0.2)
    


