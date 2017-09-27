/*
 * RGB.cpp
 *
 *  Created on: Sep 24, 2017
 *      Author: aemadzadeh
 */

#include "RGB.h"

namespace fractal {


RGB RGB::operator -(const RGB &other){
	RGB result;

	result.red = red - other.red;
	result.green = green - other.green;
	result.blue = blue - other.blue;

	return result;
}

ostream &operator<<(ostream &out, const RGB &rgb){
	out << "red: " << rgb.red << " green: " << rgb.green << " blue: " << rgb.blue;

	return out;
}


} /* namespace fractal */
