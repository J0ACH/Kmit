
#include <QApplication>
#include <KmitApplication.h>

using namespace Kmit;

int main(int argc, char *argv[]) {

	QApplication app(argc, argv);	

	//connect(&clock, SIGNAL(timeout()), this, SLOT(tick()));

	KmitApplication *kmit = new KmitApplication();

	return app.exec();
}


