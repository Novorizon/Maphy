#include "../include/math.h"

namespace Mathematics
{

	const float math::PI = 3.1415926535897931f;
	const float math::PI2 = 3.1415926535897931f * 2;
	const float math::PI2rcp = 1.0f / 3.1415926535897931f;
	const float math::Deg2Rad = PI * 2.0f / 360.0f; //0.0174533f;
	const float math::Rad2Deg = 360.0f / (PI * 2.0f);//1F / Deg2Rad;
	const float math::kEpsilonNormalSqrt = 1e-15F;

	const float  math::FLT_MIN_NORMAL = 1.175494351e-38F;
}