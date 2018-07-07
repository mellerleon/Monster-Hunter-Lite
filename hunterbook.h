#ifndef HUNTERBOOK_H
#define HUNTERBOOK_H

#include <string>
#include <fstream>
#include <iostream>
#include <set>
#include <iterator>
#include <vector>
#include "hunter.h"

struct player{
	player(string name1,string name2,string gen,int num, int a, int b, int c, int d,string name3, int e, string name4, int f) : first_name(name1), last_name(name2), gender(gen), 
	age(num), energy(a), hp(b),atk(c),def(d), s_name(name3),s_atk(e),eq_name(name4),eq_def(f) {}
	
	string first_name, last_name,gender,s_name,eq_name;
	int age,energy,hp,atk,def,s_atk,eq_def;
};

/*// Compares set values by the first name and organizes alphabetically
bool operator < (const player& left, const player& right){
	// Organizes by last name if first names are the same
	if(left.first_name == right.first_name){
		return left.last_name < right.last_name;
	}
	else{return left.first_name < right.first_name;}
	}

// Compares set values by the hunters' HP values and organizes in descending order
bool operator > (const player& left, const player& right){
	// Organizes by the hunters' attack values if the HP values are the same
	if(left.hp == right.hp){
		return left.atk > right.atk;
	}
	else{return left.hp > right.hp;}
	}*/

struct compare_name{ // comparison condition to organize first name by alphabetical order
	bool operator()(const player& left, const player& right){
		if(left.first_name == right.first_name){
			return left.last_name < right.last_name;
		}
		else{return left.first_name < right.first_name;}
	}
};

struct compare_num{ // comparison condition to organize by the hunter's HP level (descending)
	bool operator()(const player& left, const player& right){
		if(left.hp == right.hp){
			return left.hp > right.hp;
		}
		else{return left.hp > right.hp;}
	}
};

class hunterbook
{
private:
	string f_name,l_name,gend;
	int num2,count;
	set<player,compare_name> character; 
	set<player,compare_num> character_HP; 
	set<player,compare_name>::iterator iter;
	
public:
	void add(hunter*);
	int size();
	void sort(int);
	hunter* get_max(int);
	void remove(string, string);
	void search();
	void save();
	void print();

};
#endif