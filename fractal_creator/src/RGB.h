/*
 * RGB.h
 *
 *  Created on: Sep 24, 2017
 *      Author: aemadzadeh
 */

#ifndef RGB_H_
#define RGB_H_
#include <ostream>

using namespace std;

namespace fractal {

struct RGB {
	double red{0};
	double green{0};
	double blue{0};

	RGB() = default;

	RGB(double red, double green, double blue):  red(red), green(green), blue(blue) { }

	RGB operator-(const RGB &other);

	friend ostream &operator<<(ostream &out, const RGB &rgb);
};

} /* namespace fractal */

#endif /* RGB_H_ */
