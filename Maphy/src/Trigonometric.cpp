#include "../include/Trigonometric.h"

namespace Mathematica
{
	const fix trigonometric::_0_25 = 0.25;

	int64_t trigonometric::sin(int64_t value)
	{
		int32_t sign = (int32_t)(value >> 63) | 1;
		value = (value + (value >> 63)) ^ (value >> 63);

		int32_t index = (int32_t)(value >> SHIFT);
		int64_t fraction = (value - (index << SHIFT)) << 9;
		int32_t a = SinLut[index];
		int32_t b = SinLut[index + 1];
		int64_t v2 = a + (((b - a) * fraction) >> PRECISION);
		return v2 * sign;
	}

	int64_t trigonometric::cos(int64_t value)
	{
		value = (value + (value >> 63)) ^ (value >> 63);

		value += _0_25.value;

		if (value >= ONE)
		{
			value -= ONE;
		}

		int32_t index = (int32_t)(value >> SHIFT);
		int64_t fraction = (value - (index << SHIFT)) << 9;
		int32_t a = SinLut[index];
		int32_t b = SinLut[index + 1];
		int64_t v2 = a + (((b - a) * fraction) >> PRECISION);
		return v2;
	}


	int64_t trigonometric::tan(int64_t value)
	{
		int32_t sign = (int32_t)(value >> 63) | 1;
		value = (value + (value >> 63)) ^ (value >> 63);

		int32_t index = (int32_t)(value >> SHIFT);
		int64_t fraction = (value - (index << SHIFT)) << 9;
		int32_t a = TanLut[index];
		int32_t b = TanLut[index + 1];
		int64_t v2 = a + (((b - a) * fraction) >> PRECISION);
		return v2 * sign;
	}

	void trigonometric::sin_cos(int64_t value, int64_t& sin, int64_t& cos)
	{
		int32_t sign = (int32_t)(value >> 63) | 1;
		value = (value + (value >> 63)) ^ (value >> 63);

		int32_t index = (int32_t)(value >> SHIFT);
		int32_t doubleIndex = index * 2;
		int64_t fractions = (value - (index << SHIFT)) << 9;

		int32_t sinA = SinCosLut[doubleIndex];
		int32_t cosA = SinCosLut[doubleIndex + 1];
		int32_t sinB = SinCosLut[doubleIndex + 2];
		int32_t cosB = SinCosLut[doubleIndex + 3];

		sin = (sinA + (((sinB - sinA) * fractions) >> PRECISION)) * sign;
		cos = cosA + (((cosB - cosA) * fractions) >> PRECISION);
	}

	void trigonometric::sin_cos_tan(int64_t value, int64_t& sin, int64_t& cos, int64_t& tan)
	{
		int32_t sign = (int32_t)(value >> 63) | 1;
		value = (value + (value >> 63)) ^ (value >> 63);

		int32_t index = (int32_t)(value >> SHIFT);
		int32_t doubleIndex = index * 2;
		int64_t fractions = (value - (index << SHIFT)) << 9;

		int32_t sinA = SinCosLut[doubleIndex];
		int32_t cosA = SinCosLut[doubleIndex + 1];
		int32_t sinB = SinCosLut[doubleIndex + 2];
		int32_t cosB = SinCosLut[doubleIndex + 3];

		sin = (sinA + (((sinB - sinA) * fractions) >> PRECISION)) * sign;
		cos = cosA + (((cosB - cosA) * fractions) >> PRECISION);
		tan = (sin << PRECISION) / cos;
	}

	int64_t trigonometric::acos(int64_t value)
	{
		int32_t index = (int32_t)(value >> SHIFT);
		int64_t fraction = (value - (index << SHIFT)) << 9;
		int32_t a = AcosLut[index];
		int32_t b = AcosLut[index + 1];
		int64_t v2 = a + (((b - a) * fraction) >> PRECISION);
		return v2;
	}

	int64_t trigonometric::asin(int64_t value)
	{
		int32_t index = (int32_t)(value >> SHIFT);
		int64_t fraction = (value - (index << SHIFT)) << 9;
		int32_t a = AsinLut[index];
		int32_t b = AsinLut[index + 1];
		int64_t v2 = a + (((b - a) * fraction) >> PRECISION);
		return v2;
	}

}