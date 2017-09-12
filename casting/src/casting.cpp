//============================================================================
// Name        : casting.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Parent{
public:
	void speak(){
		cout << "parent!" << endl;
	}

};

class Brother : public Parent{

};

class Sister : public Parent{

};

int main() {

	Parent parent;
	Brother brother;

	float a = 2.34;
	cout << a << ", " << (int)a << ", " << int(a) << ", " << static_cast<int>(a) << endl;

	Parent *pParent = &brother;  							// we can use a pointer to a subclass
	//Brother *pBrother = &parent; 							// will not work
	Brother *pBrother = static_cast<Brother *>(&parent); 	// this works.very unsafe: virtual methods, methods in Brother which don't exist in Parent
	cout << pBrother << endl;

	Parent *ppb = &brother;
	Brother *pbb = static_cast<Brother *>(ppb); // static_cast is purely a compile time thing
												// there is no runtime checking
	cout << pbb << endl;

	Parent &&p1 = Parent();
	//Parent &&p2 = parent;		// will not work
	Parent &&p3 = static_cast<Parent &&>(parent); // Rvalue reference. function with a parameter type that is Rvalue reference
												  // can use this to pass in a Lvalue
	p3.speak();

	return 0;
}
