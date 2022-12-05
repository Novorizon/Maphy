
#include "../../include/Bounding/AABB.h"
namespace Physics
{
	const float* AABB::triangles = new float[36] { 0, 1, 5, 0, 4, 5, 2, 3, 7, 2, 6, 7, 0, 3, 7, 0, 4, 7, 1, 2, 6, 1, 5, 6, 0, 1, 2, 0, 2, 3, 4, 5, 6, 4, 6, 7 }; //暂时用于与AABB的相交检测
	const float3* AABB::Normals = new float3  [3] { float3::right, float3::up, float3::forward };//x轴 左右法线，y轴上下法线，z轴前后法线

	AABB::AABB(float3 min, float3 max)
	{
		Points = new float3[VERTEX];
		Min = min;
		Max = max;

		Center = (min + max) / 2;
		BevelRadius = (max - min) / 2;

		Points[0] = float3(Min.x, Max.y, Max.z);
		Points[1] = float3(Min.x, Max.y, Min.z);
		Points[2] = float3(Max.x, Max.y, Min.z);
		Points[3] = Max;
		Points[4] = float3(Min.x, Min.y, Max.z);
		Points[5] = Min;
		Points[6] = float3(Max.x, Min.y, Min.z);
		Points[7] = float3(Max.x, Min.y, Max.z);
	}


	AABB::AABB(AABB a, AABB b)
	{
		Points = new float3[VERTEX];
		Min = float3(math::min(a.Min.x, b.Min.x), math::min(a.Min.y, b.Min.y), math::min(a.Min.z, b.Min.z));
		Max = float3(math::max(a.Max.x, b.Max.x), math::max(a.Max.y, b.Max.y), math::max(a.Max.z, b.Max.z));

		Center = (Min + Max) / 2;
		BevelRadius = (Max - Min) / 2;

		Points[0] = float3(Min.x, Max.y, Max.z);
		Points[1] = float3(Min.x, Max.y, Min.z);
		Points[2] = float3(Max.x, Max.y, Min.z);
		Points[3] = Max;
		Points[4] = float3(Min.x, Min.y, Max.z);
		Points[5] = Min;
		Points[6] = float3(Max.x, Min.y, Min.z);
		Points[7] = float3(Max.x, Min.y, Max.z);
	}

	void AABB::Update(float3 center)
	{
		float3 offset = center - Center;
		Center = center;
		Min = Center - BevelRadius;
		Max = Center + BevelRadius;
		for (int i = 0; i < VERTEX; i++)
		{
			Points[i] += offset;
		}
	}

	void AABB::Update(float3 min, float3 max)
	{
		Min = min;
		Max = max;
		Center = (min + max) / 2;

		Points[0] = float3(Min.x, Max.y, Max.z);
		Points[1] = float3(Min.x, Max.y, Min.z);
		Points[2] = float3(Max.x, Max.y, Min.z);
		Points[3] = Max;
		Points[4] = float3(Min.x, Min.y, Max.z);
		Points[5] = Min;
		Points[6] = float3(Max.x, Min.y, Min.z);
		Points[7] = float3(Max.x, Min.y, Max.z);
	}
}