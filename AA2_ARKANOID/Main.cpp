#include "Board.h"
#include "Ball.h"
#include <Windows.h>

int main() {

	Board map;

	Ball *pelota = new Ball(map.getColumns() / 2, map.getRows() / 2);

	map.setCell(pelota->getPosX(), pelota->getPosY(), '*');

	map.printBoard();


	while (true)
	{
		Sleep(1);
		system("cls");
		int current_x = pelota->getPosX();
		int current_y = pelota->getPosY();
		int next_x = pelota->getPosX() + pelota->getVel_X();
		int next_y = pelota->getPosY() + pelota->getVel_Y();
		int newVel_X;
		int newVel_Y;
		int collisionVertical_x = pelota->getPosX() + pelota->getVel_X();
		int collisionVertical_y = pelota->getPosY();
		int collisionHorizontal_x = pelota->getPosX();
		int collisionHorizontal_y = pelota->getPosY() + pelota->getVel_Y();

		char horizontalChar = map.getCell(collisionHorizontal_x, collisionHorizontal_y);
		char verticalChar = map.getCell(collisionVertical_x, collisionVertical_y);
		char diagonalChar = map.getCell(next_x, next_y);

		if (verticalChar == ' ' && horizontalChar == ' ') {
			if (diagonalChar == '@') {
				newVel_X = pelota->getVel_X();
				newVel_X *= -1;
				newVel_Y = pelota->getVel_Y();
				newVel_Y *= -1;
				map.setCell(next_x, next_y, ' ');
			}
			else {
				newVel_X = pelota->getVel_X();
				newVel_Y = pelota->getVel_Y();
			}
		}
		else if (verticalChar != ' ' && horizontalChar == ' ') {
			newVel_X = pelota->getVel_X();
			newVel_X *= -1;
			newVel_Y = pelota->getVel_Y();
			if (verticalChar == '@') {
				map.setCell(collisionVertical_x, collisionVertical_y, ' ');
			}
		}

		else if (verticalChar == ' ' && horizontalChar != ' ') {
			newVel_X = pelota->getVel_X();
			newVel_Y = pelota->getVel_Y();
			newVel_Y *= -1;
			if (horizontalChar == '@') {
				map.setCell(collisionHorizontal_x, collisionHorizontal_y, ' ');
			}
		}

		else if (verticalChar != ' ' && horizontalChar != ' ') {
			newVel_X = pelota->getVel_X();
			newVel_X *= -1;
			newVel_Y = pelota->getVel_Y();
			newVel_Y *= -1;
			if (verticalChar == '@' && horizontalChar == '@') {
				map.setCell(collisionHorizontal_x, collisionHorizontal_y, ' ');
				map.setCell(collisionVertical_x, collisionVertical_y, ' ');
			}
			else if (verticalChar == '|' && horizontalChar == '@')
			{
				map.setCell(collisionHorizontal_x, collisionHorizontal_y, ' ');
			}
			else if (verticalChar == '@' && horizontalChar == '_') {
				map.setCell(collisionVertical_x, collisionVertical_y, ' ');
			}

		}
		pelota->setVel(newVel_X, newVel_Y);
		next_x = pelota->getPosX() + pelota->getVel_X();
		next_y = pelota->getPosY() + pelota->getVel_Y();
		map.setCell(current_x, current_y, ' ');
		map.setCell(next_x, next_y, '*');


		pelota->movement();


		map.printBoard();

	}


	return 0;
}