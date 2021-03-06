/*
 * ZoomList.cpp
 *
 *  Created on: Sep 18, 2017
 *      Author: aemadzadeh
 */

#include "ZoomList.h"
//#include <iostream>

using namespace std;


namespace fractal {


ZoomList::ZoomList(uint32_t width, uint32_t height): mWidth(width), mHeight(height) { }

void ZoomList::add(const Zoom &zoom){
	mList.push_back(zoom);
	mXcenter += (zoom.x - mWidth/2.0)*mScale;   //  numerical issues if 2 vs 2.0
	mYcenter += (mHeight - zoom.y - mHeight/2.0)*mScale;	// first mHeight takes care of bitmap reverse y coordinate
	mScale *= zoom.scale;

	//cout << mXcenter << ", " << mYcenter << ", " << mScale << endl;
}

std::pair<double, double> ZoomList::doZoom(uint32_t x, uint32_t y){

	double xFractal;
	double yFractal;

	xFractal =  static_cast<double>(x - mWidth/2.0)*mScale + mXcenter;
	yFractal =  static_cast<double>(y - mHeight/2.0)*mScale + mYcenter;

	return pair<double, double>(xFractal, yFractal);
}


} /* namespace fractal */
