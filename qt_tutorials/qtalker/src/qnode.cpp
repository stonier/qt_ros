/**
 * @file /eros_qtalker/src/qnode.cpp
 *
 * @brief Ros communication central!
 *
 * @date February 2011
 **/

/*****************************************************************************
** Includes
*****************************************************************************/

#include <ros/ros.h>
#include <ros/network.h>
#include <string>
#include "../include/qnode.hpp"
#include <std_msgs/String.h>
#include <sstream>

/*****************************************************************************
** Implementation
*****************************************************************************/

QNode::QNode(int argc, char** argv ) :
	init_argc(argc),
	init_argv(argv)
	{}

QNode::~QNode() {
	ros::shutdown(); // calling explicitly because we called ros::start()
	std::cout << "Waiting for ros thread to finish." << std::endl;
	wait();
}

void QNode::init(const std::string &topic_name) {
	ros::init(init_argc,init_argv,"qtalker");
	ros::start(); // our node handles go out of scope, so we want to control shutdown explicitly.
    ros::NodeHandle n;
    chatter_publisher = n.advertise<std_msgs::String>(topic_name, 1000);
	start();
}

void QNode::init(const std::string &master_url, const std::string &host_url, const std::string &topic_name) {
	std::map<std::string,std::string> remappings;
	remappings["__master"] = master_url;
	remappings["__hostname"] = host_url;
	ros::init(remappings,"qtalker");
	ros::start(); // our node handles go out of scope, so we want to control shutdown explicitly.
    ros::NodeHandle n;
    chatter_publisher = n.advertise<std_msgs::String>(topic_name, 1000);
	start();
}

void QNode::run() {
	ros::Rate loop_rate(1);
	int count = 0;
	while ( ros::ok() ) {

	    std_msgs::String msg;
	    std::stringstream ss;
		ss << "hello world " << count;
		msg.data = ss.str();
		ROS_INFO("%s", msg.data.c_str());

		logging.insertRows(0,1);
		std::stringstream logging_msg;
		logging_msg << "[ INFO] [" << ros::Time::now() << "]: " << msg.data;
		QVariant new_row(QString(logging_msg.str().c_str()));
		logging.setData(logging.index(0),new_row);

		chatter_publisher.publish(msg);
		ros::spinOnce();
		loop_rate.sleep();
		++count;
	}
}
