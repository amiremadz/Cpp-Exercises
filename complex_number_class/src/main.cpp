//============================================================================
// Name        : complex_number_class.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Complex.h"

using namespace std;
using namespace complex;

int main() {
	Complex c1(1.1, 1.2);
	Complex c2(2.3, 3.1);
	Complex c3, c4;
	cout << endl;
	Complex c5 = c1;	// Copy constructor inialization

	cout << endl;
	c5 = c1;			// Assignment operator

	cout << endl;
	Complex c6(c2);		// Copy constructor
	cout << endl;

	c3 = c1 + c2;
	c4 = c1 - c2;

	cout << c3 << endl;

    cout << endl;

	cout << c1 + c2 + c3 << endl;

	cout << c1 + 6 << endl;

	cout << c1 - 4 << endl;

	cout << 2.1 + c1 + 3.5 + c2 << endl;

	cout << 1 - c2 << endl;

	cout << endl;

	if(c1 == c2){
		cout << "Equals" << endl;
	}
	else{
		cout << "Not equal" << endl;
	}

	if(c1 != c2){
		cout << "Not equal" << endl;
	}
	else{
		cout << "Equals" << endl;
	}

	cout << endl;
	// Complex conjugate
	cout << *c1 << endl;

	return 0;
}
