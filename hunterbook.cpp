#include "hunterbook.h"


void hunterbook::add(hunter *h){ // Add while loop for this part in main           

	cout << "First name: ";		
	cin >> f_name;
	cout << "Last name: ";		
	cin >> l_name;
	cout << "Gender: ";
	cin >> gend;
	cout << "Age (18-70): ";
	cin >> num2;
	while(num2<18 || num2>70){
		cout << "Enter correct age: ";
		cin.clear();
		cin.ignore(100, '\n');
		cin >> num2;
	}
	character.insert(player(f_name,l_name,gend,num2,
					 h->h_stamina,h->h_hp,h->h_attack,
					 h->h_defense,h->sword_name,h->sword_atk,
					 h->equipment_name,h->equip_def));
	
	// Setting hunter names, gender, and age
	h->first_name = f_name;
	h->last_name = l_name;
	h->gender = gend;
	h->age = num2;
}


int hunterbook::size(){
	count = 0;
	for(iter = character.begin(); iter!=character.end(); iter++){
		count++;
	}
	return count;
}

void hunterbook::sort(int s){
	for(iter=character.begin(); iter!=character.end(); iter++){
		character_HP.insert(player(iter->first_name,iter->last_name,iter->gender,
							iter->age,iter->energy,iter->hp,iter->atk,iter->def,
							iter->s_name,iter->s_atk,iter->eq_name,iter->eq_def));
	}
}

hunter* hunterbook::get_max(int s){
}

void hunterbook::remove(string a, string b){
	for(iter = character.begin(); iter != character.end(); iter++){
		if((a==iter->first_name) && (b==iter->last_name)){
			cout << "\nHunter removed: " << iter->first_name << " " << iter->last_name << endl;
			character.erase(iter);
			break;
		}
	}
	if((a!=iter->first_name) && (b!=iter->last_name)){
		cout << "\nContact not found" << endl;
	}
}

void hunterbook::search(){
	string a,b;
	cout << "Enter first and last name to search: " << endl;
	cin >> a;
	cin >> b;
	for(iter = character.begin(); iter != character.end(); iter++){
		if((a==iter->first_name) && (b==iter->last_name)){
			cout << "\nContact found:" << endl;
			cout << iter->first_name << " " << iter->last_name 
			<< ", " << iter->gender << ", " << iter->age <<", HP: "
			<< iter->hp<<", Attack: "<<iter->atk<<", Defense: "<<iter->def
			<< ", Sword: " <<iter->s_name <<"("<< iter->s_atk<<")"<<", Equipment: "
			<<iter->eq_name << "(" << iter->eq_def <<")"<< endl;
			break;
		}
	}
	if((a!=iter->first_name) && (b!=iter->last_name)){
		cout << "\nContact not found." << endl;
	}
	
}

void hunterbook::save(){
	ofstream hunters("Hunter.txt");
	for(iter = character.begin(); iter != character.end(); iter++){
		hunters << iter->first_name << " " << iter->last_name 
			<< ", " << iter->gender << ", " << iter->age <<", HP: "
			<< iter->hp<<", Attack: "<<iter->atk<<", Defense: "<<iter->def
			<< ", Sword: " <<iter->s_name <<"("<< iter->s_atk<<")"<<", Equipment: "
			<<iter->eq_name << "(" << iter->eq_def <<")"<< endl << endl;
	}
	hunters.close();
}

void hunterbook::print(){
	for(iter = character.begin(); iter != character.end(); iter++){
		cout << iter->first_name << " " << iter->last_name << " " 
		<< iter->gender << " " << iter->age <<" "<< iter->s_name <<" "<< iter->s_atk<<
		" "<<iter->eq_name << " " << iter->eq_def << endl;
	}
}

