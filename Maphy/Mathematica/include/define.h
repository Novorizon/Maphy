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


	//64bit -9223372036854775808 - 9223372036854775807
	//48bit -281474976710656 - 281474976710657 :4294967296
	//32bit -2147483648 - 2147483647
}