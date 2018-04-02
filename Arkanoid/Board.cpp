#include<iostream>

//#include<>


//Estos parametros habra que cogerlos de un fichero a parte
const int NUM_ROWS{ 10 };
const int NUM_COLUMNS{ 10 };
int x; //numero bloques

//enum class componentes {bloque,bola,borde_horizontal,borde_vertical,jugador,vacio};

char **board;

void InitBoard()
{
	board = new char*[NUM_COLUMNS];
	
	for (int i = 0; i < NUM_COLUMNS; i++)
	{
		board[i] = new char [NUM_ROWS];
	}
	int bloques = x;
	if (bloques > (NUM_ROWS-2) / 2) {
		bloques = (NUM_ROWS-2) / 2;
	}	
	for (int i = 0; i <= NUM_COLUMNS;i++) //Primero los bordes del tablero
	{
		board[0][i] = '|';
	}
	for (int i = 1; i <= NUM_ROWS; i++)
	{
		board[i][0] = '_';
	}
	for (int i = 1; i <NUM_ROWS-1; i++) // Luego rellenamos el tablero de bloques y de vacio
	{ 
		for (int j = 1; j < NUM_COLUMNS-1; j++)
		{
			if (i <=bloques+1)
			{
				board[i][j] = '@';
			}
			else {
				board[i][j] = ' ';
			}			
		}
	}
}

void PrintBoard()
{	
	for (int i = 0; i < NUM_COLUMNS; i++) {
		for (int j = 0; j < NUM_ROWS; j++) {
			std::cout << board[i][j] <<std::endl;
		}
	}
}