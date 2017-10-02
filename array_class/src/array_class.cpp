//============================================================================
// Name        : _class.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "array.h"
#include <vector>


int main() {

	array<int32_t> arr_1(5, {1, 2, 3, 4, 5});
	array<int32_t> arr_2(3);

	arr_2.add(1);
	arr_2.add(2);
	arr_2.add(3);
	arr_2.add(4);

	// Copy constructor
	array<int32_t> arr_3(arr_2);

	array<int32_t> arr_4(4);
	arr_4.add({4, 5, 6, 7, 8});


	arr_1.print();

	cout << "\narray_1:" << endl;
	cout << arr_1.get(2) << endl;
	cout << arr_1[3] << endl;
	cout << arr_1 << endl;
	cout << "size: " << arr_1.size() << endl;

	cout << ""
			"\narray_2:" << endl;
	cout << arr_2 << endl;

	cout << "\narray_3:" << endl;
	cout << arr_3 << endl;

	cout << "\narray_4:" << endl;
	cout << arr_4 << endl;

	if(arr_1 == arr_2){
		cout << "arr_1 and arr_2 are equal" << endl;
	}
	else{
		cout << "arr_1 and arr_2 are not equal" << endl;
	}

	if(arr_2 != arr_3){
		cout << "arr_2 and arr_3 are not equal" << endl;
	}
	else{
		cout << "arr_2 and arr_3 are equal" << endl;
	}


	for(auto item : arr_1){
		cout << item << " ";
	}
	cout << endl;

	for(auto itt = arr_1.begin(); itt != arr_1.end(); itt++){
		cout  << *itt << " ";
	}
	cout << endl;

	// Move constructor
	vector<array<int>> vec;
	vec.push_back(array<int>(3, {22, 33, 44}));
	cout << vec[0] << endl;

	// Copy constructor
	array<int> arr_5 = arr_1;
	cout << arr_5 << endl;

	// Assignment constructor
	array<int> arr_6;
	arr_6 = arr_1;

	cout << "array_6:" << endl;
	cout << arr_6 << endl;

	// Move assignment
	array<int> arr_7;
	arr_7 = array<int>(2, {8, 9});

	cout << "array_7:" << endl;
	cout << arr_7 << endl;

	cout << "Done" << endl;
	return 0;
}
