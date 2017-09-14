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

bool Bitmap::write(string fileName){

	BitmapFileHeader fileHeader;
	BitmapInfoHeader infoHeader;

	fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + mWidth * mHeight * 3;
	fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

	infoHeader.width = mWidth;
	infoHeader.height = mHeight;

	fstream myfile;
	myfile.open(fileName, fstream::out | fstream::binary);

	if(!myfile){
		return false;
	}

	myfile.write(reinterpret_cast<char*>(&fileHeader), sizeof(fileHeader));
	myfile.write(reinterpret_cast<char*>(&infoHeader), sizeof(infoHeader));
	myfile.write(reinterpret_cast<char*>(m_pPixels.get()), mWidth*mHeight*3);			// (char*) m_pPixels.get()

	myfile.close();

	if(!myfile){
		return false;
	}

	return true;
}


void Bitmap::setPixel(int32_t x, int32_t y, uint8_t red, uint8_t green, uint8_t blue){
	uint8_t *pPixel = m_pPixels.get();
	pPixel[(3*y)*mWidth + (3*x)] = blue;			// bitmap uses little endian
	pPixel[(3*y)*mWidth + (3*x) + 1] = green;
	pPixel[(3*y)*mWidth + (3*x) + 2] = red;
}


Bitmap::~Bitmap() {
	// TODO Auto-generated destructor stub
}

} /* namespace fractal */
