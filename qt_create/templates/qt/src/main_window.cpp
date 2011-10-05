/**
 * @file /src/main_window.cpp
 *
 * @brief Implementation for the qt gui.
 *
 * @date February 2011
 **/
/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui>
#include <QMessageBox>
#include <iostream>
#include "../include/%(package)s/main_window.hpp"

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace %(package)s {

using namespace Qt;

/*****************************************************************************
** Implementation [MainWindow]
*****************************************************************************/

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this); // Calling this incidentally connects all ui's triggers to on_...() callbacks in this class.
    QObject::connect(ui.actionAbout_Qt, SIGNAL(triggered(bool)), qApp, SLOT(aboutQt())); // qApp is a global variable for the application

    ReadSettings();
	setWindowIcon(QIcon(":/images/icon.png"));
	ui.tab_manager->setCurrentIndex(0); // ensure the first tab is showing - qt-designer should have this already hardwired, but often loses it (settings?).

	// example connection to the logging viewer
	// ui.view_logging->setModel(qnode.loggingModel());
}

MainWindow::~MainWindow() {}

/*****************************************************************************
** Implementation [Slots]
*****************************************************************************/

/*
 * These triggers whenever the button is clicked, regardless of whether it
 * is already checked or not.
 */

//void MainWindow::on_button_connect_clicked(bool check ) {
//	ui.button_connect->setEnabled(false);
	// typical ros connect code.
//	if ( ui.checkbox_use_environment->isChecked() ) {
//		qnode.init(ui.line_edit_topic->text().toStdString());
//	} else {
//		qnode.init(ui.line_edit_master->text().toStdString(),
//				   ui.line_edit_host->text().toStdString(),
//				   ui.line_edit_topic->text().toStdString());
//		ui.line_edit_master->setReadOnly(true);
//		ui.line_edit_host->setReadOnly(true);
//		ui.line_edit_topic->setReadOnly(true);
//	}
//}

//void MainWindow::on_checkbox_use_environment_stateChanged(int state) {
	// typical ros environment state changed code.
//	bool enabled;
//	if ( state == 0 ) {
//		enabled = true;
//	} else {
//		enabled = false;
//	}
//	ui.line_edit_master->setEnabled(enabled);
//	ui.line_edit_host->setEnabled(enabled);
//	ui.line_edit_topic->setEnabled(enabled);
//}

/*****************************************************************************
** Implementation [Menu]
*****************************************************************************/

void MainWindow::on_actionAbout_triggered() {
    QMessageBox::about(this, tr("About ..."),tr("<h2>PACKAGE_NAME Test Program 0.10</h2><p>Copyright Yujin Robot</p><p>This package needs an about description.</p>"));
}

/*****************************************************************************
** Implementation [Configuration]
*****************************************************************************/

void MainWindow::ReadSettings() {
    QSettings settings("Qt-Ros Package", "%(package)s");
    QRect rect = settings.value("geometry", QRect(200, 200, 400, 400)).toRect();
    move(rect.topLeft());
    resize(rect.size());
}

void MainWindow::WriteSettings() {
    QSettings settings("Qt-Ros Package", "%(package)s");
    settings.setValue("geometry", geometry());
}

void MainWindow::closeEvent(QCloseEvent *event)
{
	WriteSettings();
	event->accept();
}

}  // namespace %(package)s

