//============================================================================
// Name        : stl_sorting.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Person{
public:
	Person(int id, string name):mId(id), mName(name) {}
private:
	int mId;
	string mName;
public:
	void print(){
		cout << mId << " : " << mName << endl;
	}

	friend bool comp(const Person &a, const Person &b);
/*public:
	bool operator<(const Person& other) const{
		return mId < other.mId;
	}*/
};

bool comp(const Person &a, const Person &b){
	return a.mId < b.mId;
}

int main() {

	vector<Person> vec;

	vec.push_back(Person(9, "Julie"));
	vec.push_back(Person(8, "Joe"));
	vec.push_back(Person(4, "Mike"));
	vec.push_back(Person(6, "Alex"));
	vec.push_back(Person(5, "Jen"));

	// Method 1: define < operator in class
	//sort(vec.begin(), vec.end());

	// Method 2: define comp function
	//sort(vec.begin(), vec.end(), comp);
	sort(vec.begin(), vec.begin()+4, comp);

	for(auto item:vec){
		item.print();
	}

	return 0;
}
