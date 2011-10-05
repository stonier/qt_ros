/**
 * @file /eros_qtalker/include/eros_qtalker/qnode.hpp
 *
 * @brief File comment
 *
 * File comment
 *
 * @date 25/02/2011
 **/
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef NODE_HPP_
#define NODE_HPP_

/*****************************************************************************
** Includes
*****************************************************************************/

#include <ros/ros.h>
#include <string>
#include <QThread>
#include <QStringListModel>
#include <std_msgs/String.h>
#include "eros_qt_tutorials/TwoInts.h"

/*****************************************************************************
** Class
*****************************************************************************/

class QNode : public QThread {
public:
	QNode(int argc, char** argv );
	~QNode();
	void init(const std::string &topic_name);
	void init(const std::string &master_url, const std::string &host_url, const std::string &topic_name);
	void run();

	bool add(eros_qt_tutorials::TwoInts::Request  &req, eros_qt_tutorials::TwoInts::Response &res);

	QStringListModel* loggingModel() { return &logging; }

private:
	int init_argc;
	char** init_argv;
	ros::ServiceServer add_server;
    QStringListModel logging;
};

#endif /* NODE_HPP_ */
