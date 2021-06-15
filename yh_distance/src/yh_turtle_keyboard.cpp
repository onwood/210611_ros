#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

ros::Publisher pub;

void msgCallback(const geometry_msgs::Twist::ConstPtr&msg) //const: 상수
{
	pub.publish(*msg); //*이거는 위에서 &로 주소가ㅄ으로 받기 때문에 사용함, 주소가 오는거기 때문에 주소 안에 있는 가ㅄ을 가져온다고 생각
}


int main(int argc, char** argv)
{
    ros::init(argc, argv, "yh_turtle_keyboard");
    ros::NodeHandle nh;  

    ros::Subscriber sub = nh.subscribe("/cmd_vel", 10, msgCallback);
    pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);

    ros::spin();
   	return 0;

}