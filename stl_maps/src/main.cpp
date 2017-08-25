//============================================================================
// Name        : stl_maps.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>

using namespace std;


int counter = 0;

class Person{
private:
	string mName;
	int mAge;
public:
	Person(): mName(""), mAge(0) {}

	Person(string name, int age): mName(name), mAge(age) {}
public:
	void print() {
		cout << mName << ": " << mAge << endl;
	}
public:
	Person(const Person &other){
		counter++;
		cout << counter << ": Copy constructor running!" << endl;
		mAge = other.mAge;
		mName = other.mName;
	}
};

int main() {

	map<string, int> ages;

	ages["Sue"] = 9;
	ages["Jack"] = 13;
	ages["Mimi"] = 82;

	map<string, int>::iterator it;

	for(it=ages.begin(); it != ages.end(); it++){
		cout << it->first << " : " << it->second << endl;
	}

	cout << ages["nonexistent_1"] << endl;

	for(it=ages.begin(); it != ages.end(); it++){
		cout << it->first << " : " << it->second << endl;
	}

	if(ages.find("nonexistent_2") != ages.end()){
		cout << "Key: " << ages["monexistent_2"] << endl;
	}
	else{
		cout << "Key not found" << endl;
	}

	for(it=ages.begin(); it != ages.end(); it++){
		pair<string, int> ageInfo = *it;

		cout << ageInfo.first << " : " << ageInfo.second << endl;
	}

	pair<string, int> peter("Peter", 98);
	ages.insert(peter);

	ages.insert(pair<string, int>("Rob", 44));

	ages.insert(make_pair("Don", 56));

	for(it=ages.begin(); it != ages.end(); it++){
		cout << it->first << " : " << it->second << endl;
	}

	// Objects as map values
	map<int, Person> people;

	Person("John", 12);

	people[0] = Person("John", 12);			// copy constructor called 2 time
	people[2] = Person("Sue", 67);
	people[1] = Person("Jerry", 45);
	people.insert(make_pair(3, Person("Jenny", 65)));
	people[1] = Person("Jack", 45);     	// This is only assignment since the key already exists
											// Copy constructor called only 1 time

	map<int, Person>::iterator itt;

	for(itt=people.begin(); itt != people.end(); itt++){
		cout << itt->first << " : " << flush;
		itt->second.print();
	}


	return 0;
}
