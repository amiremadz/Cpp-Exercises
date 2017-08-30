/*
 * Complex.h
 *
 *  Created on: Aug 28, 2017
 *      Author: aemadzadeh
 */

#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <iostream>

namespace complex {

class Complex {
public:
	Complex(): mReal(0), mImaginary(0) {}
	Complex(double real, double imaginary): mReal(real), mImaginary(imaginary) {}
	virtual ~Complex();
public:
	double real() const { return mReal; };
	double imag() const { return mImaginary; }
public:
	Complex(const Complex &other);
public:
	const Complex &operator=(const Complex &other);

	friend std::ostream &operator<<(std::ostream &out, const Complex &c);

	bool operator<(const Complex &other) const;

	Complex operator+(const Complex &other) const;
	Complex operator+(const double r) const;
	friend Complex operator+(double r, const Complex &c);

	Complex operator-(const Complex &other) const;
	Complex operator-(const double r) const;
	friend Complex operator-(double r, const Complex &c);

	bool operator==(const Complex &other) const;
	bool operator!=(const Complex &other) const;

	Complex operator*() const;
private:
	double mReal;
	double mImaginary;
};

} /* namespace complex */

#endif /* COMPLEX_H_ */
