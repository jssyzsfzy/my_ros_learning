#! /usr/bin/python
#coding=utf-8
import imp
import rospy
from geometry_msgs.msg import Twist

def process_data(data):
    print(data.linear.x, data.angular.z)


if __name__ == '__main__':
    rospy.init_node("node")
    sub = rospy.Subscriber("/cmd_vel", Twist, callback=process_data, queue_size=10)
    # data = LaserScan()
    
    rospy.spin()


















