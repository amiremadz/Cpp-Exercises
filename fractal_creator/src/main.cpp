//============================================================================
// Name        : main.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "FractalCreator.h"
#include "RGB.h"

using namespace std;
using namespace fractal;

int main() {

	RGB rgb1(1, 8, 3);
	RGB rgb2(4, 5, 6);
	RGB rgb3 = rgb1 - rgb2;

	cout << rgb3 << endl;

	int32_t const WIDTH = 800;
	int32_t const HEIGHT = 600;
	string fileName = "test.bmp";

	FractalCreator myFractal(WIDTH, HEIGHT);

	//myFractal.run(fileName);

	cout << "Finished!" << endl;

	return 0;
}
