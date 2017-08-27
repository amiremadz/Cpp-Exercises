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
	// Empty constructor is need if object is to be used as map's key or value
	Person(): mName(""), mAge(0) {}

	Person(string name, int age): mName(name), mAge(age) {}
public:
	// The keys in the map are returned as consts
	// So, method must be const
	void print() const {
		cout << mName << ": " << mAge << flush;
	}
public:
	Person(const Person &other){
		counter++;
		cout << counter << ": Copy constructor running!" << endl;
		mAge = other.mAge;
		mName = other.mName;
	}
public:
	// This is needed for map to be able to sort keys
	bool operator<(const Person &other) const {
		if(mName == other.mName){
			return mAge < other.mAge;
		}
		return mName < other.mName;
	}
};

int main() {

	// Basics

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

	cout << endl;

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

	cout << endl;
	cout << endl;

	// Objects as map keys

	map<Person, int> ppl;

	ppl[Person("Julie", 40)] = 44;
	ppl[Person("John", 30)] = 33;
	ppl[Person("Jack", 20)] = 22;
	ppl[Person("Jack", 20)] = 55;    // Key already exists
	ppl[Person("Jack", 60)] = 66;	 // Key does not change if age is not used in < operator

	map<Person, int>::iterator ittr;

	for(ittr=ppl.begin(); ittr!=ppl.end(); ittr++){
		cout << ittr->second << " : " << flush;
		ittr->first.print();
		cout << endl;
	}

	cout << endl;

	// Multimaps

	multimap<int, string> lockup;

	lockup.insert(make_pair(20, "John"));
	lockup.insert(make_pair(40, "Wen"));
	lockup.insert(make_pair(30, "Jack"));
	lockup.insert(make_pair(10, "Sue"));
	lockup.insert(make_pair(30, "Lili"));
	lockup.insert(make_pair(20, "Mike"));

	multimap<int, string>::iterator itt_m;

	for(itt_m=lockup.begin(); itt_m!=lockup.end(); itt_m++){
		cout << itt_m->first << " : " << itt_m->second << endl;
	}

	cout << lockup.find(20)->second << endl;

	typedef multimap<int, string>::iterator mlp_itt_t;

	pair<mlp_itt_t, mlp_itt_t> info;

	info = lockup.equal_range(30);

	for(mlp_itt_t itt = info.first; itt!=info.second; itt++){
		cout << itt->first << " : " << itt->second << endl;
	}

	auto result = lockup.equal_range(20);

	for(auto itt=result.first; itt!=result.second; itt++){
		cout << itt->first << " : " << itt->second << endl;
	}

	return 0;
}
