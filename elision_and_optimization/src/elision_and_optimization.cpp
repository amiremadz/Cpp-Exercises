//============================================================================
// Name        : elision_and_optimization.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Test{
public:
	Test(){
		cout << "empty constructor" << endl;
	}
	Test(int i){
		cout << "parameterized constructor" << endl;
	}
	Test(const Test &other){
		cout << "copy constructor" << endl;
		*this = other;
	}
public:
	Test operator=(const Test &other){
		cout << "assignment" << endl;
		*this = other;
		return *this;
	}
	friend ostream &operator<<(ostream &out, const Test &test);
public:
	~Test(){
		cout << "destructor" << endl;
	}
};

ostream &operator<<(ostream &out, const Test &test){
	out << "Print Test";
	return out;
}

Test getTest(){
	return Test();
}

//‑fno‑elide‑constructors
int main() {

	Test mytest = getTest();
	cout << mytest << endl;

	return 0;
}
