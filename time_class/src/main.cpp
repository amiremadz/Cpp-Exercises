//============================================================================
// Name        : time_class.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "time.h"

using namespace std;
using namespace mytime;



int main() {

	Time t1(23, 59);
	cout << t1 << endl;
	cout << endl;

	cout << ++t1 << endl;
	cout << t1++ << endl;
	cout << t1 << endl;
	cout << endl;

	Time t2 = t1;
	t1++;
	cout << t1 << endl;
	cout << t2 << endl;
	cout << endl;

	cout << t1.hour() << ": " << t1.minute() << endl;;

	return 0;
}
