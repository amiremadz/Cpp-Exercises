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
#include <cassert>


namespace fractal {


void FractalCreator::run(string name){
	if(rangesMakeSense()){
		calculateIterations();
		calculateRangeTotalPixels();
		calculateTotalPixels();
		drawFractal();
		writeBitmap(name);
	}
}

void FractalCreator::addRange(double rangeEnd, const RGB &rgb){
	mRanges.push_back(rangeEnd * Mandelbrot::MAX_ITERATIONS);
	mColors.push_back(rgb);

	if(mGotFirstRange){
		mRangeTotalPixels.push_back(0);
	}

	mGotFirstRange = true;
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

bool FractalCreator::rangesMakeSense(){
	if(mRanges.empty()){
		return false;
	}

	if(mRanges[0] != 0.0 ){
		cout << "Bad range values." << endl;
		cout << mRanges[0] << endl;
		return false;
	}

	if(mRanges.back() != Mandelbrot::MAX_ITERATIONS ){
		cout << "Bad range values." << endl;
		cout << mRanges.back() << endl;
		return false;
	}

	for(uint32_t index = 1; index < mRanges.size(); index++){
		if(mRanges[index] < mRanges[index-1]){
			cout << "Bad range values." << endl;
			return false;
		}
	}

	return true;
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

int32_t FractalCreator::getRangeIndex(uint32_t iterations) const{
	uint32_t index = 0;

	if(iterations >= Mandelbrot::MAX_ITERATIONS){
		return -1;
	}

	for(auto value : mRanges){
		if(iterations < value){
			break;
		}
		index++;
	}

	index--;

	assert(index >= 0);
	assert(index < mRanges.size());

	return static_cast<int32_t>(index);
}

void FractalCreator::calculateRangeTotalPixels(){

	for(uint32_t i=1; i<mRanges.size(); i++){
		uint32_t totalRangePixels = 0;
		for(uint32_t itt = mRanges[i-1]; itt<mRanges[i]; itt++){
			uint32_t numOfPixels = mHistogram[itt];
			totalRangePixels += numOfPixels;
		}
		mRangeTotalPixels[i-1] = totalRangePixels;
	}
#if 0
	uint32_t total = 0;
	for(uint32_t value : mRangeTotalPixels){
		total += value;
		cout << "Total range pixels: " << value << endl;
	}
	cout << "Total pixels1: " << total << endl;
#endif
}

void FractalCreator::calculateTotalPixels(){
	for (uint32_t i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
		mTotalPixels += mHistogram[i];
	}
#if 0
	cout << "Total pixels2: " << mTotalPixels << endl;
#endif
}

void FractalCreator::drawFractal(){

	RGB startColor(0, 0, 0);
	RGB endColor(0, 0, 255);
	RGB colorDiff = endColor - startColor;

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
					hue += static_cast<double>(mHistogram[i]) / mTotalPixels;
				}

				red = startColor.red + colorDiff.red*hue;
				green = startColor.green + colorDiff.green*hue;
				blue = startColor.blue + colorDiff.blue*hue;

				mImage.setPixel(x, y, red, green, blue);
			}
		}
	}
}








} /* namespace fractal */
