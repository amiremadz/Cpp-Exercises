//============================================================================
// Name        : standard_func_type.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;


bool check(string &txt){
	return txt.size() == 3;
}

class Check{
public:
	bool operator()(string &txt){
		return txt.size() == 3;
	}
};

class Add{
public:
	int operator()(const int &a, const int &b){
		return a + b;
	}
};

void run(function<bool(string&)> check){
	string test = "cat";
	cout << check(test) << endl;
}

int main() {

	vector<string> vec{"one", "two", "three"};

	size_t size = 3;
	int count;

	auto lambda = [&size](string txt){ return (txt.size() == size); };
	// using lambda
	count = count_if(vec.begin(), vec.end(), lambda);

	cout << count << endl;

	// using function pointer
	count = count_if(vec.begin(), vec.end(), check);

	cout << count << endl;

	Check mycheck;
	// using functor
	count = count_if(vec.begin(), vec.end(), mycheck);

	cout << count << endl;

	run(check);
	run(lambda);
	run(mycheck);

	function<int(int, int)> add = [](int a, int b){ return a+b; };
	cout << add(3, 8) << endl;

	Add myadd;
	cout << myadd(2, 3) << endl;

	return 0;
}
