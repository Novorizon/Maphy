#pragma once
#include <string>
#include <sstream>


namespace Mathematica
{
	using Int = int64_t;

	const Int BITS = 64;
	const Int PRECISION = 16;
	const Int PRECISION2 = PRECISION * 2;
	const Int ONE = 1L << PRECISION;
	const Int MAX_VALUE = 140737488355327;
	const Int MIN_VALUE = -140737488355328;


}