#pragma once
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>

class Board
{
private:
	int NUM_COLUMNS;
	int NUM_ROWS;
	int x;
	char **board;
	void initBoard();
	void readBoardFile();
public:
	Board();
	~Board();
	void printBoard();
	char getCell(int x, int y);
	int getRows();
	int getColumns();
	void setCell(int x, int y, char caracter);

};