#! /usr/bin/env python3

import rospy
from std_msgs.msg import String

if __name__ == "__main__":
    rospy.init_node("hello")
    """
    需求：实现不同类型的话题设置
    操作：
        1.全局
            rosrun exp4_rename_topic topic_name_p.py __ns:=xxx
            rosnode list 
                /rosout
                /xxx/hello
            rostopic list 
                /chat
                /rosout
                /rosout_agg

        2.相对
            rosnode list 
                /rosout
                /xxx/hello
            rostopic list 
                /rosout
                /rosout_agg
                /xxx/chat1   *****

        3.私有
            rosnode list 
                /rosout
                /xxx/hello
            rostopic list 
                /rosout
                /rosout_agg
                /xxx/hello/chat2

    """
    # pub = rospy.Publisher("/chat", String, queue_size=10)
    # pub1 = rospy.Publisher("chat1", String, queue_size=10)
    pub2 = rospy.Publisher("~chat2", String, queue_size=10)
    while not rospy.is_shutdown():
        pass








