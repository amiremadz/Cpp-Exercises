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

	int32_t const WIDTH = 800;
	int32_t const HEIGHT = 600;
	string fileName = "test.bmp";

	FractalCreator myFractal(WIDTH, HEIGHT);

	myFractal.addRange(0.0, RGB(0, 0, 0));
	myFractal.addRange(0.3, RGB(255, 0, 0));
	myFractal.addRange(0.5, RGB(255, 255, 0));
	myFractal.addRange(1.0, RGB(255, 255, 255));

#if 1

	myFractal.addZoom(Zoom(295, 202, 0.1));
	myFractal.addZoom(Zoom(312, 304, 0.1));

	myFractal.run(fileName);

#endif

	cout << "Finished!" << endl;

	return 0;
}
