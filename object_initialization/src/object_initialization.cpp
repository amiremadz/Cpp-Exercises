//============================================================================
// Name        : object_initialization.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Test{
private:
	int mId{4};
	string mName{"Mike"};
public:
	Test() = default;  						// same as Test() {}
	Test(int id): mId(id) {} 				// Now, implicit constructor must be defined
	Test(const Test &other) = default; 		// default copy constructor
	//Test(const Test &other) = delete;  	// remove default copy constructor
	Test &operator=(const Test &other) = default;
public:
	void print(){
		cout << mId << " : " << mName << endl;
	}
};


int main() {

	Test test;
	test.print();

	Test someTest(56);
	someTest.print();

	Test test2 = someTest;	// Copy constructor
	test2 = test;			// Assignment operator

	return 0;
}
