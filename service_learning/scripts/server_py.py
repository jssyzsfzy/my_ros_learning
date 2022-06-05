#!/usr/bin/env python3

import rospy
from service_learning.srv import *

"""
服务端操作，解析请求，产生响应：
1.导入包
2.初始化ros节点
3.创建服务端对象
4.处理逻辑 回调函数
5.spin
"""
# 参数是封装的请求数据
# 返回值是响应数据
def deal_data(request):
    # 解析整数
    num1 = request.num1
    num2 = request.num2
    # 结果封装响应
    response = addintResponse()
    response.sum = num1 + num2
    rospy.loginfo("输入的数据num1:%d , num2:%d, 返回的数据是:%d", num1 , num2, response.sum)
    return response

if __name__ == "__main__":
    # 2.初始化ros节点
    rospy.init_node("jia")
    # 3.创建服务端对象
    server = rospy.Service("addints", addint,deal_data)
    rospy.loginfo("节点启动")
    # 4.处理逻辑 回调函数
    # 5.spin
    rospy.spin()









