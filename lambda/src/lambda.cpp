//============================================================================
// Name        : lambda.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

using namespace std;


void test(void (*pFunc)(void)){
	pFunc();
}

void testGreet(void (*pFunc)(string)){
	pFunc("Mike");
}

/*
double runDivide( double (*pDivide)(double, double)){
	return pDivide(2.1, 3.2);
}
*/

void runDivide( double (*pDivide)(double, double)){
	cout << pDivide(2.1, 3.2) << endl;
}

class Test{
private:
	int one{1};
	int two{2};
public:
	void run(){
		int three{3};
		int four{4};

		// use this to capture instance variables
		// they are captured by reference
		// this can be anywhere: auto pLambda = [three, this, four]() {}
		// does not work: [=, this](){}
		// does work:     [&, this](){}: capture local variables by
		// reference, and instance variables
		auto pLambda = [=](){
			one = 824;
			cout << one << endl;
			cout << two << endl;
			cout << three << endl;
			cout << four << endl;
		};
		pLambda();
	}
};


int main() {

	// Basics

	auto func = [](){ cout << "Hi" << endl; };

	func();

	[](){ cout << "Hi" << endl; }();

	test(func);

	test([](){ cout << "Hi" << endl; });

	cout << endl;

	// Parameters and returns

	auto pGreet = [](string name){ cout << "Hi " << name << endl; };
	pGreet("John");

	testGreet(pGreet);

	auto pDivide = [](double a, double b) { return a/b; }; // No need to specify a return type

	// if multiple return types, use trailing return type
	auto pDivideZero = [](double a, double b) ->double {
		if(b == 0.0){
			return 0;
		}
		return a/b;
	};

	cout << pDivide(10.0, 5.1) << endl;
	cout << pDivideZero(10.0, 0.0) << endl;

	runDivide(pDivideZero);

	cout << endl;

	// Capture expressions

	int one = 1;
	int two = 2;
	int three = 3;

	// capture by value
	[one, two](){ cout << one << ", " << two << endl; }();

	// capture all local variables by value
	[=](){ cout << one << ", " << two << endl; }();

	// capture all local variables by value by default, but capture three by reference
	// This does not work: two is captured by value
	//[=, &three](){ two = 6; cout << one << ", " << two << endl;}();

	// capture all local variables by value by default, but capture three by reference
	[=, &three](){ three = 6; cout << one << ", " << two << endl; }();
	cout << three << endl;

	// capture all local variables by reference
	[&](){ one = 8; cout << one << ", "<< two << endl; }();

	// capture all local variables by reference by default, but one by value
	[&, one](){ two = 66; cout << one << ", "<< two << endl; }();

	cout << endl;

	// Capturing this with expressions

	Test test;
	test.run();

	// Mutable

	int dog = 44;

	[dog]() mutable{
		dog = 55;
		cout << dog << endl;
	}();
	cout << dog << endl;


	return 0;
}
