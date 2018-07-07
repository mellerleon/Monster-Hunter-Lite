#include "monsterbook.h"

monsterbook::monsterbook(){
	head = NULL;
	tail = NULL;
	temp1 = NULL;
	temp2 = NULL;
	temp3 = NULL;
	temp4 = NULL;
}

void monsterbook::add(monster* m){
	current = new node;

	current->first_name = m->first_name;
	current->last_name = m->last_name;
	current-> gender = m->gender;
	current->age = m->age;
	current->next = NULL;
	current->prev = NULL;

	if(head == NULL){
		head = current;
		tail = current;
		return; 
	}

	else{
		temp1 = head; // temporarily store head (old current value) 

		if(current->first_name < temp1->first_name){
			current->next = temp1; // current --> temp1 *connection set-up*
			temp1->prev = current; // current <-- temp1
			current->prev = NULL; // current is head so before is NULL
			head = current;	// set current to be the head
			temp1 = head; // temporarily store the head (new current value) 
						  // used to traverse through the list to set the tail 	

			while(temp1->next != NULL){ // traverse to set-up the tail
				temp1 = temp1->next;
				tail = temp1;
			}
		}

		else if(current->first_name > temp1->first_name){
			while(temp1 != NULL && current->first_name > temp1->first_name){
				temp2 = temp1;
				temp1 = temp1->next;

				if(temp1 == NULL){  // if the current starts with the last letter of alphabet
					temp2->next = current;
					current->prev = temp2;
					current->next = NULL;
					tail = current;
					break;
				}
				else if(current->first_name < temp1->first_name){ // if the current starts in the middle of alphabet
					temp2->next = current;
					current->prev = temp2;  // current in the middle so connect to temp2 (prev)
					current->next = temp1;  // and temp1 (next)
					temp1->prev = current;

					while(temp1 != NULL){ // setting the tail.
						temp1 = temp1->next;
						tail = temp1;
					}

					break;	
				}
			}
		}
		else if(current->first_name == temp1->first_name){ // in case if both first names are equal
			if(current->last_name < temp1->last_name){ // same conditions as first name comparison
				current->next = temp1; // current --> temp1 *connection set-up*
				temp1->prev = current; // current <-- temp1
				current->prev = NULL; // current is head so before is NULL
				head = current;	// set current to be the head
				temp1 = head; // temporarily store the head (new current value) 
						  // used to traverse through the list to set the tail 	

				while(temp1->next != NULL){ // traverse to set-up the tail
					temp1 = temp1->next;
					tail = temp1;
				}	
			}
			else if(current->last_name > temp1->last_name){
				while(temp1 != NULL){
					temp2 = temp1;
					temp1 = temp1->next;

					if(temp1 == NULL){  // if the current starts with the last letter of alphabet
						temp2->next = current;
						current->prev = temp2;
						current->next = NULL;
						tail = current;
						break;
					}
					else if(current->last_name < temp1->last_name){ // if the current starts in the middle of alphabet
						temp2->next = current;
						current->prev = temp2;  // current in the middle so connect to temp2 (prev)
						current->next = temp1;  // and temp1 (next)
						temp1->prev = current;

						while(temp1 != NULL){ // setting the tail.
							temp1 = temp1->next;
							tail = temp1;
						}

						break;	
					}
				}
			}
		}
	}
}

void monsterbook::save(){ // issue with writing values of linked list to a textfile
	temp1 = head;
	ofstream monsters("Monsters.txt");
	while(temp1 != NULL){
		monsters <<	temp1->first_name << " " << temp1->last_name << ", " 
				 << temp1->gender << ", " << temp1->age << endl;
		temp1 = temp1->next;
	}
	monsters.close();
}

void monsterbook::remove(string r){
	temp1 = head;
	if(r == temp1->first_name){
		cout << r << " removed from the list." << endl;			
		head = head->next;
		head->prev = NULL;
		delete temp1,temp2,temp3;
	}
	else{
		while(temp1 != NULL){
			temp1 = temp1->next;
			if(r == temp1->first_name){
				temp2 = temp1->prev;
				temp3 = temp1->next;
				temp2->next = temp3; // next of temp1->prev to temp1->next
				temp3->prev = temp2; // prev of temp1->next to temp1->prev
				cout << "Contact removed" << endl;
				delete temp1,temp2,temp3;
				break;
			}
			else if(temp1->next == NULL){ // deleting the last node (seg fault)
				if(r==temp1->first_name){
					tail = temp1->prev;
					cout << "Contact removed" << endl;
					delete temp1,temp2,temp3;
					break;
				}
			}
			else if(temp1==NULL){ // when not in the list (seg fault)
				cout << "Contact not found."<<endl;
				delete temp1, temp2, temp3;
				break;
			}
		}
	}
}

void monsterbook::search(string s, monster *m){
	temp1 = head;
	if(s == temp1->first_name){
		cout <<	temp1->first_name << " " << temp1->last_name << ", " 
			 << temp1->gender << ", " << temp1->age << endl;
		cout << "Attack: " << m->m_attack << endl;
		cout << "Defense: " << m->m_defense << endl;
		cout << "HP: " << m->m_hp << endl;
		delete temp1;
	}
	while(s != temp1->first_name){
		temp1 = temp1->next; // traverse through until matched name is found
		if(s == temp1->first_name){
			cout <<	temp1->first_name << " " << temp1->last_name << ", " 
			 << temp1->gender << ", " << temp1->age << endl;
			cout << "Attack: " << m->m_attack << endl;
			cout << "Defense: " << m->m_defense << endl;
			cout << "HP: " << m->m_hp << endl;
			delete temp1;
			break;
		}
		else if(temp1 == NULL){
			cout << "Contact not found" << endl;
			delete temp1;
			break;
		}
	}
	
}