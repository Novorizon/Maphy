#pragma once
#include "config.h"
#include "float2.h"
#include "float3.h"
#include "float4.h"
#include "float4x4.h"
//#include "quaternion.h"
//#include "float3x3.h"
//#include "float4x4.h"
namespace Mathematics
{
	class quaternion;
	class math
	{
	public:

		static const float PI;
		static const float PI2;
		static const float PI2rcp;
		static const float Deg2Rad;
		static const float Rad2Deg;
		static const float kEpsilonNormalSqrt;

		static const float FLT_MIN_NORMAL;

		/// <summary>Extrinsic rotation order. Specifies in which order rotations around the principal axes (x, y and z) are to be applied.</summary>
		enum RotationOrder
		{
			/// <summary>Extrinsic rotation around the x axis, then around the y axis and finally around the z axis.</summary>
			XYZ,
			/// <summary>Extrinsic rotation around the x axis, then around the z axis and finally around the y axis.</summary>
			XZY,
			/// <summary>Extrinsic rotation around the y axis, then around the x axis and finally around the z axis.</summary>
			YXZ,
			/// <summary>Extrinsic rotation around the y axis, then around the z axis and finally around the x axis.</summary>
			YZX,
			/// <summary>Extrinsic rotation around the z axis, then around the x axis and finally around the y axis.</summary>
			ZXY,
			/// <summary>Extrinsic rotation around the z axis, then around the y axis and finally around the x axis.</summary>
			ZYX,
			/// <summary>Unity default rotation order. Extrinsic Rotation around the z axis, then around the x axis and finally around the y axis.</summary>
			Default = ZXY
		};

		static float max(const float& x, const float& y) { return x > y ? x : y; }
		static float2 max(const float2 x, const float2& y) { return float2(max(x.x, y.x), max(x.y, y.y)); }
		static float3 max(const float3 x, const float3& y) { return float3(max(x.x, y.x), max(x.y, y.y), max(x.z, y.z)); }
		static float4 max(const float4 x, const float4& y) { return float4(max(x.x, y.x), max(x.y, y.y), max(x.z, y.z), max(x.w, y.w)); }

		static float min(const float& x, const float& y) { return x > y ? y : x; }
		static float2 min(const float2& x, const float2& y) { return float2(min(x.x, y.x), min(x.y, y.y)); }
		static float3 min(const float3& x, const float3& y) { return float3(min(x.x, y.x), min(x.y, y.y), min(x.z, y.z)); }
		static float4 min(const float4 x, const float4& y) { return float4(min(x.x, y.x), min(x.y, y.y), min(x.z, y.z), min(x.w, y.w)); }

		static float abs(const float& x) { return asfloat(asuint(x) & 0x7FFFFFFF); }
		static float2 abs(const float2& x) { return float2(abs(x.x), abs(x.y)); }
		static float3 abs(const float3& x) { return float3(abs(x.x), abs(x.y), abs(x.z)); }
		static float4 abs(const float4& x) { return float4(abs(x.x), abs(x.y), abs(x.z), abs(x.w)); }

		static float sign(const float& x) { return (x > 0.0f ? 1.0f : 0.0f) - (x < 0.0f ? 1.0f : 0.0f); }
		static float2 sign(const float2& x) { return float2(sign(x.x), sign(x.y)); }
		static float3 sign(const float3& x) { return float3(sign(x.x), sign(x.y), sign(x.z)); }
		static float4 sign(const float4& x) { return float4(sign(x.x), sign(x.y), sign(x.z), sign(x.w)); }

		static float trunc(const float& x) { return std::trunc(x); }
		static float2 trunc(float2 x) { return  float2(std::trunc(x.x), std::trunc(x.y)); }
		static float3 trunc(float3 x) { return  float3(std::trunc(x.x), std::trunc(x.y), std::trunc(x.z)); }
		static float4 trunc(float4 x) { return  float4(std::trunc(x.x), std::trunc(x.y), std::trunc(x.z), std::trunc(x.w)); }

		static float frac(float x) { return x - floor(x); }
		static float2 frac(float2 x) { return x - floor(x); }
		static float3 frac(float3 x) { return x - floor(x); }
		static float4 frac(float4 x) { return x - floor(x); }

		static float floor(float x) { return (float)std::floor(x); }
		static float2 floor(const float2& x) { return float2(std::floor(x.x), std::floor(x.y)); }
		static float3 floor(const float3& x) { return float3(std::floor(x.x), std::floor(x.y), std::floor(x.z)); }
		static float4 floor(const float4& x) { return float4(std::floor(x.x), std::floor(x.y), std::floor(x.z), std::floor(x.w)); }

		static float ceil(const float& x) { return (float)std::ceil(x); }
		static float2 ceil(const float2& x) { return float2(std::ceil(x.x), std::ceil(x.y)); }
		static float3 ceil(const float3& x) { return float3(std::ceil(x.x), std::ceil(x.y), std::ceil(x.z)); }
		static float4 ceil(const float4& x) { return float4(std::ceil(x.x), std::ceil(x.y), std::ceil(x.z), std::ceil(x.w)); }

		static float round(const float& x) { return (float)std::round(x); }
		static float2 round(const float2& x) { return float2(std::round(x.x), std::round(x.y)); }
		static float3 round(const float3& x) { return float3(std::round(x.x), std::round(x.y), std::round(x.z)); }
		static float4 round(const float4& x) { return float4(std::round(x.x), std::round(x.y), std::round(x.z), std::round(x.w)); }

		static float fmod(const float& x, const float& y) { return std::fmod(x, y); }
		static float2 fmod(const float2& x, float2& y) { return float2(std::fmod(x.x, y.x), std::fmod(x.y, y.y)); }
		static float3 fmod(const float3& x, float3& y) { return float3(std::fmod(x.x, y.x), std::fmod(x.y, y.y), std::fmod(x.z, y.z)); }
		static float4 fmod(const float4& x, float4& y) { return float4(std::fmod(x.x, y.x), std::fmod(x.y, y.y), std::fmod(x.z, y.z), std::fmod(x.w, y.w)); }

		static float pow(const float& x, const int& n) { return (float)std::pow(x, n); }
		static float2 pow(const float2& x, float2& y) { return float2(std::pow(x.x, y.x), std::pow(x.y, y.y)); }
		static float3 pow(const float3& x, float3& y) { return float3(std::pow(x.x, y.x), std::pow(x.y, y.y), std::pow(x.z, y.z)); }
		static float4 pow(const float4& x, float4& y) { return float4(std::pow(x.x, y.x), std::pow(x.y, y.y), std::pow(x.z, y.z), std::pow(x.w, y.w)); }

		static float log(const float& x) { return std::log(x); }/// 以e为底，x的对数	
		static float2 log(const float2& x) { return float2(log(x.x), log(x.y)); }
		static float3 log(const float3& x) { return float3(log(x.x), log(x.y), log(x.z)); }
		static float4 log(const float4& x) { return float4(log(x.x), log(x.y), log(x.z), log(x.w)); }

		static float log2(const float& x) { return std::log2(x); }	/// 以2为底，x的对数	
		static float2 log2(const float2& x) { return float2(log2(x.x), log2(x.y)); }
		static float3 log2(const float3& x) { return float3(log2(x.x), log2(x.y), log2(x.z)); }
		static float4 log2(const float4& x) { return float4(log2(x.x), log2(x.y), log2(x.z), log2(x.w)); }

		static float log10(const float& x) { return std::log10(x); }	/// 以10为底，x的对数	
		static float2 log10(const float2& x) { return float2(log10(x.x), log10(x.y)); }
		static float3 log10(const float3& x) { return float3(log10(x.x), log10(x.y), log10(x.z)); }
		static float4 log10(const float4& x) { return float4(log10(x.x), log10(x.y), log10(x.z), log10(x.w)); }

		static float sqrt(const float& x) { return std::sqrt(x); }
		static float2 sqrt(const float2& x) { return float2(std::sqrt(x.x), std::sqrt(x.y)); }
		static float3 sqrt(const float3& x) { return float3(std::sqrt(x.x), std::sqrt(x.y), std::sqrt(x.z)); }
		static float4 sqrt(const float4& x) { return float4(std::sqrt(x.x), std::sqrt(x.y), std::sqrt(x.z), std::sqrt(x.w)); }

		static float rsqrt(const float& x) { return 1.0f / sqrt(x); }
		static float2 rsqrt(const float2& x) { return float2(rsqrt(x.x), rsqrt(x.y)); }
		static float3 rsqrt(const float3& x) { return float3(rsqrt(x.x), rsqrt(x.y), rsqrt(x.z)); }
		static float4 rsqrt(const float4& x) { return float4(sqrt(x.x), sqrt(x.y), sqrt(x.z), sqrt(x.w)); }

		static float distance(const float& x, const float& y) { return abs(y - x); }
		static float distance(const float2& x, const float2& y) { return length(y - x); }
		static float distance(const float3& x, const float3& y) { return length(y - x); }
		static float distance(const float4& x, const float4& y) { return length(y - x); }

		static float distancesq(const float& x, const float& y) { return (y - x) * (y - x); }
		static float distancesq(const float2& x, const float2& y) { return lengthsq(y - x); }
		static float distancesq(const float3& x, const float3& y) { return lengthsq(y - x); }
		static float distancesq(const float4& x, const float4& y) { return lengthsq(y - x); }

		static float length(const float& x) { return abs(x); }
		static float length(const float2& x) { return sqrt(dot(x, x)); }
		static float length(const float3& x) { return sqrt(dot(x, x)); }
		static float length(const float4& x) { return sqrt(dot(x, x)); }

		static float lengthsq(const float& x) { return x * x; }
		static float lengthsq(const float2& x) { return dot(x, x); }
		static float lengthsq(const float3& x) { return dot(x, x); }
		static float lengthsq(const float4& x) { return dot(x, x); }

		static float rcp(const float& x) { return 1.0f / x; }
		static float2 rcp(const float2& x) { return 1.0f / x; }
		static float3 rcp(const float3& x) { return 1.0f / x; }
		static float4 rcp(const float4& x) { return 1.0f / x; }

		static float radians(const float& x) { return x * Deg2Rad; }
		static float2 radians(const float2& x) { return x * Deg2Rad; }
		static float3 radians(const float3& x) { return x * Deg2Rad; }
		static float4 radians(const float4& x) { return x * Deg2Rad; }

		static float degrees(const float& x) { return x * Rad2Deg; }
		static float2 degrees(const float2& x) { return x * Rad2Deg; }
		static float3 degrees(const float3& x) { return x * Rad2Deg; }
		static float4 degrees(const float4& x) { return x * Rad2Deg; }

		static float2 normalize(const float2& x) { return rsqrt(dot(x, x)) * x; }
		static float3 normalize(const float3& x) { return rsqrt(dot(x, x)) * x; }
		static float4 normalize(const float4& x) { return rsqrt(dot(x, x)) * x; }

		static float dot(const float& x, const float& y) { return x * y; }
		static float dot(const float2& x, const float2& y) { return x.x * y.x + x.y * y.y; }
		static float dot(const float3& x, const float3& y) { return x.x * y.x + x.y * y.y + x.z * y.z; }
		static float dot(const float4& x, const float4& y) { return x.x * y.x + x.y * y.y + x.z * y.z + x.w * y.w; }

		static float cross(const float2& x, const float2& y) { return x.x * y.y - x.y * y.x; }
		static float3 cross(const float3& x, const float3& y) { return (x * y.yzx() - x.yzx() * y).yzx(); }

		static float lerp(const float& x, const float y, const float s) { return x + s * (y - x); }
		static float2 lerp(const float2& x, const float2 y, const float s) { return x + s * (y - x); }
		static float3 lerp(const float3& x, const float3 y, const float s) { return x + s * (y - x); }
		static float4 lerp(const float4& x, const float4 y, const float s) { return x + s * (y - x); }

		static float csum(const float2& x) { return x.x + x.y; }
		static float csum(const float3& x) { return x.x + x.y + x.z; }
		static float csum(const float4& x) { return x.x + x.y + x.z; }

		static float2 project(const float2& x, const float2& y) { return (dot(x, y) / dot(y, y)) * y; }
		static float3 project(const float3& x, const float3& y) { return (dot(x, y) / dot(y, y)) * y; }
		static float4 project(const float4& x, const float4& y) { return (dot(x, y) / dot(y, y)) * y; }

		static float3 projectonplane(const float3& x, float3 planeNormal) { return x - dot(x, planeNormal) / dot(planeNormal, planeNormal) * planeNormal; }

		/// 入射向量i和法向量n，返回反射向量 r = i - 2.0f * dot(i, n) * n
		static float2 reflect(const float2 i, const float2 n) { return i - 2 * n * dot(i, n); }
		static float3 reflect(const float3 i, const float3 n) { return i - 2 * n * dot(i, n); }
		static float4 reflect(const float4 i, const float4 n) { return i - 2 * n * dot(i, n); }

		/// 入射向量i、法向量n和折射率eta的折射向量.
		static float2 refract(const float2 i, const float2 n, const float eta) { float ni = dot(n, i); float k = 1.0f - eta * eta * (1.0f - ni * ni); return select(float2(0), eta * i - (eta * ni + sqrt(k)) * n, k >= 0); }
		static float3 refract(const float3 i, const float3 n, const float eta) { float ni = dot(n, i); float k = 1.0f - eta * eta * (1.0f - ni * ni); return select(float3(0), eta * i - (eta * ni + sqrt(k)) * n, k >= 0); }
		static float4 refract(const float4 i, const float4 n, const float eta) { float ni = dot(n, i); float k = 1 - eta * eta * (1 - ni * ni); return select(float4(0), eta * i - (eta * ni + sqrt(k)) * n, k >= 0); }

		/// Returns the result of clamping the value x into the interval [a, b], where x, a and b are float values
		static float clamp(const float& x, const float a, const float b) { return max(a, min(b, x)); }
		static float2 clamp(const float2& x, const float2 a, const float2 b) { return max(a, min(b, x)); }
		static float3 clamp(const float3& x, const float3 a, const float3 b) { return max(a, min(b, x)); }
		static float4 clamp(const float4& x, const float4 a, const float4 b) { return max(a, min(b, x)); }

		/// 如果x取值小于0，则返回值为0。如果x取值大于1，则返回值为1。若x在0到1之间，则直接返回x的值
		static float saturate(const float& x) { return clamp(x, 0, 1); }
		static float2 saturate(const float2& x) { return clamp(x, float2(0), float2(1)); }
		static float3 saturate(const float3& x) { return clamp(x, float3(0), float3(1)); }
		static float4 saturate(const float4& x) { return clamp(x, float4(0), float4(1)); }

		/// Computes a step function. Returns 1.0f when x >= y, 0.0f otherwise
		static float step(float y, float x) { return select(0.0f, 1.0f, x >= y); }
		static float2 step(float2 y, float2 x) { return select(float2(0.0f), float2(1.0f), x >= y); }
		static float3 step(float3 y, float3 x) { return select(float3(0.0f), float3(1.0f), x >= y); }
		static float4 step(float4 y, float4 x) { return select(float4(0.0f), float4(1.0f), x >= y); }

		///Returns a smooth Hermite interpolation between 0.0f and 1.0f when x is in [a, b].
		static float smoothstep(const float a, const float b, const float x) { float t = saturate((x - a) / (b - a)); return t * t * (3 - (2 * t)); }
		static float2 smoothstep(const float2& a, const float2 b, const float2 x) { float2 t = saturate((x - a) / (b - a)); return t * t * (3 - (2 * t)); }
		static float3 smoothstep(const float3& a, const float3 b, const float3 x) { float3 t = saturate((x - a) / (b - a)); return t * t * (3 - (2 * t)); }
		static float4 smoothstep(const float4& a, const float4 b, const float4 x) { float4 t = saturate((x - a) / (b - a)); return t * t * (3 - (2 * t)); }

		/// 任意一个非0
		static bool any(const float2& x) { return x.x != 0 || x.y != 0; }
		static bool any(const float3& x) { return x.x != 0 || x.y != 0 || x.z != 0; }
		static bool any(const float4& x) { return x.x != 0 || x.y != 0 || x.z != 0 || x.w != 0; }

		/// 所有非0
		static bool all(const float2& x) { return x.x != 0 && x.y != 0; }
		static bool all(const float3& x) { return x.x != 0 && x.y != 0 && x.z != 0; }
		static bool all(const float4& x) { return x.x != 0 && x.y != 0 && x.z != 0 && x.w != 0; }

		/// Returns b if c is true, a otherwise
		static float select(const float& a, const float& b, const bool c) { return c ? b : a; }
		static float2 select(const float2& a, const float2& b, const bool c) { return c ? b : a; }
		static float3 select(const float3& a, const float3& b, const bool c) { return c ? b : a; }
		static float4 select(const float4& a, const float4& b, const bool c) { return c ? b : a; }

		static float sin(const float& x) { return std::sin(x); }
		static float2 sin(const float2& x) { return float2(std::sin(x.x), std::sin(x.y)); }
		static float3 sin(const float3& x) { return float3(std::sin(x.x), std::sin(x.y), std::sin(x.z)); }
		static float4 sin(const float4& x) { return float4(std::sin(x.x), std::sin(x.y), std::sin(x.z), std::sin(x.w)); }

		static float cos(const float& x) { return std::cos(x); }
		static float2 cos(const float2& x) { return float2(std::cos(x.x), std::cos(x.y)); }
		static float3 cos(const float3& x) { return float3(std::cos(x.x), std::cos(x.y), std::cos(x.z)); }
		static float4 cos(const float4& x) { return float4(std::cos(x.x), std::cos(x.y), std::cos(x.z), std::cos(x.w)); }

		static void sincos(const float& x, float& s, float& c) { s = sin(x); c = cos(x); }
		static void sincos(const float2& x, float2& s, float2& c) { s = sin(x); c = cos(x); }
		static void sincos(const float3& x, float3& s, float3& c) { s = sin(x); c = cos(x); }
		static void sincos(const float4& x, float4& s, float4& c) { s = sin(x); c = cos(x); }

		static float tan(const float& x) { return std::tan(x); }
		static float2 tan(const float2& x) { return float2(std::tan(x.x), std::tan(x.y)); }
		static float3 tan(const float3& x) { return float3(std::tan(x.x), std::tan(x.y), std::tan(x.z)); }
		static float4 tan(const float4& x) { return float4(std::tan(x.x), std::tan(x.y), std::tan(x.z), std::tan(x.w)); }

		static float asin(const float& x) { return std::asin(x); }
		static float2 asin(const float2& x) { return float2(std::asin(x.x), std::asin(x.y)); }
		static float3 asin(const float3& x) { return float3(std::asin(x.x), std::asin(x.y), std::asin(x.z)); }
		static float4 asin(const float4& x) { return float4(std::asin(x.x), std::asin(x.y), std::asin(x.z), std::asin(x.w)); }

		static float acos(const float& x) { return std::acos(x); }
		static float2 acos(const float2& x) { return float2(std::acos(x.x), std::acos(x.y)); }
		static float3 acos(const float3& x) { return float3(std::acos(x.x), std::acos(x.y), std::acos(x.z)); }
		static float4 acos(const float4& x) { return float4(std::acos(x.x), std::acos(x.y), std::acos(x.z), std::acos(x.w)); }


		static float atan(const float& x) { return std::atan(x); }
		static float2 atan(const float2& x) { return float2(std::atan(x.x), std::atan(x.y)); }
		static float3 atan(const float3& x) { return float3(std::atan(x.x), std::atan(x.y), std::atan(x.z)); }
		static float4 atan(const float4& x) { return float4(std::atan(x.x), std::atan(x.y), std::atan(x.z), std::atan(x.w)); }


		static float atan2(const float& y, const float& x) { return std::atan2(y, x); }
		static float2 atan2(const float2& y, const float2& x) { return float2(std::atan2(y.x, x.x), std::atan2(y.y, x.y)); }
		static float3 atan2(const float3& y, const float3& x) { return float3(std::atan2(y.x, x.x), std::atan2(y.y, x.y), std::atan2(y.z, x.z)); }
		static float4 atan2(const float4& y, const float4& x) { return float4(std::atan2(y.x, x.x), std::atan2(y.y, x.y), std::atan2(y.z, x.z), std::atan2(y.w, x.w)); }

		// Returns the angle in degrees between /from/ and /to/. This is always the smallest
		static float angle(float3 from, float3 to)
		{
			// sqrt(a) * sqrt(b) = sqrt(a * b) -- valid for real numbers
			float denominator = (float)sqrt(dot(from, from) * dot(to, to));
			if (denominator < kEpsilonNormalSqrt)
				return 0.0f;

			float d = clamp(dot(from, to) / denominator, -1.0f, 11.0f);
			return ((float)acos(d)) * Rad2Deg;
		}

		// The smaller of the two possible angles between the two vectors is returned, therefore the result will never be greater than 180 degrees or smaller than -180 degrees.
		// If you imagine the from and to vectors as lines on a piece of paper, both originating from the same point, then the /axis/ vector would point up out of the paper.
		// The measured angle between the two vectors would be positive in a clockwise direction and negative in an anti-clockwise direction.
		static float signedAngle(float3 from, float3 to, float3 axis)
		{
			float unsignedAngle = angle(from, to);

			float cross_x = from.y * to.z - from.z * to.y;
			float cross_y = from.z * to.x - from.x * to.z;
			float cross_z = from.x * to.y - from.y * to.x;
			float s = sign(axis.x * cross_x + axis.y * cross_y + axis.z * cross_z);
			return unsignedAngle * s;
		}


	/*	static float4x4 TRS(float3 t, quaternion r, float3 s)
		{
			float4x4 result(0);
			result.c0.x = (1 - 2 * (r.value.y * r.value.y + r.value.z * r.value.z)) * s.x;
			result.c0.y = (r.value.x * r.value.y + r.value.z * r.value.w) * s.x * 2;
			result.c0.z = (r.value.x * r.value.z - r.value.y * r.value.w) * s.x * 2;
			result.c0.w = 0;
			result.c1.x = (r.value.x * r.value.y - r.value.z * r.value.w) * s.y * 2;
			result.c1.y = (1 - 2 * (r.value.x * r.value.x + r.value.z * r.value.z)) * s.y;
			result.c1.z = (r.value.y * r.value.z + r.value.x * r.value.w) * s.y * 2;
			result.c1.w = 0;
			result.c2.x = (r.value.x * r.value.z + r.value.y * r.value.w) * s.z * 2;
			result.c2.y = (r.value.y * r.value.z - r.value.x * r.value.w) * s.z * 2;
			result.c2.z = (1 - 2 * (r.value.x * r.value.x + r.value.y * r.value.y)) * s.z;
			result.c2.w = 0;
			result.c3.x = t.x;
			result.c3.y = t.y;
			result.c3.z = t.z;
			result.c3.w = 1;
			return result;
		}*/
	private:

		union IntFloatUnion
		{
			int intValue;
			float floatValue;
		};

		static float asfloat(int x)
		{
			IntFloatUnion u;
			u.floatValue = 0;
			u.intValue = x;

			return u.floatValue;
		}

		static uint32_t asuint(int x) { return (uint32_t)x; }
	};
}