#pragma once
#include "fix.h"

namespace Mathematica
{
	class fix2
	{
	public:
		fix x;
		fix y;

		static const fix2 left;
		static const fix2 right;
		static const fix2 forward;
		static const fix2 backward;
		static const fix2 one;
		static const fix2 one_inverse;
		static const fix2 zero;

		fix2() { x = 0; y = 0; }

		fix2(fix a, fix b) { x.value = a.value; y.value = b.value; }
		fix2(fix a) { x.value = a.value; y.value = a.value; }

		friend fix2 operator +(const fix2& a, const fix2& b) { return fix2(a.x + b.x, a.y + b.y); }
		friend fix2 operator -(const fix2& a, const fix2& b) { return fix2(a.x - b.x, a.y - b.y); }
		friend fix2 operator -(const fix2& a, const fix& b) { return  fix2(a.x - b, a.y - b); }
		friend fix2 operator -(const fix& a, const fix2& b) { return  fix2(a - b.x, a - b.y); }
		friend fix2 operator *(const fix2& a, const fix2& b) { return fix2(a.x * b.x, a.y * b.y); }
		friend fix2 operator *(const fix2& a, const fix& b) { return fix2(a.x * b, a.y * b); }
		friend fix2 operator *(const fix& a, const fix2& b) { return fix2(a * b.x, a * b.y); }
		friend fix2 operator /(const fix2& a, const fix2& b) { return fix2(a.x / b.x, a.y / b.y); }

		void operator +=(const fix2& a) { x = x + a.x; y = y + a.y; }
		void operator -=(const fix2& a) { x = x - a.x; y = y - a.y; }
		void operator *=(const fix2& a) { x = x * a.x; y = y * a.y; }
		void operator /=(const fix2& a) { x = x / a.x; y = y / a.y; }

		friend fix2 operator-(const fix2& a) { return fix2(-a.x, -a.y); }

		friend bool operator >(fix2 a, fix2 b) { return a.x > b.y && a.y > b.y; }
		friend bool operator <(fix2 a, fix2 b) { return a.x < b.y&& a.y < b.y; }
		friend bool operator >=(fix2 a, fix2 b) { return a.x >= b.y && a.y >= b.y; }
		friend bool operator <=(fix2 a, fix2 b) { return a.x <= b.y && a.y <= b.y; }
		friend bool operator ==(fix2 a, fix2 b) { return a.x == b.y && a.y == b.y; }
		friend bool operator !=(fix2 a, fix2 b) { return a.x != b.y || a.y != b.y; }

		friend fix2 operator >>(fix2 a, int32_t amount) { return(a.x >> amount, a.y >> amount); }
		friend fix2 operator <<(fix2 a, int32_t amount) { return(a.x << amount, a.y << amount); }

		int64_t GetHashCode() { return (x.value * 397) ^ y.value; }

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
			default:
				break;
			}
		}


		std::string ToString()const
		{
			std::stringstream ss;
			ss << "(" << (x.value >> PRECISION) << "," << (y.value >> PRECISION) << ")";
			std::string out = ss.str();

			return out;
		}
		//friend fix3 xyy() { return fix3(x, y, y); }
	};


}

