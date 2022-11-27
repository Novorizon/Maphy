#pragma once
#include "common.h"
#include "fix2.h"
#include "fix3.h"
#include "fix4.h"
#include "fix3x3.h"
#include "trigonometric.h"
namespace Mathematica
{
	class math
	{
	public:

		static const fix PI;
		static const fix PI2;
		static const fix PI2rcp;
		static const fix Deg2Rad;
		static const fix Rad2Deg;

		static const fix Ln2;
		static const fix Ln10;
		static const fix Lnr;
		static const fix Epsilon;
		static const fix E;

		static	const fix atan2Number1;
		static	const fix atan2Number2;
		static	const fix atan2Number3;
		static	const fix atan2Number4;
		static	const fix atan2Number5;
		static	const fix atan2Number6;
		static	const fix atan2Number7;
		static	const fix atan2Number8;

		static fix max(const fix& x, const fix& y) { return x > y ? x : y; }
		static fix2 max(const fix2 x, const fix2& y) { return fix2(max(x.x, y.x), max(x.y, y.y)); }
		static fix3 max(const fix3 x, const fix3& y) { return fix3(max(x.x, y.x), max(x.y, y.y), max(x.z, y.z)); }
		static fix4 max(const fix4 x, const fix4& y) { return fix4(max(x.x, y.x), max(x.y, y.y), max(x.z, y.z), max(x.w, y.w)); }

		static fix min(const fix& x, const fix& y) { return x > y ? y : x; }
		static fix2 min(const fix2& x, const fix2& y) { return fix2(min(x.x, y.x), min(x.y, y.y)); }
		static fix3 min(const fix3& x, const fix3& y) { return fix3(min(x.x, y.x), min(x.y, y.y), min(x.z, y.z)); }
		static fix4 min(const fix4 x, const fix4& y) { return fix4(min(x.x, y.x), min(x.y, y.y), min(x.z, y.z), min(x.w, y.w)); }

		static fix abs(const fix& x) { fix result; result.value = (x.value + (x.value >> 63)) ^ (x.value >> 63); return result; }
		static fix2 abs(const fix2& x) { return fix2(abs(x.x), abs(x.y)); }
		static fix3 abs(const fix3& x) { return fix3(abs(x.x), abs(x.y), abs(x.z)); }
		static fix4 abs(const fix4& x) { return fix4(abs(x.x), abs(x.y), abs(x.z), abs(x.w)); }

		static fix sign(const fix& x) { return fix(x.value >> 63); }
		static fix2 sign(const fix2& x) { return fix2(sign(x.x), sign(x.y)); }
		static fix3 sign(const fix3& x) { return fix3(sign(x.x), sign(x.y), sign(x.z)); }
		static fix4 sign(const fix4& x) { return fix4(sign(x.x), sign(x.y), sign(x.z), sign(x.w)); }

		static fix trunc(const fix& x);
		static fix frac(const fix& x) { return abs(x - trunc(x)); }

		static fix floor(const fix& x) { int64_t value = (x.value >> PRECISION) << PRECISION; return fix(value); }
		static fix2 floor(const fix2& x) { return fix2(floor(x.x), floor(x.y)); }
		static fix3 floor(const fix3& x) { return fix3(floor(x.x), floor(x.y), floor(x.z)); }
		static fix4 floor(const fix4& x) { return fix4(floor(x.x), floor(x.y), floor(x.z), floor(x.w)); }

		static fix ceil(const fix& value);
		static fix2 ceil(const fix2& x) { return fix2(ceil(x.x), ceil(x.y)); }
		static fix3 ceil(const fix3& x) { return fix3(ceil(x.x), ceil(x.y), ceil(x.z)); }
		static fix4 ceil(const fix4& x) { return fix4(ceil(x.x), ceil(x.y), ceil(x.z), ceil(x.w)); }

		static fix round(const fix& x);//TODO
		static fix2 round(const fix2& x) { return fix2(round(x.x), round(x.y)); }
		static fix3 round(const fix3& x) { return fix3(round(x.x), round(x.y), round(x.z)); }
		static fix4 round(const fix4& x) { return fix4(round(x.x), round(x.y), round(x.z), round(x.w)); }

		static fix mod(const fix& x, const fix& y) { int64_t value = x.value == MIN_VALUE && y.value == -1 ? 0 : x.value % y.value; return fix(value); }

		static fix pow(const fix& x, const int& n);//TODO

		/// 以x为底，y的对数
		static fix log(const fix& x, const fix& y) { return ln(y) / ln(x); }
		static fix2 log(const fix2& x) { return fix2(log(x.x), log(x.y)); }
		static fix3 log(const fix3& x) { return fix3(log(x.x), log(x.y), log(x.z)); }
		static fix4 log(const fix4& x) { return fix4(log(x.x), log(x.y), log(x.z), log(x.w)); }

		/// 以2为底，x的对数
		static fix log(const fix& x) { return ln(x) / Ln2; }
		/// 以2为底，x的对数
		static fix log2(const fix& x) { return ln(x) / Ln2; }
		/// 以10为底，x的对数
		static fix log10(const fix& x) { return ln(x) / Ln10; }
		/// 以自然对数e为底，x的对数		
		static fix ln(const fix& x);//TODO


		static fix sqrt(const fix& x);
		static fix2 sqrt(const fix2& x) { return fix2(sqrt(x.x), sqrt(x.y)); }
		static fix3 sqrt(const fix3& x) { return fix3(sqrt(x.x), sqrt(x.y), sqrt(x.z)); }
		static fix4 sqrt(const fix4& x) { return fix4(sqrt(x.x), sqrt(x.y), sqrt(x.z), sqrt(x.w)); }

		static fix rsqrt(const fix& x) { return 1 / sqrt(x); }
		static fix2 rsqrt(const fix2& x) { return fix2(rsqrt(x.x), rsqrt(x.y)); }
		static fix3 rsqrt(const fix3& x) { return fix3(rsqrt(x.x), rsqrt(x.y), rsqrt(x.z)); }
		static fix4 rsqrt(const fix4& x) { return fix4(sqrt(x.x), sqrt(x.y), sqrt(x.z), sqrt(x.w)); }

		static fix distance(const fix& x, const fix& y) { return abs(y - x); }
		static fix distance(const fix2& x, const fix2& y) { return length(y - x); }
		static fix distance(const fix3& x, const fix3& y) { return length(y - x); }
		static fix distance(const fix4& x, const fix4& y) { return length(y - x); }

		static fix distancesq(const fix& x, const fix& y) { return (y - x) * (y - x); }
		static fix distancesq(const fix2& x, const fix2& y) { return lengthsq(y - x); }
		static fix distancesq(const fix3& x, const fix3& y) { return lengthsq(y - x); }
		static fix distancesq(const fix4& x, const fix4& y) { return lengthsq(y - x); }

		static fix length(const fix& x) { return abs(x); }
		static fix length(const fix2& x) { return sqrt(dot(x, x)); }
		static fix length(const fix3& x) { return sqrt(dot(x, x)); }
		static fix length(const fix4& x) { return sqrt(dot(x, x)); }

		static fix lengthsq(const fix& x) { return x * x; }
		static fix lengthsq(const fix2& x) { return dot(x, x); }
		static fix lengthsq(const fix3& x) { return dot(x, x); }
		static fix lengthsq(const fix4& x) { return dot(x, x); }

		static fix rcp(const fix& x) { return One / x; }
		static fix2 rcp(const fix2& x) { return One / x; }
		static fix3 rcp(const fix3& x) { return One / x; }
		static fix4 rcp(const fix4& x) { return One / x; }

		static fix radians(const fix& x) { return x * Deg2Rad; }
		static fix2 radians(const fix2& x) { return x * Deg2Rad; }
		static fix3 radians(const fix3& x) { return x * Deg2Rad; }
		static fix4 radians(const fix4& x) { return x * Deg2Rad; }

		static fix degrees(const fix& x) { return x * Rad2Deg; }
		static fix2 degrees(const fix2& x) { return x * Rad2Deg; }
		static fix3 degrees(const fix3& x) { return x * Rad2Deg; }
		static fix4 degrees(const fix4& x) { return x * Rad2Deg; }

		static fix2 normalize(const fix2& x) { return rsqrt(dot(x, x)) * x; }
		static fix3 normalize(const fix3& x) { return rsqrt(dot(x, x)) * x; }
		static fix4 normalize(const fix4& x) { return rsqrt(dot(x, x)) * x; }

		static fix dot(const fix& x, const fix& y) { return x * y; }
		static fix dot(const fix2& x, const fix2& y) { return x.x * y.x + x.y * y.y; }
		static fix dot(const fix3& x, const fix3& y) { return x.x * y.x + x.y * y.y + x.z * y.z; }
		static fix dot(const fix4& x, const fix4& y) { return x.x * y.x + x.y * y.y + x.z * y.z + x.w * y.w; }

		static fix cross(const fix2& x, const fix2& y) { return x.x * y.y - x.y * y.x; }
		static fix3 cross(const fix3& x, const fix3& y) { return (x * y.yzx() - x.yzx() * y).yzx(); }

		static fix lerp(const fix& x, const fix y, const fix s) { return x + s * (y - x); }
		static fix2 lerp(const fix2& x, const fix2 y, const fix s) { return x + s * (y - x); }
		static fix3 lerp(const fix3& x, const fix3 y, const fix s) { return x + s * (y - x); }
		static fix4 lerp(const fix4& x, const fix4 y, const fix s) { return x + s * (y - x); }

		static fix csum(const fix2& x) { return x.x + x.y; }
		static fix csum(const fix3& x) { return x.x + x.y + x.z; }
		static fix csum(const fix4& x) { return x.x + x.y + x.z; }

		static fix2 project(const fix2& x, const fix2& y) { return (dot(x, y) / dot(y, y)) * y; }
		static fix3 project(const fix3& x, const fix3& y) { return (dot(x, y) / dot(y, y)) * y; }
		static fix4 project(const fix4& x, const fix4& y) { return (dot(x, y) / dot(y, y)) * y; }

		static fix3 projectonplane(const fix3& x, fix3 planeNormal) { return x - dot(x, planeNormal) / dot(planeNormal, planeNormal) * planeNormal; }

		/// 入射向量i和法向量n，返回反射向量 r = i - 2.0f * dot(i, n) * n
		static fix2 reflect(const fix2 i, const fix2 n) { return i - 2 * n * dot(i, n); }
		static fix3 reflect(const fix3 i, const fix3 n) { return i - 2 * n * dot(i, n); }
		static fix4 reflect(const fix4 i, const fix4 n) { return i - 2 * n * dot(i, n); }

		/// 入射向量i、法向量n和折射率eta的折射向量.
		static fix2 refract(const fix2 i, const fix2 n, const fix eta) { fix ni = dot(n, i); fix k = 1.0f - eta * eta * (1.0f - ni * ni); return select(fix2(0), eta * i - (eta * ni + sqrt(k)) * n, k >= 0); }
		static fix3 refract(const fix3 i, const fix3 n, const fix eta) { fix ni = dot(n, i); fix k = 1.0f - eta * eta * (1.0f - ni * ni); return select(fix3(0), eta * i - (eta * ni + sqrt(k)) * n, k >= 0); }
		static fix4 refract(const fix4 i, const fix4 n, const fix eta) { fix ni = dot(n, i); fix k = 1 - eta * eta * (1 - ni * ni); return select(fix4(0), eta * i - (eta * ni + sqrt(k)) * n, k >= 0); }

		/// Returns the result of clamping the value x into the interval [a, b], where x, a and b are fix values
		static fix clamp(const fix& x, const fix a, const fix b) { return max(a, min(b, x)); }
		static fix2 clamp(const fix2& x, const fix2 a, const fix2 b) { return max(a, min(b, x)); }
		static fix3 clamp(const fix3& x, const fix3 a, const fix3 b) { return max(a, min(b, x)); }
		static fix4 clamp(const fix4& x, const fix4 a, const fix4 b) { return max(a, min(b, x)); }

		/// 如果x取值小于0，则返回值为0。如果x取值大于1，则返回值为1。若x在0到1之间，则直接返回x的值
		static fix saturate(const fix& x) { return clamp(x, 0, 1); }
		static fix2 saturate(const fix2& x) { return clamp(x, fix2(0), fix2(1)); }
		static fix3 saturate(const fix3& x) { return clamp(x, fix3(0), fix3(1)); }
		static fix4 saturate(const fix4& x) { return clamp(x, fix4(0), fix4(1)); }

		/// Computes a step function. Returns 1.0f when x >= y, 0.0f otherwise
		static fix step(fix y, fix x) { return select(0.0f, 1.0f, x >= y); }

		///Returns a smooth Hermite interpolation between 0.0f and 1.0f when x is in [a, b].
		static fix smoothstep(const fix a, const fix b, const fix x) { fix t = saturate((x - a) / (b - a)); return t * t * (3 - (2 * t)); }
		static fix2 smoothstep(const fix2& a, const fix2 b, const fix2 x) { fix2 t = saturate((x - a) / (b - a)); return t * t * (3 - (2 * t)); }
		static fix3 smoothstep(const fix3& a, const fix3 b, const fix3 x) { fix3 t = saturate((x - a) / (b - a)); return t * t * (3 - (2 * t)); }
		static fix4 smoothstep(const fix4& a, const fix4 b, const fix4 x) { fix4 t = saturate((x - a) / (b - a)); return t * t * (3 - (2 * t)); }

		/// 任意一个非0
		static bool any(const fix2& x) { return x.x != 0 || x.y != 0; }
		static bool any(const fix3& x) { return x.x != 0 || x.y != 0 || x.z != 0; }
		static bool any(const fix4& x) { return x.x != 0 || x.y != 0 || x.z != 0 || x.w != 0; }

		/// 所有非0
		static bool all(const fix2& x) { return x.x != 0 && x.y != 0; }
		static bool all(const fix3& x) { return x.x != 0 && x.y != 0 && x.z != 0; }
		static bool all(const fix4& x) { return x.x != 0 && x.y != 0 && x.z != 0 && x.w != 0; }

		/// Returns b if c is true, a otherwise
		static fix select(const fix& a, const fix& b, const bool c) { return c ? b : a; }
		static fix2 select(const fix2& a, const fix2& b, const bool c) { return c ? b : a; }
		static fix3 select(const fix3& a, const fix3& b, const bool c) { return c ? b : a; }
		static fix4 select(const fix4& a, const fix4& b, const bool c) { return c ? b : a; }

		static fix sin(const fix& x) { fix result; result.value = x.value % PI2.value; result *= PI2rcp; result.value = trigonometric::sin(result.value); return result; }
		static fix2 sin(const fix2& x) { return fix2(sin(x.x), sin(x.y)); }
		static fix3 sin(const fix3& x) { return fix3(sin(x.x), sin(x.y), sin(x.z)); }
		static fix4 sin(const fix4& x) { return fix4(sin(x.x), sin(x.y), sin(x.z), sin(x.w)); }

		static fix cos(const fix& x) { fix result; result.value = x.value % PI2.value; result *= PI2rcp; result.value = trigonometric::cos(result.value); return result; }
		static fix2 cos(const fix2& x) { return fix2(cos(x.x), cos(x.y)); }
		static fix3 cos(const fix3& x) { return fix3(cos(x.x), cos(x.y), cos(x.z)); }
		static fix4 cos(const fix4& x) { return fix4(cos(x.x), cos(x.y), cos(x.z), cos(x.w)); }

		static void sincos(const fix& x, fix& s, fix& c) { s = sin(x); c = cos(x); }
		static void sincos(const fix2& x, fix2& s, fix2& c) { s = sin(x); c = cos(x); }
		static void sincos(const fix3& x, fix3& s, fix3& c) { s = sin(x); c = cos(x); }
		static void sincos(const fix4& x, fix4& s, fix4& c) { s = sin(x); c = cos(x); }

		static fix tan(const fix& x) { fix result; result.value = x.value % PI2.value; result *= PI2rcp; result.value = trigonometric::tan(result.value); return result; }
		static fix2 tan(const fix2& x) { return fix2(tan(x.x), tan(x.y)); }
		static fix3 tan(const fix3& x) { return fix3(tan(x.x), tan(x.y), tan(x.z)); }
		static fix4 tan(const fix4& x) { return fix4(tan(x.x), tan(x.y), tan(x.z), tan(x.w)); }

		static fix asin(const fix& x) { fix result; result.value = x.value + ONE; result *= _0_5; result.value = trigonometric::asin(result.value); return result; }
		static fix2 asin(const fix2& x) { return fix2(asin(x.x), asin(x.y)); }
		static fix3 asin(const fix3& x) { return fix3(asin(x.x), asin(x.y), asin(x.z)); }
		static fix4 asin(const fix4& x) { return fix4(asin(x.x), asin(x.y), asin(x.z), asin(x.w)); }

		static fix acos(const fix& x) { return x; }
		static fix2 acos(const fix2& x) { return fix2(acos(x.x), acos(x.y)); }
		static fix3 acos(const fix3& x) { return fix3(acos(x.x), acos(x.y), acos(x.z)); }
		static fix4 acos(const fix4& x) { return fix4(acos(x.x), acos(x.y), acos(x.z), acos(x.w)); }


		static fix atan(const fix& x) { return atan2(x, _1); }
		static fix2 atan(const fix2& x) { return fix2(atan(x.x), atan(x.y)); }
		static fix3 atan(const fix3& x) { return fix3(atan(x.x), atan(x.y), atan(x.z)); }
		static fix4 atan(const fix4& x) { return fix4(atan(x.x), atan(x.y), atan(x.z), atan(x.w)); }


		static fix atan2(const fix& y, const fix& x);
		static fix2 atan2(const fix2& y, const fix2& x) { return fix2(atan2(y.x, x.x), atan2(y.y, x.y)); }
		static fix3 atan2(const fix3& y, const fix3& x) { return fix3(atan2(y.x, x.x), atan2(y.y, x.y), atan2(y.z, x.z)); }
		static fix4 atan2(const fix4& y, const fix4& x) { return fix4(atan2(y.x, x.x), atan2(y.y, x.y), atan2(y.z, x.z), atan2(y.w, x.w)); }

	private:
		static fix Logarithm(const fix& x);
	};
}