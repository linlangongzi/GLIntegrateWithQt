#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QMainWindow *parent = Q_NULLPTR);

private:
	Ui::MainWindowClass ui;
};
