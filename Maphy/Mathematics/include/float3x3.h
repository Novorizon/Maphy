#pragma once
#include "define.h"
#include "float3.h"
namespace Mathematics
{
	class float3x3
	{
	public:
		float3 c0;
		float3 c1;
		float3 c2;

		float3x3(float3 col0, float3 col1, float3 col2)
		{
			c0 = col0;
			c1 = col1;
			c2 = col2;
		}

		float3x3(float m00, float m01, float m02,
			float m10, float m11, float m12,
			float m20, float m21, float m22)
		{
			c0 = float3(m00, m10, m20);
			c1 = float3(m01, m11, m21);
			c2 = float3(m02, m12, m22);
		}

		float3x3(float v)
		{
			float3 x = float3(v, v, v);
			c0 = x;
			c1 = x;
			c2 = x;
		}

		friend float3x3 operator +(float3x3 lhs, float3x3 rhs) { return float3x3(lhs.c0 + rhs.c0, lhs.c1 + rhs.c1, lhs.c2 + rhs.c2); }
		friend float3x3 operator -(float3x3 lhs, float3x3 rhs) { return float3x3(lhs.c0 - rhs.c0, lhs.c1 - rhs.c1, lhs.c2 - rhs.c2); }
		friend float3x3 operator *(float3x3 lhs, float3x3 rhs) { return float3x3(lhs.c0 * rhs.c0, lhs.c1 * rhs.c1, lhs.c2 * rhs.c2); }
		friend float3x3 operator *(float3x3 lhs, float rhs) { return float3x3(lhs.c0 * rhs, lhs.c1 * rhs, lhs.c2 * rhs); }
		friend float3x3 operator *(float lhs, float3x3 rhs) { return float3x3(lhs * rhs.c0, lhs * rhs.c1, lhs * rhs.c2); }
		friend float3x3 operator /(float3x3 lhs, float3x3 rhs) { return float3x3(lhs.c0 / rhs.c0, lhs.c1 / rhs.c1, lhs.c2 / rhs.c2); }

		friend float3x3 operator -(float3x3 val) { return float3x3(-val.c0, -val.c1, -val.c2); }

		friend bool operator ==(float3x3 lhs, float3x3 rhs) { return lhs.c0 == rhs.c0 && lhs.c1 == rhs.c1 && lhs.c2 == rhs.c2; }
		friend bool operator !=(float3x3 lhs, float3x3 rhs) { return lhs.c0 != rhs.c0 || lhs.c1 != rhs.c1 || lhs.c2 != rhs.c2; };

		const float3& operator[](int i) const
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
			default:
				break;
			}
		}
	};


}