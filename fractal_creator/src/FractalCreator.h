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
#include "Zoom.h"

using namespace std;

namespace fractal {

class FractalCreator {
private:
	uint32_t mWidth;
	uint32_t mHeight;

public:
	FractalCreator(uint32_t width, uint32_t height);

public:
	void calculateIterations();

	void drawFractal();

	void addZoom(const Zoom &zoom);

	void writeBitmap(string name);

	virtual ~FractalCreator();
};

} /* namespace fractal */

#endif /* FRACTALCREATOR_H_ */
