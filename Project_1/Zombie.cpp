#include "Zombie.h"
#include "LTexture.h"

extern LTexture gZombieTexture;

Zombie::Zombie()
{
	mPosX = 0;
	mPosY = 0;
	mAngle = 0.0;
	mVelX = 0;
	mVelY = 0;
}


void Zombie::move(int aX, int aY)
{
	if (aX > mPosX) {
		mVelX = Z_VEL;
	}
	else if (aX < mPosX) {
		mVelX = -Z_VEL;
	}
	else if (aX == mPosX) {
		mVelX == 0;
	}


	mPosX += mVelX;

	if (aY > mPosY) {
		mVelY = Z_VEL;
	}
	else if (aY < mPosY) {
		mVelY = -Z_VEL;
	}
	else if (aY == mPosY) {
		mVelY == 0;
	}


	mPosY += mVelY;
}

void Zombie::render()
{
	gZombieTexture.render(mPosX, mPosY, NULL, mAngle);
}

int Zombie::getPosX()
{
	return mPosX;
}

int Zombie::getPosY()
{
	return mPosY;
}
