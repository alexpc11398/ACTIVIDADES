#include <stdio.h>
#include <iostream>
#include <time.h>

const int NUM_ROWS{ 10 };
const int NUM_COLUMNS{ 10 };
info jugador;

enum class Movement 
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	MAX
};


enum class componentes
{
	PIEDRAS,
	MONEDAS,
	JUGADOR,
	VACIO,
	MAX
};

componentes board[NUM_ROWS][NUM_COLUMNS];


struct info
{
	int posRows;
	int posColumns;
	int score;
};

componentes initializeBoard(componentes array[][NUM_COLUMNS]) {
	
	int piedras = rand() % (20 / 100)*(NUM_ROWS*NUM_COLUMNS);
	int monedas = rand() % (30 / 100)*(NUM_ROWS*NUM_COLUMNS);
	int player = 1;	
	
	for (int i = 0; i < NUM_ROWS; i++) {
		for (int j = 0; j < NUM_COLUMNS; j++)
		{
			array[i][j] = componentes::VACIO;					
		}
	}

	for (int i = 0; i < piedras; i++)
	{
		int row = rand() % NUM_ROWS;
		int column = rand() % NUM_COLUMNS;
		if (array[row][column] == componentes::VACIO) {
			array[row][column] = componentes::PIEDRAS;
		}
		else {
			i--;
		}
	}

	for (int i = 0; i < monedas; i++)
	{
		int row = rand() % NUM_ROWS;
		int column = rand() % NUM_COLUMNS;
		if (array[row][column] == componentes::VACIO) {
			array[row][column] = componentes::MONEDAS;
		}
		else {
			i--;
		}
	}

	for (int i = 0; i < piedras; i++)
	{
		int row = rand() % NUM_ROWS;
		int column = rand() % NUM_COLUMNS;
		if (array[row][column] == componentes::VACIO) {
			array[row][column] = componentes::JUGADOR;
			jugador.posRows = row;
			jugador.posColumns = column;
		}
		else {
			i--;
		}
	}

}


bool checkMovement(info& player, Movement movimiento) {
	switch (movimiento)
	{
	case Movement::UP:
		if (player.posRows != 0)
			return board[player.posRows - 1][player.posColumns] != componentes::PIEDRAS;
		else
			return false;
		
	case Movement::DOWN:
		if (player.posRows != NUM_ROWS)
			return board[player.posRows + 1][player.posColumns] != componentes::PIEDRAS;
		else
			return false;
		
	case Movement::LEFT:
		if (player.posColumns != 0)
			return board[player.posRows][player.posColumns - 1] != componentes::PIEDRAS;
		else
			return false;
		
	case Movement::RIGHT:
		if (player.posColumns != NUM_COLUMNS)
			return board[player.posRows][player.posColumns + 1] != componentes::PIEDRAS;
		else
			return false;
			
	default:
		break;
	}
	
}

int updateScore() {
	jugador.score++;
}

int updateScore(info& player, int row,int columns) {
	player.posRows=row;
	player.posColumns= columns;
}

int movePlayer(Movement movimiento) {
	switch (movimiento)
	{
	case Movement::UP:
		checkMovement(jugador,movimiento);
	case Movement::DOWN:
		break;
	case Movement::LEFT:
		break;
	case Movement::RIGHT:
		break;
	case Movement::MAX:
		break;
	default:
		break;
	}
}