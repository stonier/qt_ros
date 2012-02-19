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
	QNode(argc,argv,"qadd_client")
	{}

void QAdd::ros_comms_init() {
    ros::NodeHandle n;
    add_client = n.serviceClient<qt_tutorials::TwoInts>("add_two_ints");
}

void QAdd::run() {
	ros::Rate loop_rate(1);
	int last_sum = 0;
	int count = 1;
	while( ros::ok() ) {
		qt_tutorials::TwoInts srv;
		srv.request.a = count;
		srv.request.b = last_sum;
		std::stringstream logging_msg;
		if ( add_client.call(srv) ) {
			ROS_INFO_STREAM("Sum: " << srv.response.sum);
			last_sum = srv.response.sum;
			logging_msg << "[ INFO] [" << ros::Time::now() << "]: " << srv.request.a << " + " << srv.request.b << " = " << srv.response.sum;
			++count;
		} else {
			ROS_INFO_STREAM("failed to contact the server");
			logging_msg << "[ INFO] [" << ros::Time::now() << "]: failed to contact the server";
		}
		logging.insertRows(0,1);
		QVariant new_row(QString(logging_msg.str().c_str()));
		logging.setData(logging.index(0),new_row);
		ros::spinOnce();
		loop_rate.sleep();
	}
	std::cout << "Ros shutdown, proceeding to close the gui." << std::endl;
	Q_EMIT rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
}
