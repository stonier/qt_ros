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

	void chatterCallback(const std_msgs::String::ConstPtr &msg);

	QStringListModel* loggingModel() { return &logging; }

private:
	int init_argc;
	char** init_argv;
	ros::Subscriber chatter_subscriber;
    QStringListModel logging;
};

#endif /* NODE_HPP_ */
