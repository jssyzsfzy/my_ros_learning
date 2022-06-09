#! /usr/bin/env python3
import rospy


if __name__ == "__main__":
    rospy.init_node("hello")
    """
    设置不同类型参数：
    1.  全局
    2.  相对
    3.  私有

    rosrun exp4_rename_param param_rename_p.py __ns:=xxx
    rosparam list 
        /radius
        /xxx/hello/radiu
        /xxx/radius
    """
    # 1.  全局
    rospy.set_param("/radius", 0.1)
    # 2.  相对
    rospy.set_param("radius", 0.2)
    # 3.  私有
    rospy.set_param("~radiu", 0.3)

    while not rospy.is_shutdown():
        pass


