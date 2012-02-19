/**
 * @file /qtalker/talker.cpp
 *
 * @brief Ros communication central!
 *
 * @date February 2011
 **/

/*****************************************************************************
** Includes
*****************************************************************************/

#include <ros/ros.h>
#include <string>
#include "talker.hpp"
#include <std_msgs/String.h>
#include <sstream>

/*****************************************************************************
** Implementation
*****************************************************************************/

Talker::Talker(int argc, char** argv ) :
	QNode(argc,argv,"qtalker")
	{}

void Talker::ros_comms_init() {
    ros::NodeHandle n;
    chatter_publisher = n.advertise<std_msgs::String>("chatter", 1000);
}

void Talker::run() {
	ros::Rate loop_rate(1);
	int count = 0;
	while ( ros::ok() ) {
	    std_msgs::String msg;
	    std::stringstream ss;
		ss << "hello world " << count;
		msg.data = ss.str();
		ROS_INFO("%s", msg.data.c_str());

		this->logging.insertRows(0,1);
		std::stringstream logging_msg;
		logging_msg << "[ INFO] [" << ros::Time::now() << "]: " << msg.data;
		QVariant new_row(QString(logging_msg.str().c_str()));
		logging.setData(logging.index(0),new_row);

		chatter_publisher.publish(msg);
		ros::spinOnce();
		loop_rate.sleep();
		++count;
	}
    std::cout << "Ros shutdown, proceeding to close the gui." << std::endl;
    Q_EMIT rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
}
