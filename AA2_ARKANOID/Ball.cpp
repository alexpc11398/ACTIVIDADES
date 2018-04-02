#include "Ball.h"



Ball::Ball()
{
}

Ball::Ball(int x, int y)
{
	vel_X = 1;
	vel_Y = 1;
	posX = x;
	posY = y;
}


Ball::~Ball()
{
}

int Ball::getPosX()
{
	return posX;
}

int Ball::getPosY()
{
	return posY;
}

int Ball::getVel_X()
{
	return vel_X;
}

int Ball::getVel_Y()
{
	return vel_Y;
}

void Ball::setPos(int x, int y)
{
	posX = x;
	posY = y;
}

void Ball::setVel(int x, int y)
{
	vel_X = x;
	vel_Y = y;
}

void Ball::movement()
{
	posX += vel_X;
	posY += vel_Y;
}
