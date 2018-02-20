
#include "KmitApplication.h"

namespace Kmit {
	
	KmitApplication::KmitApplication(QObject *parent) {
		qDebug() << "Kmit::new";
		Win *win = new Win(100, 100, 800, 700);
		win->name_("Kmit");

		Jui::loadFonts();
		/*
		ScServer server(win);
		server.setPath("C:/Program Files/SuperCollider-3.9.0");
		*/

		txt = new PureText(win);
		txt->geometry_(10, 50, 300, 20);

		connect(&clock, SIGNAL(timeout()), this, SLOT(onTick()));
		clock.start(10);
	}

	void KmitApplication::onTick() {
		txt->text_(clock.now().toString());
	}

}