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

int main() {

	// Basics

	auto func = [](){ cout << "Hi" << endl; };

	func();

	[](){ cout << "Hi" << endl; }();

	test(func);

	test([](){ cout << "Hi" << endl; });


	return 0;
}
