/*
 * Circular.h
 *
 *  Created on: Sep 11, 2017
 *      Author: aemadzadeh
 */

#ifndef CIRCULAR_H_
#define CIRCULAR_H_

#include <iostream>
#include <initializer_list>
#include <cstring>

using namespace std;

template <typename T>
class Circular {
private:
	size_t mSize{0};
	T* mBuffer{nullptr};
	size_t mIndex{0};

public:
	Circular() = default;

	Circular(size_t size): mSize(size){
		mBuffer = new T[size];
	}

	// Initializer list
	Circular(initializer_list<T> list){
		mSize = list.size();
		mBuffer = new T[mSize];
		add(list);
	}

public:
	// Copy constructor
	Circular(const Circular<T> &other){
		//cout << "copy" << endl;
		mSize = other.mSize;
		mIndex = other.mIndex;
		mBuffer = new T[mSize]{};
		memcpy(mBuffer, other.mBuffer, mSize*sizeof(T));
	}

	// Move constructor
	Circular(Circular<T> &&other){
		cout << "move constructor" << endl;
		mSize = other.mSize;
		mIndex = other.mIndex;
		mBuffer = other.mBuffer;
		other.mBuffer = nullptr;
	}

public:
	template<typename S>
	friend ostream &operator<<(ostream &out, const Circular<S> &buffer);

	T operator[](size_t index) const {
		return mBuffer[index];
	}

	// Copy assignment
	Circular operator=(const Circular &other){
		mSize = other.mSize;
		mIndex = other.mIndex;
		mBuffer = new T[mSize];
		memcpy(mBuffer, other.mBuffer, mSize*sizeof(T));
		return *this;
	}

	// Move assignment
	Circular operator=(Circular &&other){
		cout << "move assignment" << endl;
		delete[] mBuffer;
		mSize = other.mSize;
		mIndex = other.mIndex;
		mBuffer = other.mBuffer;
		delete[] other.mBuffer;
		return *this;
	}

public:
	void add(T value) {
		mBuffer[mIndex] = value;
		mIndex++;
		if(mIndex >= mSize){
			mIndex = 0;
		}
	}

	void add(initializer_list<T> list){
		for(auto item : list){
			add(item);
		}
	}

	size_t size() const { return mSize; }

public:
	class iterator;

public:
	iterator begin() {
		return iterator(0, *this);
	}

	iterator end(){
		return iterator(mSize, *this);
	}

public:
	~Circular(){
		delete[] mBuffer;
	}
};

template<typename S>
ostream &operator<<(ostream &out, const Circular<S> &circ_buffer){
	for(size_t i=0; i<circ_buffer.mSize; i++){
		out << circ_buffer.mBuffer[i] << " ";
	}
	return out;
}

template<typename T>
class Circular<T>::iterator{
private:
	size_t mIndex{0};
	Circular<T> &mCircular;
public:
	iterator(size_t index, Circular<T> &circular): mIndex(index), mCircular(circular){
		//mCircular = circular; // does not work: a reference cannot be reassigned.
								// so it must be initialized at the member-initialization-list.
	}

public:
	//prefix
	iterator operator++(){
		mIndex++;
		return *this;
	}

	// postfix
	iterator operator++(int){
		mIndex++;
		return *this;
	}

	T operator*() const {
		return mCircular.mBuffer[mIndex];
	}

	bool operator!=(const iterator &other) const {
		return mIndex != other.mIndex;
	}

	iterator operator+(const int right){
		mIndex += right;
		return *this;
	}
};



#endif /* CIRCULAR_H_ */
