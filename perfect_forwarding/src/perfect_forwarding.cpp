//============================================================================
// Name        : perfect_forwarding.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <typeinfo>
using namespace std;

class Test{
private:
	int _id{0};
public:
	Test() : _id(5) {}
public:
	int id() { return _id; }
};

// we could call this function either with Rvalye or Lvalue arg
// we want ro preserve Lvalue or Rvalueness of arg : perfect forwarding
template<typename T>
void call(T && arg){
	//check(arg); 					    // pass in an Lvalue
	//check(static_cast<T>(arg));		// preserve Lvalue/Rvalueness
	check(forward<T>(arg));				// preserve Lvalue/Rvalueness
}

void check(Test &test){
	cout << "lvalue" << endl;
}

void check(Test &&test){
	cout << "Rvalue" << endl;
}

int main() {

	Test test; // Lvalue

	auto &&t1 = Test(); // Rvalue

	auto &&t2 = test;   // works: if auto boils down to lvalue reference type, we get Lvalue reference

	//Test &&t3 = test;	// t3 cannot be an Rvalue reference: does not bind to an Lvalue

	call(Test());	// pass in an Rvalue
	call(test);		// pass in an Lvalue

	cout << test.id() << endl;

	cout << typeid(test).name() << endl;

	return 0;
}
