//============================================================================
// Name        : stl_list.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <list>

using namespace std;

int main() {

	list<int> numbers;

	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_front(0);

	list<int>::iterator it;

	it = numbers.begin();

	it++;
	cout << "Element: " << *it << endl;
	numbers.insert(it, 100);   					// insert before current element
	cout << "Element: " << *it << endl;

	it++;
	cout << "Element: " << *it << endl;
	numbers.insert(it, 200);
	cout << "Element: " << *it << endl;

	for(it=numbers.begin(); it!=numbers.end(); it++){
		cout << *it << endl;
	}

	list<int>::iterator eraseIt = numbers.begin();

	eraseIt++;
	eraseIt = numbers.erase(eraseIt);			// delete element from list
	cout << "Element: " << *eraseIt << endl;

	for(it = numbers.begin(); it != numbers.end(); it++){
		cout << *it << endl;
	}

	cout << "List size: " << numbers.size() << endl;

	it = numbers.begin();

	while(it != numbers.end()){
		if(*it == 1){
			it = numbers.erase(it);
		}
		else{
			it++;
		}
	}

	cout << "After deleting 1:" << endl;

	for(it = numbers.begin(); it != numbers.end(); it++){
		cout << *it << endl;
	}

	return 0;
}
