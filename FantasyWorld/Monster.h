#pragma once
class Monster
{
public:
	Monster();
	~Monster();
	void PrintMonster();
	static int MonsterNumber;
	int HP;
	int MonsterName;
	int MonsterLocX;
	int MonsterLocY;
	bool Alive;
};

