#include<iostream>
//#include<>


//Estos parametros habra que cogerlos de un fichero a parte
const int NUM_ROWS{ 10 };
const int NUM_COLUMNS{ 10 };
int x; //numero bloques



enum class componentes {bloque,bola,borde_inferior,borde_lateral,jugador,vacio};

componentes board[NUM_ROWS][NUM_COLUMNS];

componentes InitBoard(componentes array[][NUM_COLUMNS])
{
	int bloques = x;
	for (int i = 0; i <= NUM_COLUMNS;i++) //Primero los bordes del tablero
	{
		array[0][i] = componentes::borde_lateral;

	}
	for (int i = 1; i <= NUM_ROWS; i++)
	{
		array[i][0] = componentes::borde_inferior;

	}
	for (int i = 1; i < NUM_ROWS >0; i++) // Luego rellenamos el tablero de bloques y de vacio
	{ 
		for (int j = 1; j < NUM_COLUMNS >0; j++)
		{
			if (bloques > 0)
			{
				array[i][j] = componentes::bloque;
			}
			else {
				array[i][j] = componentes::vacio;
			}
			
		}

	}


}

componentes PrintBoard(componentes array[][NUM_COLUMNS])
{
	
}