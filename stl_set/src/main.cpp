//============================================================================
// Name        : stl_set.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <set>

using namespace std;

class Person{
private:
	int mId;
	string mName;
public:
	// Empty constructor: Needed for creating sets of object
	Person(): mId(0), mName(""){}
	Person(int id, string name): mId(id), mName(name) {}
public:
	// Needs to be const: to be able to put object in a set
	void print() const {
		cout << mId << " : " << mName << endl;
	}
public:
	// Needed to have a set of objects
	bool operator<(const Person &other) const {
		return mId < other.mId;
	}
};

int main() {

	set<int> numbers;

	numbers.insert(50);
	numbers.insert(20);
	numbers.insert(10);
	numbers.insert(20);

	set<int>::iterator itt;

	for(itt=numbers.begin(); itt!=numbers.end(); itt++){
		cout << *itt << endl;
	}

	itt = numbers.find(20);

	if(itt != numbers.end()){
		cout << "Found: " << *itt << endl;
	}
	else{
		cout << "Not found: " << endl;
	}

	if(numbers.count(30)){
		cout << "Found." << endl;
	}
	else{
		cout << "Not found." << endl;
	}

	cout << endl;

	// Objects as set members

	set<Person> people;

	people.insert(Person(10, "Mike"));
	people.insert(Person(30, "Jack"));
	people.insert(Person(20, "Joe"));

	set<Person>::iterator ittr;

	for(ittr=people.begin(); ittr!=people.end(); ittr++){
		ittr->print();
	}

	return 0;
}
