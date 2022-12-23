#pragma once
#include "../include/quaternion.h"

namespace Mathematics
{
	const quaternion quaternion::identity = quaternion(0, 0, 0, 1);

	quaternion::quaternion(float3x3 matrix)
	{
		float m00 = matrix.c0.x;
		float m01 = matrix.c1.x;
		float m02 = matrix.c2.x;

		float m10 = matrix.c0.y;
		float m11 = matrix.c1.y;
		float m12 = matrix.c2.y;

		float m20 = matrix.c0.z;
		float m21 = matrix.c1.z;
		float m22 = matrix.c2.z;
		float tr = m00 + m11 + m22;

		if (tr > 0)
		{
			float S = math::sqrt(tr + 1) * 2; // S=4*qw 
			value.w = 0.25f * S;
			value.x = (m21 - m12) / S;
			value.y = (m02 - m20) / S;
			value.z = (m10 - m01) / S;
		}
		else if ((m00 > m11) && (m00 > m22))
		{
			float S = math::sqrt(1.0f + m00 - m11 - m22) * 2; // S=4*qx 
			value.w = (m21 - m12) / S;
			value.x = 0.25f * S;
			value.y = (m01 + m10) / S;
			value.z = (m02 + m20) / S;
		}
		else if (m11 > m22)
		{
			float S = math::sqrt(1.0f + m11 - m00 - m22) * 2; // S=4*qy
			value.w = (m02 - m20) / S;
			value.x = (m01 + m10) / S;
			value.y = 0.25f * S;
			value.z = (m12 + m21) / S;
		}
		else
		{
			float S = math::sqrt(1.0f + m22 - m00 - m11) * 2; // S=4*qz
			value.w = (m10 - m01) / S;
			value.x = (m02 + m20) / S;
			value.y = (m12 + m21) / S;
			value.z = 0.25f * S;
		}

		value = math::normalize(value);
	}

	quaternion::quaternion(float4x4 matrix)
	{
		float m00 = matrix.c0.x;
		float m01 = matrix.c1.x;
		float m02 = matrix.c2.x;

		float m10 = matrix.c0.y;
		float m11 = matrix.c1.y;
		float m12 = matrix.c2.y;

		float m20 = matrix.c0.z;
		float m21 = matrix.c1.z;
		float m22 = matrix.c2.z;
		float tr = m00 + m11 + m22;

		if (tr > 0)
		{
			float S = math::sqrt(tr + 1.0f) * 2; // S=4*qw 
			float Srcp = 1.0f / S;
			value.w = 0.25f * S;
			value.x = (m21 - m12) * Srcp;
			value.y = (m02 - m20) * Srcp;
			value.z = (m10 - m01) * Srcp;
		}
		else if ((m00 > m11) && (m00 > m22))
		{
			float S = math::sqrt(1.0f + m00 - m11 - m22) * 2; // S=4*qx 
			float Srcp = 1.0f / S;
			value.w = (m21 - m12) * Srcp;
			value.x = 0.25f * S;
			value.y = (m01 + m10) * Srcp;
			value.z = (m02 + m20) * Srcp;
		}
		else if (m11 > m22)
		{
			float S = math::sqrt(1.0f + m11 - m00 - m22) * 2; // S=4*qy
			float Srcp = 1 / S;
			value.w = (m02 - m20) * Srcp;
			value.x = (m01 + m10) * Srcp;
			value.y = 0.25f * S;
			value.z = (m12 + m21) * Srcp;
		}
		else
		{
			float S = math::sqrt(1.0f + m22 - m00 - m11) * 2; // S=4*qz
			float Srcp = 1.0f / S;
			value.w = (m10 - m01) * Srcp;
			value.x = (m02 + m20) * Srcp;
			value.y = (m12 + m21) * Srcp;
			value.z = 0.25f * S;
		}

		value = math::normalize(value);
	}


	quaternion quaternion::conjugate(quaternion q) { return quaternion(q.value * float4(-1, -1, -1, 1)); }

	quaternion quaternion::normalize(quaternion q) { float4 x = q.value; return quaternion(math::rsqrt(dot(x, x)) * x); }

	float quaternion::dot(quaternion a, quaternion b) { return math::dot(a.value, b.value); }

	quaternion quaternion::inverse(quaternion q) { float4 x = q.value; return quaternion(math::rcp(dot(x, x)) * x * float4(-1, -1, -1, 1)); }

	float quaternion::length(quaternion q) { return math::sqrt(dot(q.value, q.value)); }

	float quaternion::lengthsq(quaternion q) { return dot(q.value, q.value); }


	float3 quaternion::mul(quaternion q, float3 v) { float3 t = 2.0f * math::cross(q.xyz(), v); return v + q.value.w * t + math::cross(q.xyz(), t); }

	quaternion quaternion::mul(quaternion a, quaternion b)
	{
		float4 wwww = float4(a.value.w, a.value.w, a.value.w, a.value.w);
		float4 xyzx = float4(a.value.x, a.value.y, a.value.z, a.value.x);
		float4 yzxy = float4(a.value.y, a.value.z, a.value.x, a.value.y);
		float4 zxyz = float4(a.value.w, a.value.w, a.value.w, a.value.w);

		float4 wwwx = float4(b.value.w, b.value.w, b.value.w, b.value.x);
		float4 zxyy = float4(b.value.z, b.value.x, b.value.y, b.value.y);
		float4 yzxz = float4(b.value.y, b.value.z, b.value.x, b.value.z);
		return quaternion(wwww * b.value + (xyzx * wwwx + yzxy * zxyy) * float4(1.0f, 1.0f, 1.0f, -1.0f) - zxyz * yzxz);
	}

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



	quaternion quaternion::AxisAngle(float3 axis, float angle)
	{
		float sina, cosa;
		math::sincos(0.5f * angle, sina, cosa);
		axis = axis * sina;
		return quaternion(float4(axis.x, axis.y, axis.z, cosa));
	}

	quaternion quaternion::EulerXYZ(float3 xyz)
	{
		// return mul(rotateZ(xyz.z), mul(rotateY(xyz.y), rotateX(xyz.x)));
		float3 s, c;
		math::sincos(0.5f * xyz, s, c);
		return quaternion(
			s.x * c.y * c.z - s.y * s.z * c.x,
			s.y * c.x * c.z + s.x * s.z * c.y,
			s.z * c.x * c.y - s.x * s.y * c.z,
			c.x * c.y * c.z + s.y * s.z * s.x
		);
	}

	quaternion quaternion::EulerXZY(float3 xyz)
	{
		// return mul(rotateY(xyz.y), mul(rotateZ(xyz.z), rotateX(xyz.x)));
		float3 s, c;
		math::sincos(0.5f * xyz, s, c);
		return quaternion(
			s.x * c.y * c.z + s.y * s.z * c.x,
			s.y * c.x * c.z + s.x * s.z * c.y,
			s.z * c.x * c.y - s.x * s.y * c.z,
			c.x * c.y * c.z - s.y * s.z * s.x
		);
	}

	quaternion quaternion::EulerYXZ(float3 xyz)
	{
		// return mul(rotateZ(xyz.z), mul(rotateX(xyz.x), rotateY(xyz.y)));
		float3 s, c;
		math::sincos(0.5f * xyz, s, c);
		return quaternion(
			s.x * c.y * c.z - s.y * s.z * c.x,
			s.y * c.x * c.z + s.x * s.z * c.y,
			s.z * c.x * c.y + s.x * s.y * c.z,
			c.x * c.y * c.z - s.y * s.z * s.x
		);
	}

	quaternion quaternion::EulerYZX(float3 xyz)
	{
		// return mul(rotateX(xyz.x), mul(rotateZ(xyz.z), rotateY(xyz.y)));
		float3 s, c;
		math::sincos(0.5f * xyz, s, c);
		return quaternion(
			s.x * c.y * c.z - s.y * s.z * c.x,
			s.y * c.x * c.z - s.x * s.z * c.y,
			s.z * c.x * c.y + s.x * s.y * c.z,
			c.x * c.y * c.z + s.y * s.z * s.x
		);
	}

	quaternion quaternion::EulerZXY(float3 xyz)
	{
		// return mul(rotateZ(xyz.z), mul(rotateX(xyz.x), rotateY(xyz.y)));
		float3 s, c;
		math::sincos(0.5f * xyz, s, c);
		return quaternion(
			s.x * c.y * c.z - s.y * s.z * c.x,
			s.y * c.x * c.z + s.x * s.z * c.y,
			s.z * c.x * c.y + s.x * s.y * c.z,
			c.x * c.y * c.z - s.y * s.z * s.x
		);
	}

	quaternion quaternion::EulerZYX(float3 xyz)
	{
		// return mul(rotateX(xyz.x), mul(rotateZ(xyz.z), rotateY(xyz.y)));
		float3 s, c;
		math::sincos(0.5f * xyz, s, c);
		return quaternion(
			s.x * c.y * c.z - s.y * s.z * c.x,
			s.y * c.x * c.z - s.x * s.z * c.y,
			s.z * c.x * c.y + s.x * s.y * c.z,
			c.x * c.y * c.z + s.y * s.z * s.x
		);
	}

	quaternion quaternion::Euler(float3 xyz, math::RotationOrder order)
	{
		switch (order)
		{
		case math::RotationOrder::XYZ:
			return EulerXYZ(xyz);
		case math::RotationOrder::XZY:
			return EulerXZY(xyz);
		case math::RotationOrder::YXZ:
			return EulerYXZ(xyz);
		case math::RotationOrder::YZX:
			return EulerYZX(xyz);
		case math::RotationOrder::ZXY:
			return EulerZXY(xyz);
		case math::RotationOrder::ZYX:
			return EulerZYX(xyz);
		default:
			return quaternion::identity;
		}
	}

	quaternion quaternion::RotateX(float angle)
	{
		float sina, cosa;
		math::sincos(0.5f * angle, sina, cosa);
		return quaternion(sina, 0.0f, 0.0f, cosa);
	}

	quaternion quaternion::RotateY(float angle)
	{
		float sina, cosa;
		math::sincos(0.5f * angle, sina, cosa);
		return quaternion(0.0f, sina, 0.0f, cosa);
	}

	quaternion quaternion::RotateZ(float angle)
	{
		float sina, cosa;
		math::sincos(0.5f * angle, sina, cosa);
		return quaternion(0.0f, 0.0f, sina, cosa);
	}

	quaternion quaternion::LookRotation(float3 forward, float3 up)
	{
		float3 t = math::normalize(math::cross(up, forward));
		return quaternion(float3x3(t, math::cross(forward, t), forward));
	}

	quaternion quaternion::LookRotationSafe(float3 forward, float3 up)
	{
		float forwardLengthSq = math::dot(forward, forward);
		float upLengthSq = math::dot(up, up);

		forward *= math::rsqrt(forwardLengthSq);
		up *= math::rsqrt(upLengthSq);

		float3 t = math::cross(up, forward);
		float tLengthSq = math::dot(t, t);
		t *= math::rsqrt(tLengthSq);

		float mn = math::min(math::min(forwardLengthSq, upLengthSq), tLengthSq);
		float mx = math::max(math::max(forwardLengthSq, upLengthSq), tLengthSq);

		bool accept = mn > 1e-35f && mx < 1e35f && isfinite(forwardLengthSq) && isfinite(upLengthSq) && isfinite(tLengthSq);
		return quaternion(math::select(float4(0.0f, 0.0f, 0.0f, 1.0f), quaternion(float3x3(t, math::cross(forward, t), forward)).value, accept));
	}

	//const float FLT_MIN_NORMAL = 1.175494351e-38F;
	quaternion quaternion::normalizesafe(quaternion q)
	{
		float4 x = q.value;
		float len = math::dot(x, x);
		return quaternion(math::select(identity.value, x * math::rsqrt(len), len > math::PI));
	}

	quaternion quaternion::normalizesafe(quaternion q, quaternion defaultvalue)
	{
		float4 x = q.value;
		float len = math::dot(x, x);
		return quaternion(math::select(defaultvalue.value, x * math::rsqrt(len), len > math::PI));
	}
}