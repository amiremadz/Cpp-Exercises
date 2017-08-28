//============================================================================
// Name        : overloading_leftBitShift.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Person{
public:
	Person(): mId(0), mName("") {}
	Person(int id, string name): mId(id), mName(name) {}
public:
	Person(const Person &other){
		*this = other;
	}
public:
	const Person &operator=(const Person &other){
		mId = other.mId;
		mName = other.mName;
		return *this;
	}
	friend ostream &operator<<(ostream &out, Person person){
		out << person.mId << " : " << person.mName;
		return out;
	}
public:
	void print(){
		cout << mId << " : " << mName << endl;
	}
private:
	int mId;
	string mName;
};


int main() {

	Person person1(10, "Mike");
	person1.print();

	cout << person1 << endl;



	return 0;
}
