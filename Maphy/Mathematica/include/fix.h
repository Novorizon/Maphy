#pragma once
#include "define.h"

namespace Mathematica
{
	class fix
	{

	private:

	public:
		Int value;

		Int Value() { return(value >> PRECISION); }

		fix() { value = 0; }

		inline fix(int v) { value = (Int)v << PRECISION; }
		inline fix(Int v) { value = v << PRECISION; }
		inline fix(float v) { value = (Int)(v * ONE + 0.5f * (v < 0 ? -1 : 1)); }
		inline fix(double v) { value = (Int)(v * ONE); }

		//inline	operator float() { return 1.0f; }

		inline fix& operator =(const fix& a) { value = a.value; return *this; }
		inline fix(const fix& other) { value = other.value; }

		inline static fix Raw(const Int& value) { fix v; v.value = value;  return v; }
		inline bool Equals(const fix& other) { return value == other.value; }



		friend	fix operator +(const fix& a, const fix& b) { fix result; result.value = a.value + b.value; return result; }
		friend	fix operator -(const fix& a, const fix& b) { fix result; result.value = a.value - b.value; return result; }
		friend	fix operator *(const fix& a, const fix& b) { fix result; result.value = a.value * b.value;  return result; }
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



	};


}
