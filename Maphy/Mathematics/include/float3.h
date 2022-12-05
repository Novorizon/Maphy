#pragma once
#include "define.h"

namespace Mathematics
{
	class float3
	{
	public:
		float x;
		float y;
		float z;

		static const float3 left;
		static const float3 right;
		static const float3 up;
		static const float3 down;
		static const float3 forward;
		static const float3 backward;
		static const float3 one;
		static const float3 one_inverse;
		static const float3 zero;
		float3()
		{
			x = 0;
			y = 0;
			z = 0;
		}

		float3(float a, float b, float c)
		{
			x = a;
			y = b;
			z = c;
		}

		float3(float a)
		{
			x = a;
			y = a;
			z = a;
		}

		friend float3 operator +(const float3& a, const float3& b) { return float3(a.x + b.x, a.y + b.y, a.z + b.z); }
		friend float3 operator -(const float3& a, const float3& b) { return float3(a.x - b.x, a.y - b.y, a.z - b.z); }
		friend float3 operator -(const float3& a, const float& b) { return  float3(a.x - b, a.y - b, a.z - b); }
		friend float3 operator -(const float& a, const float3& b) { return  float3(a - b.x, a - b.y, a - b.z); }
		friend float3 operator *(const float3& a, const float3& b) { return float3(a.x * b.x, a.y * b.y, a.z * b.z); }
		friend float3 operator *(const float3& a, const float& b) { return float3(a.x * b, a.y * b, a.z * b); }
		friend float3 operator *(const float& a, const float3& b) { return float3(a * b.x, a * b.y, a * b.z); }
		friend float3 operator /(const float3& a, const float3& b) { return float3(a.x / b.x, a.y / b.y, a.z / b.z); }

		void operator +=(const float3& a) { x = x + a.x; y = y + a.y; z = z + a.z; }
		void operator -=(const float3& a) { x = x - a.x; y = y - a.y; z = z - a.z; }
		void operator *=(const float3& a) { x = x * a.x; y = y * a.y; z = z * a.z; }
		void operator /=(const float3& a) { x = x / a.x; y = y / a.y; z = z / a.z; }

		friend float3 operator-(const float3& a) { return float3(-a.x, -a.y, -a.z); }

		friend bool operator >=(float3 a, float3 b) { return a.x >= b.y && a.y >= b.y && a.z >= b.z; }
		friend bool operator <=(float3 a, float3 b) { return a.x <= b.y && a.y <= b.y && a.z <= b.z; }
		friend bool operator ==(float3 a, float3 b) { return a.x == b.y && a.y == b.y && a.z == b.z; }
		friend bool operator !=(float3 a, float3 b) { return a.x != b.y || a.y != b.y || a.z != b.z; }

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
			case 2:
				return z;
				break;
			default:
				//float result = float::MaxValue;
				//return MaxValue;
				break;
			}
		}

		std::string ToString()const
		{
			std::stringstream ss;
			ss << "(" << x << "," << y << "," << z << ")";
			std::string out = ss.str();

			return out;
		}
		//friend float3* xy(float3 a) {
		//  float3* result; 
		//  result->x = a.x; 
		//  result->y=a. y; 
		//  return result; }
		//};
		float3 yzx() const { return float3(y, z, x); }
	};
}