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
#include <typeinfo>

using namespace std;

class Test{
private:
	static const int kSIZE = 100;
	int *m_pBuffer { nullptr };
public:
	Test(){
		//cout << "empty constructor" << endl;
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

	//*
	Test(Test &&other){
		cout << "Move constructor" << endl;
		m_pBuffer = other.m_pBuffer;
		other.m_pBuffer = nullptr;
	}
	//*/

public:
	Test operator=(const Test &other){
		//cout << "assignment" << endl;
		m_pBuffer = new int[kSIZE]{};
		memcpy(m_pBuffer, other.m_pBuffer, kSIZE*sizeof(int));
		return *this;
	}

	Test operator=(Test &&other){
		cout << "move assignement" << endl;
		// The object that we are assigning to, already has beed alocated memory
		// it needs to be freed.
		delete[] m_pBuffer;
		m_pBuffer= other.m_pBuffer;

		// Now, we should stop other trying to delete that memory
		other.m_pBuffer = nullptr;

		return *this;
	}

	friend ostream &operator<<(ostream &out, const Test &test);

public:
	~Test(){
		//cout << "destructor" << endl;
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

void check(const Test &rTest){
	cout << "Lvalue reference: Test" << endl;
}

void check(Test &&rTest){
	cout << "Rvalue reference: Test" << endl;
}


void check_int(const int &rInt){
	cout << "Lvalue reference: int" << endl;
}

void check_int(int &&rInt){
	cout << "Rvalue reference: int" << endl;
}

//‑fno‑elide‑constructors
int main() {
#if 1
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

	cout << endl;

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

	cout << endl;

	// Lvalue References

	vector<Test> vec;
	vec.push_back(Test());

	Test &rTest1 = mytest;
	//Test &rTest2 = getTest();		// does not work: mutable Lvalue reference cannot bind to Rvalues

	const Test &rTest3 = getTest(); // works: const Lvalue reference can bind to Rvalues

	Test test2(Test());				// Copy constructor: Test() is Rvalue
									// input to copy is const Lvalue reference
	int var = 88;
	int &rVar = var;
	var = 99;
	cout << rVar << endl;

	cout << endl;

	// Rvalue references

	Test &&rMyTest1 = Test();
	Test &&rMyTest2 = getTest();

	cout << typeid(rMyTest1).name() << endl;

	cout << "*** Lvalue reference:" << endl;
	check(rTest1);
	check(rMyTest1);
	check(rMyTest2);

	cout << "*** Rvalue reference:" << endl;
	check(Test());
	check(getTest());

	cout << endl;

	int val = 12;

	check_int(val++);
	check_int(++val);

	int && rVal = val++;
	cout << "reference: " << rVal << endl;
	cout << "value: "<< val << endl;

	val = 16;
	cout << "value: " << val << endl;
	cout << "reference: " << rVal << endl;


	cout << endl;
#endif
	// Move constructor

	vector<Test> vect;
	vect.push_back(Test());

	// Move assignment constructor
	Test test;
	test = getTest(); // assigning to an Rvalue

	return 0;
}
