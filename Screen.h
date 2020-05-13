/*
 * Screen.h
 *
 *  Created on: Apr 27, 2020
 *      Author: michael_kilcorse
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL.h>

namespace mak {

class Screen {
public:
	const static int SCREEN_WIDTH = 800;
	const static int SCREEN_HEIGHT = 600;
private:
	SDL_Window *m_window;
	SDL_Renderer *m_renderer;
	SDL_Texture *m_texture;
	Uint32 *m_buffer1;
	Uint32 *m_buffer2;
public:
	Screen();
	virtual ~Screen();
	bool init();
	bool processEvents();
	void update();
	void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
	void clear();
	void boxBlur();
	void close();
};

} /* namespace mak */

#endif /* SCREEN_H_ */
