
#include "../../include/Bounding/AABB.h"
namespace Physics
{
	const Float* AABB::triangles = new Float[36]{ 0, 1, 5, 0, 4, 5, 2, 3, 7, 2, 6, 7, 0, 3, 7, 0, 4, 7, 1, 2, 6, 1, 5, 6, 0, 1, 2, 0, 2, 3, 4, 5, 6, 4, 6, 7 }; //暂时用于与AABB的相交检测
	const Float3* AABB::Normals = new Float3[3]{ Float3::right, Float3::up, Float3::forward };//x轴 左右法线，y轴上下法线，z轴前后法线

	AABB::AABB(Float3 min, Float3 max)
	{
		Points = new Float3[VERTEX];
		Min = min;
		Max = max;

		Center = (min + max) / 2;
		BevelRadius = (max - min) / 2;

		Points[0] = Float3(Min.x, Max.y, Max.z);
		Points[1] = Float3(Min.x, Max.y, Min.z);
		Points[2] = Float3(Max.x, Max.y, Min.z);
		Points[3] = Max;
		Points[4] = Float3(Min.x, Min.y, Max.z);
		Points[5] = Min;
		Points[6] = Float3(Max.x, Min.y, Min.z);
		Points[7] = Float3(Max.x, Min.y, Max.z);
	}


	AABB::AABB(AABB a, AABB b)
	{
		Points = new Float3[VERTEX];
		Min = Float3(Math::min(a.Min.x, b.Min.x), Math::min(a.Min.y, b.Min.y), Math::min(a.Min.z, b.Min.z));
		Max = Float3(Math::max(a.Max.x, b.Max.x), Math::max(a.Max.y, b.Max.y), Math::max(a.Max.z, b.Max.z));

		Center = (Min + Max) / 2;
		BevelRadius = (Max - Min) / 2;

		Points[0] = Float3(Min.x, Max.y, Max.z);
		Points[1] = Float3(Min.x, Max.y, Min.z);
		Points[2] = Float3(Max.x, Max.y, Min.z);
		Points[3] = Max;
		Points[4] = Float3(Min.x, Min.y, Max.z);
		Points[5] = Min;
		Points[6] = Float3(Max.x, Min.y, Min.z);
		Points[7] = Float3(Max.x, Min.y, Max.z);
	}

	void AABB::Update(Float3 center)
	{
		Float3 offset = center - Center;
		Center = center;
		Min = Center - BevelRadius;
		Max = Center + BevelRadius;
		for (int i = 0; i < VERTEX; i++)
		{
			Points[i] += offset;
		}
	}

	void AABB::Update(Float3 min, Float3 max)
	{
		Min = min;
		Max = max;
		Center = (min + max) / 2;

		Points[0] = Float3(Min.x, Max.y, Max.z);
		Points[1] = Float3(Min.x, Max.y, Min.z);
		Points[2] = Float3(Max.x, Max.y, Min.z);
		Points[3] = Max;
		Points[4] = Float3(Min.x, Min.y, Max.z);
		Points[5] = Min;
		Points[6] = Float3(Max.x, Min.y, Min.z);
		Points[7] = Float3(Max.x, Min.y, Max.z);
	}
}