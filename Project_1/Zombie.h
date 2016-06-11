#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>

class Zombie
{
public:
	//The dimensions
	static const int Z_WIDTH = 100;
	static const int Z_HEIGHT = 100;

	//Maximum axis velocity of the dot
	static const int Z_VEL = 1;

	//Initializes the variables
	Zombie();

	void move(int aX,int aY);

	void render();

	//Position accessors
	int getPosX();
	int getPosY();
private:
	int mPosX, mPosY;
	double mAngle;
	int mVelX, mVelY;
};