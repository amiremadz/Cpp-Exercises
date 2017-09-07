/*
 * RingBuffer.h
 *
 *  Created on: Sep 6, 2017
 *      Author: aemadzadeh
 */

#ifndef RINGBUFFER_H_
#define RINGBUFFER_H_

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
	size_t mPos;
	RingBuffer &mRing;
public:
	iterator(std::size_t pos, RingBuffer &ring) : mPos(pos), mRing(ring) {}
public:
	iterator &operator++(){
		mPos++;
		return *this;
	}

	iterator operator++(int){
		mPos++;
		return *this;
	}

	T &operator*() const {
		return mRing.mBuffer[mPos];
	}

	bool operator!=(const iterator &other) const {
		return mPos != other.mPos;
	}

};




#endif /* RINGBUFFER_H_ */
