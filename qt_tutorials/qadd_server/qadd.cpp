/**
 * @file /qadd_server/qadd.cpp
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
#include "qadd.hpp"
#include <std_msgs/String.h>

/*****************************************************************************
** Implementation
*****************************************************************************/

QAdd::QAdd(int argc, char** argv ) :
	QNode(argc,argv,"qadd_server")
	{}

void QAdd::ros_comms_init() {
    ros::NodeHandle n;
    add_server = n.advertiseService("add_two_ints", &QAdd::add, this);
}

bool QAdd::add(qt_tutorials::TwoInts::Request  &req, qt_tutorials::TwoInts::Response &res) {
	res.sum = req.a + req.b;
	ROS_INFO_STREAM(req.a << " + " << req.b << " = " << res.sum);

	logging.insertRows(0,1);
	std::stringstream logging_msg;
	logging_msg << "[ INFO] [" << ros::Time::now() << "]: " << req.a << " + " << req.b << " = " << res.sum;
	QVariant new_row(QString(logging_msg.str().c_str()));
	logging.setData(logging.index(0),new_row);

	return true;
}

void QAdd::run() {
	ros::spin();
    std::cout << "Ros shutdown, proceeding to close the gui." << std::endl;
    Q_EMIT rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
}
