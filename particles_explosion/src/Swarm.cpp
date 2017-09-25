/*
 * Swarm.cpp
 *
 *  Created on: Aug 18, 2017
 *      Author: aemadzadeh
 */

#include "Swarm.h"
#include <vector>
namespace particles {

Swarm::Swarm() {
	mParticles = new Particle[NPARTICLES];
	mLastTime = 0;
}

Swarm::~Swarm() {
	delete[] mParticles;
}


void Swarm::update(int elapsed){
	int interval = elapsed - mLastTime;

	for(int i=0; i<NPARTICLES; i++){
			mParticles[i].update(interval, elapsed);
		}

	mLastTime = elapsed;
}



} /* namespace particles */
