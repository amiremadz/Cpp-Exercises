/*
 * ZoomList.cpp
 *
 *  Created on: Sep 18, 2017
 *      Author: aemadzadeh
 */

#include "ZoomList.h"


namespace fractal {



ZoomList::ZoomList(uint32_t width, uint32_t height): mWidth(width), mHeight(height) {

}


void ZoomList::add(const Zoom &zoom){
	mList.push_back(zoom);
}


std::pair<double, double> ZoomList::doZoom(uint32_t x, uint32_t y){
	return std::pair<double, double>(0.0, 0.0);
}


} /* namespace fractal */
