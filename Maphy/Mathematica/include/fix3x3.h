#pragma once
#include "fix.h"
#include "fix2.h"
#include "fix3.h"
namespace Mathematica
{
	class fix3x3
	{
	public:
		fix3 c0;
		fix3 c1;
		fix3 c2;

		fix3x3(fix3 col0, fix3 col1, fix3 col2)
		{
			c0 = col0;
			c1 = col1;
			c2 = col2;
		}

		fix3x3(fix m00, fix m01, fix m02,
			fix m10, fix m11, fix m12,
			fix m20, fix m21, fix m22)
		{
			c0 = fix3(m00, m10, m20);
			c1 = fix3(m01, m11, m21);
			c2 = fix3(m02, m12, m22);
		}

		fix3x3(fix v)
		{
			fix3 x = fix3(v, v, v);
			c0 = x;
			c1 = x;
			c2 = x;
		}

		friend fix3x3 operator +(fix3x3 lhs, fix3x3 rhs) { return fix3x3(lhs.c0 + rhs.c0, lhs.c1 + rhs.c1, lhs.c2 + rhs.c2); }
		friend fix3x3 operator -(fix3x3 lhs, fix3x3 rhs) { return fix3x3(lhs.c0 - rhs.c0, lhs.c1 - rhs.c1, lhs.c2 - rhs.c2); }
		friend fix3x3 operator *(fix3x3 lhs, fix3x3 rhs) { return fix3x3(lhs.c0 * rhs.c0, lhs.c1 * rhs.c1, lhs.c2 * rhs.c2); }
		friend fix3x3 operator *(fix3x3 lhs, fix rhs) { return fix3x3(lhs.c0 * rhs, lhs.c1 * rhs, lhs.c2 * rhs); }
		friend fix3x3 operator *(fix lhs, fix3x3 rhs) { return fix3x3(lhs * rhs.c0, lhs * rhs.c1, lhs * rhs.c2); }
		friend fix3x3 operator /(fix3x3 lhs, fix3x3 rhs) { return fix3x3(lhs.c0 / rhs.c0, lhs.c1 / rhs.c1, lhs.c2 / rhs.c2); }

		friend fix3x3 operator -(fix3x3 val) { return fix3x3(-val.c0, -val.c1, -val.c2); }

		friend bool operator ==(fix3x3 lhs, fix3x3 rhs) { return lhs.c0 == rhs.c0 && lhs.c1 == rhs.c1 && lhs.c2 == rhs.c2; }
		friend bool operator !=(fix3x3 lhs, fix3x3 rhs) { return lhs.c0 != rhs.c0 || lhs.c1 != rhs.c1 || lhs.c2 != rhs.c2; };

		const fix3& operator[](int i) const
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