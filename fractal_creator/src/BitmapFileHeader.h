/*
 * BitmapFileHeader.h
 *
 *  Created on: Sep 13, 2017
 *      Author: aemadzadeh
 */

#ifndef BITMAPFILEHEADER_H_
#define BITMAPFILEHEADER_H_

#include <cstdint>
using namespace std;

#pragma pack(2);					// no padding in struct


namespace fractal{

struct BitmapFileHeader{
	char header[2]{'B', 'M'};		// used to adentify BMP file
	int32_t fileSize;				// has to be 32 bits
	int32_t reserved{0};
	int32_t dataOffset;
};

}

#endif /* BITMAPFILEHEADER_H_ */
