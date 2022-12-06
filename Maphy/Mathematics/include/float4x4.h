#pragma once
#include "config.h"
#include "float4.h"
namespace Mathematics
{
	class float4x4
	{
	public:
		float4 c0;
		float4 c1;
		float4 c2;
		float4 c3;

		float4x4(float4 col0, float4 col1, float4 col2, float4 col3)
		{
			c0 = col0;
			c1 = col1;
			c2 = col2;
			c3 = col3;
		}

		float4x4(float m00, float m01, float m02, float m03,
			float m10, float m11, float m12, float m13,
			float m20, float m21, float m22, float m23,
			float m30, float m31, float m32, float m33)
		{
			c0 = float4(m00, m10, m20, m30);
			c1 = float4(m01, m11, m21, m31);
			c2 = float4(m02, m12, m22, m32);
			c0 = float4(m03, m13, m23, m33);
		}

		float4x4(float v)
		{
			float4 x = float4(v, v, v, v);
			c0 = x;
			c1 = x;
			c2 = x;
			c3 = x;
		}

		friend float4x4 operator +(float4x4 lhs, float4x4 rhs) { return float4x4(lhs.c0 + rhs.c0, lhs.c1 + rhs.c1, lhs.c2 + rhs.c2, lhs.c3 + rhs.c3); }
		friend float4x4 operator -(float4x4 lhs, float4x4 rhs) { return float4x4(lhs.c0 - rhs.c0, lhs.c1 - rhs.c1, lhs.c2 - rhs.c2, lhs.c3 - rhs.c3); }
		friend float4x4 operator *(float4x4 lhs, float4x4 rhs) { return float4x4(lhs.c0 * rhs.c0, lhs.c1 * rhs.c1, lhs.c2 * rhs.c2, lhs.c3 * rhs.c3); }
		friend float4x4 operator *(float4x4 lhs, float rhs) { return float4x4(lhs.c0 * rhs, lhs.c1 * rhs, lhs.c2 * rhs, lhs.c3 * rhs); }
		friend float4x4 operator *(float lhs, float4x4 rhs) { return float4x4(lhs * rhs.c0, lhs * rhs.c1, lhs * rhs.c2, lhs * rhs.c3); }
		friend float4x4 operator /(float4x4 lhs, float4x4 rhs) { return float4x4(lhs.c0 / rhs.c0, lhs.c1 / rhs.c1, lhs.c2 / rhs.c2, lhs.c3 / rhs.c3); }

		friend float4x4 operator -(float4x4 val) { return float4x4(-val.c0, -val.c1, -val.c2, -val.c3); }

		friend bool operator ==(float4x4 lhs, float4x4 rhs) { return lhs.c0 == rhs.c0 && lhs.c1 == rhs.c1 && lhs.c2 == rhs.c2 && lhs.c3 == rhs.c3; }
		friend bool operator !=(float4x4 lhs, float4x4 rhs) { return lhs.c0 != rhs.c0 || lhs.c1 != rhs.c1 || lhs.c2 != rhs.c2 || lhs.c3 != rhs.c3; };

		const float4& operator[](int i) const
		{
			switch (i)
			{
			case 0:
				return c0;
				break;
			case 1:
				return c1;
				break;
			case 2:
				return c2;
				break;
			case 3:
				return c3;
				break;
			default:
				break;
			}
		}
	};


}