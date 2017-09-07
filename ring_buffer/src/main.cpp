//============================================================================
// Name        : ring_class.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "RingBuffer.h"
//#include "Ring.h"

using namespace std;
//using namespace ring;

int main() {

	RingBuffer<int> vec_ints(3);
	vec_ints.add(1);
	vec_ints.add(2);
	vec_ints.add(3);
	vec_ints.add(4);

	for(RingBuffer<int>::iterator itt = vec_ints.begin(); itt != vec_ints.end(); itt++){
		cout << *itt << endl;
	}

	cout << endl;

	for(auto item : vec_ints){
		cout << item << endl;
	}

	cout << endl;

	RingBuffer<string> textstring(3);

	textstring.add("one");
	textstring.add("two");
	textstring.add("three");
	textstring.add("four");
	textstring.add("five");
	textstring.add("six");


	for(size_t i=0; i<textstring.size(); i++){
		cout << textstring.get(i) << endl;
	}

	cout << endl;

	for(RingBuffer<string>::iterator it = textstring.begin(); it != textstring.end(); it++){
		cout << *it << endl;
	}

	cout << endl;

	for(auto val : textstring){
		cout << val << endl;
	}

	return 0;
}
