#include <iostream>
#include <string>
#include <ctime>


std::string names[] = { "Pepe","Alex","Edu","Marc" };
int i=0;
int j = 0;
enum EnemyType
{
	ZOMBIE, VAMPIRE, GHOST, WITCH
};

struct Enemy
{
	EnemyType type;
	std::string name;
	int health;
};

bool equalEnemies(Enemy x, Enemy y)
{
	return x.type == y.type && x.name == y.name;
}

Enemy createRandomEnemy()
{
	Enemy enemigo1;	

	enemigo1.type =	static_cast <EnemyType> (rand() % 4);

	enemigo1.name = names[rand() % 4];

	enemigo1.health = rand() % 101;
	
	return enemigo1;

}

std::string getEnemyTypeString(Enemy x) 
{
	std::string tipoEnemigo;

	tipoEnemigo = static_cast <EnemyType> (x.type);

	return tipoEnemigo;

}


int main() 
{
	Enemy banda[5];

	while (i < 5)
	{
		banda[i] = createRandomEnemy();

		while (j < i) {
			if (equalEnemies(banda[i], banda[j])) {
				banda[i] = createRandomEnemy();
			}
			else j++;
		}
		i++;
	}
	for (int i = 0; i < 5; i++) 
	{
		std::cout << banda[i].name << " is a " << getEnemyTypeString(banda[i]) << " whose life is " << banda[i].health << std::endl;
	}

	
}
