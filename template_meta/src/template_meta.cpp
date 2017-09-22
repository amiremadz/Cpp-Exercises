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
	enum { value = n * factoriel<n-1>::value };
};

// template specialization
template<>
struct factoriel<1>{
	enum { value = 1 };
};

int main() {

	cout << factoriel<5>::value << endl;

	cout << "Done!" << endl;

	return 0;
}
