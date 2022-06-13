#! /usr/bin/python
#coding=utf-8

import rospy
import rosbag
from std_msgs.msg import String
"""
需求：实现rosbag的写操作
1.  导入
2.  初始化
3.  创建rosbag对象并打开文件流
4.  写数据并关闭
"""


if __name__ == "__main__":
    # 2.  初始化
    rospy.init_node("write_bag_p")
    # 3.  创建rosbag对象并打开文件流
    bag = rosbag.Bag("/home/fuhua/desktop/hello_p.bag", mode='w')
    # 4.  写数据并关闭
    msg = String()
    msg.data = "bagbag"
    bag.write("/conver", msg)
    bag.close()

