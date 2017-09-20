/*
 * Zoom.h
 *
 *  Created on: Sep 18, 2017
 *      Author: aemadzadeh
 */

#ifndef ZOOM_H_
#define ZOOM_H_

#include <cstdint>


namespace fractal {



struct Zoom {
	uint32_t x{0};			// zoom center x value
	uint32_t y{0};			// zoom center y value
	double scale{1.0};

	Zoom(uint32_t x, uint32_t y, double scale) : x(x), y(y), scale(scale) { }
};


} /* namespace fractal */

#endif /* ZOOM_H_ */
