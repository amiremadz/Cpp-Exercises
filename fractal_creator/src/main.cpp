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

	for(int32_t x=0; x<WIDTH; x++){
		for(int32_t y=0; y<HEIGHT; y++){
			image.setPixel(x, y, 255, 0, 0);
		}
	}


	bool result = image.write(fileName);

	cout << result << endl;

	cout << sizeof(BitmapFileHeader) << endl;
	cout << sizeof(BitmapInfoHeader) << endl;

	cout << "Finished!" << endl;

	return 0;
}
