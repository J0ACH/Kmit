
#include "Clocks.h"

namespace Kmit {

	SystemClock::SystemClock() {

	}

	double SystemClock::now() {
		using namespace std::chrono;
		system_clock::time_point timePoint = system_clock::now();
		system_clock::duration sinceEpoch = timePoint.time_since_epoch();
		seconds secs = duration_cast<seconds>(sinceEpoch);
		nanoseconds nsecs = sinceEpoch - secs;

		unsigned long int sec_1970_now = secs.count();
		unsigned long long int nsec_1970_now = nsecs.count();

		double nowTime = secs.count() + nsecs.count() / 1000000000.0;
		
		return nowTime;
		//emit print(tr("nowTime                   : %1").arg(QString::number(nowTime, 'f', 12)));
		//emit print(tr("ScServer::now time [sec.nano]          : %1").arg(QString::number(nowTime, 'f', 22)));
		//return nowTime;
	}


}