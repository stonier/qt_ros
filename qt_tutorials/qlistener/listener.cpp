/**
 * @file /qlistener/listener.cpp
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
#include <sstream>
#include "listener.hpp"
#include <std_msgs/String.h>

/*****************************************************************************
** Implementation
*****************************************************************************/

Listener::Listener(int argc, char** argv ) :
	QNode(argc,argv,"qlistener")
	{}

void Listener::ros_comms_init() {
	ros::NodeHandle n;
	chatter_subscriber = n.subscribe("chatter", 1000, &Listener::chatterCallback, this);
}

void Listener::chatterCallback(const std_msgs::String::ConstPtr &msg) {
	ROS_INFO("I heard: [%s]", msg->data.c_str());
	logging.insertRows(0,1);
	std::stringstream logging_msg;
	logging_msg << "[ INFO] [" << ros::Time::now() << "]: I heard: " << msg->data;
	QVariant new_row(QString(logging_msg.str().c_str()));
	logging.setData(logging.index(0),new_row);
}

void Listener::run() {
	ros::spin();
    std::cout << "Ros shutdown, proceeding to close the gui." << std::endl;
    Q_EMIT rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
}
