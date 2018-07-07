#ifndef hunter_h
#define hunter_h

#include "monster.h"
#include "palico.h"
#include "dummy.h"
#include <string>

using namespace std;

class hunter{
public:
	int h_stamina;
	int h_hp; 
	int h_attack; 
	int h_defense; 
	int sword_atk;
	int equip_def;
	string sword_name,equipment_name;

	string last_name, first_name, gender;
	int age;
	
	int h_x,h_y;
	int R,G,B;

	int max_stamina,max_HP,max_atk,max_def;

	hunter(int, int, int, int, string, int, string, int);
	void attackMonster(monster *);
	void defendMonster(monster *);
	void lostStamina();
	bool checkDead();
	int getStamina();
	int getHP();
};

#endif 
