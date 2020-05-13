/*
 * Swarm.h
 *
 *  Created on: Apr 28, 2020
 *      Author: michael_kilcorse
 */

#ifndef SWARM_H_
#define SWARM_H_
#include "Particle.h"
#include <iostream>

namespace mak {

class Swarm {
public:
	const static int N_PARTICLES = 3000;
private:
	Particle  *m_pParticle;
	int lastTime;
public:
	Swarm();
	virtual ~Swarm();

	const Particle * const getParticles() { return m_pParticle; }

	void update(int elapsed);
};

} /* namespace mak */

#endif /* SWARM_H_ */
