/*
 * Bitmap.cpp
 *
 *  Created on: Sep 13, 2017
 *      Author: aemadzadeh
 */

#include "Bitmap.h"

namespace fractal {

Bitmap::Bitmap(int32_t width, int32_t height): mWidth(width), mHeight(height), mPixels(new uint8_t[width*height*3]) {

}

bool Bitmap::write(string filename){

	return false;
}


void Bitmap::setPixel(int32_t x, int32_t y, uint8_t red, uint8_t green, uint8_t blue){

}


Bitmap::~Bitmap() {
	// TODO Auto-generated destructor stub
}

} /* namespace fractal */
