#include "ros/ros.h"
#include "yh_topic_service/yh_topic_service_msg.h"
#include "yh_topic_service/yh_topic_service_srv.h"
#include <stdio.h>
// #include <vector>
// #include <cstdlib>

// using namespace std;
//단순 변수를 넣으면 어떻게 될까
//vector<int> v1;
//vector<int> v2;
// int a = 0;
// int b = 0;

ros::NodeHandle nh;
ros::ServiceClient client = nh.serviceClient<yh_topic_service::yh_topic_service_srv>("yh_topic_service_srv");

void msgCallback(const yh_topic_service::yh_topic_service_msg::ConstPtr&msg) //const: 상수
{
	int num1 = msg -> data1;
	int num2 = msg -> data2;
	if(num2 % 10 == 0)
	{
		yh_topic_service::yh_topic_service_srv srv;
		srv.request.data1 = num1;
 		srv.request.data2 = num2;
 		if (client.call(srv))
 		{
 			ROS_INFO("receive srv, srv.Response.result : %ld", (long int)srv.response.result);
 		}
		
	}
 	//ROS_INFO("receive a = %d", a);	
 	//v1.push_back(msg1);
 	//ROS_INFO("receive v1 = %d", v1[v1.size()-2]);
}

// void msgCallback2(const yh_topic_service::yh_topic_service_msg::ConstPtr&msg) //const: 상수
// {
// 	int msg2 = msg -> data;
// 	ROS_INFO("receive msg = %d", msg2);
// 	b = msg2;

// 	ros::NodeHandle nh;
// 	ros::ServiceClient client = nh.serviceClient<yh_topic_service::yh_topic_service_srv>("yh_topic_service_srv");
// 	yh_topic_service::yh_topic_service_srv srv;
// 	srv.request.b = b;

//	ROS_INFO("receive b = %d", srv.request.b);
	
// 	if(client.call(srv))
// 	{
// 		ROS_INFO("send srv, srv.Request.b : %ld", (long int)srv.request.b);
// 		ROS_INFO("receive b = %d", srv.request.b);
// 	}

// 	//ROS_INFO("receive b = %d", b);	
// 	//v2.push_back(msg2);
// 	//ROS_INFO("receive v2 = %d", v2[v2.size()-2]);
// }


int main(int argc, char **argv)
{
 	ros::init(argc, argv, "yh_sub_client");
 	ros::Subscriber sub = nh.subscribe("yh_topic_service_msg", 100, msgCallback);
 	// ros::Subscriber sub2 = nh.subscribe("yh_s_topic2", 100, msgCallback2);
 	//ros::Rate loop_rate(1);

 	//yh_topic_service::yh_topic_service_srv srv;
	
 	// srv.request.a = v1[v1.size()-2];
 	// srv.request.b = v2[v2.size()-2];
	
 	//srv.request.a = a;
 	//srv.request.b = b;

 	//ROS_INFO("receive a = %d", srv.request.a);	
 	//ROS_INFO("receive b = %d", srv.request.b);	

 	//int count = 1;
 	//if (count%10==0)
 	//{
 	//if(client.call(srv)) //서버로 요청을 보냈으면
 	//{
 	//	ROS_INFO("send srv, srv.Request.a and b : %ld, %ld", (long int)srv.request.a, (long int)srv.request.b);
 	//	ROS_INFO("receive srv, srv.Response.result : %ld", (long int)srv.response.result);
 	//}
 	//else //서버로 요청이 안 보내졌으면
 	//{
 	//	ROS_ERROR("Failed to call service");
 	//	return 1;
 	//}
	//}

 	//loop_rate.sleep();
 	//++count;
 	//ros::spinOnce();

 	//ROS_INFO("receive srv, srv.Response.result : %ld", (long int)srv.response.result);
 	ros::spin(); // 어떤 값이 들어오기 전까지 대기
 	return 0;
}
