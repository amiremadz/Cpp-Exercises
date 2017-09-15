/*
 * Mandelbrot.cpp
 *
 *  Created on: Sep 14, 2017
 *      Author: aemadzadeh
 */

#include "Mandelbrot.h"
#include <complex>

using namespace std;

namespace fractal {

Mandelbrot::Mandelbrot() {
	// TODO Auto-generated constructor stub

}

Mandelbrot::~Mandelbrot() {
	// TODO Auto-generated destructor stub
}



uint32_t Mandelbrot::getIterations(double x, double y){

	uint32_t iterations = 0;

	complex<double> c(x, y);
	complex<double> z = 0;

	while(iterations < Mandelbrot::MAX_ITERATIONS){
		z = z * z + c;

		if(abs(z) > 2.0){
			break;
		}

		iterations++;
	}

	return iterations;

}










} /* namespace fractal */
