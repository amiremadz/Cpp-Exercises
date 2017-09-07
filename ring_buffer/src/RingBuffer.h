/*
 * RingBuffer.h
 *
 *  Created on: Sep 6, 2017
 *      Author: aemadzadeh
 */

#ifndef RINGBUFFER_H_
#define RINGBUFFER_H_

#include <cstring>
#include <initializer_list>

template<typename T>
class RingBuffer{
private:
	T *mBuffer;
	std::size_t mSize;
	std::size_t mIndex;
public:
	RingBuffer(std::size_t size): mSize(size), mIndex(0){
		mBuffer = new T[size];
	}

	RingBuffer(std::initializer_list<T> vec){
		mSize = vec.size();
		mIndex = 0;
		mBuffer = new T[mSize];
		size_t index = 0;
		for(auto item : vec){
			mBuffer[index] = item;
			index++;
		}
	}
public:
	// This is not needed, if pass by refernce is used in iterator class
	RingBuffer(const RingBuffer &other){
		mBuffer = new T[other.mSize];
		mSize = other.mSize;
		mIndex = other.mIndex;

		/*
		 * Method 1: memcpy
		 */
		std::memcpy(mBuffer, other.mBuffer, other.mSize*sizeof(T));
		/*
		 * Method 2: copy one by one
		 */
		/*
		for(std::size_t i=0; i<other.mSize; i++){
			mBuffer[i] = other.mBuffer[i];
		}
		*/
		std::cout << "copy" << std::endl;
	}
public:
	~RingBuffer(){
		delete[] mBuffer;
	}
public:
	std::size_t size() const { return mSize; }

	T &get(size_t i) const { return mBuffer[i]; }

	void add(T value){
		/*
		 * This is a circular buffer
		 */
		mBuffer[mIndex] = value;
		mIndex++;
		mIndex %= mSize;

		/* This throws out the last element
		 * and adds a new element at the begining
		 */
		/*
		if(mIndex < mSize){
			mBuffer[mIndex] = value;
			mIndex++;
			return;
		}
		for(std::size_t i=mIndex-1; i>0; i--){
			mBuffer[i] = mBuffer[i-1];
		}
		mBuffer[0] = value;
		*/
	}

	void add(std::initializer_list<T> values){
		for(T item : values){
			mBuffer[mIndex] = item;
			mIndex++;
			if(mIndex == mSize){
				mIndex = 0;
			}
		}
	}

public:
	class iterator;
public:
	iterator begin(){
		return iterator(0, *this);
	}

	iterator end(){
		return iterator(mSize, *this);
	}

};

template<typename T>
class RingBuffer<T>::iterator{
private:
	std::size_t mPos;
	RingBuffer &mRing;		// needed for pass by reference constructor
	//RingBuffer mRing;		// needed for pass by value constructor
public:
	iterator(std::size_t pos, RingBuffer &ring): mPos(pos), mRing(ring)  {} 	// pass by refernce: copy constructor not called
	//iterator(std::size_t pos, RingBuffer ring): mPos(pos), mRing(ring) {}	 	// pass by value: copy constructor is called
public:
	iterator operator++(){
		mPos++;
		return *this;
	}
	iterator operator++(int){
		mPos++;
		return *this;
	}
	bool operator!=(const iterator &other) const {
		return mPos != other.mPos;
	}
	T &operator*() const {
		return mRing.mBuffer[mPos];
	}
};















#endif /* RINGBUFFER_H_ */
