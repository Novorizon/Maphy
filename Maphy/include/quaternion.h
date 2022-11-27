#pragma once
#include "fix.h"
#include "fix3x3.h"
#include "fix4x4.h"
#include "math.h"

namespace Mathematica
{
	class quaternion
	{
	public:
		fix4 value;

		quaternion(fix4 q) { value = q; }

		quaternion(fix x, fix y, fix z, fix w) { value.x = x; value.y = y; value.z = z; value.w = w; }

		quaternion(fix3x3 matrix)
		{
			fix m00 = matrix.c0.x;
			fix m01 = matrix.c1.x;
			fix m02 = matrix.c2.x;

			fix m10 = matrix.c0.y;
			fix m11 = matrix.c1.y;
			fix m12 = matrix.c2.y;

			fix m20 = matrix.c0.z;
			fix m21 = matrix.c1.z;
			fix m22 = matrix.c2.z;
			fix tr = m00 + m11 + m22;

			if (tr > 0)
			{
				fix S = math::sqrt(tr + 1) * 2; // S=4*qw 
				value.w = _0_25 * S;
				value.x = (m21 - m12) / S;
				value.y = (m02 - m20) / S;
				value.z = (m10 - m01) / S;
			}
			else if ((m00 > m11) && (m00 > m22))
			{
				fix S = math::sqrt(_1 + m00 - m11 - m22) * 2; // S=4*qx 
				value.w = (m21 - m12) / S;
				value.x = _0_25 * S;
				value.y = (m01 + m10) / S;
				value.z = (m02 + m20) / S;
			}
			else if (m11 > m22)
			{
				fix S = math::sqrt(_1 + m11 - m00 - m22) * 2; // S=4*qy
				value.w = (m02 - m20) / S;
				value.x = (m01 + m10) / S;
				value.y = _0_25 * S;
				value.z = (m12 + m21) / S;
			}
			else
			{
				fix S = math::sqrt(_1 + m22 - m00 - m11) * 2; // S=4*qz
				value.w = (m10 - m01) / S;
				value.x = (m02 + m20) / S;
				value.y = (m12 + m21) / S;
				value.z = _0_25 * S;
			}

			value = math::normalize(value);
		}

		quaternion(fix4x4 matrix)
		{
			fix m00 = matrix.c0.x;
			fix m01 = matrix.c1.x;
			fix m02 = matrix.c2.x;

			fix m10 = matrix.c0.y;
			fix m11 = matrix.c1.y;
			fix m12 = matrix.c2.y;

			fix m20 = matrix.c0.z;
			fix m21 = matrix.c1.z;
			fix m22 = matrix.c2.z;
			fix tr = m00 + m11 + m22;

			if (tr > 0)
			{
				fix S = math::sqrt(tr + _1) * 2; // S=4*qw 
				fix Srcp = 1 / S;
				value.w = _0_25 * S;
				value.x = (m21 - m12) * Srcp;
				value.y = (m02 - m20) * Srcp;
				value.z = (m10 - m01) * Srcp;
			}
			else if ((m00 > m11) && (m00 > m22))
			{
				fix S = math::sqrt(_1 + m00 - m11 - m22) * 2; // S=4*qx 
				fix Srcp = 1 / S;
				value.w = (m21 - m12) * Srcp;
				value.x = _0_25 * S;
				value.y = (m01 + m10) * Srcp;
				value.z = (m02 + m20) * Srcp;
			}
			else if (m11 > m22)
			{
				fix S = math::sqrt(_1 + m11 - m00 - m22) * 2; // S=4*qy
				fix Srcp = 1 / S;
				value.w = (m02 - m20) * Srcp;
				value.x = (m01 + m10) * Srcp;
				value.y = _0_25 * S;
				value.z = (m12 + m21) * Srcp;
			}
			else
			{
				fix S = math::sqrt(_1 + m22 - m00 - m11) * 2; // S=4*qz
				fix Srcp = 1 / S;
				value.w = (m10 - m01) * Srcp;
				value.x = (m02 + m20) * Srcp;
				value.y = (m12 + m21) * Srcp;
				value.z = _0_25 * S;
			}

			value = math::normalize(value);
		}

		friend quaternion operator *(quaternion lhs, quaternion rhs)
		{
			return quaternion(
				lhs.value.w * rhs.value.x + lhs.value.x * rhs.value.w + lhs.value.y * rhs.value.z - lhs.value.z * rhs.value.y,
				lhs.value.w * rhs.value.y + lhs.value.y * rhs.value.w + lhs.value.z * rhs.value.x - lhs.value.x * rhs.value.z,
				lhs.value.w * rhs.value.z + lhs.value.z * rhs.value.w + lhs.value.x * rhs.value.y - lhs.value.y * rhs.value.x,
				lhs.value.w * rhs.value.w - lhs.value.x * rhs.value.x - lhs.value.y * rhs.value.y - lhs.value.z * rhs.value.z);
		}

		friend fix3 operator *(quaternion q, fix3 v)
		{
			fix3 t = _2 * math::cross(q.value.xyz(), v);
			return v + q.value.w * t + math::cross(q.value.xyz(), t);
		}

		friend bool operator ==(quaternion a, quaternion b) { return a.value.x == b.value.x && a.value.y == b.value.y && a.value.z == b.value.z && a.value.w == b.value.w; }
		friend bool operator !=(quaternion a, quaternion b) { return a.value.x != b.value.x || a.value.y != b.value.y || a.value.z != b.value.z || a.value.w != b.value.w; }

		static quaternion conjugate(quaternion q);
		static quaternion normalize(quaternion q);
		static fix dot(quaternion a, quaternion b);
		static quaternion inverse(quaternion q);
		static fix length(quaternion q);
		static fix lengthsq(quaternion q);
		static fix3 mul(quaternion q, fix3 v);
		static fix3 rotate(quaternion q, fix3 v);
		static quaternion nlerp(quaternion q1, quaternion q2, fix t);
		static fix3 forward(quaternion q);
		const quaternion slerp(quaternion q1, quaternion q2, fix t);

		const fix& operator[](int i) const
		{
			switch (i)
			{
			case 0:
				return value.x;
				break;
			case 1:
				return value.y;
				break;
			case 2:
				return value.z;
				break;
			case 3:
				return value.w;
				break;
			default:
				break;
			}
		}
	};


}