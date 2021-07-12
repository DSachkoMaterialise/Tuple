#include <iostream>
#include "Tuple.h"

using namespace std;

int main()
	{
	Tuple<int, string> tup(1, "kek");

	cout << tup.get<0>() << ' ' << tup.get<1>();
	}