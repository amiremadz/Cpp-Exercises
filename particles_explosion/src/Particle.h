/*
 * Particle.h
 *
 *  Created on: Aug 18, 2017
 *      Author: aemadzadeh
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <math.h>
#include "Screen.h"


namespace particles {

class Particle {
public:
	Particle();

private:
	double mX;
	double mY;
	double mR;
	double mTheta;
	double mRspeed;
	Uint8 mRed;
	Uint8 mGreen;
	Uint8 mBlue;


public:
	double getX() { return mX; }
	double getY() { return mY; }
	void update(int interval, int elapsed);
	Uint8 getRed() { return mRed; }
	Uint8 getGreen() { return mGreen; }
	Uint8 getBlue() { return mBlue; }


private:
	void init();

public:
	virtual ~Particle();

};

} /* namespace particles */

#endif /* PARTICLE_H_ */
