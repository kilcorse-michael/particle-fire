/*
 * Swarm.cpp
 *
 *  Created on: Apr 28, 2020
 *      Author: michael_kilcorse
 */
#include <iostream>
#include "Swarm.h"

namespace mak {

Swarm::Swarm() {
	m_pParticle = new Particle[N_PARTICLES];
	lastTime = 0;

}

Swarm::~Swarm() {
	delete [] m_pParticle;
}

void Swarm::update(int elapsed){
	int interval = elapsed - lastTime;
	for (int i = 0; i < N_PARTICLES; i++) {
		m_pParticle[i].update(interval);
	}
	lastTime += elapsed;
//	std::cout << "Swarm Update Flag" << std::endl;
}

} /* namespace mak */
