#pragma once
#include "fix.h"
#include "fix2.h"
#include "fix4.h"
namespace Mathematica
{
	class fix4x4
	{
	public:
		fix4 c0;
		fix4 c1;
		fix4 c2;
		fix4 c3;

		fix4x4(fix4 col0, fix4 col1, fix4 col2, fix4 col3)
		{
			c0 = col0;
			c1 = col1;
			c2 = col2;
			c3 = col3;
		}

		fix4x4(fix m00, fix m01, fix m02, fix m03,
			fix m10, fix m11, fix m12, fix m13,
			fix m20, fix m21, fix m22, fix m23,
			fix m30, fix m31, fix m32, fix m33)
		{
			c0 = fix4(m00, m10, m20, m30);
			c1 = fix4(m01, m11, m21, m31);
			c2 = fix4(m02, m12, m22, m32);
			c0 = fix4(m03, m13, m23, m33);
		}

		fix4x4(fix v)
		{
			fix4 x = fix4(v, v, v, v);
			c0 = x;
			c1 = x;
			c2 = x;
			c3 = x;
		}

		friend fix4x4 operator +(fix4x4 lhs, fix4x4 rhs) { return fix4x4(lhs.c0 + rhs.c0, lhs.c1 + rhs.c1, lhs.c2 + rhs.c2, lhs.c3 + rhs.c3); }
		friend fix4x4 operator -(fix4x4 lhs, fix4x4 rhs) { return fix4x4(lhs.c0 - rhs.c0, lhs.c1 - rhs.c1, lhs.c2 - rhs.c2, lhs.c3 - rhs.c3); }
		friend fix4x4 operator *(fix4x4 lhs, fix4x4 rhs) { return fix4x4(lhs.c0 * rhs.c0, lhs.c1 * rhs.c1, lhs.c2 * rhs.c2, lhs.c3 * rhs.c3); }
		friend fix4x4 operator *(fix4x4 lhs, fix rhs) { return fix4x4(lhs.c0 * rhs, lhs.c1 * rhs, lhs.c2 * rhs, lhs.c3 * rhs); }
		friend fix4x4 operator *(fix lhs, fix4x4 rhs) { return fix4x4(lhs * rhs.c0, lhs * rhs.c1, lhs * rhs.c2, lhs * rhs.c3); }
		friend fix4x4 operator /(fix4x4 lhs, fix4x4 rhs) { return fix4x4(lhs.c0 / rhs.c0, lhs.c1 / rhs.c1, lhs.c2 / rhs.c2, lhs.c3 / rhs.c3); }

		friend fix4x4 operator -(fix4x4 val) { return fix4x4(-val.c0, -val.c1, -val.c2, -val.c3); }

		friend bool operator ==(fix4x4 lhs, fix4x4 rhs) { return lhs.c0 == rhs.c0 && lhs.c1 == rhs.c1 && lhs.c2 == rhs.c2 && lhs.c3 == rhs.c3; }
		friend bool operator !=(fix4x4 lhs, fix4x4 rhs) { return lhs.c0 != rhs.c0 || lhs.c1 != rhs.c1 || lhs.c2 != rhs.c2 || lhs.c3 != rhs.c3; };

		const fix4& operator[](int i) const
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