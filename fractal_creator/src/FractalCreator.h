/*
 * FractalCreator.h
 *
 *  Created on: Sep 24, 2017
 *      Author: aemadzadeh
 */

#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include <cstdint>
#include <string>
#include <memory>
#include "Zoom.h"
#include "ZoomList.h"
#include "Mandelbrot.h"
#include "Bitmap.h"

using namespace std;

namespace fractal {

class FractalCreator {
private:
	uint32_t mWidth{0};
	uint32_t mHeight{0};

	ZoomList mZoomList;

	unique_ptr<uint32_t[]> mHistogram{nullptr};
	unique_ptr<uint32_t[]> mFractal{nullptr};

	Bitmap mImage;

	uint32_t mTotal{0};

public:
	FractalCreator(uint32_t width, uint32_t height);

private:
	void calculateTotalIterations();

private:
	void calculateIterations();
	void drawFractal();
	void addZoom(const Zoom &zoom);
	void writeBitmap(string name);

public:
	void run(string name);

};

} /* namespace fractal */

#endif /* FRACTALCREATOR_H_ */
