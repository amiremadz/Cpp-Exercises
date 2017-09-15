//============================================================================
// Name        : main.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"
#include "Bitmap.h"
#include "Mandelbrot.h"

using namespace std;
using namespace fractal;

int main() {

	int32_t const WIDTH = 800;
	int32_t const HEIGHT = 600;

	double min = INT32_MAX;
	double max = INT32_MIN;

	string fileName = "test.bmp";

	Bitmap image(WIDTH, HEIGHT);

	unique_ptr<uint32_t[]> histogram(new uint32_t[Mandelbrot::MAX_ITERATIONS + 1]{});

	//image.setPixel(WIDTH/2, HEIGHT/2, 255, 255, 255);

	for(int32_t x=0; x<WIDTH; x++){
		for(int32_t y=0; y<HEIGHT; y++){
			//image.setPixel(x, y, 255, 0, 0);

			double xFractal = static_cast<double>(x - WIDTH/2.0 - 200)/(HEIGHT/2.0);
			double yFractal = static_cast<double>(y - HEIGHT/2.0)/(HEIGHT/2.0);

			uint32_t iterations = Mandelbrot::getIterations(xFractal, yFractal);

			histogram[iterations]++;

			cout << "x: " << x << " y: " << y << " iterations: " << iterations << endl;

			// map to a color
			uint8_t color = static_cast<uint8_t>(256*static_cast<double>(iterations)/Mandelbrot::MAX_ITERATIONS);

			color = color * color * color;

			if(xFractal < min){
				min = xFractal;
			}

			if(xFractal > max){
				max = xFractal;
			}

			image.setPixel(x, y, 0, color, 0);
		}
	}

	cout << "min: " << min << " max: " << max << endl;

	for(uint32_t i = 0; i<Mandelbrot::MAX_ITERATIONS; i++){
		cout << "itteration: " << i << " count: " << histogram[i] << endl;
	}

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
