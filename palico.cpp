#include "palico.h"

palico::palico(int hp, int atk, string f_name, string l_name, string sex, int num, string s_name, int s_atk)	// Set constructor
{
	p_hp = hp;
	p_attack = atk + s_atk;
	first_name = f_name;
	last_name = l_name;
	gender = sex;
	age = num;
	sword_name = s_name;
	sword_atk = s_atk;
}

void palico::attackMonster(monster *m) // Palico attacking MOnster
{
	if(p_attack > m->m_defense){
		m->m_hp -= p_attack - m->m_defense;
	}
	else{
		m->m_hp -= 1;
	}
}

void palico::cure(hunter *h) // Palico increasing the HP of Hunter and itself by 5 HP
{
	h->h_hp += 5;
	p_hp += 5;
}

bool palico::checkDead() // checks to see if the Palico is dead or not
{
	if(p_hp <= 0)
	{
		return true;
	}

	else{return false;}
}

int palico::getHP() // returns the HP of Palico
{
	return p_hp;
}