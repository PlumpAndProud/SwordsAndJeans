#include <iostream>
using namespace std;

class character
{
public:
	//parameters
	string name;
	string specialization;

	int hp;
	int speed;
	int mana;

	character()
	{
		this->name = " ";
		this->specialization = " ";
		this->hp = 0;
		this->speed = 0;
		this->mana = 0;
	}

	//methods
	void introduce();
	void whatIsMyHp();
	void isAlive();
};