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

	myFractal.addZoom(Zoom(295, 202, 0.1));
	myFractal.addZoom(Zoom(312, 304, 0.1));

	myFractal.run(fileName);

	cout << "Finished!" << endl;

	return 0;
}
