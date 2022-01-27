#include <iostream>
#include "character.h"

void Character::whatIsMyHp()
{
	cout << "Mam " << this->hp << " HP" << endl;
}

void Character::introduce()
{
	cout << "Mam na imie " << this->name << " a moja klasa to " << this->specialization << endl
		 << endl;
}