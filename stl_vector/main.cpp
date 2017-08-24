/*
 * main.cpp
 *
 *  Created on: Aug 24, 2017
 *      Author: aemadzadeh
 */
#include <iostream>
#include <vector>

using namespace std;

int main(){

	// vector

	vector<string> vec(5);
	vec[1] = "hi";
	cout << vec[1] << endl;

	vector<string> strings;

	strings.push_back("one");
	strings.push_back("two");
	strings.push_back("three");

	for(unsigned int i=0; i<strings.size(); i++ ){
		cout << strings[i] << endl;
	}

	vector<string>::iterator it = strings.begin();
	cout << *it << endl;

	it++;
	cout << *it << endl;

	for(it=strings.begin(); it<strings.end(); it++){
		cout << *it << endl;
	}

	it = strings.begin();
	it += 2;

	cout << *it << endl;

	vector<double> nums(15, 4);
	for(int i=0; i<15; i++){
		cout << nums[i] << endl;
	}

	vector<double> numbers(0);

	int size = numbers.size();
	unsigned int capacity = numbers.capacity();

	cout << "Size: " << size << endl;
	cout << "Capacity: " << capacity << endl;

	capacity = numbers.capacity();

	for(int i; i<400; i++){
		numbers.push_back(i);
		if(numbers.capacity() != capacity){
			capacity = numbers.capacity();
			cout << "Capacity: " << capacity << " - Size: " << numbers.size() << endl;
		}
	}

	numbers.reserve(1000);
	cout << "\nCapacity: " << capacity << " - Size: " << numbers.size() << endl;
	cout << numbers[2] << endl;
	cout << numbers[101] << endl;

	numbers.resize(100);
	cout << "\nCapacity: " << capacity << " - Size: " << numbers.size() << endl;
	cout << numbers[2] << endl;
	cout << numbers[101] << endl;

	numbers.clear();
	cout << "\nCapacity: " << capacity << " - Size: " << numbers.size() << "\n" << endl;

	vector< vector<int> > grid(3, vector<int>(4,0));

	grid[1].push_back(8);

	for(unsigned int row=0; row<grid.size(); row++){
		for(unsigned int col=0; col<grid[row].size(); col++){
			cout << grid[row][col] << flush;
		}
		cout << endl;
	}

	return 0;
}


