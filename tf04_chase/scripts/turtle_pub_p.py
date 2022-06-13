#! /usr/bin/env python
#coding=utf-8
from turtle import pos
import rospy
# tf2的包 含有发送与订阅
import tf2_ros
# 导入乌龟需要的包 数据类型等
from turtlesim.msg import Pose
from geometry_msgs.msg import TransformStamped
import tf_conversions
import sys
"""
    1.包含头文件
    2.初始化ros节点
    3.创建订阅对象
    4.处理订阅数据(回调函数)
    5.spin()
"""
def do_pose(pose):
    # 创建坐标系相对关系对象
    pub = tf2_ros.TransformBroadcaster()
    # 将pose转换成坐标系相对关系信息
    tfs = TransformStamped()
    # 被参考的坐标系
    tfs.header.frame_id = "world"
    tfs.header.stamp = rospy.Time.now()
    tfs.child_frame_id = turtle_name
    tfs.transform.translation.x = pose.x
    tfs.transform.translation.y = pose.y
    tfs.transform.translation.z = 0
    # 欧拉角转四元数
    """
        乌龟的x翻滚 y俯仰 均为0,只有z上的偏航
    """
    trans = tf_conversions.transformations.quaternion_from_euler(0, 0, pose.theta)
    tfs.transform.rotation.x = trans[0]
    tfs.transform.rotation.y = trans[1]
    tfs.transform.rotation.z = trans[2]
    tfs.transform.rotation.w = trans[3]
    # 发布
    pub.sendTransform(tfs)

turtle_name = ""

if __name__ == "__main__":
    # 2.初始化ros节点
    rospy.init_node("sub_ros_p")
    if len(sys.argv) != 4:
        rospy.logerr("error")
        sys.exit(1)
    else:
        turtle_name = sys.argv[1]
    # 3.创建订阅对象
    sub = rospy.Subscriber(turtle_name + "/pose", Pose, do_pose, queue_size=10)
    # 4.处理订阅数据(回调函数)
    # 5.spin()
    rospy.spin()  

