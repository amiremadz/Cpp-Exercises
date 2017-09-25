/*
 * Swarm.h
 *
 *  Created on: Aug 18, 2017
 *      Author: aemadzadeh
 */

#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"

namespace particles {

class Swarm {
public:
	static const int NPARTICLES = 5000;

public:
	Swarm();

private:
	Particle* mParticles;
	int mLastTime;

public:
	const Particle* const getParticles() { return mParticles; }
	void update(int elapsed);

public:
	virtual ~Swarm();
};

} /* namespace particles */

#endif /* SWARM_H_ */
