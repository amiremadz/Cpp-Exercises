//============================================================================
// Name        : rangeBasedLoops.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <typeinfo>

using namespace std;

int main() {

	char* texts1[] = {"one", "two"};

	cout << typeid(texts1).name() << endl;

	for(auto text:texts1){
		cout << text << endl;
	}

	auto texts2 = {"three", "four"};

	cout << typeid(texts2).name() << endl;

	// This does not work!
	//cout << texts2[0] << endl;

	return 0;
}
