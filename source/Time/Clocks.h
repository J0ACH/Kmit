#ifndef CLOCKs_H
#define CLOCKs_H

#include <chrono>

//#include "Core.h"

namespace Kmit
{
	// Clock /////////////////////////////////////////////////////

	class SystemClock
	{

	public:
		SystemClock();

		double now();
	};
}

#endif // CLOCKs_H