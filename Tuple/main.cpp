#include <iostream>
#include "Tuple.h"
#include <tuple>

using namespace std;

int main()
	{
	Tuple tup(1, "kek"s);
	cout << tup.get<0>() << ' ' << tup.get<1>() << endl;

	Tuple<int, string> tup2;
	tup2 = tup;
	cout << tup2.get<0>() << ' ' << tup2.get<1>() << endl;

	auto& [x, y] = tup;
	x = 2;
	y = "lol";
	cout << tup.get<0>() << ' ' << tup.get<1>() << endl;

	Tuple<int&, string&> tup_ref{x, y};
	tup_ref.get<0>() = 0;
	tup_ref.get<1>() = "zero";
	cout << x << ' ' << y << endl;

	int a;
	Tuple t{a};
	Tuple<int> t2 = t;
	}