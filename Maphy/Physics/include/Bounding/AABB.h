#include "Bounding.h"
#include "../../config.h"
namespace Physics
{
	struct AABB : IBounding
	{
	public:
		static const int EDGE = 12;
		static const int FACE = 6;
		static const int VERTEX = 8;
		static const int NORMAL = 3;

		static const Float* triangles; //暂时用于与AABB的相交检测
		static const Float3* Normals;//x轴 左右法线，y轴上下法线，z轴前后法线

		Float3 Center;
		Float3 BevelRadius;

		Float3 Min;
		Float3 Max;
		AABB* Bounds;
		Float3* Points;//上面 左前 左后 右后 右前 //下面 左前 左后 右后 右前 

		AABB(Float3 min, Float3 max);

		AABB(AABB a, AABB b);


		void Update(Float3 center);

		void Update(Float3 min, Float3 max);


	};
}