#include "Avatar.h"
#include "LTexture.h"
extern LTexture gAvatarTexture;
extern const int LEVEL_WIDTH = 1024;
extern const int LEVEL_HEIGHT = 768;

Avatar::Avatar()
{
	//Initialize the offsets
	mPosX = 0;
	mPosY = 0;

	//Initialize the velocity
	mVelX = 0;
	mVelY = 0;

	mAngle = 0.0;
	health = 100;
	maxHealth = 100;
}

void Avatar::handleEvent(SDL_Event& e)
{
	//If a key was pressed
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		//Adjust the velocity
		switch (e.key.keysym.sym)
		{
		case SDLK_w: mVelY -= AV_VEL; break;
		case SDLK_s: mVelY += AV_VEL; break;
		case SDLK_a: mVelX -= AV_VEL; break;
		case SDLK_d: mVelX += AV_VEL; break;

		}
	}
	//If a key was released
	else if (e.type == SDL_KEYUP && e.key.repeat == 0)
	{
		//Adjust the velocity
		switch (e.key.keysym.sym)
		{
		case SDLK_w: mVelY += AV_VEL; break;
		case SDLK_s: mVelY -= AV_VEL; break;
		case SDLK_a: mVelX += AV_VEL; break;
		case SDLK_d: mVelX -= AV_VEL; break;
		}
	}
}

void Avatar::move()
{
	//Move the dot left or right
	mPosX += mVelX;

	//If the dot went too far to the left or right
	if ((mPosX < 0) || (mPosX + AV_WIDTH > LEVEL_WIDTH))
	{
		//Move back
		mPosX -= mVelX;
	}

	//Move the dot up or down
	mPosY += mVelY;

	//If the dot went too far up or down
	if ((mPosY < 0) || (mPosY + AV_HEIGHT > LEVEL_HEIGHT))
	{
		//Move back
		mPosY -= mVelY;
	}
}

void Avatar::render()
{
	//Show the dot relative to the camera
	gAvatarTexture.render(mPosX, mPosY,NULL,mAngle);
}

int Avatar::getPosX()
{
	return mPosX;
}

int Avatar::getPosY()
{
	return mPosY;
}

void Avatar::calculateAngle(int mX,int mY) {
	mAngle = (atan2((mPosX+AV_WIDTH/2) - mX, (mPosY+AV_HEIGHT/2) - mY)*180.0000) / (-3.1416) ;

}
