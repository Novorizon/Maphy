#pragma once
#include "define.h"

namespace Mathematics
{
	class float4
	{
	public:
		float x;
		float y;
		float z;
		float w;

		float4()
		{
		}

		float4(float a, float b, float c, float d)
		{
			x = a;
			y = b;
			z = c;
			w = d;
		}

		float4(float a)
		{
			x = a;
			y = a;
			z = a;
			w = a;
		}

		friend float4 operator +(const float4& a, const float4& b) { return float4(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w); }
		friend float4 operator -(const float4& a, const float4& b) { return float4(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w); }
		friend float4 operator -(const float4& a, const float& b) { return  float4(a.x - b, a.y - b, a.z - b, a.w - b); }
		friend float4 operator -(const float& a, const float4& b) { return  float4(a - b.x, a - b.y, a - b.z, a - b.w); }
		friend float4 operator *(const float4& a, const float4& b) { return float4(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w); }
		friend float4 operator *(const float4& a, const float& b) { return float4(a.x * b, a.y * b, a.z * b, a.w * b); }
		friend float4 operator *(const float& a, const float4& b) { return float4(a * b.x, a * b.y, a * b.z, a * b.w); }
		friend float4 operator /(const float4& a, const float4& b) { return float4(a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w); }

		void operator +=(const float4& a) { x = x + a.x; y = y + a.y; z = z + a.z; w = w + a.w; }
		void operator -=(const float4& a) { x = x - a.x; y = y - a.y; z = z - a.z; w = w - a.w; }
		void operator *=(const float4& a) { x = x * a.x; y = y * a.y; z = z * a.z;  w = w * a.w; }
		void operator /=(const float4& a) { x = x / a.x; y = y / a.y; z = z / a.z;  w = w / a.w; }

		friend float4 operator-(const float4& a) { return float4(-a.x, -a.y, -a.z, -a.w); }

		friend bool operator >=(float4 a, float4 b) { return a.x >= b.y && a.y >= b.y && a.z >= b.z && a.w >= b.w; }
		friend bool operator <=(float4 a, float4 b) { return a.x <= b.y && a.y <= b.y && a.z <= b.z && a.w <= b.w; }
		friend bool operator ==(float4 a, float4 b) { return a.x == b.x && a.y == b.y && a.z == b.z && a.w == b.w; }
		friend bool operator !=(float4 a, float4 b) { return a.x != b.y || a.y != b.y || a.z != b.z || a.w != b.w; }

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
			case 3:
				return w;
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
		//friend float4* xy(float4 a) {
		//  float4* result; 
		//  result->x = a.x; 
		//  result->y=a. y; 
		//  return result; }
		//};

		//float3 xyz() { return float3(x, y, z); }
	};
}