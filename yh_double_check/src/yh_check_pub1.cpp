#include "ros/ros.h"
#include "yh_double_check/yh_double_check_msg.h" 
//#include <std_msgs/Int32.h>

int main(int argc, char **argv)
{
	ros::init(argc, argv, "yh_check_pub1"); 
	ros::NodeHandle nh; 

	ros::Publisher pub = nh.advertise<yh_double_check::yh_double_check_msg>("yh_double_check_msg", 100); 

	ros::Rate loop_rate(2);

	yh_double_check::yh_double_check_msg msg;
	//std_msgs::Int32 msg;
	
	while(ros::ok()) 
	{
		int a = 0;
		//msg.stamp = ros::Time::now(); 
		msg.data1 = a; 

		//ROS_INFO("send msg = %d", msg.stamp.sec);
		//ROS_INFO("send msg = %d", msg.stamp.nsec);
		ROS_INFO("send msg = %d", msg.data1);
		
		pub.publish(msg); 
		loop_rate.sleep();
		
		a = 1;
		msg.data1 = a;
		ROS_INFO("send msg = %d", msg.data1);
		
		pub.publish(msg); 
		loop_rate.sleep();


		// [선생님 풀이]
		// 선생님은 토픽을 2개로 분리해서 풀었음
		// if (msg.data == 0)
		// {
		// 	msg.data = 1;
		// }
		// else
		// {
		// 	msg.data = 0;
		// }
		// pub.publish(msg); 
		// loop_rate.sleep();

	}
	return 0;
}
