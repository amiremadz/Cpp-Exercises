/*
 * Screen.cpp
 *
 *  Created on: Aug 17, 2017
 *      Author: aemadzadeh
 */

#include "Screen.h"

namespace particles {

Screen::Screen():
		mWindow(NULL), mRenderer(NULL), mTexture(NULL), mBuffer(NULL), mExtraBuffer(NULL) {
}

Screen::~Screen() {
	delete[] mBuffer;
	delete[] mExtraBuffer;
}

bool Screen::init(){
	if(SDL_Init(SDL_INIT_VIDEO) < 0 )
	{
		return false;
	}

	mWindow = SDL_CreateWindow("Particle Fire Explosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
	// | SDL_WINDOW_FULLSCREEN_DESKTOP

	if(mWindow == NULL)
	{
		SDL_Quit();
		return false;
	}

	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_PRESENTVSYNC);

	if(mRenderer == NULL){
		SDL_DestroyWindow(mWindow);
		SDL_Quit();
		return false;
	}

	mTexture = SDL_CreateTexture(mRenderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

	if(mTexture == NULL){
		SDL_DestroyRenderer(mRenderer);
		SDL_DestroyWindow(mWindow);
		SDL_Quit();
		return false;
	}

	mBuffer = new Uint32[SCREEN_WIDTH*SCREEN_HEIGHT];
	mExtraBuffer = new Uint32[SCREEN_WIDTH*SCREEN_HEIGHT];

	memset(mBuffer, 0, (Screen::SCREEN_WIDTH)*(Screen::SCREEN_HEIGHT)*sizeof(Uint32));
	memset(mExtraBuffer, 0, (Screen::SCREEN_WIDTH)*(Screen::SCREEN_HEIGHT)*sizeof(Uint32));

	return true;
}

bool Screen::processEvents(){
	SDL_Event event;
	while(SDL_PollEvent(&event)){
		if(event.type == SDL_QUIT)
		{
			return false;
		}
	}
	return true;
}

void Screen::update(){
	SDL_UpdateTexture(mTexture, NULL, mBuffer, SCREEN_WIDTH*sizeof(Uint32));
	SDL_RenderClear(mRenderer);
	SDL_RenderCopy(mRenderer, mTexture, NULL, NULL);
	SDL_RenderPresent(mRenderer);
}

Uint32 Screen::makeColor(Uint8 red, Uint8 green, Uint8 blue){
	Uint32 color = red;

	color <<= 8;
	color += green;
	color <<= 8;
	color += blue;
	color <<= 8;
	color += 0xFF;

	return color;
}

void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue){
	if( (y<0) || (y>=SCREEN_HEIGHT) || (x<0) || (x>=SCREEN_WIDTH) ){
		return;
	}

	Uint32 color = makeColor(red, green, blue);
	int index = y*SCREEN_WIDTH + x;
	mBuffer[index] = color;
}

void Screen::close(){
	delete[] mBuffer;
	delete[] mExtraBuffer;
	SDL_DestroyRenderer(mRenderer);
	SDL_DestroyTexture(mTexture);
	SDL_DestroyWindow(mWindow);
	SDL_Quit();
}

void Screen::boxBlur(){
	Uint32* temp;
	temp = mBuffer;
	mBuffer = mExtraBuffer;
	mExtraBuffer = temp;

	for(int x=0; x<Screen::SCREEN_WIDTH; x++){
		for(int y=0; y<Screen::SCREEN_HEIGHT; y++){

			Uint32 totalRed = 0;
			Uint32 totalGreen = 0;
			Uint32 totalBlue = 0;

			for(int xShift=-1; xShift<=1; xShift++){
				for(int yShift=-1; yShift<=1; yShift++){

					int currentX = x + xShift;
					int currentY = y + yShift;

					bool isIndexValid = currentX >= 0 && currentX < Screen::SCREEN_WIDTH
							&& currentY >=0  && currentY < Screen::SCREEN_HEIGHT;

					if(isIndexValid){
						Uint32 color = mExtraBuffer[currentY*Screen::SCREEN_WIDTH + currentX];

						Uint8 red = color >> 24; //(color & 0xFF000000) >> 24;
						Uint8 green = color >> 16;
						Uint8 blue = color >> 8;

						totalRed += red;
						totalGreen += green;
						totalBlue += blue;
					}
				}
			}

			Uint8 avgRed = totalRed/9;
			Uint8 avgGreen = totalGreen/9;
			Uint8 avgBlue = totalBlue/9;

			setPixel(x, y, avgRed, avgGreen, avgBlue);
		}
	}
}

} /* namespace particles */
