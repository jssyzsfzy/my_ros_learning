#! /usr/bin/env python
#coding=utf-8
import rospy
from turtlesim.srv import *


if __name__ == "__main__":
    # 2.初始化ros节点
    rospy.init_node("add_turtle_p")
    # 3.创建服务端对象
    client = rospy.ServiceProxy("/spawn", Spawn)
    # 4.组织数据发送
    # 4.1组织数据
    spawn = SpawnRequest()
    spawn.x = 3
    spawn.y = 4
    spawn.theta = 1.57
    spawn.name = "turtle_new"
    # 4.2判断服务器状态
    client.wait_for_service()
    try:
        ans = client.call(spawn)
        # 5.处理响应
        rospy.loginfo("返回的是:%s",ans.name)
    except Exception as e:
        rospy.logerr("failed")


