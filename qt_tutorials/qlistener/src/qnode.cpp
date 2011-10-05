/**
 * @file /eros_qtalker/src/qnode.cpp
 *
 * @brief File comment
 *
 * File comment
 *
 * @date 25/02/2011
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
	ros::init(init_argc,init_argv,"qlistener");
	ros::start(); // our node handles go out of scope, so we want to control shutdown explicitly.
    ros::NodeHandle n;
	chatter_subscriber = n.subscribe(topic_name, 1000, &QNode::chatterCallback, this);
	start();
}

void QNode::init(const std::string &master_url, const std::string &host_url, const std::string &topic_name) {
	std::map<std::string,std::string> remappings;
	remappings["__master"] = master_url;
	remappings["__hostname"] = host_url;
	ros::init(remappings,"qlistener");
	ros::start(); // our node handles go out of scope, so we want to control shutdown explicitly.
    ros::NodeHandle n;
	chatter_subscriber = n.subscribe(topic_name, 1000, &QNode::chatterCallback, this);
	start();
}

void QNode::run() {
	ros::spin();
}

void QNode::chatterCallback(const std_msgs::String::ConstPtr &msg) {
	ROS_INFO("I heard: [%s]", msg->data.c_str());
	logging.insertRows(0,1);
	std::stringstream logging_msg;
	logging_msg << "[ INFO] [" << ros::Time::now() << "]: I heard: " << msg->data;
	QVariant new_row(QString(logging_msg.str().c_str()));
	logging.setData(logging.index(0),new_row);
}
