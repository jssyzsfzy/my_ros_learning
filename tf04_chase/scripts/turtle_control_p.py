#! /usr/bin/python
#coding=utf-8

# 1.导包
from cmath import sqrt
import imp
from math import atan2
import rospy
import tf2_ros
from geometry_msgs.msg import TransformStamped
from tf2_geometry_msgs import PointStamped
from geometry_msgs.msg import Twist
import math


if __name__ == "__main__":
    # 2.初始化 ROS 节点
    rospy.init_node("frames_sub_p")
    # 3.创建 TF 订阅对象
    buffer = tf2_ros.Buffer()
    listener = tf2_ros.TransformListener(buffer)
    # 创建速度发布对象
    pub = rospy.Publisher("/turtle_new/cmd_vel", Twist, queue_size=10)
    rate = rospy.Rate(10)
    while not rospy.is_shutdown():
        try:
        # 4.调用 API 求出 son1 相对于 son2 的坐标关系
            #lookup_transform(self, target_frame, source_frame, time, timeout=rospy.Duration(0.0)):
            tfs = buffer.lookup_transform("turtle_new","turtle1",rospy.Time(0))
            
            # tfs.transform.translation.x,
            # tfs.transform.translation.y,
            # tfs.transform.translation.z,
            # 组织速度消息
            twist = Twist()
            twist.linear.x = 0.5*math.sqrt(math.pow(tfs.transform.translation.x, 2)+math.pow(tfs.transform.translation.y, 2))
            twist.angular.z = 4*math.atan2(tfs.transform.translation.y, tfs.transform.translation.x)
            # 发布消息
            pub.publish(twist)
        except Exception as e:
            rospy.logwarn("错误提示:%s",e)


        rate.sleep()
    # 6.spin    
    # rospy.spin()






