#include <iostream>
using namespace std;

class Mage : public Character
{
public:
	// parameters
	int chantSpeed;
	bool dualChant;

	// constructor

	Mage(string name)
	{
		// string
		this->name = name;
		this->specialization = "Mage";
		// int
		this->hp = 12;
		this->speed = 8;
		this->mana = 20;
		this->chantSpeed = 2;
		// bool
		this->dualChant = false;
	}

	// methods
};
