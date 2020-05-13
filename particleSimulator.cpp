//============================================================================
// Name        : particleSimulator.cpp
// Author      : Michael Kilcorse
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <SDL.h>
#include <math.h>
#include "Screen.h"
#include <stdlib.h>
#include <time.h>
#include "Swarm.h"
using namespace std;
using namespace mak;

int main() {

	srand(time(NULL));

	Screen screen;

	if (screen.init() == false) {
		cout << "Error initialising SDL." << endl;
	}

	Swarm swarm;

	const int HALF_WIDTH = Screen::SCREEN_WIDTH / 2;
	const int HALF_HEIGHT = Screen::SCREEN_HEIGHT / 2;

	while (true) {
		// Update particles
		// Draw particles

		int elapsed = SDL_GetTicks();


		swarm.update(elapsed);

		unsigned char green =
				(unsigned char) ((1 + sin(elapsed * 0.0001)) * 128);
		unsigned char red = (unsigned char) ((1 + sin(elapsed * 0.0002)) * 128);
		unsigned char blue = (unsigned char) ((1 + sin(elapsed * 0.0003)) * 128);

		const Particle * const pParticles = swarm.getParticles();

		for (int i = 0; i < Swarm::N_PARTICLES; i++) {
			Particle particle = pParticles[i];

			int x = (particle.m_x+ 1) * HALF_WIDTH;
			int y = particle.m_y  * HALF_WIDTH + HALF_HEIGHT;

			screen.setPixel(x, y, red, green, blue);
		}

		screen.boxBlur();

		// Draw the screen
		screen.update();

		// Check for messages/events
		if (screen.processEvents() == false) {
			break;
		}
	}

	screen.close();

	return 0;
}

