#include "fix.h"

#include "lut/SinLut.h"
#include "lut/SinCosLut.h"
#include "lut/AsinLut.h"
#include "lut/AcosLut.h"
#include "lut/TanLut.h"

namespace Mathematica
{
	class trigonometric
	{
	private:
		static const fix _0_25;

	public:
		static const int32_t SHIFT = PRECISION - 9;


		static  int64_t sin(int64_t value);

		static  int64_t cos(int64_t value);

		static  int64_t tan(int64_t value);

		static  void sin_cos(int64_t value, int64_t& sin, int64_t& cos);

		static  void sin_cos_tan(int64_t value, int64_t& sin, int64_t& cos, int64_t& tan);

		static int64_t acos(int64_t value);

		static int64_t asin(int64_t value);
	};
}