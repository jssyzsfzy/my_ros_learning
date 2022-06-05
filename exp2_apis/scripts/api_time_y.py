#! /usr/bin/env python3

import rospy

"""
1.演示时间有关的操作(获取+设置)

2.程序停顿5s

3.获取开始执行的时刻并计算运行时间

4.创建定时器，类似于ros::rate的功能

"""


def do_timer(event):
    rospy.loginfo("————————————")
    rospy.logdebug("调试")
    rospy.logwarn("警告")
    rospy.loginfo("当前时刻%.4f", event.current_real.to_sec())
    rospy.logerr("错误")
    rospy.logfatal("致命")

if __name__ == "__main__":
    rospy.init_node("time_node_p")
    # 1.演示时间有关的操作(获取+设置)
    # 获取时刻
    right_t = rospy.Time.now()
    rospy.loginfo("目前的时间是：%.2f", right_t.to_sec())
    # 设置时间
    t1 = rospy.Time(1000.3175)
    rospy.loginfo("目前的时间是：%.2f", t1.to_sec())
    # 从某个时间值获取时间对象
    timg1 = rospy.Time.from_sec(210.25)
    rospy.loginfo("目前的时间是：%.2f", timg1.to_sec())
    rospy.loginfo("-------------")
    # 2.程序停顿5s
    rospy.loginfo("开始停顿")
    start = rospy.Time.now()
    # 先封装一个时间对象
    du = rospy.Duration(1.5)
    # 再将持续时间休眠
    rospy.sleep(du)
    end = rospy.Time.now()
    rospy.loginfo("停止停顿")
    rospy.loginfo("停顿时间：%.4f", end.to_sec() - start.to_sec())
    rospy.loginfo("-------------")
    # 3.获取开始执行的时刻并计算运行时间
        # 1.获取一个时刻 t1
    t1 = rospy.Time.now()
        # 2.设置持续时间 du2
    du2 = rospy.Duration(1.5)
        # 3.结束时间 t2 = t1 + du2
    t2 = t1 + du2
    rospy.loginfo("开始时刻：%.4f", t1.to_sec())
    rospy.loginfo("结束时刻：%.4f", t2.to_sec())
    # 4.创建定时器，类似于ros::rate的功能

    """    
    def __init__(self, period, callback, oneshot=False, reset=False):
        Constructor.
        @param period: 回调函数的时间间隔
        @type  period: rospy.Duration
        @param callback: 回调函数
        @type  callback: function taking rospy.TimerEvent
        @param oneshot: 设置为True，就只执行一次，否则循环执行
        @type  oneshot: bool
        @param reset: if True, timer is reset when rostime moved backward. [default: False]
        @type  reset: bool
    """

    tomer1 = rospy.Timer(rospy.Duration(1), do_timer)  # 创建定时器对象

    rospy.spin()

