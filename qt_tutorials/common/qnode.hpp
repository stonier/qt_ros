/**
 * @file /eros_qtalker/include/eros_qtalker/qnode.hpp
 *
 * @brief Ros communication central!
 *
 * @date February 2011
 **/
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef NODE_HPP_
#define NODE_HPP_

/*****************************************************************************
** Includes
*****************************************************************************/

#ifndef Q_MOC_RUN
#include <ros/ros.h>
#endif

#include <string>
#include <QThread>
#include <QStringListModel>

/*****************************************************************************
** Class
*****************************************************************************/

class QNode : public QThread {
Q_OBJECT

public:
	QNode(int argc, char** argv, const std::string &name );
	virtual ~QNode();

	bool on_init();
	bool on_init(const std::string &master_url, const std::string &host_url);
	void shutdown();
	virtual void run() = 0;

	QStringListModel* loggingModel() { return &logging; }
	const std::string& nodeName() { return node_name; }

Q_SIGNALS:
	void loggingUpdated();
	void rosShutdown();

protected:
	virtual void ros_comms_init() = 0;
	int init_argc;
	char** init_argv;
    QStringListModel logging;
    const std::string node_name;
};

#endif /* NODE_HPP_ */
