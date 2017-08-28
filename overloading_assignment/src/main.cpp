//============================================================================
// Name        : stl_complex_dataTypes.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Person{
public:
	Person(): mId(0), mName("") {}
	Person(int id, string name): mId(id), mName(name){}
private:
	int mId;
	string mName;
public:
	void print(){
		cout << mId << " : " << mName << endl;
	}
public:
	const Person &operator=(const Person &other){
		cout << "Assignment running." << endl;
		mId = other.mId;
		mName = other.mName;
		return *this;
	}
public:
	Person(const Person &other){
		cout << "Copy constructor running." << endl;
		mId = other.mId;
		mName = other.mName;
		//*this = other.
	}
public:
	~Person(){}
};


int main() {

	Person person1(10, "Mike");
	cout << "print person1: " << flush;
	person1.print();

	Person person2(20, "Bob");
	cout << "print person2: " << flush;
	person2.print();

	// Shallow copy: copying all the avlues of person1 to person2
	// This may be not desirable. Pointers might be issue.
	cout << "Assignment1: " << endl;
	person2 = person1;
	person2.print();

	Person person3;
	cout << "Assignement2:" << endl;
	person3.operator=(person2);

	cout << "print person3: " << flush;
	person3.print();

	cout << endl;

	// Assignment operator is not called!
	// Copy initialization. Implicit invoke of copy constructor.
	// Because the object is not initialized.
	Person person4 = person1;
	person4.print();


	return 0;
}
