#include<iostream>
#include "Monster.h"
#include <stdlib.h>
#include <time.h>

using namespace std;


Monster::Monster()
{
}


Monster::~Monster()
{
}

void Monster::PrintMonster()
{
	HP = rand() % 6 + 1;
}
