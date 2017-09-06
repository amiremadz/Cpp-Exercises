//============================================================================
// Name        : functors.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct Test{
	virtual bool operator()(string &txt) = 0;
	virtual ~Test() {}
};


// Functor: it overloads paranthesis operator
struct MatchTest : public Test{
	virtual bool operator()(string &txt){
		return txt == "lion";
	}
	virtual ~MatchTest() {}
};

void check(string text, Test &test){
	if(test(text)){
		cout << "Strings match!" << endl;
	}
	else{
		cout << "Strings do not match!" << endl;
	}
}

int main() {

	MatchTest pred;
	string value = "liond";

	// cannot use literal value here: pass by reference
	// pred("lion")

	cout << pred(value) << endl;

	cout << endl;

	check("lion", pred);
	check("cat", pred);


	return 0;
}
