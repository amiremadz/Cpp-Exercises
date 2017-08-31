//============================================================================
// Name        : passing_functions.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void test(){
	cout << "Hi" << endl;
}

int anotherTest(int n){
	return n;
}

bool match(const string &text){
	return text.size() == 3;
}

int countStrings(const vector<string> texts, bool (*match)(const string &)){
	int count = 0;
	for(auto str:texts){
		if(match(str)){
			count++;
		}
	}
	return count;
}

int main() {

	test();

	void (*ptr1)();

	/*
	ptr1 = &test;
	(*ptr1)();
	*/

	ptr1 = test;
	ptr1();

	cout << endl;

	/*
	int (*ptr2)(int);
	ptr2 = &anotherTest;
	cout << (*ptr2)(8) << endl;
	*/

	cout << anotherTest(7) << endl;
	int (*ptr2)(int);
	ptr2 = anotherTest;
	cout << ptr2(8) << endl;

	cout << endl;

	vector<string> texts;

	texts.push_back("one");
	texts.push_back("two");
	texts.push_back("three");
	texts.push_back("four");
	texts.push_back("five");
	texts.push_back("six");

	int mycount = count_if(texts.begin(), texts.end(), match);
	cout << mycount << endl;

	cout << countStrings(texts, match) << endl;

	return 0;
}
