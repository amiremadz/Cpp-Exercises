/*
 * Bitmap.cpp
 *
 *  Created on: Sep 13, 2017
 *      Author: aemadzadeh
 */

#include "Bitmap.h"
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"

using namespace fractal;

namespace fractal {

Bitmap::Bitmap(int32_t width, int32_t height): mWidth(width), mHeight(height), m_pPixels(new uint8_t[width*height*3]{}) {

}

bool Bitmap::write(string filename){
	BitmapFileHeader fileHeader;
	BitmapInfoHeader infoHeader;

	fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + mWidth*mHeight*3;
	fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

	infoHeader.width = mWidth;
	infoHeader.height = mHeight;

	return false;
}


void Bitmap::setPixel(int32_t x, int32_t y, uint8_t red, uint8_t green, uint8_t blue){

}


Bitmap::~Bitmap() {
	// TODO Auto-generated destructor stub
}

} /* namespace fractal */
