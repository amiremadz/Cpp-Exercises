//============================================================================
// Name        : delegating_constructors.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Parent {
private:
	int mDogs{44};
	string mText{"dum"};
public:

	Parent(): Parent("Hola"){
		mDogs = 5;
		cout << "No param parent constructor" << endl;
	}

	// delegating constructor
	// Because of this, the default constructor won't be available, unless redefined.
	Parent(string text){
		mDogs = 5;
		mText = text;
		cout << "String parent constructor" << endl;
	}
};

class Child : public Parent {
public:
	//Child() : Parent("hi");
	Child() = default;
};


int main() {
	Parent parent("hello");
	Child child; // it must run the parent constructor
				 // it calls the default constructor of Child

	return 0;
}
