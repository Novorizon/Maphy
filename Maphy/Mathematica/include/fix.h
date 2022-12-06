#pragma once
#include "config.h"

namespace Mathematica
{
	class fix
	{

	private:

	public:
		Int value;

		static const fix MaxValue;//32位最大值 2147483647 (140737488355327)
		static const fix MinValue;//32位最小值 2147483648
		static const fix one;
		static const fix zero;
		static const fix epsilon;
		static const fix NaN;

		Int Value() { return(value >> PRECISION); }

		fix() { value = 0; }

		inline fix(int v) { value = (Int)v << PRECISION; }
		inline fix(Int v) { value = v << PRECISION; }
		inline fix(float v) { value = (Int)(v * ONE + 0.5f * (v < 0 ? -1 : 1)); }
		inline fix(double v) { value = (Int)(v * ONE); }

		//inline	operator float() { return 1.0f; }

		inline fix& operator =(const fix& a) { value = a.value; return *this; }
		inline fix(const fix& other) { value = other.value; }

		inline static fix Raw(const Int& value) { fix v; v.value = value; return v; }
		inline bool Equals(const fix& other) { return value == other.value; }



		friend	fix operator +(const fix& a, const fix& b) { fix result; result.value = a.value + b.value; return result; }
		friend	fix operator -(const fix& a, const fix& b) { fix result; result.value = a.value - b.value; return result; }
		friend	fix operator *(const fix& a, const fix& b) { fix result; result.value = a.value * b.value; return result; }
		friend	fix operator /(const fix& a, const fix& b) { fix result; result.value = (a.value << PRECISION) / b.value; return result; }

		void operator +=(const fix& a) { value = value + a.value; }
		void operator -=(const fix& a) { value = value - a.value; }
		void operator *=(const fix& a) { value = value * a.value; }
		void operator /=(const fix& a) { value = (value << PRECISION) / a.value; }


		friend fix operator-(const fix& a) { return fix(-a.value); }

		friend bool operator >(fix a, fix b) { return a.value > b.value; }
		friend bool operator <(fix a, fix b) { return a.value < b.value; }
		friend bool operator >=(fix a, fix b) { return a.value >= b.value; }
		friend bool operator <=(fix a, fix b) { return a.value <= b.value; }
		friend bool operator ==(fix a, fix b) { return a.value == b.value; }
		friend bool operator !=(fix a, fix b) { return a.value != b.value; }

		friend fix operator >>(fix a, int32_t amount) { return(a.value >> amount); }
		friend fix operator <<(fix a, int32_t amount) { return(a.value << amount); }





		std::string ToString() const
		{
			std::stringstream ss;
			ss << (value >> PRECISION);
			std::string out = ss.str();

			return out;
		}


		static const fix _0;
		static const fix _1;
		static const fix _2;
		static const fix _3;
		static const fix _4;
		static const fix _5;
		static const fix _6;
		static const fix _7;
		static const fix _8;
		static const fix _9;
		static const fix _10;
		static const fix _100;
		static const fix _1000;
		static const fix _10000;
		static const fix _100000;

		static const fix _0_00001;
		static const fix _0_0001;
		static const fix _0_0005;
		static const fix _0_9995;

		static const fix _0_001;
		static const fix _0_002;
		static const fix _0_003;
		static const fix _0_004;
		static const fix _0_005;

		static const fix _0_01;
		static const fix _0_02;
		static const fix _0_03;
		static const fix _0_04;
		static const fix _0_05;

		static const fix _0_1;
		static const fix _0_2;
		static const fix _0_25;
		static const fix _0_5;
		static const fix _0_75;
		static const fix _0_95;
		static const fix _0_99;

		static const fix _1_01;
		static const fix _1_1;
		static const fix _1_5;

	};


}
