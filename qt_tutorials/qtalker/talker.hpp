/**
 * @file /qtalker/talker.hpp
 *
 * @brief Ros communication central!
 *
 * @date February 2011
 **/
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef TALKER_NODE_HPP_
#define TALKER_NODE_HPP_

/*****************************************************************************
** Includes
*****************************************************************************/

#ifndef Q_MOC_RUN
#include <ros/ros.h>
#include "../common/qnode.hpp"
#endif

#include <string>

/*****************************************************************************
** Class
*****************************************************************************/

class Talker : public QNode {

public:
	Talker(int argc, char** argv);
	virtual ~Talker() {}
	void run();
	void ros_comms_init();
private:
	ros::Publisher chatter_publisher;
};

#endif /* TALKER_NODE_HPP_ */
