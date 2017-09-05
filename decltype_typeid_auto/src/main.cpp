//============================================================================
// Name        : decltype_typeid.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <typeinfo>

using namespace std;

auto test() -> int {
	return 10;
}


template<typename T, typename S>
auto usefulTest(T value1, S value2) -> decltype(value1 + value2) {
	return value1 + value2;
}

int get(){
	return 888;
}

auto mytest() -> decltype(get()){
	return get();
}


int main() {

	string val;

	// Name mangling
	cout << typeid(val).name() << endl;

	cout << endl;

	decltype(val) name = "Bob";
	cout << typeid(name).name() << endl;
	cout << endl;

	int num;
	cout << typeid(num).name() << endl;
	cout << endl;

	auto text = "hi";
	auto n = 8;

	cout << typeid(text).name() << endl;
	cout << typeid(n).name() << endl;
	cout << typeid(decltype(n)).name() << endl;

	cout << endl;

	cout << test() << endl;
	cout << usefulTest(1, 2.1) << endl;
	cout << mytest() << endl;

	return 0;
}
