/*
 * array.h
 *
 *  Created on: Oct 1, 2017
 *      Author: aemadzadeh
 */

#ifndef ARRAY_H_
#define ARRAY_H_

#include <ostream>
#include <stdint.h>
#include <initializer_list>
#include <cstring>

using namespace std;

template<typename T>
class array {
	private:
		uint32_t mLength{0};
		T *mArray{nullptr};
		uint32_t mIndex{0};

	public:
		array() = default;

		array(uint32_t length) : mLength(length), mArray(new T[length]) { }

		array(uint32_t length, initializer_list<T> list) : mLength(length), mArray(new T[length]) {
			for(T item : list){
				if(mIndex < mLength){
					mArray[mIndex] = item;
					mIndex++;
				}
				else{
					cout << "constructor: extra item!" << endl;
				}

			}
		}

	public:
		array(const array &other) {
			mLength = other.mLength;
			mArray = new T[mLength];
			memcpy(mArray, other.mArray, mLength * sizeof(T));
			mIndex = other.mIndex;
		}

		//array operator=(const array &other);

	public:
		bool operator==(const array &other) const {
			if(mLength != other.mLength){
				return false;
			}

			for(uint32_t i = 0; i < mLength; i++){
				if(mArray[i] != other.mArray[i]){
					return false;
				}
			}

			return true;
		}

		friend bool operator!=(const array &lhs, const array &rhs) {
			return !(lhs == rhs);
		}

	public:
		T operator[](uint32_t index) const {
			return mArray[index];
		}

		friend ostream &operator<<(ostream &out, array &arr) {
			for(uint32_t i = 0; i < arr.mLength; i++){
				out << arr.mArray[i] << " ";
			}
			return out;
		}

	public:
		uint32_t size() const { return mLength; }

		void print(){
			for(uint32_t i = 0; i < mLength; i++){
				cout << mArray[i] << " ";
			}
			cout << endl;
		}

		T get(uint32_t index) const { return mArray[index]; }

		void add(T item) {
			if(mIndex < mLength){
				mArray[mIndex] = item;
				mIndex++;
			}
			else{
				cout << "No more add: array is full!" << endl;
			}
		}

		void add(initializer_list<T> list) {
			for(T item : list){
				if(mIndex < mLength){
					mArray[mIndex] = item;
					mIndex++;
				}
				else{
					cout << "No more add: array is full!" << endl;
				}
			}
		}

	public:
		class iterator;

	public:
			iterator begin(){
				return iterator(*this, 0);
			}

			iterator end(){
				return iterator(*this, mLength);
			}

	public:
		~array() { delete[] mArray; }
};


template<typename T>
class array<T>::iterator{
	private:
		array<T> &mArrayObj;
		uint32_t mIndex;

	public:
		iterator(array<T> &arr, uint32_t index): mArrayObj(arr), mIndex(index) { };

	public:
		T operator*() const { return mArrayObj.mArray[mIndex]; }

		iterator operator++() {
			mIndex++;
			return *this;
		}

		iterator operator++(int) {
			mIndex++;
			return *this;
		}

		iterator operator--() {
			mIndex--;
			return *this;
		}

		bool operator!=(const iterator &other){
			return mIndex != other.mIndex;
		}

};

#endif /* ARRAY_H_ */
