#!/usr/bin/env python2
#coding=utf-8

import rospy
# tf2的包 含有发送与订阅
import tf2_ros
# 点发送的数据
from geometry_msgs.msg import TransformStamped
# 欧拉角转四元数
import tf
"""
    发布方实现：发布两个坐标系之间的关系 车与雷达 base_link  ---- laser
    流程:
        1.  导入
        2.  初始化ros与节点
        3.  创建发布对象
        4.  组织被发布的数据
        5.  发布数据
        6.  spin
"""


if __name__ == "__main__":
    # 2.  初始化ros与节点
    rospy.init_node("static_pub_p")
    # 3.  创建发布对象
    broad = tf2_ros.StaticTransformBroadcaster()
    # 4.  组织被发布的数据
    ts = TransformStamped()
    # head
    ts.header.stamp = rospy.Time.now()
    ts.header.frame_id = "base_link"
    # child_frame_id
    ts.child_frame_id = "laser"
    # 相对关系(偏移与四元数)
    ts.transform.translation.x = 0.2
    ts.transform.translation.y = 0.0
    ts.transform.translation.z = 0.5
    # 欧拉角转四元数
    qtn = tf.transformations.quaternion_from_euler(0, 0, 0)
    ts.transform.rotation.x = qtn[0]
    ts.transform.rotation.y = qtn[1]
    ts.transform.rotation.z = qtn[2]
    ts.transform.rotation.w = qtn[3]
    # 5.  发布数据
    broad.sendTransform(ts)
    # 6.  spin
    rospy.spin()





