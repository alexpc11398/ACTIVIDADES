#pragma once
class Ball
{
private:
	int vel_X;
	int vel_Y;
	int posX;
	int posY;

public:
	Ball();
	Ball(int x, int y);
	~Ball();
	int getPosX();
	int getPosY();
	int getVel_X();
	int getVel_Y();
	void setPos(int x, int y);
	void setVel(int x, int y);
	void movement();



};