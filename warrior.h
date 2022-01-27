#include <iostream>
using namespace std;

class warrior : public character
{
public:
	
	//parameters
	int armor;
	int stamina;

	//constructor

	warrior(string name)
	{
		//string
		this->name = name;
		this->specialization = "Warrior";
		//int
		this->str = 3;
		this->hp = 20;
		this->speed = 4;
		this->mana = 0;
		this->armor = 5;
		this->stamina = 2;
	}

};
