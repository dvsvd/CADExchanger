#pragma once
#define _USE_MATH_DEFINES

#include <functional>
#include <iostream>
#include <limits>
#include <cmath>

namespace Utility {
	bool ValidateNum(float n)
	{
		return !(isnan(n) || isinf(n));
	}
}
