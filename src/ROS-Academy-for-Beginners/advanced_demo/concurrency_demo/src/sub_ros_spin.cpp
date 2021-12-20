
#include <ros/ros.h>
#include <std_msgs/String.h>

void subCallback1(const std_msgs::String::ConstPtr &msg)
{
    static ros::Time last_time = ros::Time::now();
    ROS_WARN_STREAM("Sub1: Get one msg at " << (ros::Time::now() - last_time).toSec() );
    last_time = ros::Time::now();
    ros::Duration(2).sleep();
}

void subCallback2(const std_msgs::String::ConstPtr &msg)
{
    static ros::Time last_time = ros::Time::now();
    ROS_INFO_STREAM("Sub2: Get one msg at " << (ros::Time::now() - last_time).toSec() );
    last_time = ros::Time::now();
    ros::Duration(1).sleep();
}

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "concurrency_sub");
    ros::NodeHandle nh;
    ros::Subscriber sub1 = nh.subscribe("chatter1", 1, subCallback1);
    ros::Subscriber sub2 = nh.subscribe("chatter2", 1, subCallback2);

    ros::spin();

    return 0;
}

// [ WARN] [1640006114.342912287]: Sub1: Get one msg at 4.57e-05
// [ INFO] [1640006116.345894673]: Sub2: Get one msg at 2.8984e-05
// [ WARN] [1640006117.346107764]: Sub1: Get one msg at 3.00041
// [ INFO] [1640006119.346345215]: Sub2: Get one msg at 3.00033
// [ WARN] [1640006120.346639659]: Sub1: Get one msg at 3.00046
// [ INFO] [1640006122.346801099]: Sub2: Get one msg at 3.00035