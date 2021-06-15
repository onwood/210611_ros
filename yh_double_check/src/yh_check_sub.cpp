#include "ros/ros.h"
#include "yh_double_check/yh_double_check_msg.h" 
//#include <std_msgs/Int32.h>


// 선생님은 토픽을 2개로 분리해서 풀었음


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

// 선생님 방식
// void msgCallback2(const std_msgs::yh_double_check_msg::ConstPtr&msg) 
// {
// 	data2 = msg -> data;
// 	if (data1 == 1 && data2 == 1)
// 	{
// 		ROS_INFO("avoidance");
// 	}
// }


int main(int argc, char **argv)
{
	ros::init(argc, argv, "yh_check_sub");
	ros::NodeHandle nh;

	ros::Subscriber sub = nh.subscribe("yh_double_check_msg", 100, msgCallback);
	//// 선생님 방식
	//ros::Subscriber sub2 = nh.subscribe("yh_double_check_msg2", 100, msgCallback2);
	////
	ros::spin(); 
	return 0;
}
