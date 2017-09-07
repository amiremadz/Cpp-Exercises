/*
 * Ring.h
 *
 *  Created on: Sep 6, 2017
 *      Author: aemadzadeh
 */

#ifndef RING_H_
#define RING_H_


#include <vector>
#include <iostream>

using namespace std;


namespace ring {

template<typename T>
class Ring {
private:
	vector<T> mContainer;
	size_t mSize;
public:
	size_t size() const { return mContainer.size(); }

	T get(size_t i) const { return mContainer[i]; }

	void add(T value){
		if(mContainer.size() < mSize){
			mContainer.push_back(value);
			return;
		}
		for(std::size_t i=mContainer.size()-1; i>0; i--){
			mContainer[i] = mContainer[i-1];
		}
		mContainer[0] = value;
	}
public:
	Ring(std::size_t size): mSize(size) {}
public:
	class iterator;
};


template<typename T>
class Ring<T>::iterator{
public:
	void print() {cout << "It" << T() << endl; }
};


} /* namespace ring */

#endif /* RING_H_ */
