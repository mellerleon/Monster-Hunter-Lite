#ifndef MONSTERBOOK_H
#define MONSTERBOOK_H

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "monster.h"

struct node
{
    node *next, *prev;
    string first_name;
    string last_name;
    string gender;
    int age;
};

class monsterbook
{
	private:
	node *head;
	node *tail;
	node *current;
	node *temp1;
	node *temp2;
	node *temp3;
	node *temp4;

	
	public:
	monsterbook();
	void add(monster*);
	void save();
	void remove(string);
	void search(string, monster*);

};
#endif