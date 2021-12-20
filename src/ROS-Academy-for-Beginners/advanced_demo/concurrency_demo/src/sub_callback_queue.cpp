
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <ros/callback_queue.h>

void subCallback1(const std_msgs::String::ConstPtr &msg)
{
    static ros::Time last_time = ros::Time::now();
    ROS_WARN_STREAM("Sub1: Get one msg at " << (ros::Time::now() - last_time).toSec());
    last_time = ros::Time::now();
    ros::Duration(2).sleep();
}

void subCallback2(const std_msgs::String::ConstPtr &msg)
{
    static ros::Time last_time = ros::Time::now();
    ROS_INFO_STREAM("Sub2: Get one msg at " << (ros::Time::now() - last_time).toSec());
    last_time = ros::Time::now();
    ros::Duration(1).sleep();
}

void subCallback3(const std_msgs::String::ConstPtr &msg)
{
    static ros::Time last_time = ros::Time::now();
    ROS_ERROR_STREAM("Sub3: Get one msg at " << (ros::Time::now() - last_time).toSec());
    last_time = ros::Time::now();
    ros::Duration(0.5).sleep();
}

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "concurrency_sub");
    ros::NodeHandle nh;
    ros::CallbackQueue queue_1;
    ros::CallbackQueue queue_2;
    nh.setCallbackQueue(&queue_1);
    ros::Subscriber sub1 = nh.subscribe("chatter1", 1, subCallback1);

    nh.setCallbackQueue(&queue_2);
    ros::Subscriber sub2 = nh.subscribe("chatter2", 1, subCallback2);
    ros::Subscriber sub3 = nh.subscribe("chatter3", 1, subCallback3);

    ros::AsyncSpinner spinner1(1, &queue_1);
    spinner1.start();

    ros::AsyncSpinner spinner2(1, &queue_2);
    spinner2.start();

    ros::waitForShutdown();

    return 0;
}

// [ WARN] [1640007982.804819528]: Sub1: Get one msg at 5.8279e-05
// [ INFO] [1640007982.807514880]: Sub2: Get one msg at 9.7773e-05
// [ERROR] [1640007983.807682174]: Sub3: Get one msg at 1.0522e-05
// [ INFO] [1640007984.307830560]: Sub2: Get one msg at 1.50022
// [ WARN] [1640007984.807643289]: Sub1: Get one msg at 2.00016
// [ERROR] [1640007985.308066099]: Sub3: Get one msg at 1.50031
// [ INFO] [1640007985.808352703]: Sub2: Get one msg at 1.50045
// [ WARN] [1640007986.807884555]: Sub1: Get one msg at 2.00012
// [ERROR] [1640007986.808567920]: Sub3: Get one msg at 1.5004