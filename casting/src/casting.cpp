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
	// if not virtual, dynamic_cast will not work
	virtual void speak(){
		cout << "parent!" << endl;
	}

};

class Brother : public Parent{

};

class Sister : public Parent{

};

int main() {

	// static_cast

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

	// dynamic_cast

	// This is ok
	//Parent *ppb = &brother;
	//Brother *pbb = static_cast<Brother *>(ppb);

	// what if:
	Parent *ppb2 = &parent;
	Brother *pbb2 = static_cast<Brother *>(ppb2);

	Brother *pbb3 = dynamic_cast<Brother *>(ppb2);		// checks types at runtime to make sure make sense

	if(pbb3 == nullptr){
		cout << "invalid cast" << endl; // ppb2 = &parent
	}
	else{
		cout << pbb3 << endl; 			// ppb2 = &brother
	}

	// reinterpret_cast

	Parent *ptr2br = &brother;
	//Sister *ptr2sis = dynamic_cast<Sister *>(ptr2br); 	// this picks up the mistake
	//Sister *ptr2sis = static_cast<Sister *>(ptr2br);		// this does not pick up the mistake
	Sister *ptr2sis = reinterpret_cast<Sister *>(ptr2br);	// this does not pick up the mistake. it does a binary cast of one pointer type to another

	if(ptr2sis == nullptr){
		cout << "invalid cast" << endl;
	}
	else{
		cout << ptr2sis << endl;
	}

	return 0;
}
