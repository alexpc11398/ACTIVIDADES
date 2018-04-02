#include "Board.h"



Board::Board()
{
	readBoardFile();
	initBoard();


}


Board::~Board()
{
}

void Board::initBoard()
{
	board = new char*[NUM_ROWS];

	for (int i = 0; i < NUM_ROWS; i++)
	{
		board[i] = new char[NUM_COLUMNS];
	}
	int bloques = x;
	if (bloques >(NUM_ROWS - 2) / 2) {
		bloques = (NUM_ROWS - 2) / 2;
	}
	for (int i = 0; i < NUM_ROWS; i++) //Primero los bordes del tablero
	{
		board[i][0] = '|';
		board[i][NUM_COLUMNS - 1] = '|';
	}
	for (int i = 0; i < NUM_COLUMNS; i++)
	{
		board[0][i] = '_';
		board[NUM_ROWS - 1][i] = '_';
	}
	for (int i = 1; i <NUM_ROWS - 1; i++) // Luego rellenamos el tablero de bloques y de vacio
	{
		for (int j = 1; j < NUM_COLUMNS - 1; j++)
		{
			if (i <= bloques)
			{
				board[i][j] = '@';
			}
			else {
				board[i][j] = ' ';
			}
		}
	}
}

void Board::printBoard()
{
	for (int i = 0; i < NUM_ROWS; i++) {
		for (int j = 0; j < NUM_COLUMNS; j++) {
			std::cout << board[i][j];
		}
		std::cout << std::endl;
	}
}

char Board::getCell(int x, int y)
{
	return board[y][x];
}

int Board::getRows()
{
	return NUM_ROWS;
}

int Board::getColumns()
{
	return NUM_COLUMNS;
}

void Board::setCell(int x, int y, char caracter)
{
	board[y][x] = caracter;
}

void Board::readBoardFile()
{
	std::string ROWS;
	std::string COLUMNS;
	std::string BLOQUES;
	std::string line;

	std::ifstream myFile("config.txt");
	if (myFile.is_open())
	{
		int lineCounter = 0;
		while (getline(myFile, line))
		{
			if (lineCounter == 0) {
				int i = 0;
				while (line[i] != ';')
				{
					ROWS.push_back(line[i]);
					i++;
				}
				i++;
				while (line[i] != ';')
				{
					COLUMNS.push_back(line[i]);
					i++;
				}
			}
			else {
				int i = 0;
				while (line[i] != ';')
				{
					BLOQUES.push_back(line[i]);
					i++;
				}
			}
			lineCounter++;
		}
		myFile.close();
	}
	else std::cout << "Unable to open file";


	NUM_ROWS = std::stoi(ROWS);
	NUM_COLUMNS = std::stoi(COLUMNS);
	x = std::stoi(BLOQUES);
}