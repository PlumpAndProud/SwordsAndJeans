#include <iostream>
using namespace std;

class Character
{
public:
	// parameters
	string name;
	string specialization;

	int hp;
	int speed;
	int mana;
	int str;

	Character()
	{
		this->name = " ";
		this->specialization = " ";
		this->str = 0;
		this->hp = 0;
		this->speed = 0;
		this->mana = 0;
	}

	// methods
	void introduce();
	void myStats();
};