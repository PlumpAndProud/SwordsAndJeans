#include <iostream>
#include "character.h"

void character::whatIsMyHp()
{
	cout << "Mam " << this->hp << " HP" << endl;
}

void character::introduce()
{
	cout << "Mam na imie " << this->name << " a moja klasa to " << this->specialization << endl<<endl;
}