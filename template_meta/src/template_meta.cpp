//============================================================================
// Name        : template_meta.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


template<int n>
struct factoriel{
	//enum { value = n * factoriel<n-1>::value };
    static int func() { return n*factoriel<n-1>::func(); }  // this musy be static.
};

// template specialization
template<>
struct factoriel<1>{
	//enum { value = 1 };
    static int func() { return 1; }                         // this must be static
};

void change(int &num){
	num *= 2;
}

void change(int* arr){
	arr[0] = 0;
}

int main() {

	//cout << factoriel<5>::value << endl;

    cout << factoriel<5>::func() << endl;

	int B;
	B = 3;
	change(B);
	cout << B << endl;

	int arr[3] = {1, 2, 3};

	change(arr);

	cout << arr[0] << endl;


	cout << "Done!" << endl;

	return 0;
}
