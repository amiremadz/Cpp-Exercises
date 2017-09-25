/*
 * Bitmap.h
 *
 *  Created on: Sep 13, 2017
 *      Author: aemadzadeh
 */

#ifndef BITMAP_H_
#define BITMAP_H_

#include <cstdint>
#include <string>
#include <memory>
#include <fstream> // if this is in Bitmap.cpp, it causes a crash!

using namespace std;

namespace fractal {

class Bitmap {
private:
	int32_t mWidth{0};
	int32_t mHeight{0};
	unique_ptr<uint8_t[]> m_pPixels{nullptr};

public:
	//Bitmap() = default;

	Bitmap(int32_t width, int32_t height);

public:
	bool write(string fileName);
	void setPixel(int32_t x, int32_t y, uint8_t red, uint8_t green, uint8_t blue); // x=0 at left, y=0 at bottom

public:
	virtual ~Bitmap();
};

} /* namespace fractal */

#endif /* BITMAP_H_ */
