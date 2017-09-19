/*
 * ZoomList.h
 *
 *  Created on: Sep 18, 2017
 *      Author: aemadzadeh
 */

#ifndef ZOOMLIST_H_
#define ZOOMLIST_H_

#include <cstdint>
#include <vector>
#include <utility>
#include "Zoom.h"



namespace fractal {

class ZoomList {
private:
	uint32_t mWidth{0};
	uint32_t mHeight{0};
	std::vector<Zoom> mList{};

public:
	ZoomList(uint32_t width, uint32_t height);

public:
	void add(const Zoom &zoom);

	std::pair <double, double> doZoom(uint32_t x, uint32_t y);

};

} /* namespace fractal */

#endif /* ZOOMLIST_H_ */
