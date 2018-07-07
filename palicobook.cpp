#include "palicobook.h"


void palicobook::add(palico *p){ // Inserting a new struct to the set companion           

	companion.insert(palico_cat(p->first_name,p->last_name,p->gender,p->age,p->p_hp,
		             p->p_attack,p->sword_name,p->sword_atk));
}

void palicobook::change_mode(int hp_attack){

}

palico* palicobook::max(int hp_attack){
	
}

void palicobook::remove(string a, string b){
	for(iter = companion.begin(); iter != companion.end(); iter++){
		if((a==iter->first_name) && (b==iter->last_name)){
			companion.erase(iter);
			cout << "\nPalico removed" << endl;
			break;
		}
	}
	if((a!=iter->first_name) && (b!=iter->last_name)){
		cout << "\nContact not found" << endl;
	}
}

void palicobook::search(){
	string a,b;
	cout << "\nEnter first and last name to search: " << endl;
	cin >> a;
	cin >> b;
	for(iter = companion.begin(); iter != companion.end(); iter++){
		if((a==iter->first_name) && (b==iter->last_name)){
			cout << "\nContact found" << endl;
			cout << iter->first_name << " " << iter->last_name 
			<< ", " << iter->gender << ", " << iter->age <<", HP: "
			<< iter->hp<<", Attack: "<<iter->atk << ", Sword: " <<iter->s_name 
			<<"("<< iter->s_atk<<")" << endl;
			break;
		}
	}
	if((a!=iter->first_name) && (b!=iter->last_name)){
		cout << "\nContact not found" << endl;
	}
}

void palicobook::save(){
	ofstream palicos("Palico.txt");
	for(iter = companion.begin(); iter != companion.end(); iter++){
		palicos << iter->first_name << " " << iter->last_name << " " 
		<< iter->gender << " " << iter->age <<", HP: "
		<< iter->hp<<", Attack: "<<iter->atk << ", Sword: " <<iter->s_name 
		<<"("<< iter->s_atk<<")"<<endl<<endl;
	}
	palicos.close();
}

void palicobook::print(){
	for(iter = companion.begin(); iter != companion.end(); iter++){
		cout << iter->first_name << " " << iter->last_name << endl;
	}
}
