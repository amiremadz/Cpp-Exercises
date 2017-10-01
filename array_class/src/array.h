/*
 * array.h
 *
 *  Created on: Oct 1, 2017
 *      Author: aemadzadeh
 */

#ifndef ARRAY_H_
#define ARRAY_H_

#include <ostream>
#include cstdint>


using namespace std;

template<typename T>
class array {
	private:
		T *mArray{nullptr};
		uint32_t mLength{0};
		uint32_t mIndex{0};

	public:
		array();
		array(uint32_t length);

	public:
		void add(T value);
		void get(uint32_t index);

	public:
		array(const array &other);
		array operator=(const array &other);

	public:
		bool operator==(const array &other) const;
		bool operator!=(const array &other) const;
		friend ostream &operator<<(ostream &out, const array<T> &arr);
		T operator[](uint32_t index) const;

	public:
		iterator begin() const;
		iterator end() const;

	public:
		class iterator;

	public:
		virtual ~array();
};

template<typename T>
ostream &operator<<(ostream &out, const array<T> &arr);


array<T>::iterator{
	private:
		T &mArray;
		uint32_t &mIndex;
	public:
		iterator(T &array, uint &index) {mArray = array; mIndex = index;};

	public:
		T operator*();
		void operator++();
		void operator--();
		bool operator==(const iterator &other);
		bool operator!=(const iterator &other);

};

#endif /* ARRAY_H_ */
