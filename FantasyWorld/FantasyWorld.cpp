#include<iostream>
#include "FantasyWorld.h"
#include "Monster.h"
#include <stdlib.h>
#include <time.h>

using namespace std;
//Monster *mst = new Monster();
Monster *monloc[30][30];


int Monster::MonsterNumber = 0;

FantasyWorld::FantasyWorld()
{
}


FantasyWorld::~FantasyWorld()
{
}

void FantasyWorld::PrintWorld()
{	

}

void FantasyWorld::InitMonster()
{
	
	srand(time(NULL));
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			if (Monster::MonsterNumber < 99)
			{
				int randspawn = rand() % 5;
				if (randspawn == 1)
				{
					
					/*Monster::MonsterNumber++;
					monloc[i][j].PrintMonster();
					monloc[i][j].MonsterName = Monster::MonsterNumber;
					monloc[i][j].MonsterLocX = j;
					monloc[i][j].MonsterLocY = i;
					monloc[i][j].Alive = true;*/
					/*Monster::MonsterNumber++;
					MapGrid[i][j] = Monster::MonsterNumber;*/

					
					Monster::MonsterNumber++;
					monloc[i][j] = new Monster();
					monloc[i][j]->MonsterName = Monster::MonsterNumber;
					monloc[i][j]->PrintMonster();
				}
			}
		}
	}

	//cout << Monster::MonsterNumber++;
}

void FantasyWorld::UpdateWorld()
{
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			if (monloc[i][j] != NULL)
			{
				if (monloc[i][j]->HP > 0)
				{
					monloc[i][j]->HP--;
				}

				if (monloc[i][j]->HP <= 0)
				{
					
					RespawnMonster(i,j);
					monloc[i][j] = NULL;
				}
			}
		}
	}
}

void FantasyWorld::RespawnMonster(int row,int col)
{
	bool finishSwap = false;
	int Monnum = monloc[row][col]->MonsterName;

	while (!finishSwap)
	{
		int newX = rand() % 30;
		int newY = rand() % 30;
		if (monloc[newY][newX] == NULL)
		{	
			monloc[newY][newX] = new Monster();
			monloc[newY][newX]->MonsterName = Monnum;
			monloc[newY][newX]->PrintMonster();
			finishSwap = true;
		}
	}
}

void FantasyWorld::print()
{
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{

			if (monloc[i][j] != NULL)
			{
				//cout << "[" <<"<" << monloc[i][j].MonsterName << ">" <<monloc[i][j].HP << "]";
				if (monloc[i][j]->MonsterName < 10)
				{
					cout << "[0" << monloc[i][j]->MonsterName << "]";
				}
				else
				{
					cout << "[" << monloc[i][j]->MonsterName << "]";
				}
			}
			else
			{
				cout << "[  ]";
			}

			if (j == 29)
			{
				cout << endl;
			}

		}
	}
	cout << "---------------------------------------" <<endl;

}