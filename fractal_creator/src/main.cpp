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

	string fileName = "test.bmp";

	Bitmap image(800, 600);
	bool result = image.write(fileName);

	cout << result << endl;

	cout << sizeof(BitmapFileHeader) << endl;
	cout << sizeof(BitmapInfoHeader) << endl;

	cout << "Finished!" << endl;

	return 0;
}
