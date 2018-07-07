#ifndef monster_h
#define monster_h

#include "hunter.h"
#include "palico.h"
#include "dummy.h"
#include <string>

using namespace std;

class monster{
public:
	int m_hp;
	int m_attack;
	int m_defense;
	string last_name, first_name, gender;
	int age;

	int R,G,B;
	int m_x,m_y;

	monster(int, int, int, string, string, string, int);
	void attackHunter(hunter *h);
	void defendHunter(hunter *h);
	void attackPalico(palico *p);
	bool checkDead();
	int getHP();
};

#endif