#include "ros/ros.h"
#include "yh_double_check/yh_double_check_msg.h" 

void msgCallback(const yh_double_check::yh_double_check_msg::ConstPtr&msg) 
{
	// ROS_INFO("receive msg = %d", msg -> stamp.sec);
	// ROS_INFO("receive msg = %d", msg -> stamp.nsec);
	//ROS_INFO("receive msg_1 = %d", msg -> data1);
	//ROS_INFO("receive msg_2 = %d", msg -> data2);
	if (msg -> data1 == msg -> data2 == 1)
	{
		ROS_INFO("avoidance");
	}
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "yh_check_sub");
	ros::NodeHandle nh;

	ros::Subscriber sub = nh.subscribe("yh_double_check_msg", 100, msgCallback);
	ros::spin(); 
	return 0;
}
