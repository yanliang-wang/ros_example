
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

    uint32_t thread_count;
    if (argc != 2)
    {
        thread_count = 2;
    }
    else
    {
        thread_count = uint32_t(atoi(argv[1]));
    }
    ros::MultiThreadedSpinner spinner(thread_count);
    spinner.spin();
    return 0;
}

/// when thread_count >= 2 or thread_count == 0 (0 means automatically use however many hardware threads exist on your system)
// [ WARN] [1640006044.561310016]: Sub1: Get one msg at 2.4503e-05
// [ INFO] [1640006046.562845736]: Sub2: Get one msg at 2.8214e-05
// [ WARN] [1640006047.563128301]: Sub1: Get one msg at 3.00046
// [ INFO] [1640006049.563367854]: Sub2: Get one msg at 3.0004
// [ WARN] [1640006050.563662427]: Sub1: Get one msg at 3.0004
// [ INFO] [1640006052.563938492]: Sub2: Get one msg at 3.00045
// [ WARN] [1640006053.564242597]: Sub1: Get one msg at 3.00047

/// when thread_count >= 2 or thread_count == 0 (means automatically use however many hardware threads exist on your system)
// [ WARN] [1640005702.794667163]: Sub1: Get one msg at 4.8028e-05
// [ INFO] [1640005702.797655567]: Sub2: Get one msg at 7.8154e-05
// [ INFO] [1640005703.797898118]: Sub2: Get one msg at 1.00012
// [ WARN] [1640005704.797750062]: Sub1: Get one msg at 2.00012
// [ INFO] [1640005704.798159452]: Sub2: Get one msg at 1.00016
// [ INFO] [1640005705.798392452]: Sub2: Get one msg at 1.00012
// [ WARN] [1640005706.798029385]: Sub1: Get one msg at 2.00017
// [ INFO] [1640005706.798619269]: Sub2: Get one msg at 1.00011


