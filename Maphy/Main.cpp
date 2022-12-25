
#include <iostream>
#include "Mathematica/include/quaternion.h"
#include "Mathematics/include/math.h"
#include "Mathematics/include/quaternion.h"
using namespace std;
//using maths = Mathematics::math;
using math = Mathematica::math;
using fix= Mathematica::fix;
using fix2 = Mathematica::fix2;
using fix3 = Mathematica::fix3;
using quaternion = Mathematica::quaternion;
int main()
{
	auto f3 = fix3::left;
	auto aaaaa = Mathematics::math::Rad2Deg;
	if (fix::NaN == std::numeric_limits<float>::quiet_NaN())
		int aaaa = 1;
	fix as1 = math::atan2Number1;
	fix as2 = math::sqrt(-1);
	fix as3 = math::sign(-1);
	int t1 = 1;
	int t2 = t1;
	int* p = &t1;
	std::cout << t1 << std::endl;
	std::cout << &t1 << std::endl;
	std::cout << &t2 << std::endl;
	std::cout << p << std::endl;
	std::cout << &(*p) << std::endl;

	string str = "abc";
	std::cout << str << std::endl;
	std::cout << &str << std::endl;
	std::cout << &str[0] << std::endl;

	char* ch = new char[3] { 'a', 'b', 'c' };
	//const	char ccc[3] = "abc";

	std::cout << ch << std::endl;
	std::cout << &ch << std::endl;
	std::cout << ch[0] << std::endl;

	/*  Triangle navmeshes[100] ;
	  Triangle* navmesh = new Triangle[100];
	  for (int32_t i = 0; i < 100; i++)
	  {
		  float3 a=float3(i, i * 2 , i * 3);
		  float3 b = float3(i*2, i * 3, i * 4);
		  float3 c= float3(i * 3, i * 4, i * 5);
		  navmeshes[i] = Triangle(a,b,c);
	  }
	  AStar astar = AStar();
	  astar.SetNavMesh(navmeshes,100);*/

	  /*  for (size_t i = 0; i < 100; i++)
		{
			std::cout << astar.triangles [i] << "\n";
		}*/

	fix a = 0;

	Mathematica::fix b = 1.1f;

	Mathematica::fix c = 1;
	c = c + 1;

	//std::string str = c.ToString();

	std::cout << a.ToString() << "\n";

	Mathematica::fix2 a2 = Mathematica::fix2(1);
	a = a2[1];

	float aaa = 1;
	fix bbb = 2;
	fix ccc = aaa + bbb;
	//bbb = fix::_0;

	fix2 a222(1, 2);
	fix aaaa = 1 / bbb;
	int64_t asd = aaaa.Value();
	string str2 = aaaa.ToString();
	cout << (fix(1 / bbb)).ToString() << endl;







	Mathematics::quaternion q = Mathematics::quaternion(0, 0, 0, 1);
	Mathematics::quaternion q1 = Mathematics::quaternion(0, 0, 0, 1);
	q= Mathematics::quaternion::Euler(1.56, 1.62, 59.23);
	quaternion(0.01881894f, 0.005562271f, 0.493907f, 0.8692933f);
	auto angle=q.EulerAngles();
	fix maxValue = fix::Raw(Mathematica::MAX_VALUE);//140737488355327->2147483647 32位最大值 
	//{x = 357.810028 y = 0.511404157 z = 300.782288 }
	std::cout << q.value.x << std::endl;
	std::cout << angle.x << std::endl;


	int64_t t = 9223372036854775807;
	fix max = fix::Raw(((int64_t)1 << (int64_t)46) - 2);//可表示的最大值
	max = fix::Raw(281474976710698);//可表示的最大值
	std::cout << fix::MaxValue.ToString() << "\n";
	std::cout << fix::MinValue.ToString() << "\n";
}