#pragma once
#include "fix.h"
#include "fix2.h"
#include "fix3.h"
#include "fix4.h"

//64bit -9223372036854775808 - 9223372036854775807
//48bit -281474976710656 - 281474976710657 :4294967296
//32bit -2147483648 - 2147483647
namespace Mathematica
{
	const fix MaxValue = fix::Raw(MAX_VALUE);//32位最大值 2147483647 (140737488355327)
	const fix MinValue = fix::Raw(MIN_VALUE);//32位最小值 2147483648
	const fix One = fix::Raw(ONE);
	const fix Zero = fix(0);

	//const fix Max = fix::Raw(((int64_t)1 << (BITS - PRECISION)) - 1);//可表示的最大值 4294967296 (281474976710657)
	//const fix Min = fix::Raw(-((int64_t)1 << (BITS - PRECISION - 1)));//可表示的最小值 -4294967295

	const fix _0 = fix(0);
	const fix _1 = fix(1);
	const fix _2 = fix(2);
	const fix _3 = fix(3);
	const fix _4 = fix(4);
	const fix _5 = fix(5);
	const fix _6 = fix(6);
	const fix _7 = fix(7);
	const fix _8 = fix(8);
	const fix _9 = fix(9);
	const fix _10 = fix(10);
	const fix _100 = fix(100);
	const fix _1000 = fix(1000);
	const fix _10000 = fix(10000);
	const fix _100000 = fix(100000);

	const fix _0_00001 = fix(0.0001);
	const fix _0_0001 = fix(0.001);
	const fix _0_0005 = fix(0.0005);
	const fix _0_9995 = fix(0.9995);

	const fix _0_001 = fix(0.001);
	const fix _0_002 = fix(0.002);
	const fix _0_003 = fix(0.003);
	const fix _0_004 = fix(0.004);
	const fix _0_005 = fix(0.005);

	const fix _0_01 = fix(0.01);
	const fix _0_02 = fix(0.02);
	const fix _0_03 = fix(0.03);
	const fix _0_04 = fix(0.04);
	const fix _0_05 = fix(0.05);

	const fix _0_1 = fix(0.1);
	const fix _0_2 = fix(0.2);
	const fix _0_25 = fix(0.25);
	const fix _0_5 = fix(0.5);
	const fix _0_75 = fix(0.75);
	const fix _0_95 = fix(0.95);
	const fix _0_99 = fix(0.99);

	const fix _1_01 = fix(1.01);
	const fix _1_1 = fix(1.1);
	const fix _1_5 = fix(1.5);

}