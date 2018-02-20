#ifndef KMITAPPLICATION_H
#define KMITAPPLICATION_H

#include <QDebug>

#include <core.h>
#include <screens.h>
#include <text.h>

#include <scserver.h>

#include <Clocks.h>

using namespace Jui;
using namespace SC;

namespace Kmit {
	
	class KmitApplication : public QObject
	{
		Q_OBJECT

	public:
		KmitApplication(QObject *parent = Q_NULLPTR);

		public slots :
		void onTick();

	private:
		PureText * txt;
		Clock clock;
	};
}

#endif // KMITAPPLICATION_H