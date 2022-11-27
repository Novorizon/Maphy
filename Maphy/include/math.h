#pragma once
#include "common.h"
namespace Mathematica
{
	class math
	{
	public:

		const fix PI = fix::Raw(205887L);
		const fix PI2 = PI * 2;
		const fix PI2rcp = 1 / PI2;
		const fix Deg2Rad = fix::Raw(1144L);
		const fix Rad2Deg = fix::Raw(3754936L);

		const fix Ln2 = fix::Raw(45426);
		const fix Ln10 = 2.3025850929940456840179914547;
		const fix Lnr = 0.2002433314278771112016301167;
		const fix Epsilon = fix::Raw(1);
		const fix E = fix::Raw(178145L);

		static fix max(const fix& x, const  fix& y) { return x > y ? x : y; }
		static fix2 max(const fix2 x, const  fix2 y) { return  fix2(max(x.x, y.x), max(x.y, y.y)); }
		static fix3 max(const fix3 x, const  fix3 y) { return  fix3(max(x.x, y.x), max(x.y, y.y), max(x.z, y.z)); }

		static fix min(const fix& x, const fix& y) { return x > y ? y : x; }
		static fix2 min(const fix2& x, const  fix2& y) { return  fix2(min(x.x, y.x), min(x.y, y.y)); }
		static fix3 min(const fix3& x, const  fix3& y) { return  fix3(min(x.x, y.x), min(x.y, y.y), min(x.z, y.z)); }


		static fix abs(const fix& x) { fix result; result.value = (x.value + (x.value >> 63)) ^ (x.value >> 63); return result; }
		static fix2 abs(const fix2& x) { return fix2(abs(x.x), abs(x.y)); }
		static fix3 abs(const fix3& x) { return fix3(abs(x.x), abs(x.y), abs(x.z)); }
		static fix4 abs(const fix4& x) { return fix4(abs(x.x), abs(x.y), abs(x.z), abs(x.w)); }

		static fix sign(const fix& x) { return fix(x.value >> 63); }
		static fix2 sign(const fix2& x) { return fix2(sign(x.x), sign(x.y)); }
		static fix3 sign(const fix3& x) { return fix3(sign(x.x), sign(x.y), sign(x.z)); }
		static fix4 sign(const fix4& x) { return fix4(sign(x.x), sign(x.y), sign(x.z), sign(x.w)); }

		static fix trunc(fix x)
		{
			x.value = x.value >> PRECISION << PRECISION;
			if (sign(x) != 0)
				x.value = x.value + (1 << PRECISION);
			return x;
		}


		static fix sqrt(fix x)
		{
			if (x.value < 0)
				return MinValue;

			if (x.value == 0)
				return Zero;

			fix a = x;
			long b = (a.value >> 2) + 1L;
			a.value = (b + (x.value << PRECISION) / a.value) >> 1;
			while (a.value < b)
			{
				b = a.value;
				a.value = (a.value + (x.value << PRECISION) / a.value) >> 1;
			}
			return a;
		}

		static fix2 sqrt(fix2 x) { return fix2(sqrt(x.x), sqrt(x.y)); }
		static fix3 sqrt(fix3 x) { return fix3(sqrt(x.x), sqrt(x.y), sqrt(x.z)); }
		static fix4 sqrt(fix4 x) { return fix4(sqrt(x.x), sqrt(x.y), sqrt(x.z), sqrt(x.w)); }


		static fix rsqrt(fix x) { return 1 / sqrt(x); }
		static fix2 rsqrt(fix2 x) { return fix2(rsqrt(x.x), rsqrt(x.y)); }
		static fix3 rsqrt(fix3 x) { return fix3(rsqrt(x.x), rsqrt(x.y), rsqrt(x.z)); }
		static fix4 rsqrt(fix4 x) { return fix4(sqrt(x.x), sqrt(x.y), sqrt(x.z), sqrt(x.w)); }

		static fix distance(fix x, fix y) { return abs(y - x); }
		static fix distance(fix2 x, fix2 y) { return length(y - x); }
		static fix distance(fix3 x, fix3 y) { return length(y - x); }
		static fix distance(fix4 x, fix4 y) { return length(y - x); }

		static fix distancesq(fix x, fix y) { return (y - x) * (y - x); }
		static fix distancesq(fix2 x, fix2 y) { return lengthsq(y - x); }
		static fix distancesq(fix3 x, fix3 y) { return lengthsq(y - x); }
		static fix distancesq(fix4 x, fix4 y) { return lengthsq(y - x); }

		static fix length(fix x) { return abs(x); }
		static fix length(fix2 x) { return sqrt(dot(x, x)); }
		static fix length(fix3 x) { return sqrt(dot(x, x)); }
		static fix length(fix4 x) { return sqrt(dot(x, x)); }

		static fix lengthsq(fix x) { return x * x; }
		static fix lengthsq(fix2 x) { return dot(x, x); }
		static fix lengthsq(fix3 x) { return dot(x, x); }
		static fix lengthsq(fix4 x) { return dot(x, x); }

		static fix dot(fix x, fix y) { return x * y; }
		static fix dot(fix2 x, fix2 y) { return x.x * y.x + x.y * y.y; }
		static fix dot(fix3 x, fix3 y) { return x.x * y.x + x.y * y.y + x.z * y.z; }
		static fix dot(fix4 x, fix4 y) { return x.x * y.x + x.y * y.y + x.z * y.z + x.w * y.w; }

		static fix rcp(fix x) { return One / x; }
		static fix2 rcp(fix2 x) { return One / x; }
		static fix3 rcp(fix3 x) { return One / x; }
		static fix4 rcp(fix4 x) { return One / x; }

		const fix radians(fix x) { return x * Deg2Rad; }


		const fix degrees(fix x) { return x * Rad2Deg; }


		static fix2 normalize(fix2 x) { return rsqrt(dot(x, x)) * x; }
		static fix3 normalize(fix3 x) { return rsqrt(dot(x, x)) * x; }
		static fix4 normalize(fix4 x) { return rsqrt(dot(x, x)) * x; }


		static fix cross(fix2 x, fix2 y) { return x.x * y.y - x.y * y.x; }
		static fix3 cross(fix3 x, fix3 y) { return (x * y.yzx() - x.yzx() * y).yzx(); }


		static fix lerp(fix x, fix y, fix s) { return x + s * (y - x); }
		static fix2 lerp(fix2 x, fix2 y, fix s) { return x + s * (y - x); }
		static fix3 lerp(fix3 x, fix3 y, fix s) { return x + s * (y - x); }
		static fix4 lerp(fix4 x, fix4 y, fix s) { return x + s * (y - x); }

		 const fix sin(fix x) { /*x.value %= PI2.value; x *= PI2rcp; x.value = trigonometric.sin(x.value);*/ return x; }
		 const fix2 sin(fix2 x) { return  fix2(sin(x.x), sin(x.y)); }
		 const fix3 sin(fix3 x) { return  fix3(sin(x.x), sin(x.y), sin(x.z)); }
		 const fix4 sin(fix4 x) { return  fix4(sin(x.x), sin(x.y), sin(x.z), sin(x.w)); }

		 static fix acos(fix x) {  return x; }
		 static fix2 acos(fix2 x) { return  fix2(acos(x.x), acos(x.y)); }
		 static fix3 acos(fix3 x) { return  fix3(acos(x.x), acos(x.y), acos(x.z)); }
		 static fix4 acos(fix4 x) { return  fix4(acos(x.x), acos(x.y), acos(x.z), acos(x.w)); }
	};

}