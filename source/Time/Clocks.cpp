
#include "Clocks.h"

namespace Kmit {

	// TimeStamp /////////////////////////////////////////////////////

	TimeStamp::TimeStamp() { epochSec = 0; nanoSec = 0; }
	TimeStamp::TimeStamp(qint64 secs, qint64 nsecs) { epochSec = secs; nanoSec = nsecs; }

	qint64 TimeStamp::secs() { return epochSec; }
	qint64 TimeStamp::nsecs() { return nanoSec; }

	QString TimeStamp::toString() {
		QString txt, nulls;
		int cnt = std::to_string(nanoSec).size();
		for (int i = 0; i < (9 - cnt); i++) { nulls += "0"; }
		txt = QString("secs: %1 || nsec: %2%3").arg(
			QString::number(epochSec),
			nulls,
			QString::number(nanoSec)
		);
		return txt;
	}

	// Clocks /////////////////////////////////////////////////////

	Clock::Clock(QObject *parent) {
		//time.start();
		initTime = now();
		setTimerType(Qt::PreciseTimer);
		//connect(this, SIGNAL(timeout()), this, SLOT(tick()));
		
		qDebug() << "START" << initTime.toString();
		//qint64 syncNsecs = 1000000000 - initTime.nsecs();


		//int cnt = std::to_string(sync.nsecs()).size();

		/*
		qDebug() << "cnt:" << syncFullSec.remainingTimeNSecs();
		*/
	}

	/*
	void SystemClock::restartTime() {
		//QThread::usleep(1000000000 - initTime.nsecs());
		//std::this_thread::sleep_for(std::chrono::nanoseconds(1000000000 - initTime.nsecs()));

		qint64 restTime = 1000000000 - initTime.nsecs();
		QElapsedTimer restClock;
		restClock.start();

		while (restClock.nsecsElapsed() <= restTime)
		{
			QString txt, nulls;
			qint64 rest = restTime - restClock.nsecsElapsed();
			int cnt = std::to_string(rest).size();
			for (int i = 0; i < (9 - cnt); i++) { nulls += "0"; }
			txt = QString("nsec: %1%2").arg(
				nulls,
				QString::number(rest)
			);
			qDebug() << "FIN at:" << txt;
		}
		time.start();

		TimeStamp sync = now();
		qDebug() << "DONE" << sync.toString();
		qDebug() << "time" << time.nsecsElapsed();
	}
	*/

	void Clock::tick() {
		qDebug() << "TICK" << now().toString();
	}

	TimeStamp Clock::now() {
		using namespace std::chrono;
		system_clock::time_point timePoint = system_clock::now();
		system_clock::duration sinceEpoch = timePoint.time_since_epoch();
		seconds secs = duration_cast<seconds>(sinceEpoch);
		nanoseconds nsecs = sinceEpoch - secs;
		return TimeStamp(secs.count(), nsecs.count());
	}



}