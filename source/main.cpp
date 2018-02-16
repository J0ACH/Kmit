

#include <QApplication>
#include <QWidget>
#include <scserver.h>

using namespace SC;

int main(int argc, char *argv[]) {

	QApplication app(argc, argv);
	
	QWidget *win = new QWidget();
	win->setGeometry(100, 100, 800, 700);
	win->show();

	SC::ScServer server(win);	
	server.setPath("C:/Program Files/SuperCollider-3.9.0");

	return app.exec();
}
