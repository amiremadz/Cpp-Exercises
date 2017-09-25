/*
 * Screen.h
 *
 *  Created on: Aug 17, 2017
 *      Author: aemadzadeh
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL.h>
#include <stdio.h>

namespace particles {

class Screen {
public:
	Screen();

public:
	static const int SCREEN_WIDTH = 800;
	static const int SCREEN_HEIGHT = 600;

public:
	bool init();
	bool processEvents();
	/**
	 * x : column number
	 * y : row number
	 */
	void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
	void update();
	void close();
	void boxBlur();


private:
	Uint32 makeColor(Uint8 red, Uint8 green, Uint8 blue);
	void filter(Uint32* pixel);

private:
	SDL_Window *mWindow;
	SDL_Renderer *mRenderer;
	SDL_Texture *mTexture;
	Uint32 *mBuffer;
	Uint32 * mExtraBuffer;

public:
	virtual ~Screen();
};

} /* namespace particles */

#endif /* SCREEN_H_ */
