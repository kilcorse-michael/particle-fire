/*
 * Particle.h
 *
 *  Created on: Apr 28, 2020
 *      Author: michael_kilcorse
 */
#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace mak {

struct Particle {
	double m_x;
	double m_y;

private:
	double m_speed;
	double m_direction;

private:
	void init();

public:
	Particle();
	virtual ~Particle();
	void update(int interval);
};

} /* namespace caveofprogramming */

#endif /* PARTICLE_H_ */

