//============================================================================
// Name        : unique_pointers.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <memory>

using namespace std;

class Test{
public:
	Test(){
		cout << "Created" << endl;
	}
public:
	void greet(){
		cout << "Hello" << endl;
	}
public:
	~Test(){
		cout << "destroyed" << endl;
	}
};

class Temp{
private:
	//unique_ptr<Test[]> pTest<new Test[2]>; // does not work. we have to creat a constructor
										   // for Temp class
	unique_ptr<Test[]> pTest;

public:
	Temp() : pTest(new Test[2]){
	}
};


int main() {
	{// memory clean-up happens
	// smart pointers: they handle deallocation of memery for you
	//unique_ptr<int> pTest = new int; // does not work:
	// delete[]	is not needed
	unique_ptr<int> pInt(new int);
	*pInt = 7;
	cout << *pInt << endl;

	unique_ptr<Test> pTest(new Test);
	// auto_pair: does not work with arrays
	pTest->greet();

	unique_ptr<Test[]> pTestArr(new Test[3]); // <Test*> does not work
	pTestArr[0].greet();
	}
	cout << endl;

	{
	// Objects being allocated
	Temp temp;
	}
	cout << endl;

	cout << "Finished" << endl; // prints !!!Hello World!!!

	return 0;
}
