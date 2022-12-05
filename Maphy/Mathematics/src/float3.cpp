#include "../include/float3.h"

namespace Mathematics
{
	const float3 float3::left = float3(-1, 0, 0);
	const float3 float3::right = float3(1, 0, 0);
	const float3 float3::up = float3(0, 1, 0);
	const float3 float3::down = float3(0, -1, 0);
	const float3 float3::forward = float3(0, 0, 1);
	const float3 float3::backward = float3(0, 0, -1);
	const float3 float3::one = float3(1, 1, 1);
	const float3 float3::one_inverse = float3(-1, -1, -1);
	const float3 float3::zero = float3(0, 0, 0);
}