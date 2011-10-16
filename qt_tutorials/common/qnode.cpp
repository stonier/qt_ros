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
#include "qnode.hpp"
#include <std_msgs/String.h>
#include <sstream>

/*****************************************************************************
** Implementation
*****************************************************************************/

QNode::QNode(int argc, char** argv, const std::string &name ) :
	init_argc(argc),
	init_argv(argv),
	node_name(name)
	{}

QNode::~QNode() {
	shutdown();
}
/**
 * This is called by the qt application to stop the ros node before the
 * qt app closes.
 */
void QNode::shutdown() {
    if(ros::isStarted()) {
      ros::shutdown(); // explicitly needed since we use ros::start();
      ros::waitForShutdown();
    }
	wait();
}

bool QNode::on_init() {
	ros::init(init_argc,init_argv,node_name);
	if ( ! ros::master::check() ) {
		return false;
	}
	ros::start(); // our node handles go out of scope, so we want to control shutdown explicitly.
	ros_comms_init();
	start();
	return true;
}

bool QNode::on_init(const std::string &master_url, const std::string &host_url) {
	std::map<std::string,std::string> remappings;
	remappings["__master"] = master_url;
	remappings["__hostname"] = host_url;
	ros::init(remappings,node_name);
	if ( ! ros::master::check() ) {
		return false;
	}
	ros::start(); // our node handles go out of scope, so we want to control shutdown explicitly.
	ros_comms_init();
	start();
	return true;
}

