#pragma once
#include "float3x3.h"
#include "float4x4.h"
#include "math.h"

namespace Mathematics
{
	class quaternion
	{
	public:
		float4 value;

		quaternion(float4 q) { value = q; }

		quaternion(float x, float y, float z, float w) { value.x = x; value.y = y; value.z = z; value.w = w; }

		quaternion(float3x3 matrix)
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

		quaternion(float4x4 matrix)
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

		friend quaternion operator *(quaternion lhs, quaternion rhs)
		{
			return quaternion(
				lhs.value.w * rhs.value.x + lhs.value.x * rhs.value.w + lhs.value.y * rhs.value.z - lhs.value.z * rhs.value.y,
				lhs.value.w * rhs.value.y + lhs.value.y * rhs.value.w + lhs.value.z * rhs.value.x - lhs.value.x * rhs.value.z,
				lhs.value.w * rhs.value.z + lhs.value.z * rhs.value.w + lhs.value.x * rhs.value.y - lhs.value.y * rhs.value.x,
				lhs.value.w * rhs.value.w - lhs.value.x * rhs.value.x - lhs.value.y * rhs.value.y - lhs.value.z * rhs.value.z);
		}

		friend float3 operator *(quaternion q, float3 v)
		{
			float3 t = 2.0f * math::cross(q.xyz(), v);
			return v + q.value.w * t + math::cross(q.xyz(), t);
		}

		friend bool operator ==(quaternion a, quaternion b) { return a.value.x == b.value.x && a.value.y == b.value.y && a.value.z == b.value.z && a.value.w == b.value.w; }
		friend bool operator !=(quaternion a, quaternion b) { return a.value.x != b.value.x || a.value.y != b.value.y || a.value.z != b.value.z || a.value.w != b.value.w; }

		static quaternion conjugate(quaternion q);
		static quaternion normalize(quaternion q);
		static float dot(quaternion a, quaternion b);
		static quaternion inverse(quaternion q);
		static float length(quaternion q);
		static float lengthsq(quaternion q);
		static float3 mul(quaternion q, float3 v);
		static float3 rotate(quaternion q, float3 v);
		static quaternion nlerp(quaternion q1, quaternion q2, float t);
		static float3 forward(quaternion q);
		static quaternion slerp(quaternion q1, quaternion q2, float t);

		const float& operator[](int i) const
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

		float3 xyz() { return float3(value.x, value.y, value.z); }
	};


}