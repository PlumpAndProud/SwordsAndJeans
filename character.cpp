#include <iostream>
#include "character.h"

void character::introduce()
{
	cout << "My name is " << this->name << " and my class is " << this->specialization << endl<<endl;
}

void character::myStats()
{
	cout << "My stats are: " << endl;
	cout << "Hp: " << this->hp << endl;
	cout << "Dmg: " << this->str << endl;
	cout << "Speed: " << this->speed << endl << endl;
}