#include "ros/ros.h" //ROS 기본 헤더파일 
#include "yh_topic_service/yh_topic_service_msg.h" //메시지 파일 헤더(빌드하면 자동으로 생성)
#include "yh_topic_service/yh_topic_service_srv.h"


bool calculation(yh_topic_service::yh_topic_service_srv::Request &req, yh_topic_service::yh_topic_service_srv::Response &res)
{
 	res.result = req.data1 + req.data2;
 	ROS_INFO("request : x = %ld, y = %ld", (long int)req.data1, (long int)req.data2);
 	ROS_INFO("sending back response : %ld", (long int)res.result);

 	return true;
}

// void timerCallback1(const ros::TimerEvent& event)
// {
// 	ros::NodeHandle nh;
// 	ros::Publisher pub1 = nh.advertise<yh_topic_service::yh_topic_service_msg>("yh_s_topic1", 100);
// 	yh_topic_service::yh_topic_service_msg msg1;
// 	msg1.data = count1;
// 	ROS_INFO("send msg_1 = %d", msg1.data);
// 	pub1.publish(msg1);
// 	++count1;	
	
// }

// void timerCallback2(const ros::TimerEvent& event)
// {
// 	ros::NodeHandle nh;
// 	ros::Publisher pub2 = nh.advertise<yh_topic_service::yh_topic_service_msg>("yh_s_topic2", 100);
// 	yh_topic_service::yh_topic_service_msg msg2;
// 	msg2.data = count2;
// 	ROS_INFO("send msg_2 = %d", msg2.data);
// 	pub2.publish(msg2);
// 	++count2;	
	
// }

int main(int argc, char **argv) //ros::은 ros/ros.h를 불러왔기 때문에 사용 가능 - 그 뒤에 나오는 것은 ros에 종속된 함수
{
	ros::init(argc, argv, "yh_pub_server"); //노드 이름 초기화
	ros::NodeHandle nh; //ROS 시스템과 통신을 위한 노드 핸들 선언, NodeHandle을 nh로 명명
	
	//퍼블리셔 선언, 패키지 (  )의 메시지 파일(  )을 이용해서
	//퍼블리셔 (  )을 작성한다.
	//토픽명은 (  )이며, 퍼블리셔 사이즈를 (  )개로 설정한다.
	//publisher 선언, pub으로 명명, publisher라서 advertise기능 사용, 토픽 이름 정하고 메모리를 사용할 공간 확보(큐라고 함)
	ros::Publisher pub = nh.advertise<yh_topic_service::yh_topic_service_msg>("yh_topic_service_msg", 100);
	//ros::Publisher pub2 = nh.advertise<yh_topic_service::yh_topic_service_msg>("yh_s_topic2", 100);
	ros::ServiceServer server = nh.advertiseService("yh_topic_service_srv", calculation); //("서비스명", 함수)
	ROS_INFO("ready srv server!!");

	ros::Rate loop_rate(10); //루프 주기를 10Hz로 설정 - 1초 당 10씩, loop_rate라는 이름은 개인이 만든 것
	//ros::Rate loop_rate2(7);
	
	yh_topic_service::yh_topic_service_msg msg; //개인이 만든 메시지 파일 형식으로 (  )라는 메시지를 선언
	//yh_topic_service::yh_topic_service_msg msg2;
	//ros::Timer timer1 = nh.createTimer(ros::Duration(3), timerCallback1);
	//ros::Timer timer2 = nh.createTimer(ros::Duration(0.1), timerCallback2);
	//ros::spin();
	
	int count1 = 0;
	int count2 = 0;
	

	while(ros::ok()) //ros가 실행되면 실행된다고 확인되는 함수
	{
		//msg.stamp = ros::Time::now(); //현재 시간을 msg 하위 stamp 메시지에 담는다.
		msg.data1 = count1; //count 변수 값을 msg 하위 data 메시지에 담는다.
		msg.data2 = count2;

		//ROS_INFO("send msg = %d", msg.stamp.sec);
		//ROS_INFO("send msg = %d", msg.stamp.nsec);
		ROS_INFO("send msg = %d, %d", msg.data1, msg.data2);
		//ROS_INFO("send msg_2 = %d", msg2.data);

		++count1;
		if(count1 % 10 == 0)
		{
			count2 = count2 + 3;
		}
		pub.publish(msg); //실제로 메시지가 발행되는 부분
		loop_rate.sleep();
		ros::spinOnce();
	}
	return 0;
}
