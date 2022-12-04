#pragma once
#include "../include/quaternion.h"

namespace Mathematics
{

	quaternion quaternion::conjugate(quaternion q) { return quaternion(q.value * float4(-1, -1, -1, 1)); }

	quaternion quaternion::normalize(quaternion q) { float4 x = q.value; return quaternion(math::rsqrt(dot(x, x)) * x); }

	float quaternion::dot(quaternion a, quaternion b) { return math::dot(a.value, b.value); }

	quaternion quaternion::inverse(quaternion q) { float4 x = q.value; return quaternion(math::rcp(dot(x, x)) * x * float4(-1, -1, -1, 1)); }

	float quaternion::length(quaternion q) { return math::sqrt(dot(q.value, q.value)); }

	float quaternion::lengthsq(quaternion q) { return dot(q.value, q.value); }


	float3 quaternion::mul(quaternion q, float3 v) { float3 t = 2.0f * math::cross(q.xyz(), v); return v + q.value.w * t + math::cross(q.xyz(), t); }

	float3 quaternion::rotate(quaternion q, float3 v) { float3 t = 2.0f * math::cross(q.xyz(), v); return v + q.value.w * t + math::cross(q.xyz(), t); }

	quaternion quaternion::nlerp(quaternion q1, quaternion q2, float t)
	{
		float dt = dot(q1, q2);
		if (dt < 0)
		{
			q2.value = math::abs(q2.value);
		}

		return normalize(quaternion(math::lerp(q1.value, q2.value, t)));
	}

	quaternion quaternion::slerp(quaternion q1, quaternion q2, float t)
	{
		float dt = dot(q1, q2);
		if (dt < 0)
		{
			dt = -dt;
			q2.value = -q2.value;
		}

		if (dt < 0.9995f)
		{
			float angle = math::acos(dt);
			float s = math::rsqrt(1 - dt * dt);
			float w1 = math::sin(angle * (1 - t)) * s;
			float w2 = math::sin(angle * t) * s;
			return quaternion(q1.value * w1 + q2.value * w2);
		}
		else
		{
			// if the angle is small, use linear interpolation
			return nlerp(q1, q2, t);
		}
	}


	float3 quaternion::forward(quaternion q) { return mul(q, float3(0, 0, 1)); }


}