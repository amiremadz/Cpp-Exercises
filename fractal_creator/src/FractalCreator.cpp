/*
 * FractalCreator.cpp
 *
 *  Created on: Sep 24, 2017
 *      Author: aemadzadeh
 */

#include "FractalCreator.h"
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"
#include <cmath>
#include <iostream>


namespace fractal {



void FractalCreator::run(string name){

	addZoom(Zoom(295, mHeight - 202, 0.1));
	addZoom(Zoom(312, mHeight - 304, 0.1));

	calculateIterations();
	drawFractal();
	writeBitmap(name);
}

FractalCreator::FractalCreator(uint32_t width, uint32_t height) : mWidth(width), mHeight(height), mZoomList(width, height),
		mHistogram(new uint32_t[Mandelbrot::MAX_ITERATIONS]{ }), mFractal(new uint32_t[width * height] { }),  mImage(width, height){
	mZoomList.add(Zoom(width/2.0, height/2.0, 4.0/width));
}

void FractalCreator::calculateIterations(){
	for (uint32_t x = 0; x < mWidth; x++) {
		for (uint32_t y = 0; y < mHeight; y++) {
			pair<double, double> coordinates = mZoomList.doZoom(x, y);

			double xFractal = coordinates.first;
			double yFractal = coordinates.second;

			uint32_t iterations = Mandelbrot::getIterations(xFractal, yFractal);

			mFractal[y * mWidth + x] = iterations;

			// exclude MAX_ITERATIONS: to make the histogram smooth
			if (iterations < Mandelbrot::MAX_ITERATIONS) {
				mHistogram[iterations]++;
			}
		}
	}
}


void FractalCreator::calculateTotalIterations(){
	for (uint32_t i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
		mTotal += mHistogram[i];
	}
}

void FractalCreator::drawFractal(){

	calculateTotalIterations();

	for (uint32_t x = 0; x < mWidth; x++) {
		for (uint32_t y = 0; y < mHeight; y++) {
			uint8_t red = 0;
			uint8_t green = 0;
			uint8_t blue = 0;

			uint32_t iterations = mFractal[y * mWidth + x];

			// Points which do not diverge: Black
			// Points which diverge: Colorful
			if (iterations != Mandelbrot::MAX_ITERATIONS) {
				double hue = 0.0;

				for (uint32_t i = 0; i <= iterations; i++) {
					hue += static_cast<double>(mHistogram[i]) / mTotal;
				}

				//green = pow(255, hue);
				green = hue * 255;

				mImage.setPixel(x, y, red, green, blue);
			}
		}
	}
}

void FractalCreator::addZoom(const Zoom &zoom){
	mZoomList.add(zoom);
}

void FractalCreator::writeBitmap(string name){
	bool result = mImage.write(name);

	if (result) {
		cout << "write successful!" << endl;
	} else {
		cout << "write failed!" << endl;
	}
}





} /* namespace fractal */
