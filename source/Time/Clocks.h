#ifndef CLOCKs_H
#define CLOCKs_H

#include <chrono>
#include <thread>

//#include <QTime>
#include <QDebug>
#include <QString>
#include <QTimer>
//#include <QElapsedTimer>
//#include <QDeadlineTimer>
//#include <QThread>

//#include "Core.h"

namespace Kmit
{
	// TimeStamp /////////////////////////////////////////////////////

	class TimeStamp
	{
	public:
		TimeStamp();
		TimeStamp(qint64 secs, qint64 nsecs);

		//void sec_();
		qint64 secs();
		qint64 nsecs();

		QString toString();

	private:
		qint64 epochSec;
		qint64 nanoSec;
	};

	// Clocks /////////////////////////////////////////////////////

	class Clock : public QTimer
	{
		Q_OBJECT

	public:
		Clock(QObject *parent = Q_NULLPTR);

		TimeStamp now();
		
		void sched(TimeStamp t);

	private:
		
		TimeStamp initTime;

		private slots:
		void tick();

		//void restartTime();
	};
}

#endif // CLOCKs_H