//============================================================================
// Name        : overloading_plus_string.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>


using namespace std;



class MyString : public string{
public:
	MyString() : mStr("") {}
	MyString(string str): mStr(str) {}
	MyString(const MyString &other){
		cout << "copy constructor" << endl;
		*this = other;
	}
private:
	string mStr;
public:
	MyString operator+=(const MyString &rhs){
		mStr = mStr + "--" + rhs.mStr;
		return *this;
	}

	friend MyString operator+(const MyString &str1, const MyString &str2);

	friend ostream &operator<<(ostream &out, const MyString rhs);

};

ostream &operator<<(ostream &out, const MyString rhs){
	out << "*" << rhs.mStr << "*";
	return out;
}

MyString operator+(const MyString &str1, const MyString &str2){
		return MyString(str1.mStr + "+" + str2.mStr);
	}

int main() {

	MyString str1("Hi");
	MyString str2("Hello");
	MyString str3 = str1 + str2;
	MyString str4 = str3;
	str4 += MyString("Bye");

	cout << str1 << endl;
	cout << str3 << endl;
	cout << str4 << endl;

	return 0;
}
