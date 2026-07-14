#include <Utilities/Calculations.h>

namespace utils::calculations {

	float getPercentagef(float percentage, float number) {
		return number * (percentage / 100.0f);
	}

}

