#include "ros/ros.h"
#include "yh_210611/yh_210611_msg.h"

void msgCallback1(const yh_210611::yh_210611_msg::ConstPtr&msg) //const: 상수
{
	ROS_INFO("receive msg_1 = %d", msg -> data);
}

void msgCallback2(const yh_210611::yh_210611_msg::ConstPtr&msg) //const: 상수
{
	ROS_INFO("receive msg_2 = %d", msg -> data);
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "yh_sub2_210611");
	ros::NodeHandle nh;

	ros::Subscriber sub1 = nh.subscribe("yh_210611_topic1", 100, msgCallback1);
	ros::Subscriber sub2 = nh.subscribe("yh_210611_topic2", 100, msgCallback2);
	ros::spin(); // 어떤 값이 들어오기 전까지 대기
	return 0;
}
