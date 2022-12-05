#include "../include/fix.h"



namespace Mathematica
{
	const fix fix::MaxValue = fix::Raw(MAX_VALUE);//32位最大值 2147483647 (140737488355327)
	const fix fix::MinValue = fix::Raw(MIN_VALUE);//32位最小值 2147483648
	const fix fix::one = fix::Raw(ONE);
	const fix fix::zero = fix(0);
	const fix fix::epsilon = std::numeric_limits<float>::epsilon();
	const fix fix::NaN = std::numeric_limits<float>::quiet_NaN();

	const fix fix::_0 = fix(0);
	const fix fix::_1 = fix(1);
	const fix fix::_2 = fix(2);
	const fix fix::_3 = fix(3);
	const fix fix::_4 = fix(4);
	const fix fix::_5 = fix(5);
	const fix fix::_6 = fix(6);
	const fix fix::_7 = fix(7);
	const fix fix::_8 = fix(8);
	const fix fix::_9 = fix(9);
	const fix fix::_10 = fix(10);
	const fix fix::_100 = fix(100);
	const fix fix::_1000 = fix(1000);
	const fix fix::_10000 = fix(10000);
	const fix fix::_100000 = fix(100000);

	const fix fix::_0_00001 = fix(0.0001);
	const fix fix::_0_0001 = fix(0.001);
	const fix fix::_0_0005 = fix(0.0005);
	const fix fix::_0_9995 = fix(0.9995);

	const fix fix::_0_001 = fix(0.001);
	const fix fix::_0_002 = fix(0.002);
	const fix fix::_0_003 = fix(0.003);
	const fix fix::_0_004 = fix(0.004);
	const fix fix::_0_005 = fix(0.005);

	const fix fix::_0_01 = fix(0.01);
	const fix fix::_0_02 = fix(0.02);
	const fix fix::_0_03 = fix(0.03);
	const fix fix::_0_04 = fix(0.04);
	const fix fix::_0_05 = fix(0.05);

	const fix fix::_0_1 = fix(0.1);
	const fix fix::_0_2 = fix(0.2);
	const fix fix::_0_25 = fix(0.25);
	const fix fix::_0_5 = fix(0.5);
	const fix fix::_0_75 = fix(0.75);
	const fix fix::_0_95 = fix(0.95);
	const fix fix::_0_99 = fix(0.99);

	const fix fix::_1_01 = fix(1.01);
	const fix fix::_1_1 = fix(1.1);
	const fix fix::_1_5 = fix(1.5);
}