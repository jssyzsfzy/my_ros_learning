#!/usr/bin/env python2
#coding=utf-8
"""  
    需求:
        现有坐标系统，父级坐标系统 world,下有两子级系统 son1，son2，
        son1 相对于 world，以及 son2 相对于 world 的关系是已知的，
        求 son1 与 son2中的坐标关系，又已知在 son1中一点的坐标，要求求出该点在 son2 中的坐标
    实现流程:   
        1.导包
        2.初始化 ROS 节点
        3.创建 TF 订阅对象
        4.调用 API 求出 son1 相对于 son2 的坐标关系
        5.创建一依赖于 son1 的坐标点，调用 API 求出该点在 son2 中的坐标
        6.spin

"""
# 1.导包
import rospy
import tf2_ros
from geometry_msgs.msg import TransformStamped
from tf2_geometry_msgs import PointStamped

if __name__ == "__main__":
    # 2.初始化 ROS 节点
    rospy.init_node("frames_sub_p")
    # 3.创建 TF 订阅对象
    buffer = tf2_ros.Buffer()
    listener = tf2_ros.TransformListener(buffer)

    rate = rospy.Rate(1)
    while not rospy.is_shutdown():
        try:
        # 4.调用 API 求出 son1 相对于 son2 的坐标关系
            #lookup_transform(self, target_frame, source_frame, time, timeout=rospy.Duration(0.0)):
            tfs = buffer.lookup_transform("son2","son1",rospy.Time(0))
            rospy.loginfo("son1 与 son2 相对关系:")
            rospy.loginfo("父级坐标系:%s",tfs.header.frame_id)
            rospy.loginfo("子级坐标系:%s",tfs.child_frame_id)
            rospy.loginfo("相对坐标:x=%.2f, y=%.2f, z=%.2f",
                        tfs.transform.translation.x,
                        tfs.transform.translation.y,
                        tfs.transform.translation.z,
            )
        # 5.创建一依赖于 son1 的坐标点，调用 API 求出该点在 son2 中的坐标
            point_source = PointStamped()
            point_source.header.frame_id = "son1"
            point_source.header.stamp = rospy.Time.now()
            point_source.point.x = 1
            point_source.point.y = 1
            point_source.point.z = 1

            point_target = buffer.transform(point_source,"son2",rospy.Duration(0.5))

            rospy.loginfo("point_target 所属的坐标系:%s",point_target.header.frame_id)
            rospy.loginfo("坐标点相对于 son2 的坐标:(%.2f,%.2f,%.2f)",
                        point_target.point.x,
                        point_target.point.y,
                        point_target.point.z
            )

        except Exception as e:
            rospy.logerr("错误提示:%s",e)


        rate.sleep()
    # 6.spin    
    # rospy.spin()
