#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <Navigation/Joystick.h>
#include <iostream>
#include <string>

int main(int argc, char **argv) {
	ros::init(argc, argv, "user_input_node");
	ros::NodeHandle n;
	ros::Publisher publisher = n.advertise<Navigation::Joystick>("user_input", 1);
	Navigation::Joystick user_input;
	
	int input;
	user_input.joystick_horizontal = 0;
	user_input.joystick_vertical = 0;

	ros::Rate naptime(1.0);

	while(ros::ok())
	{
		std::cout << "Enter any integer between 0 and 95 for the horizontal joystick reading: ";
		
		std::cin >> input;
		if(input > 95 || input < 0 )
			std::cout << "Invalid input";
		else 
			user_input.joystick_horizontal = input;
		
		std::cout << "Enter any integer between -95 and 95 for the horizontal joystick reading: ";
		std::cin >> input;
		if(input < -95 || input >95)
			std::cout << "Invalid input";
		else 
			user_input.joystick_vertical = input;
		
		publisher.publish(user_input);

		naptime.sleep();
	}
}
