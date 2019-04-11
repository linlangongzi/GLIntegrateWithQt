#include "MainWindow.h"
#include <QtWidgets/QApplication>
#include <GLWidget.h>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	GLWidget *widget = new GLWidget();
	MainWindow w;
	w.setCentralWidget(widget);
	w.show();
	return a.exec();
}
