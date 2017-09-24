//============================================================================
// Name        : main.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"
#include "Bitmap.h"
#include "Mandelbrot.h"
#include "ZoomList.h"

using namespace std;
using namespace fractal;

int main() {

	int32_t const WIDTH = 800;
	int32_t const HEIGHT = 600;

	double min = INT32_MAX;
	double max = INT32_MIN;

	string fileName = "test.bmp";

	Bitmap image(WIDTH, HEIGHT);

	ZoomList zoomList(WIDTH, HEIGHT);

	zoomList.add(Zoom(WIDTH/2, HEIGHT/2, 4.0/WIDTH));
	zoomList.add(Zoom(295, HEIGHT-202, 0.1));
	zoomList.add(Zoom(312, HEIGHT-304, 4.0/WIDTH));


	unique_ptr<uint32_t[]> histogram(new uint32_t[Mandelbrot::MAX_ITERATIONS]{});
	unique_ptr<uint32_t[]> fractal(new uint32_t[WIDTH*HEIGHT]{});

	for(int32_t x=0; x<WIDTH; x++){
		for(int32_t y=0; y<HEIGHT; y++){
			pair<double, double> coordinates = zoomList.doZoom(x, y);
			double xFractal = coordinates.first;
			double yFractal = coordinates.second;

			uint32_t iterations = Mandelbrot::getIterations(xFractal, yFractal);

			fractal[y*WIDTH + x] = iterations;

			// exclude MAX_ITERATIONS: to make the histogram smooth
			if(iterations < Mandelbrot::MAX_ITERATIONS){
				histogram[iterations]++;
			}
			//cout << "x: " << x << " y: " << y << " iterations: " << iterations << endl;
		}
	}

	uint32_t total = 0;
	for(uint32_t i = 0; i < Mandelbrot::MAX_ITERATIONS; i++){
		total += histogram[i];
	}

	for(int32_t x=0; x<WIDTH; x++){
		for (int32_t y = 0; y < HEIGHT; y++) {

			uint8_t red = 0;
			uint8_t green = 0;
			uint8_t blue = 0;

			uint32_t iterations = fractal[y * WIDTH + x];

			// Points which do not diverge: Black
			// Points which diverge: Colorful
			if (iterations != Mandelbrot::MAX_ITERATIONS) {
				double hue = 0.0;

				for (uint32_t i = 0; i <= iterations; i++) {
					hue += static_cast<double>(histogram[i]) / total;
				}

				/*
				if (hue > .95) {
					cout << "x: " << x << " y: " << y << " hue: " << hue
							<< endl;
				}
				*/

				green = pow(255, hue);

				image.setPixel(x, y, red, green, blue);
			}
		}
	}
	//*/


#if 0
	uint32_t sum = 0;
	for(uint32_t i = 0; i < Mandelbrot::MAX_ITERATIONS; i++){
		sum += histogram[i];
		cout << histogram[i] << " " << flush;
	}

	cout << endl;
	cout << "min: " << min << " max: " << max << endl;
	cout << "sum: " << sum << " expected: " << WIDTH*HEIGHT<< endl;
#endif
	bool result = image.write(fileName);

	if(result){
		cout << "write successful!" << endl;
	}
	else{
		cout << "write failed!" << endl;
	}

	cout << "Finished!" << endl;

	return 0;
}
