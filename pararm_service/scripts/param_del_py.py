#! /usr/bin/env python3

import rospy

"""
删除参数：
    delet_param()
"""

if __name__ == "__main__":
    rospy.init_node("param_del_p")
    try:
        # 删除参数
        # 1.delete_param
        rospy.delete_param("center_p_x")
        rospy.loginfo("删除成功")
    except Exception as e:
        rospy.loginfo("删除失败")

