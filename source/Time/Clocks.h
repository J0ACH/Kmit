#ifndef CLOCKs_H
#define CLOCKs_H

#include <chrono>
#include <thread>

//#include <QTime>
#include <QDebug>
#include <QString>
#include <QElapsedTimer>
#include <QDeadlineTimer>
#include <QThread>

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

	class SystemClock
	{

	public:
		SystemClock();

		TimeStamp now();
		//qint64 iTime();
		void sched(TimeStamp t);

	private:
		QElapsedTimer time;
		TimeStamp initTime;

		void restartTime();
	};
}

#endif // CLOCKs_H