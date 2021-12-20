
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sstream>

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "concurrency_pub");
    ros::NodeHandle nh;
    ros::Publisher pub1 = nh.advertise<std_msgs::String>("chatter1", 1);
    ros::Publisher pub2 = nh.advertise<std_msgs::String>("chatter2", 1);
    ros::Publisher pub3 = nh.advertise<std_msgs::String>("chatter3", 1);
    ros::Rate rate(10);
    int count = 0;
    while (ros::ok())
    {
        std_msgs::String msg;
        std::stringstream ss;
        ss << "Hello world" << count;
        msg.data = ss.str();
        pub1.publish(msg);
        pub2.publish(msg);
        pub3.publish(msg);
        ros::spinOnce();
        rate.sleep();
        ++count;
    }
    return 0;
}
