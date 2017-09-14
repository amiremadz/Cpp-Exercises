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

using namespace std;
using namespace fractal;

int main() {

	int32_t const WIDTH = 800;
	int32_t const HEIGHT = 600;

	string fileName = "test.bmp";

	Bitmap image(WIDTH, HEIGHT);

	//image.setPixel(WIDTH/2, HEIGHT/2, 255, 255, 255);

	double min = 9999999;
	double max = -9999999;

	for(int32_t x=0; x<WIDTH; x++){
		for(int32_t y=0; y<HEIGHT; y++){
			//image.setPixel(x, y, 255, 0, 0);
			double xFractal = static_cast<double>(x - WIDTH/2.0)/(WIDTH/2.0);
			double yFractal = static_cast<double>(y - HEIGHT/2.0)/(HEIGHT/2.0);

			if(yFractal < min){
				min = yFractal;
			}

			if(yFractal > max){
				max = yFractal;
			}
		}
	}

	cout << min << ", " << max << endl;

	bool result = image.write(fileName);

	cout << result << endl;

	cout << sizeof(BitmapFileHeader) << endl;
	cout << sizeof(BitmapInfoHeader) << endl;

	cout << "Finished!" << endl;

	return 0;
}
