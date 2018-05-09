#include <iostream>
#include "FantasyWorld.h"
#include "Monster.h"

using namespace std;
int main()
{
	char c;
	FantasyWorld *ftw = new FantasyWorld();
	
	ftw->InitMonster();
	ftw->print();
	while (true)
	{
		cin >> c;
		if (c == 'a')
		{
			ftw->UpdateWorld();
			ftw->print();
		}
	}
	
	
	getchar();
	return 0;
}