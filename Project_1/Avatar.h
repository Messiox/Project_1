#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>

class Avatar
{
public:
	static const int AV_WIDTH = 100;
	static const int AV_HEIGHT = 100;
	static const int AV_VEL = 7;

	//Initializes the variables
	Avatar();

	//Takes key presses and adjusts the dot's velocity
	void handleEvent(SDL_Event& e);

	//Moves the dot
	void move();

	//Shows the dot on the screen relative to the camera
	void render();

	//Position accessors
	int getPosX();
	int getPosY();
	void calculateAngle(int mX,int mY);
private:
	//The X and Y offsets of the dot
	int mPosX, mPosY;

	//The velocity of the dot
	int mVelX, mVelY;

	double mAngle;

	int health, maxHealth;
};