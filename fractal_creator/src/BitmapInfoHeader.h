/*
 * BitmapInfoHeader.h
 *
 *  Created on: Sep 13, 2017
 *      Author: aemadzadeh
 */

#ifndef BITMAPINFOHEADER_H_
#define BITMAPINFOHEADER_H_


#include <cstdint>

#pragma pack(2)

namespace fractal{

struct BitmapInfoHeader{
	int32_t headerSize{40};		// size of struct in bytes
	int32_t width;
	int32_t height;
	int16_t planes{1};
	int16_t bitsPerPixel{24};	// RGB: 1 byte per color
	int32_t compression{0};
	int32_t dataSize{0};		// size of data to be written onto bmp file
	int32_t horizontalResolution{2400};
	int32_t verticalResolution{2400};
	int32_t colors{0};
	int32_t importantColos{0};
};


}

#endif /* BITMAPINFOHEADER_H_ */
