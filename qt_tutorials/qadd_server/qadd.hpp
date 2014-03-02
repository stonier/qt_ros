/**
 * @file /qadd_server/qadd.hpp
 *
 * @brief Ros communication central!
 *
 * @date February 2011
 **/
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef QADD_NODE_HPP_
#define QADD_NODE_HPP_

/*****************************************************************************
** Includes
*****************************************************************************/

#ifndef Q_MOC_RUN
#include <ros/ros.h>
#include "../common/qnode.hpp"
#include "qt_tutorials/TwoInts.h"
#endif

#include <string>
#include <std_msgs/String.h>

/*****************************************************************************
** Class
*****************************************************************************/

class QAdd : public QNode {

public:
	QAdd(int argc, char** argv);
	virtual ~QAdd() {}
	void run();
	void ros_comms_init();
private:
	bool add(qt_tutorials::TwoInts::Request  &req, qt_tutorials::TwoInts::Response &res);
	ros::ServiceServer add_server;
};

#endif /* QADD_NODE_HPP_ */
