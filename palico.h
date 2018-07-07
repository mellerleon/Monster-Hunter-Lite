#ifndef palico_h
#define palico_h

#include "hunter.h"
#include "monster.h"
#include "dummy.h"
#include <string>

using namespace std;

class palico{
	
public:
int p_hp;
int p_attack;
int sword_atk;
string sword_name;

string last_name, first_name, gender;
int age;

int R,G,B;
int p_x,p_y;

palico(int,int,string,string,string,int,string,int);
void attackMonster(monster *);
void cure(hunter *);
bool checkDead();
int getHP();	
};


#endif