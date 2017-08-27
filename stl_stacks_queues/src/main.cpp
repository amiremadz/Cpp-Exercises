//============================================================================
// Name        : stl_stacks_queues.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int counter = 0;

class Person{
private:
	string mName;
public:
	Person(string name):mName(name) { cout << "Constructor called." << endl; }
public:
	void print(){
		cout << mName << endl;
	}
public:
	~Person(){
		counter++;
		//cout << counter << " : Object destroyed." << endl;
	}
};


int main() {

	// Stack: LIFO

	stack<Person> myStack;

	myStack.push(Person("Mike")); // destructor is called 1 time.
	myStack.push(Person("John"));
	myStack.push(Person("Sue"));

	//Person top = myStack.top(); // top returns a reference to object. =: Shallow copy -> destructor is called
	Person &top = myStack.top();  // destructor is not called. No copy.
	top.print();

	/*
	// Bad code: Invalid code. Object is destroyed.
	Person &badtop = myStack.top();
	myStack.pop();
	badtop.print();
	*/

	/*
	// Good code
	Person goodtop = myStack.top();
	myStack.pop();
	goodtop.print();
	*/

	cout << endl;

	while(myStack.size() != 0){
		Person &person = myStack.top();
		person.print();
		myStack.pop();
	}

	cout << endl;

	// Queue: FIFO

	queue<Person> myQueue;
	myQueue.push(Person("Jen"));
	myQueue.push(Person("Lance"));
	myQueue.push(Person("Jessy"));

	cout << "Queue back: " << flush;
	myQueue.back().print();

	while(myQueue.size() != 0 ){
		Person &person = myQueue.front();
		person.print();
		myQueue.pop();
	}



	return 0;
}
