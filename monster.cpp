#include "monster.h"

monster::monster(int hp, int atk, int def,string f_name, string l_name, string sex, int num){	// Set constructor
	m_hp = hp;
	m_attack = atk;
	m_defense = def;
	first_name = f_name;
	last_name = l_name;
	gender = sex;
	age = num;
}

void monster::attackHunter(hunter *h){	// Monster attacking Hunter
	if((m_attack - h->h_defense) <= 0){
		h->h_hp -= 5;
	} 
	else{
		h->h_hp -= m_attack - h->h_defense;
	}
}

void monster::defendHunter(hunter *h){	// Monster defending the attack from Hunter
	if((h -> h_attack - m_defense) <= 0){
		m_hp -= 0;
	}
	else{
		m_hp -= h->h_attack - m_defense;
	}
}

void monster::attackPalico(palico *p)	// Monster attacking Palico
{
	p->p_hp -= m_attack;
}

bool monster::checkDead(){	// Checking whether Monster is dead when its HP = 0
	if(m_hp <= 0){
		return true;
	}
	else{return false;}
}

int monster::getHP(){	// Returns the HP value
	return m_hp;
}