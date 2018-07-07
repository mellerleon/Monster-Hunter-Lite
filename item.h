#ifndef item_h
#define item_h

#include <string>

class item{
public:
	std::string names;
};

class sword : public item{
public:
	int attack[10];
	std::string sword_name[10];
	sword();
};

class equipment : public item{
public: 
	int defense[3];
	std::string equip_name[3];
	equipment();
};

#endif