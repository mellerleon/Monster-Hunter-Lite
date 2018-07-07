#include "hunter.h"

hunter::hunter(int hp, int stamina, int atk, int def, string s_name, int s_atk, string e_name, int e_def) // Set constructor
{ 
	h_hp = hp;
	h_stamina = stamina;
	h_attack = atk + s_atk;
	h_defense = def + e_def;
	sword_name = s_name;
	equipment_name = e_name;
	sword_atk = s_atk;
	equip_def = e_def;
}

void hunter::attackMonster(monster *m) // Hunter attacking monster
{
	if((h_attack - m->m_defense) <= 0)
	{
		m->m_hp -= 5;
	} 
	else{m->m_hp -= h_attack - m->m_defense;}
}

void hunter::defendMonster(monster *m) // Hunter defending from monster attack
{
	if((m->m_attack - h_defense) <= 0)
	{
		h_hp -= 0;
	}
	else{h_hp -= m->m_attack - h_defense;}
}

void hunter::lostStamina() // Stamina loss everytime Hunter encounters monster or walks
{
	h_stamina -= 20;
}

bool hunter::checkDead(){	// Checking whether Hunter is dead when he or she is out of HP or stamina 
	if(h_hp <= 0){
		return true;
	}
	else{return false;}
}

int hunter::getStamina(){	// Returns the stamina value
	return h_stamina;
}

int hunter::getHP(){	// Returns the HP value
	return h_hp;
}
