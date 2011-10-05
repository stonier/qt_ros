/**
 * @file /include/%(package)s/main_window.hpp
 *
 * @brief Qt based gui for %(package)s.
 *
 * @date November 2010
 **/
#ifndef %(package)s_MAIN_WINDOW_H
#define %(package)s_MAIN_WINDOW_H

/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui/QMainWindow>
#include "ui_main_window.h"

/*****************************************************************************
** Namespace
*****************************************************************************/

namespace %(package)s {

/*****************************************************************************
** Interface [MainWindow]
*****************************************************************************/
/**
 * @brief Qt central, all operations relating to the view part here.
 */
class MainWindow : public QMainWindow {
Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();

	void ReadSettings(); // Load up qt program settings at startup
	void WriteSettings(); // Save qt program settings when closing

	void closeEvent(QCloseEvent *event); // Overloaded function

public slots:
	// Put automatically triggered slots here (because of connectSlotsByName())
	// void on_button_enable_clicked(bool check); // example only
	void on_actionAbout_triggered();
	// examples: typical ros style connection slots
	// void on_button_connect_clicked(bool check );
	// void on_checkbox_use_environment_stateChanged(int state);

private:
	Ui::MainWindowDesign ui;
};

}  // namespace %(package)s

#endif // %(package)s_MAIN_WINDOW_H
