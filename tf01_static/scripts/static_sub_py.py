#!/usr/bin/env python2
#coding=utf-8


from ast import Expression
import rospy
# 订阅对象
import tf2_ros
# 原始消息封装
from tf2_geometry_msgs import tf2_geometry_msgs as tf_msg

"""
    订阅：订阅坐标信息，转入被转换的坐标点，调用转换算法
    流程：
        1.导入
        2.初始化
        3.创建订阅对象
        4.组织被转化的坐标点
        5.转换逻辑实现，使用tf算法
        6.输出转换结果

"""

if __name__ == "__main__":
    # 2.初始化
    rospy.init_node("static_sub_p")
    # 3.创建订阅对象
    # 3.1创建缓存对象
    buffer = tf2_ros.Buffer()
    # 3.2创建订阅对象(传入缓存)
    sub = tf2_ros.TransformListener(buffer)
    # 4.组织被转化的坐标点
    ts = tf_msg.PointStamped()
    ts.header.stamp = rospy.Time.now()
    ts.header.frame_id = "laser"
    ts.point.x = 2.0
    ts.point.y = 3.0
    ts.point.z = 5.0
    # 5.转换逻辑实现，使用tf算法
    rate = rospy.Rate(10)
    while not rospy.is_shutdown():
        # 转换实现
        try:
            ret = buffer.transform(ts, "base_link")
            rate.sleep()
            # 6.输出转换结果
            rospy.loginfo("x:%.2f, y:%.2f, z:%.2f, 参考坐标系是%s", ret.point.x,ret.point.y,ret.point.z,ret.header.frame_id)
        except Exception as e:
            rospy.logwarn("错误提示:%s",e)
    # 7.spin | spinOnce

