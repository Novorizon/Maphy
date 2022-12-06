#pragma once
#include "config.h"
namespace Mathematics
{
	class float2
	{
	public:
		float x;
		float y;

		static const float2 left;
		static const float2 right;
		static const float2 forward;
		static const float2 backward;
		static const float2 one;
		static const float2 one_inverse;
		static const float2 zero;

		float2() { x = 0; y = 0; }
		float2(float a, float b) { x = a; y = b; }
		float2(float a) { x = a; y = a; }

		friend float2 operator +(const float2& a, const float2& b) { return float2(a.x + b.x, a.y + b.y); }
		friend float2 operator -(const float2& a, const float2& b) { return float2(a.x - b.x, a.y - b.y); }
		friend float2 operator -(const float2& a, const float& b) { return  float2(a.x - b, a.y - b); }
		friend float2 operator -(const float& a, const float2& b) { return  float2(a - b.x, a - b.y); }
		friend float2 operator *(const float2& a, const float2& b) { return float2(a.x * b.x, a.y * b.y); }
		friend float2 operator *(const float2& a, const float& b) { return float2(a.x * b, a.y * b); }
		friend float2 operator *(const float& a, const float2& b) { return float2(a * b.x, a * b.y); }
		friend float2 operator /(const float2& a, const float2& b) { return float2(a.x / b.x, a.y / b.y); }

		void operator +=(const float2& a) { x = x + a.x; y = y + a.y; }
		void operator -=(const float2& a) { x = x - a.x; y = y - a.y; }
		void operator *=(const float2& a) { x = x * a.x; y = y * a.y; }
		void operator /=(const float2& a) { x = x / a.x; y = y / a.y; }

		friend float2 operator-(const float2& a) { return float2(-a.x, -a.y); }

		friend bool operator >(float2 a, float2 b) { return a.x > b.y && a.y > b.y; }
		friend bool operator <(float2 a, float2 b) { return a.x < b.y&& a.y < b.y; }
		friend bool operator >=(float2 a, float2 b) { return a.x >= b.y && a.y >= b.y; }
		friend bool operator <=(float2 a, float2 b) { return a.x <= b.y && a.y <= b.y; }
		friend bool operator ==(float2 a, float2 b) { return a.x == b.y && a.y == b.y; }
		friend bool operator !=(float2 a, float2 b) { return a.x != b.y || a.y != b.y; }

		friend float2 operator >>(float2 a, int32_t amount) { return(a >> amount, a >> amount); }
		friend float2 operator <<(float2 a, int32_t amount) { return(a << amount, a << amount); }


		const float& operator[](int i) const
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
			ss << "(" << x << "," << y << ")";
			std::string out = ss.str();

			return out;
		}
		//friend float2 xyy() { return float2(x, y, y); }
	};


}

