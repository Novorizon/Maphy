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


	fix3 quaternion::mul(quaternion q, fix3 v) { fix3 t = fix::_2 * math::cross(q.xyz(), v); return v + q.value.w * t + math::cross(q.xyz(), t); }

	fix3 quaternion::rotate(quaternion q, fix3 v) { fix3 t = fix::_2 * math::cross(q.xyz(), v); return v + q.value.w * t + math::cross(q.xyz(), t); }

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

		if (dt < fix::_0_9995)
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
	
		// quaternion quaternion::AxisAngle(float3 axis, float angle)
		//{
		//	float sina, cosa;
		//	math::sincos(0.5f * angle, sina, cosa);
		//	axis = axis * sina;
		//	return quaternion(float4(axis.x, axis.y, axis.z, cosa));
		//}

		///// <summary>
		///// Returns a quaternion constructed by first performing a rotation around the x-axis, then the y-axis and finally the z-axis.
		///// All rotation angles are in radians and clockwise when looking along the rotation axis towards the origin.
		///// </summary>
		///// <param name="xyz">A float3 vector containing the rotation angles around the x-, y- and z-axis measures in radians.</param>
		///// <returns>The quaternion representing the Euler angle rotation in x-y-z order.</returns>
		// quaternion quaternion::EulerXYZ(float3 xyz)
		//{
		//	// return mul(rotateZ(xyz.z), mul(rotateY(xyz.y), rotateX(xyz.x)));
		//	float3 s, c;
		//	math::sincos(0.5f * xyz,  s,  c);
		//	return quaternion(
		//		// s.x * c.y * c.z - s.y * s.z * c.x,
		//		// s.y * c.x * c.z + s.x * s.z * c.y,
		//		// s.z * c.x * c.y - s.x * s.y * c.z,
		//		// c.x * c.y * c.z + s.y * s.z * s.x
		//		float4(s.xyz, c.x) * c.yxxy * c.zzyz + s.yxxy * s.zzyz * float4(c.xyz, s.x) * float4(-1.0f, 1.0f, -1.0f, 1.0f)
		//	);
		//}

}