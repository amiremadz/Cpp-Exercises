//============================================================================
// Name        : elision_and_optimization.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <memory.h>
#include <vector>

using namespace std;

class Test{
private:
	static const int kSIZE = 100;
	int *m_pBuffer;
public:
	Test(){
		cout << "empty constructor" << endl;
		m_pBuffer = new int[kSIZE]{};  				// or {}
		//memset(m_pBuffer, 0, kSIZE*sizeof(int));  // from memory library

	}
	Test(int i) : Test(){
		cout << "parameterized constructor" << endl;
		for(int i=0; i<kSIZE; i++){
			m_pBuffer[i] = 7*i;
		}
	}
	Test(const Test &other){
		cout << "copy constructor" << endl;
		m_pBuffer = new int[kSIZE]{};
		memcpy(m_pBuffer, other.m_pBuffer, kSIZE*sizeof(int));
	}
public:
	Test operator=(const Test &other){
		cout << "assignment" << endl;
		m_pBuffer = new int[kSIZE]{};
		memcpy(m_pBuffer, other.m_pBuffer, kSIZE*sizeof(int));
		return *this;
	}
	friend ostream &operator<<(ostream &out, const Test &test);
public:
	~Test(){
		cout << "destructor" << endl;
		delete[] m_pBuffer;
	}
};

ostream &operator<<(ostream &out, const Test &test){
	out << "Print Test";
	return out;
}

Test getTest(){
	return Test();
}

//‑fno‑elide‑constructors
int main() {

	// Without optimization:
	// constructor: Test()
	// copy constructor: return->copy to temporary return value
	// destructur: of Test()
	// copy constructor: to mytest
	// destructor: temporary returned object destroyed
	// print
	// destructor: of mytest
	Test mytest = getTest();
	cout << mytest << endl;

	// Rvalues and Lvalues

	// Lvalue: anything that you can get the address of
	int value = 7;
	int *pValue = &value;
	// int *pVal = &7;     			// wrong: 7 is an Rvalue

	Test *pMytest = &mytest;
	// Test *pTest = &getTest()   	// wrong: function return value is Rvalue

	int *pValue2 = &++value;
	cout << *pValue2 << endl;

	//int *pValue2 = &++value; 		// wrong: Rvalue
	//int *pS = &(7 + value);		// wrong: Rvalue

	// Lvalue References

	vector<Test> vec;
	vec.push_back(Test());

	Test &rTest1 = mytest;
	//Test &rTest2 = getTest();		// does not work: mutable Lvalue reference cannot bind to Rvalues

	const Test &rTest3 = getTest(); // works: const Lvalue reference can bind to Rvalues

	Test test2(Test());				// Copy constructor: Test() is Rvalue
									// input to copy is const Lvalue reference



	return 0;
}
