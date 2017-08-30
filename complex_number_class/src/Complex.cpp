/*
 * Complex.cpp
 *
 *  Created on: Aug 28, 2017
 *      Author: aemadzadeh
 */

#include "Complex.h"

namespace complex {

Complex::~Complex() {
	// TODO Auto-generated destructor stub
}

const Complex &Complex::operator=(const Complex &other){
	std::cout << "Assignment" << std::endl;
	mReal = other.mReal;
	mImaginary = other.mImaginary;
	return *this;	// To enable chaining
}

Complex::Complex(const Complex &other){
	std::cout << "Copy" << std::endl;
	//*this = other;
	mReal = other.mReal;
	mImaginary = other.mImaginary;
}

std::ostream &operator<<(std::ostream &out, const Complex &c){
	out << c.mReal << " + " << c.mImaginary << "i";
	return out;
}

bool Complex::operator <(const Complex &other) const {
	return mReal*mReal + mImaginary*mImaginary < other.mReal*other.mReal + other.mImaginary*other.mImaginary;
}

Complex Complex::operator+(const Complex &other) const {
	Complex result;
	result.mReal = mReal + other.mReal;
	result.mImaginary = mImaginary + other.mImaginary;
	return result;
}

Complex Complex::operator+(const double r) const {
	return Complex(mReal+r, mImaginary);
}

Complex operator+(double r, const Complex &c){
	return Complex(c.mReal+r, c.mImaginary);
}


Complex Complex::operator-(const Complex &other) const {
	Complex result;
	result.mReal = mReal - other.mReal;
	result.mImaginary= mImaginary - other.mImaginary;
	return result;
}

Complex Complex::operator-(const double r) const {
	return Complex(mReal-r, mImaginary);
}

Complex operator-(double r, const Complex &c){
	return Complex(r - c.mReal, -c.mImaginary);
}

bool Complex::operator==(const Complex &other) const {
	return (mReal == other.mReal) && (mImaginary == other.mImaginary);
}

bool Complex::operator!=(const Complex &other) const {
	return (mReal != other.mReal) || (mImaginary != other.mImaginary);
	//return !(*this == other)
}

Complex Complex::operator*() const {
	return Complex(mReal, -mImaginary);
}



} /* namespace complex */
