

#include <QApplication>
#include <QWidget>

#include <core.h>
#include <screens.h>
#include <scserver.h>

using namespace Jui;
using namespace SC;

int main(int argc, char *argv[]) {

	QApplication app(argc, argv);
	
	/*
	QWidget *win = new QWidget();
	win->setGeometry(100, 100, 800, 700);
	win->show();
	*/

	
	Win *win = new Win(100,100,800,700);
	win->name_("Kmit");
		
	SC::ScServer server(win);	
	server.setPath("C:/Program Files/SuperCollider-3.9.0");

	return app.exec();
}
