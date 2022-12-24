#pragma once
#include "../include/quaternion.h"

namespace Mathematics
{
#define kPI 3.14159265358979323846264338327950288419716939937510F

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

	float3 quaternion::EulerAngles()
	{
		return Positive(QuaternionToEuler(normalizesafe(*this)) * math::Rad2Deg);
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

	quaternion quaternion::Axis(float3 axis, float angle)
	{
		float sina, cosa;
		math::sincos(0.5f * angle * math::Deg2Rad, sina, cosa);
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
		math::sincos(0.5f * xyz*math::Deg2Rad, s, c);
		float3 sxyz = float3(s.x, s.y, s.z);
		float4 syxxy = float4(s.y, s.x, s.x,s.y);
		float4 szzyz = float4(s.z, s.z, s.y, s.z);

		float4 cyxxy = float4(c.y, c.x, c.x,c.y);
		float4 czzyz = float4(c.z, c.z, c.y, c.z);
		float3 cxyz = float3(c.x, c.y, c.z);
	
		float4 a = float4(sxyz.x, sxyz.y, sxyz.z, c.x);
		a = a * cyxxy * czzyz;

		float4 b = float4(cxyz.x, cxyz.y, cxyz.z, s.x);
		b = syxxy * szzyz * b;

		//float4 c = float4(1.0f, -1.0f, -1.0f, 1.0f);
		float4 d =a+b* float4(1.0f, -1.0f, -1.0f, 1.0f);
		//float4(sxyz, c.x) * cyxxy * czzyz + syxxy * szzyz * float4(cxyz, s.x) * float4(1.0f, -1.0f, -1.0f, 1.0f)
		return quaternion(d
	/*		s.x * c.y * c.z - s.y * s.z * c.x,
			s.y * c.x * c.z + s.x * s.z * c.y,
			s.z * c.x * c.y + s.x * s.y * c.z,
			c.x * c.y * c.z - s.y * s.z * s.x*/
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

	/// <summary>
	/// Returns a quaternion view rotation given a unit length forward vector and a unit length up vector.
	/// The two input vectors are assumed to be unit length and not collinear.
	/// If these assumptions are not met use float3x3.LookRotationSafe instead.
	/// </summary>
	/// <param name="forward">The view forward direction.</param>
	/// <param name="up">The view up direction.</param>
	/// <returns>The quaternion view rotation.</returns>
	/// 参数为单位向量 向量不共线，否则使用LookRotationSafe
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

	float3 quaternion::Positive(float3 euler)
	{
		float negativeFlip = -0.0001f * math::Rad2Deg;
		float positiveFlip = 360.0f + negativeFlip;

		if (euler.x < negativeFlip)
			euler.x += 360.0f;
		else if (euler.x > positiveFlip)
			euler.x -= 360.0f;
		else if (euler.x == -0)
			euler.x = 0;

		if (euler.y < negativeFlip)
			euler.y += 360.0f;
		else if (euler.y > positiveFlip)
			euler.y -= 360.0f;
		else if (euler.y == -0)
			euler.y = 0;

		if (euler.z < negativeFlip)
			euler.z += 360.0f;
		else if (euler.z > positiveFlip)
			euler.z -= 360.0f;
		else if (euler.z == -0)
			euler.z = 0;

		return euler;
	}


	float3 quaternion::QuaternionToEuler(const quaternion& quaternion)
	{
		float3x3 m(0);
		return MatrixToEuler(QuaternionToMatrix(quaternion, m));
	}

	float3x3 quaternion::QuaternionToMatrix(const quaternion& quaternion, float3x3& mm)
	{
		float3x3 m(0);
		float4 q = quaternion.value;
		float x = q.x * 2.0F;
		float y = q.y * 2.0F;
		float z = q.z * 2.0F;
		float xx = q.x * x;
		float yy = q.y * y;
		float zz = q.z * z;
		float xy = q.x * y;
		float xz = q.x * z;
		float yz = q.y * z;
		float wx = q.w * x;
		float wy = q.w * y;
		float wz = q.w * z;

		// Calculate 3x3 matrix from orthonormal basis
		m.c0.x = 1.0f - (yy + zz);
		m.c0.y = xy + wz;
		m.c0.z = xz - wy;

		m.c1.x = xy - wz;
		m.c1.y = 1.0f - (xx + zz);
		m.c1.z = yz + wx;

		m.c2.x = xz + wy;
		m.c2.y = yz - wx;
		m.c2.z = 1.0f - (xx + yy);
		return m;
	}


	/// This is YXZ euler conversion
	float3 quaternion::MatrixToEuler(const float3x3& matrix)
	{
		// from http://www.geometrictools.com/Documentation/EulerAngles.pdf
		float3 v(0);
		// YXZ order
		if (matrix[1][2] < 0.999F) // some fudge for imprecision
		{
			if (matrix[1][2] > -0.999F) // some fudge for imprecision
			{
				v.x = asin(-matrix[1][2]);
				v.y = atan2(matrix[0][2], matrix[2][2]);
				v.z = atan2(matrix[1][0], matrix[1][1]);
				MakePositive(v);
			}
			else
			{
				// WARNING.  Not unique.  YA - ZA = atan2(r01,r00)
				v.x = kPI * 0.5F;
				v.y = atan2(matrix[0][1], matrix[0][0]);
				v.z = 0.0F;
				MakePositive(v);
			}
		}
		else
		{
			// WARNING.  Not unique.  YA + ZA = atan2(-r01,r00)
			v.x = -kPI * 0.5F;
			v.y = atan2(-matrix[0][1], matrix[0][0]);
			v.z = 0.0F;
			MakePositive(v);
		}
		return v;
	}


	void quaternion::MakePositive(float3& euler)
	{
		const float negativeFlip = -0.0001F;
		const float positiveFlip = (kPI * 2.0F) - 0.0001F;

		if (euler.x < negativeFlip)
			euler.x += 2.0 * kPI;
		else if (euler.x > positiveFlip)
			euler.x -= 2.0 * kPI;

		if (euler.y < negativeFlip)
			euler.y += 2.0 * kPI;
		else if (euler.y > positiveFlip)
			euler.y -= 2.0 * kPI;

		if (euler.z < negativeFlip)
			euler.z += 2.0 * kPI;
		else if (euler.z > positiveFlip)
			euler.z -= 2.0 * kPI;
	}
}