
#include "KmitApplication.h"

namespace Kmit {

	KmitApplication::KmitApplication(QObject *parent) {
		
		initTime = clock.now();
		
		Win *win = new Win(100, 100, 325, 130);
		win->name_("Kmit");

		Jui::loadFonts();

		ScServer server(win);
		server.setPath("C:/Program Files/SuperCollider-3.9.0");

		txt = new PureText(win);
		txt->geometry_(10, 50, 300, 20);

		timestamp = new PureText(win);
		timestamp->geometry_(10, 80, 300, 20);
		
		clock.connectOnSec(this, SLOT(onTick()));
	}

	void KmitApplication::onTick() {
		Orloj::Timetag nowTime = clock.now();
		txt->text_(nowTime.toString(Orloj::Timetag::FULL));
	}

}