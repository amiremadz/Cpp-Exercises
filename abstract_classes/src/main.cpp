//============================================================================
// Name        : abstract_classes.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


// Does not make sense to instantiate Animal
// Abstract class: contains only pure virtual function
// Cannot instantiate it
// Cannot run a constructor
class Animal{
public:
	// All pure virtual methods must be implemented in derived classes
	virtual void run() = 0;
	virtual void speak() = 0; // pure virtual function
public:
	virtual ~Animal() {}
};

// Dog cannot be instantiated, because
// run() is not implemented.
class Dog : public Animal{
public:
	virtual void speak(){
		cout << "Woof!" << endl;
	}
public:
	virtual ~Dog() {}
};

class Lab : public Dog{
public:
	virtual void run(){
		cout << "Lab is running!" << endl;
	}
};

void test(Animal &a){
	a.run();
}

int main() {

	//Dog dog;
	//dog.speak();

	Lab lab;
	lab.run();
	lab.speak();

	cout << endl;

	// Cannot creat an array
	// Because the constructor of object is run
	//Animal animals[4];

	// Lab constructor is run
	Lab labs[4];

	// Array of pointers
	Animal *animals[5];
	animals[0] = &lab;
	animals[0]->speak();

	cout << endl;

	test(lab);

	return 0;
}
