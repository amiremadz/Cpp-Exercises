//============================================================================
// Name        : templates.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

template<typename T>
class Test{
public:
	Test(T obj){
		mObj = obj;
	}
public:
	void print(){
		cout << mObj << endl;
	}
private:
	T mObj;
};

// Explicit specialization
template<>
void Test<double>::print(){
	cout << scientific << mObj << endl;
}


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

	return 0;
}
