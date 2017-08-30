//============================================================================
// Name        : templates.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Storage.h"
#include "Test.h"
#include <stdio.h>

using namespace std;

template<typename T>
void print(T val){
	cout << val << endl;
}

template<>
void print<double>(double val){
	cout << scientific << val << endl;
}

void print(int n){
	cout << "Non-template version" << endl;
}

template<typename T>
void show(){
	cout << T() << endl;
}


int main() {


	// Dynamically allocate a temporary string
	char *string = new char[40];

	// Ask user for their name
	cout << "Enter your name: ";
	cin >> string;

	// Store the name
	Storage<char*> value(string);

	// Delete the temporary string
	delete[] string;

	// Print out our value
	value.print(); // This will print garbage

	Storage<int> val(5);
	val.print();

	cout << "End" << endl;

#if 0
	Test<string> test("Hi");
	test.print();

	cout << endl;

	Test<double> my_double(5.1);
	my_double.print();

	cout << endl;

	Test<int> my_int(5);
	my_int.print();

	cout << endl;

	print<int>(5);

	print<string>("Hello");

	print("Hola");

	// Non-tempalte version
	print(6);

	// Template version
	print<>(6);

	// Tyoe must be explicit
	show<int>();

	// Explicit specialization
	print(6.1);
	print<double>(7);
#endif
	return 0;
}
