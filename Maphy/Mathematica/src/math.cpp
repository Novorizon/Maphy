#include "../include/math.h"

namespace Mathematica
{

	const fix math::PI = fix::Raw(205887L);
	const fix math::PI2 = PI * 2;
	const fix math::PI2rcp = 1 / PI2;
	const fix math::Deg2Rad = fix::Raw(1144L);
	const fix math::Rad2Deg = fix::Raw(3754936L);

	const fix math::Ln2 = fix::Raw(45426);
	const fix math::Ln10 = 2.3025850929940456840179914547;
	const fix math::Lnr = 0.2002433314278771112016301167;
	const fix math::Epsilon = fix::Raw(1);
	const fix math::E = fix::Raw(178145L);

	const fix math::atan2Number1 = fix::Raw(-883);
	const fix math::atan2Number2 = fix::Raw(3767);
	const fix math::atan2Number3 = fix::Raw(7945);
	const fix math::atan2Number4 = fix::Raw(12821);
	const fix math::atan2Number5 = fix::Raw(21822);
	const fix math::atan2Number6 = fix::Raw(65536);
	const fix math::atan2Number7 = fix::Raw(102943);
	const fix math::atan2Number8 = fix::Raw(205887);

	fix math::trunc(const fix& x)
	{
		fix result;
		result.value = x.value >> PRECISION << PRECISION;
		if (sign(result) != 0)
			result.value = x.value + (1 << PRECISION);
		return result;
	}

	fix math::ceil(const fix& value)
	{
		if ((value.value << (BITS - PRECISION)) == 0)
			return value;

		fix result;
		result.value = value.value >> PRECISION << PRECISION;
		result += fix::one;
		return result;
	}

	fix math::round(const fix& x)
	{
		fix fractional = frac(x);
		fix truncation = trunc(x);
		if (fractional.value < (1 << (PRECISION - 2)))
		{
			return truncation;
		}
		else
		{
			int sign = (int)(x >> 63).value << PRECISION;//int sign = (int)(x >> 63); CHECK
			if (sign == 0)
			{
				fix result;
				result.value = truncation.value + ONE;
				return x;
			}
			else
			{
				fix result;
				result.value = truncation.value - ONE;
				return x;
			}
		}
	}

	/// lnx=ln(1+y)/(1-y)=2y(1/1+1/3*y*y+1/5*y*y*y*y+......)
	fix math::ln(const fix& x)
	{
		if (x <= 0)
			return fix::MinValue;

		fix result(x.value);
		int k = 0, l = 0;
		for (; result > 1; k++)
			result = result / 10;

		for (; result <= 0.1; k--)
			result *= 10;        // ( 0.1, 1 ]

		for (; result < 0.9047; l--)
			result *= 1.2217; // [ 0.9047, 1.10527199 )

		return k * Ln10 + l * Lnr + Logarithm((result - 1) / (result + 1));
	}

	fix math::pow(const fix& x, const int& n)
	{
		if (x == 0)
			return 0;

		if (n == std::numeric_limits<int>::min())
		{
			return x == 1 || x == -1 ? 1 : 0;
		}
		fix res = 1;

		fix y(x.value);
		int m = n;
		if (m < 0)
		{
			m = -m;
			y = 1 / x;
		}

		while (m > 0)
		{
			if ((m & 1) > 0)
				res *= y;
			y *= y;
			m >>= 1;
		}
		return res;
	}

	fix math::sqrt(const fix& x)
	{
		if (x.value < 0)
			return fix::MinValue;

		if (x.value == 0)
			return fix::zero;

		fix a = x;
		int64_t b = (a.value >> 2) + 1L;
		a.value = (b + (x.value << PRECISION) / a.value) >> 1;
		while (a.value < b)
		{
			b = a.value;
			a.value = (a.value + (x.value << PRECISION) / a.value) >> 1;
		}
		return a;
	}

	fix math::atan2(const fix& y, const fix& x)
	{
		fix absX = abs(x);
		fix absY = abs(y);
		fix t3 = absX;
		fix t1 = absY;
		fix t0 = max(t3, t1);
		t1 = min(t3, t1);
		t3 = fix::_1 / t0;
		t3 = t1 * t3;
		fix t4 = t3 * t3;
		t0 = atan2Number1;
		t0 = t0 * t4 + atan2Number2;
		t0 = t0 * t4 - atan2Number3;
		t0 = t0 * t4 + atan2Number4;
		t0 = t0 * t4 - atan2Number5;
		t0 = t0 * t4 + atan2Number6;
		t3 = t0 * t3;
		t3 = absY > absX ? atan2Number7 - t3 : t3;
		t3 = x < fix::_0 ? atan2Number8 - t3 : t3;
		t3 = y < fix::_0 ? -t3 : t3;
		return t3;
	}

	fix math::Logarithm(const fix& x)
	{
		// y in ( -0.05-, 0.05+ ), return ln((1+y)/(1-y))
		fix v = 1, x2 = x * x, t = x2, z = t / 3;
		for (int i = 3; z != 0; z = (t = t * x2) / (i += 2))
			v += z;
		return v * x * 2;
	}
}