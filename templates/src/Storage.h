/*
 * Storage.h
 *
 *  Created on: Aug 30, 2017
 *      Author: aemadzadeh
 */

#ifndef STORAGE_H_
#define STORAGE_H_

#include <string.h>

template<typename T>
class Storage{
public:
	Storage(T value): mValue(value) {}
private:
	T mValue;
public:
	~Storage(){}
public:
	void print(){
		std::cout << mValue << std::endl;
	}
};

template<>
void Storage<double>::print(){
	std::cout << std::scientific << mValue << std::endl;
}

int len(char* str){
	int l = 0;
	while(*str){
		l++;
		str++;
	}
	return l;
}

// Template specizaion to avoid shallow copy
template<>
Storage<char *>::Storage(char* value){
	int length = len(value);

	// Method 1
	mValue = new char[length];
	memcpy(mValue, value, length*sizeof(char));

	/* Method 2
	char* ch = value;
	int i = 0;
	mValue = new char[length+1];
	while(*ch != '\0'){
		mValue[i] = *ch;
		ch++;
		i++;
	}
	*/
}

template<>
Storage<char*>::~Storage(){
	delete[] mValue;
}


#endif /* STORAGE_H_ */
