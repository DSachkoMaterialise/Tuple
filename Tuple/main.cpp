#include <iostream>
#include "Tuple.h"

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
	}