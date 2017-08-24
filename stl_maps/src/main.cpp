//============================================================================
// Name        : stl_maps.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>

using namespace std;

int main() {

	map<string, int> ages;

	ages["Sue"] = 9;
	ages["Jack"] = 13;
	ages["Mimi"] = 82;

	map<string, int>::iterator it;

	for(it=ages.begin(); it != ages.end(); it++){
		cout << it->first << " : " << it->second << endl;
	}

	cout << ages["nonexistent_1"] << endl;

	for(it=ages.begin(); it != ages.end(); it++){
		cout << it->first << " : " << it->second << endl;
	}

	if(ages.find("nonexistent_2") != ages.end()){
		cout << "Key: " << ages["monexistent_2"] << endl;
	}
	else{
		cout << "Key not found" << endl;
	}

	for(it=ages.begin(); it != ages.end(); it++){
		pair<string, int> ageInfo = *it;

		cout << ageInfo.first << " : " << ageInfo.second << endl;
	}

	pair<string, int> peter("Peter", 98);
	ages.insert(peter);

	ages.insert(pair<string, int>("Rob", 44));

	ages.insert(make_pair("Don", 56));

	for(it=ages.begin(); it != ages.end(); it++){
		cout << it->first << " : " << it->second << endl;
	}

	return 0;
}
