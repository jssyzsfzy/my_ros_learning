#!/usr/bin/env python3

import rospy
from service_learning.srv import *
import time
import sys
"""
客户端操作，组织并提交请求，处理服务端响应：
1.导入包
2.初始化ros节点
3.创建客户端对象
4.组织请求数据，并发送请求
5.处理响应

优化：动态传参

再优化：随即启动顺序，先客户后服务端
实现：内置函数：
服务未启动，挂起
1.client.wait_for_service()
2.rospy.wait_for_service("addints")
"""

if __name__ == "__main__":
    rospy.loginfo("开始")
    # 判断参数长度
    if len(sys.argv) != 3:
        rospy.loginfo("参数错了……")
        sys.exit()
    # 2.初始化ros节点
    rospy.init_node("calls")
    # 3.创建客户端对象
    client = rospy.ServiceProxy("addints", addint)
    
    num1 = int(sys.argv[1])
    num2 = int(sys.argv[2])
    # 等待服务启动
    # 第一种
    # client.wait_for_service()
    # 第二种
    rospy.wait_for_service("addints")
    # 4.组织请求数据，并发送请求
    response = client.call(num1, num2)
    # 5.处理响应
    rospy.loginfo("相应的数据：%d", response.sum)
    # time.sleep(1)




