#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <cstdlib>
#include <stdio.h>

//int distance

double old_vel == 0;
ros::Time start_time;

void msgCallback(const geometry_msgs::Twist::ConstPtr&msg) //const: 상수
{
	 
    // time이라는 변수에 현재 시간할당
    ROS_INFO("receive msg = %f", msg -> linear.x);
    if (msg -> linear.x > 0 && old_vel == 0)
    {   
        start_time = ros::Time::now();
        old_vel = msg -> linear.x;
    }
    if (msg -> linear.x == 0 && old_vel > 0)
    {
        ros::Time end_time = ros::Time::now();
        ros::Duration duration = end_time - start_time; // 이동한 시간

        double duration_sec duration.toSec();
        double distance = duration_sec * old_vel; // 거리 = 시간 * 속력

        ROS_INFO("distance: %lf", distance);
        old_vel = 0;
    }
	//ROS_INFO("receive msg = %d", msg -> stamp.nsec);
	//ROS_INFO("receive msg = %d", msg -> data);

    //ros::Time end_time = ros::Time::now(); // time이라는 변수에 현재 시간할당
    //ros::Duration duration = end_time - start_time;
    //ROS_INFO("receive duration = %f", duration);

    //ros::Time end_time = ros::Time::now();
    //실수를 시간형태로 바꿔주는 함수
    //duration.toSec();
    //ros::Duration duration = end_time - start_time;
    //ROS_INFO("receive duration = %f", duration);
}


int main(int argc, char** argv)
{
    ros::init(argc, argv, "yh_distance_x");
    ros::NodeHandle nh;

    //ros::Time start_time = ros::Time::now();
    ros::Subscriber sub = nh.subscribe<geometry_msgs::Twist>("/cmd_vel", 100, msgCallback);    
    //ros::Time end_time = ros::Time::now();
    //ros::Duration duration = end_time - start_time;
    //ROS_INFO("receive duration = %f", duration);
    ros::spin(); // 어떤 값이 들어오기 전까지 대기
	return 0;

}