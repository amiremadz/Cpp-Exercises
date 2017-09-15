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

	int32_t min = INT32_MAX;
	int32_t max = INT32_MIN;

	string fileName = "test.bmp";

	Bitmap image(WIDTH, HEIGHT);

	//image.setPixel(WIDTH/2, HEIGHT/2, 255, 255, 255);

	for(int32_t x=0; x<WIDTH; x++){
		for(int32_t y=0; y<HEIGHT; y++){
			//image.setPixel(x, y, 255, 0, 0);
			cout << "x: " << x << " y: " << y << endl;

			double xFractal = static_cast<double>(x - WIDTH/2.0)/(WIDTH/2.0);
			double yFractal = static_cast<double>(y - HEIGHT/2.0)/(HEIGHT/2.0);

			uint32_t iterations = Mandelbrot::getIterations(xFractal, yFractal);

			// map to a color
			uint8_t red = static_cast<uint8_t>(256*static_cast<double>(iterations)/Mandelbrot::MAX_ITERATIONS);

			if(red < min){
				min = red;
			}

			if(red > max){
				max = red;
			}

			image.setPixel(x, y, red, red, red);
		}
	}

	cout << "min: " << min << " max: " << max << endl;;

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
