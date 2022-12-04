#pragma once
#include "fix.h"

namespace Mathematica
{
	class fix3
	{
	public:
		fix x;
		fix y;
		fix z;

		fix3()
		{
		}

		fix3(fix a, fix b, fix c)
		{
			x.value = a.value;
			y.value = b.value;
			z.value = c.value;
		}

		fix3(fix a)
		{
			x.value = a.value;
			y.value = a.value;
			z.value = a.value;
		}

		friend fix3 operator +(const fix3& a, const fix3& b) { return fix3(a.x + b.x, a.y + b.y, a.z + b.z); }
		friend fix3 operator -(const fix3& a, const fix3& b) { return fix3(a.x - b.x, a.y - b.y, a.z - b.z); }
		friend fix3 operator -(const fix3& a, const fix& b) { return  fix3(a.x - b, a.y - b, a.z - b); }
		friend fix3 operator -(const fix& a, const fix3& b) { return  fix3(a - b.x, a - b.y, a - b.z); }
		friend fix3 operator *(const fix3& a, const fix3& b) { return fix3(a.x * b.x, a.y * b.y, a.z * b.z); }
		friend fix3 operator *(const fix3& a, const fix& b) { return fix3(a.x * b, a.y * b, a.z * b); }
		friend fix3 operator *(const fix& a, const fix3& b) { return fix3(a * b.x, a * b.y, a * b.z); }
		friend fix3 operator /(const fix3& a, const fix3& b) { return fix3(a.x / b.x, a.y / b.y, a.z / b.z); }

		void operator +=(const fix3& a) { x = x + a.x; y = y + a.y; z = z + a.z; }
		void operator -=(const fix3& a) { x = x - a.x; y = y - a.y; z = z - a.z; }
		void operator *=(const fix3& a) { x = x * a.x; y = y * a.y; z = z * a.z; }
		void operator /=(const fix3& a) { x = x / a.x; y = y / a.y; z = z / a.z; }

		friend fix3 operator-(const fix3& a) { return fix3(-a.x, -a.y, -a.z); }

		friend bool operator ==(fix3 a, fix3 b) { return a.x == b.y && a.y == b.y && a.z == b.z; }
		friend bool operator !=(fix3 a, fix3 b) { return a.x != b.y || a.y != b.y || a.z != b.z; }

		const fix& operator[](int i) const
		{
			switch (i)
			{
			case 0:
				return x;
				break;
			case 1:
				return y;
				break;
			case 2:
				return z;
				break;
			default:
				//fix result = fix::MaxValue;
				//return MaxValue;
				break;
			}
		}

		std::string ToString()const
		{
			std::stringstream ss;
			ss << "(" << (x.value >> PRECISION) << "," << (y.value >> PRECISION) << "," << (z.value >> PRECISION) << ")";
			std::string out = ss.str();

			return out;
		}
		//friend fix3* xy(fix3 a) {
		//  fix3* result; 
		//  result->x = a.x; 
		//  result->y=a. y; 
		//  return result; }
		//};
		fix3 yzx() const { return fix3(y, z, x); }
	};
}