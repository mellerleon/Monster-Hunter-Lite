#include "dummy.h"
#include "hunter.h"
#include "palico.h"

class champion : public hunter, palico{
public:

	void attackMonster(monster *m){
		if((h_attack - m->m_defense) > 0){
			m->m_hp -= h_attack - m->m_defense;
		}
		if(p_attack > m->m_defense){
			m->m_hp -= p_attack - m->m_defense;
		}
	}

	void cure(){
		h_hp += 5;
	}
};