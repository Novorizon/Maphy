#pragma once
#include "../include/fix.h"
#include "../include/fix3x3.h"
#include "../include/quaternion.h"
#include "../include/math.h"

namespace Mathematica
{

	quaternion quaternion::conjugate(quaternion q) { return quaternion(q.value * fix4(-1, -1, -1, 1)); }

	quaternion quaternion::normalize(quaternion q) { fix4 x = q.value; return quaternion(math::rsqrt(dot(x, x)) * x); }

	fix quaternion::dot(quaternion a, quaternion b) { return math::dot(a.value, b.value); }

	quaternion quaternion::inverse(quaternion q) { fix4 x = q.value; return quaternion(math::rcp(dot(x, x)) * x * fix4(-1, -1, -1, 1)); }

	fix quaternion::length(quaternion q) { return math::sqrt(dot(q.value, q.value)); }

	fix quaternion::lengthsq(quaternion q) { return dot(q.value, q.value); }


	fix3 quaternion::mul(quaternion q, fix3 v) { fix3 t = _2 * math::cross(q.xyz(), v); return v + q.value.w * t + math::cross(q.xyz(), t); }

	fix3 quaternion::rotate(quaternion q, fix3 v) { fix3 t = _2 * math::cross(q.xyz(), v); return v + q.value.w * t + math::cross(q.xyz(), t); }

	quaternion quaternion::nlerp(quaternion q1, quaternion q2, fix t)
	{
		fix dt = dot(q1, q2);
		if (dt < 0)
		{
			q2.value = math::abs(q2.value);
		}

		return normalize(quaternion(math::lerp(q1.value, q2.value, t)));
	}

	quaternion quaternion::slerp(quaternion q1, quaternion q2, fix t)
	{
		fix dt = dot(q1, q2);
		if (dt < 0)
		{
			dt = -dt;
			q2.value = -q2.value;
		}

		if (dt < _0_9995)
		{
			fix angle = math::acos(dt);
			fix s = math::rsqrt(1 - dt * dt);
			fix w1 = math::sin(angle * (1 - t)) * s;
			fix w2 = math::sin(angle * t) * s;
			return quaternion(q1.value * w1 + q2.value * w2);
		}
		else
		{
			// if the angle is small, use linear interpolation
			return nlerp(q1, q2, t);
		}
	}


	fix3 quaternion::forward(quaternion q) { return mul(q, fix3(0, 0, 1)); }


}