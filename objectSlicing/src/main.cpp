//============================================================================
// Name        : objectSlicing.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


class Parent{
public:
	Parent(): one(0) { cout << "parent constructor" << endl; } // After defining the copy constructor, we lose the implicit empty constructor

	Parent(const Parent &other): one(0){
		one = other.one;
		cout << "copy parent" << endl;
	}
public:
	virtual void print(){
		cout << "parent" << endl;
	}
private:
	int one;

public:
	virtual ~Parent() {}
};

// when we define a subclass, we must either have a default constructor in parent class
// or else, we must specify what constructor we want to run
class Child : public Parent{
public:
	Child(): two(0) { cout << "child constructor" << endl; }
private:
	int two;
public:
	void print(){
		cout << "child" << endl;
	}
public:
	virtual ~Child() {}
};


int main() {

	Child child;
	cout << endl;

	Parent &parent = child; // Object slicing: "two" variable is sliced away
	cout << endl;

	parent.print();

	cout << endl;

	// Copy initialization: Implicit copy constructor from Parent class
	// Upcasting a child object to parent type
	Parent p2 = Child();
	cout << endl;

	p2.print();

	return 0;
}
