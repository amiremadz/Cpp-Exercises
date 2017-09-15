/*
 * Mandelbrot.h
 *
 *  Created on: Sep 14, 2017
 *      Author: aemadzadeh
 */

#ifndef MANDELBROT_H_
#define MANDELBROT_H_

#include <cstdint>

namespace fractal {

class Mandelbrot {
public:
	static const uint32_t MAX_ITERATIONS = 1000;

public:
	Mandelbrot();

public:
	static uint32_t getIterations(double x, double y);

public:
	virtual ~Mandelbrot();
};

} /* namespace fractal */

#endif /* MANDELBROT_H_ */
