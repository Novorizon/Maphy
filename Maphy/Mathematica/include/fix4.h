#pragma once
#include "fix.h"

namespace Mathematica
{
	class fix4
	{
	public:
		fix x;
		fix y;
		fix z;
		fix w;

		fix4()
		{
		}

		fix4(fix a, fix b, fix c, fix d)
		{
			x.value = a.value;
			y.value = b.value;
			z.value = c.value;
			w.value = d.value;
		}

		fix4(fix a)
		{
			x.value = a.value;
			y.value = a.value;
			z.value = a.value;
			w.value = a.value;
		}

		friend fix4 operator +(const fix4& a, const fix4& b) { return fix4(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w); }
		friend fix4 operator -(const fix4& a, const fix4& b) { return fix4(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w); }
		friend fix4 operator -(const fix4& a, const fix& b) { return  fix4(a.x - b, a.y - b, a.z - b, a.w - b); }
		friend fix4 operator -(const fix& a, const fix4& b) { return  fix4(a - b.x, a - b.y, a - b.z, a - b.w); }
		friend fix4 operator *(const fix4& a, const fix4& b) { return fix4(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w); }
		friend fix4 operator *(const fix4& a, const fix& b) { return fix4(a.x * b, a.y * b, a.z * b, a.w * b); }
		friend fix4 operator *(const fix& a, const fix4& b) { return fix4(a * b.x, a * b.y, a * b.z, a * b.w); }
		friend fix4 operator /(const fix4& a, const fix4& b) { return fix4(a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w); }

		void operator +=(const fix4& a) { x = x + a.x; y = y + a.y; z = z + a.z; w = w + a.w; }
		void operator -=(const fix4& a) { x = x - a.x; y = y - a.y; z = z - a.z; w = w - a.w; }
		void operator *=(const fix4& a) { x = x * a.x; y = y * a.y; z = z * a.z;  w = w * a.w; }
		void operator /=(const fix4& a) { x = x / a.x; y = y / a.y; z = z / a.z;  w = w / a.w; }

		friend fix4 operator-(const fix4& a) { return fix4(-a.x, -a.y, -a.z, -a.w); }

		friend bool operator ==(fix4 a, fix4 b) { return a.x == b.x && a.y == b.y && a.z == b.z && a.w == b.w; }
		friend bool operator !=(fix4 a, fix4 b) { return a.x != b.y || a.y != b.y || a.z != b.z || a.w != b.w; }

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
			case 3:
				return w;
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
			ss << "(" << (x.value >> PRECISION) << "," << (y.value >> PRECISION) << "," << (z.value >> PRECISION) << "," << (w.value >> PRECISION) << ")";
			std::string out = ss.str();

			return out;
		}
		//friend fix4* xy(fix4 a) {
		//  fix4* result; 
		//  result->x = a.x; 
		//  result->y=a. y; 
		//  return result; }
		//};

		//fix3 xyz() { return fix3(x, y, z); }
	};
}