#include "ros/ros.h"

/*
实现参数的查询
需求：查询机器人共享参数例如类型，半径(0.15)

实现：
    ros::NodeHandle --------------------------------------------------------------
        Param(键,默认值)
            存在返回结果，否则返回默认值
        
        getParam(键,存储结果的变量2)
            存在，返回True,且赋值给参数2
            不存在，返回false并且不赋值
        
        getParamCached(键,存储结果的变量2)
            存在，返回true, 赋值给参数2
            否则 返回false并且不赋值
        
        getParamNames( std::vector<std::string>)
            获取所有键 并存储在vector中
        
        hasParam(键)
            是否包含某个键
        
        searchParam(参数1,参数2)
            搜索键，参数1是被搜索的键，参数2存储搜索结果的变量

    ros::param             -------------------------------------------------------------
        同上面的
*/

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc, argv,"get_param_c");
    ros::NodeHandle nh;
    // ros::NodeHandle -------------------------------------------------------------------
    // 1.Param(键,默认值)
    //        存在返回结果，否则返回默认值
    float radius = nh.param("radius", 1.0);
    ROS_INFO("nh.param得到的结果：%.2f", radius);

    // 2.getParam(键,存储结果的变量2)
    //         存在，返回True,且赋值给参数2
    //         不存在，返回false并且不赋值
    float radius_getParam;
    bool result = nh.getParam("radius", radius_getParam);
    if(result){
        ROS_INFO("nh.getParam得到的结果：%.2f", radius_getParam);
    }
    else{
        ROS_INFO("没有参数");
    }
    
    // 3.getParamCached(键,存储结果的变量2)  # 从缓存拿数据
    //         存在，返回true, 赋值给参数2
    //         否则 返回false并且不赋值
    float radius_getParamCached;
    result = nh.getParamCached("radius", radius_getParamCached);
    if(result){
        ROS_INFO("nh.getParamCached得到的结果：%.2f", radius_getParamCached);
    }
    else{
        ROS_INFO("没有参数");
    }

    // 4.getParamNames( std::vector<std::string>)
    //         获取所有键 并存储在vector中
    std::vector<std::string> names;
    nh.getParamNames(names);
    for(auto &&name : names)
    {
        ROS_INFO("nh.getParamNames的元素%s", name.c_str());
    }

    // 5.hasParam(键)
    //         是否包含某个键
    bool result1 = nh.hasParam("radius");
    result = nh.hasParam("key");
    ROS_INFO("nh.hasParam 存在radius与否%d", result1);
    ROS_INFO("nh.hasParam 存在key与否%d", result);

    // 6.searchParam(参数1,参数2)
    //         搜索键，参数1是被搜索的键，参数2存储搜索结果的变量
    std::string key;
    nh.searchParam("radius", key);
    ROS_INFO("nh.searchParam搜索结果%s", key.c_str());

    ROS_INFO("——————————————————");
    // 与上面一一对应
    // 例如
    float param_radius = ros::param::param("radius", 2.0);
    ROS_INFO("ros::param::param得到的结果：%.2f", param_radius);
    
    std::vector<std::string> names_param;
    ros::param::getParamNames(names_param);
    for(auto &&name : names_param)
    {
        ROS_INFO("ros::param::getParamNames的元素%s", name.c_str());
    }

    return 0;
}