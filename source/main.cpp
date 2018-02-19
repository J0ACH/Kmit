

#include <QApplication>
#include <QWidget>

#include <core.h>
#include <screens.h>
#include <text.h>

#include <scserver.h>

#include <Clocks.h>


using namespace Jui;
using namespace SC;
using namespace Kmit;

int main(int argc, char *argv[]) {

	QApplication app(argc, argv);

	Win *win = new Win(100, 100, 800, 700);
	win->name_("Kmit");

	/*
	ScServer server(win);
	server.setPath("C:/Program Files/SuperCollider-3.9.0");
		*/

	PureText *txt = new PureText(win);
		txt->geometry_(10, 50, 300, 20);

	SystemClock sysClock;
	txt->text_(QString::number(sysClock.now(),'f',22));

	return app.exec();
}
