//============================================================================
// Name        : circular_buffer.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Circular.h"
#include <vector>

using namespace std;

Circular<int> getCircular(){
	return Circular<int>();
}

int main() {

	Circular<int> buff{1, 2, 3, 4};

	cout << buff << endl;

	buff.add(5);

	cout << buff << endl;

	buff.add({6, 7});

	cout << buff << endl;

	Circular<int> cpy_buff(buff);

	cout << cpy_buff << endl;

	cout << cpy_buff[2] << endl;

	Circular<int> assgn_buff;
	assgn_buff = cpy_buff;

	cout << assgn_buff	<< endl;

	cout << assgn_buff[0]	<< endl;

	vector< Circular<int> > vec{ Circular<int>{3, 4} };

	// Move constructor
	vec.push_back(Circular<int>{6, 7, 8});

	cout << vec[0] << endl;

	for(auto val : buff){
		cout << val << endl;
	}

	cout << endl;

	for(Circular<int>::iterator it=buff.begin(); it != buff.end(); it++){
		cout << *it << endl;
	}

	// Move assignment
	Circular<int> test;
	test = getCircular();

	return 0;
}
