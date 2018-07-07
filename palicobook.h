#ifndef PALICOBOOK_H
#define PALICOBOOK_H

#include <string>
#include <fstream>
#include <iostream>
#include <set>
#include <iterator>
#include "palico.h"

struct palico_cat{
	palico_cat(string name1,string name2,string gen,int num, int a, int b, string name3, int c) 
				: first_name(name1), last_name(name2), gender(gen), 
				age(num),hp(a),atk(b),s_name(name3),s_atk(c) {}

	string first_name, last_name,gender,s_name;
	int age,hp,atk,s_atk;
};

struct compare1{ // comparison condition
	bool operator()(const palico_cat& left, const palico_cat& right){
		if(left.first_name == right.first_name){
			return left.last_name < right.last_name;
		}
		else{return left.first_name < right.first_name;}
	}
};

struct sort_num1{ // comparison condition organize by HP (descending order)
	bool operator()(const palico_cat& left, const palico_cat& right){
		if(left.hp == right.hp){
			return left.atk > right.atk;
		}
		else{return left.hp > right.hp;}
	}
};

class palicobook
{
	private:
		int count;
		set<palico_cat, compare1> companion; 
		set<palico_cat, compare1>::iterator iter;
	
	public:
	void add(palico*);
	int size();
	void change_mode(int);
	palico *max(int);
	void remove(string, string);
	void search();
	void save();
	void print();

};
#endif