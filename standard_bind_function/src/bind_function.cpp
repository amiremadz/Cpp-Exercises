//============================================================================
// Name        : bind_function.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <functional>

using namespace std;
using namespace placeholders;





class Test{
public:
	int add(int a, int b, int c){
		cout << a << ", " << b << ", " << c << endl;
		return a + b + c;
	}

	int run(function<int(int, int)> func){
		func(7, 3);
	}

	static int multiply(int a, int b, int c){
		cout << a << ", " << b << ", " << c << endl;
		return a * b * c;
	}
};

int add(int a, int b, int c){
	cout << a << ", " << b << ", " << c << endl;
	return a + b + c;
}

int run(function<int(int, int)> func){
	func(7, 3);
}

int main() {

	cout << add(1, 2, 3) << endl;

	cout << endl;

	auto calculate = bind(add, 3, 4, 5);
	cout << calculate() << endl;

	cout << endl;

	// placeholders: one can change their order
	auto my_calculate = bind(add, _1, _2, _3);
	cout << my_calculate(3, 4, 5) << endl;

	cout << endl;

	auto more_calculate = bind(add, _2, _3, _1);
	cout << more_calculate(3, 4, 5) << endl;

	cout << endl;

	auto another_calculate = bind(add, _2, 100, _1);
	cout << another_calculate(30, 40) << endl;

	cout << endl;
	cout << run(another_calculate) << endl;

	cout << endl;

	Test test;

	// placeholders: one can change their order
	// for methods, & for pointer is obligatory
	// we need to pass-jn the object
	auto method_calculate = bind(&Test::add, test, 200, 400, 300);
	cout << method_calculate() << endl;

	cout << endl;

	auto method_mycalculate = bind(&Test::add, test, _2, 400, _1);
	cout << method_mycalculate(500, 600) << endl;

	cout << endl;

	// class methods: pass-in object not needed
	auto static_calculate = bind(&Test::multiply, _2, 4, _1);
	cout << static_calculate(5, 6) << endl;


	return 0;
}
