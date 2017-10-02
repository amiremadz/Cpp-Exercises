//============================================================================
// Name        : pass_by_reference.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void change(int &n){
	++n;
}

int main() {

	cout << 0 << endl;

	int a = 4;
	change(a);
	cout << "a: " << a << endl;

	int &b = a;
	change(b);
	cout << "a: " << a << " b: " << b << endl;

	int c = a;
	change(c);
	cout << "a: " << a << " b: " << b << " c: " << c << endl;


	int &d = a;
	change(d);
	cout << "a: " << a << " b: " << b << " c: " << c << " d: " << d << endl;

	return 0;
}
