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
#include <vector>
#include "Zoom.h"
#include "ZoomList.h"
#include "Mandelbrot.h"
#include "Bitmap.h"
#include "RGB.h"

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

	uint32_t mTotalPixels{0};

	vector<uint32_t> mRanges;
	vector<RGB>	mColors;
	vector<uint32_t> mRangeTotalPixels;			// length = total # of addRanges - 1 (addrange(0) does not count)

	bool mGotFirstRange{false};

public:
	FractalCreator(uint32_t width, uint32_t height);

private:
	void calculateIterations();
	void drawFractal();
	void writeBitmap(string name);
	void calculateTotalPixels();

	void calculateRangeTotalPixels();

	bool rangesMakeSense();

	uint32_t getRangeIndex(uint32_t iterations) const;	// starts from index 0

public:
	void addZoom(const Zoom &zoom);
	void addRange(double rangeEnd, const RGB &rgb);
	void run(string name);

};

} /* namespace fractal */

#endif /* FRACTALCREATOR_H_ */
