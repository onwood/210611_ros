#include "ros/ros.h"
#include "yh_double_check/yh_double_check_msg.h" 

int main(int argc, char **argv)
{
	ros::init(argc, argv, "yh_check_pub2"); 
	ros::NodeHandle nh; 

	ros::Publisher pub = nh.advertise<yh_double_check::yh_double_check_msg>("yh_double_check_msg", 100); 

	ros::Rate loop_rate(2.5);

	yh_double_check::yh_double_check_msg msg; 
	
	while(ros::ok()) 
	{
		int a = 0;
		//msg.stamp = ros::Time::now(); 
		msg.data2 = a; 

		//ROS_INFO("send msg = %d", msg.stamp.sec);
		//ROS_INFO("send msg = %d", msg.stamp.nsec);
		ROS_INFO("send msg = %d", msg.data2);
		
		pub.publish(msg); 
		loop_rate.sleep();
		
		a = 1;
		msg.data2 = a;
		ROS_INFO("send msg = %d", msg.data2);
		
		pub.publish(msg); 
		loop_rate.sleep();
	}
	return 0;
}
