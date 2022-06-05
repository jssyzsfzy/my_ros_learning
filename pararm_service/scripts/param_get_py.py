#! /usr/bin/env python3

import rospy

"""
键值的查询
get_param(键,默认值)
    当键存在时，返回对应的值，如果不存在返回默认值
get_param_cached
get_param_names
has_param
search_param

"""

if __name__ == "__main__":
    rospy.init_node("param_get_p")
    # 1.get_param
    audius = rospy.get_param("audius", 0.3)
    rospy.loginfo("get_param  audius得到的是：%.2f", audius)

    # 2.get_param_cached
    audius = rospy.get_param_cached("audius", 1)
    rospy.loginfo("get_param_cached  audius得到的是：%.2f", audius)

    # 3.get_param_names
    names = rospy.get_param_names()
    for i in names:
        rospy.loginfo("get_param_names  name%s", i)

    # 4.has_param
    flag1 = rospy.has_param("audius")
    if flag1:
        rospy.loginfo("存在")
    else:
        rospy.loginfo("不存在")

    # 5.search_param
    key = rospy.search_param("center_p_x")
    rospy.loginfo(key)
