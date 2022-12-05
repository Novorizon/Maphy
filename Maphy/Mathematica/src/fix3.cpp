#include "../include/fix3.h"

namespace Mathematica
{
	const fix3 fix3::left = fix3(-1, 0, 0);
	const fix3 fix3::right = fix3(1, 0, 0);
	const fix3 fix3::up = fix3(0, 1, 0);
	const fix3 fix3::down = fix3(0, -1, 0);
	const fix3 fix3::forward = fix3(0, 0, 1);
	const fix3 fix3::backward = fix3(0, 0, -1);
	const fix3 fix3::one = fix3(1, 1, 1);
	const fix3 fix3::one_inverse = fix3(-1, -1, -1);
	const fix3 fix3::zero = fix3(0, 0, 0);
}