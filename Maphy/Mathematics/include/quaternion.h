#pragma once
#include "float3x3.h"
#include "float4x4.h"
#include "math.h"

namespace Mathematics
{
	class quaternion
	{
	public:
		float4 value;
		static const quaternion identity;
		quaternion(float4 q) { value = q; }

		quaternion(float x, float y, float z, float w) { value.x = x; value.y = y; value.z = z; value.w = w; }
		quaternion(float3x3 matrix);
		quaternion(float4x4 matrix);


		float3 EulerAngles();

		friend quaternion operator *(quaternion lhs, quaternion rhs)
		{
			return quaternion(
				lhs.value.w * rhs.value.x + lhs.value.x * rhs.value.w + lhs.value.y * rhs.value.z - lhs.value.z * rhs.value.y,
				lhs.value.w * rhs.value.y + lhs.value.y * rhs.value.w + lhs.value.z * rhs.value.x - lhs.value.x * rhs.value.z,
				lhs.value.w * rhs.value.z + lhs.value.z * rhs.value.w + lhs.value.x * rhs.value.y - lhs.value.y * rhs.value.x,
				lhs.value.w * rhs.value.w - lhs.value.x * rhs.value.x - lhs.value.y * rhs.value.y - lhs.value.z * rhs.value.z);
		}

		friend float3 operator *(quaternion q, float3 v)
		{
			float3 t = 2.0f * math::cross(q.xyz(), v);
			return v + q.value.w * t + math::cross(q.xyz(), t);
		}


		friend quaternion operator / (const quaternion& q, const float s) { if (s == 0)return quaternion::identity; return quaternion(q.value / s); }
		friend bool operator ==(quaternion a, quaternion b) { return a.value.x == b.value.x && a.value.y == b.value.y && a.value.z == b.value.z && a.value.w == b.value.w; }
		friend bool operator !=(quaternion a, quaternion b) { return a.value.x != b.value.x || a.value.y != b.value.y || a.value.z != b.value.z || a.value.w != b.value.w; }

		static quaternion conjugate(quaternion q);
		static quaternion normalize(quaternion q);
		static float dot(quaternion a, quaternion b);
		static quaternion inverse(quaternion q);
		static float length(quaternion q);
		static float lengthsq(quaternion q);
		static float3 mul(quaternion q, float3 v);
		static quaternion mul(quaternion a, quaternion b);
		static float3 rotate(quaternion q, float3 v);
		static quaternion nlerp(quaternion q1, quaternion q2, float t);
		static float3 forward(quaternion q);
		static quaternion slerp(quaternion q1, quaternion q2, float t);

		/// <summary>
		/// Returns a safe normalized version of the q by scaling it by 1 / length(q).
		/// Returns the identity when 1 / length(q) does not produce a finite number.
		/// <summary>
		/// <param name="q">The quaternion to normalize.</param>
		/// <returns>The normalized quaternion or the identity quaternion.</returns>
		static quaternion normalizesafe(const quaternion& q);

		/// <summary>
		/// Returns a safe normalized version of the q by scaling it by 1 / length(q).
		/// Returns the given default value when 1 / length(q) does not produce a finite number.
		/// </summary>
		/// <param name="q">The quaternion to normalize.</param>
		/// <param name="defaultvalue">The default value.</param>
		/// <returns>The normalized quaternion or the default value.</returns>
		static quaternion normalizesafe(quaternion q, quaternion defaultvalue);


		/// <summary>
		/// Returns a quaternion representing a rotation around a unit axis by an angle in radians.
		/// The rotation direction is clockwise when looking along the rotation axis towards the origin.
		/// </summary>
		/// <param name="axis">The axis of rotation.</param>
		/// <param name="angle">The angle of rotation in radians.</param>
		/// <returns>The quaternion representing a rotation around an axis.</returns>
		/// 参数为弧度，旋转轴为看向起点的顺时针
		static quaternion AxisAngle(float3 axis, float angle);

		/// 参数为角度，旋转轴为看向起点的顺时针
		static quaternion Axis(float3 axis, float angle);

		/// 参数为角度，旋转轴为看向起点的顺时针
		static quaternion AxisDegrees(float3 axis, float angle) { return Axis(axis, angle); };

		/// <summary>
		/// Returns a quaternion constructed by first performing a rotation around the x-axis, then the y-axis and finally the z-axis.
		/// All rotation angles are in radians and clockwise when looking along the rotation axis towards the origin.
		/// </summary>
		/// <param name="xyz">A float3 vector containing the rotation angles around the x-, y- and z-axis measures in radians.</param>
		/// <returns>The quaternion representing the Euler angle rotation in x-y-z order.</returns>
		/// 参数为弧度
		static quaternion EulerXYZ(float3 xyz);
		static quaternion EulerXZY(float3 xyz);
		static quaternion EulerYXZ(float3 xyz);
		static quaternion EulerYZX(float3 xyz);
		static quaternion EulerZXY(float3 xyz);
		static quaternion EulerZYX(float3 xyz);

		static quaternion  EulerXYZ(float x, float y, float z) { return EulerXYZ(float3(x, y, z)); }
		static quaternion  EulerXZY(float x, float y, float z) { return EulerXZY(float3(x, y, z)); }
		static quaternion  EulerYXZ(float x, float y, float z) { return EulerYXZ(float3(x, y, z)); }
		static quaternion  EulerYZX(float x, float y, float z) { return EulerYZX(float3(x, y, z)); }
		static quaternion  EulerZXY(float x, float y, float z) { return EulerZXY(float3(x, y, z)); }
		static quaternion  EulerZYX(float x, float y, float z) { return EulerZYX(float3(x, y, z)); }

		/// <summary>
		/// Returns a quaternion constructed by first performing 3 rotations around the principal axes in a given order.
		/// All rotation angles are in radians and clockwise when looking along the rotation axis towards the origin.
		/// When the rotation order is known at compile time, it is recommended for performance reasons to use specific
		/// Euler rotation constructors such as EulerZXY(...).
		/// </summary>
		/// <param name="xyz">A float3 vector containing the rotation angles around the x-, y- and z-axis measures in radians.</param>
		/// <param name="order">The order in which the rotations are applied.</param>
		/// <returns>The quaternion representing the Euler angle rotation in the specified order.</returns>
		static quaternion Euler(float3 xyz, math::RotationOrder order = math::RotationOrder::ZXY);
		static quaternion Euler(float x, float y, float z, math::RotationOrder order = math::RotationOrder::ZXY) { return Euler(float3(x, y, z), order); }

		static quaternion RotateX(float angle);

		/// <summary>Returns a quaternion that rotates around the y-axis by a given number of radians.</summary>
		/// <param name="angle">The clockwise rotation angle when looking along the y-axis towards the origin in radians.</param>
		/// <returns>The quaternion representing a rotation around the y-axis.</returns>
		static quaternion RotateY(float angle);

		/// <summary>Returns a quaternion that rotates around the z-axis by a given number of radians.</summary>
		/// <param name="angle">The clockwise rotation angle when looking along the z-axis towards the origin in radians.</param>
		/// <returns>The quaternion representing a rotation around the z-axis.</returns>
		static quaternion RotateZ(float angle);


		/// <summary>
		/// Returns a quaternion view rotation given a unit length forward vector and a unit length up vector.
		/// The two input vectors are assumed to be unit length and not collinear.
		/// If these assumptions are not met use float3x3.LookRotationSafe instead.
		/// </summary>
		/// <param name="forward">The view forward direction.</param>
		/// <param name="up">The view up direction.</param>
		/// <returns>The quaternion view rotation.</returns>
		static quaternion LookRotation(float3 forward, float3 up);

		/// <summary>
		/// Returns a quaternion view rotation given a forward vector and an up vector.
		/// The two input vectors are not assumed to be unit length.
		/// If the magnitude of either of the vectors is so extreme that the calculation cannot be carried out reliably or the vectors are collinear,
		/// the identity will be returned instead.
		/// </summary>
		/// <param name="forward">The view forward direction.</param>
		/// <param name="up">The view up direction.</param>
		/// <returns>The quaternion view rotation or the identity quaternion.</returns>
		static quaternion LookRotationSafe(float3 forward, float3 up);

		bool Equals(quaternion x) { return value.x == x.value.x && value.y == x.value.y && value.z == x.value.z && value.w == x.value.w; }

		const float& operator[](int i) const
		{
			switch (i)
			{
			case 0:
				return value.x;
				break;
			case 1:
				return value.y;
				break;
			case 2:
				return value.z;
				break;
			case 3:
				return value.w;
				break;
			default:
				break;
			}
		}

		float3 xyz() { return float3(value.x, value.y, value.z); }
	private:

		// Makes euler angles positive 0/360 with 0.0001 hacked to support old behaviour of QuaternionToEuler
		inline static float3 MakeDegreePositive(float3 euler);
		inline void MakeRadianPositive(float3& euler);

		inline float3 QuaternionToEuler(const quaternion& quat);
		inline float3x3 QuaternionToMatrix(const quaternion& quaternion);
		inline float3 MatrixToEuler(const float3x3& matrix);
		inline float3x3 EulerToMatrix(const float3& v);
		//float3x3 TRS(quaternion r);

		//inline quaternion NormalizeSafe(const quaternion& q);
	};


}