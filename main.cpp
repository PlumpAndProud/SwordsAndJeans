﻿#include <iostream>
#include <conio.h>
#include "character.h"
#include "warrior.h"
#include "mage.h"
#include "archer.h"

int main()
{
    int select = 0;
    int getch();

    //for player
    //character* player = new warrior(" ");

    warrior warrior1("Marek");
    mage mage1("Antonio");
    archer archer1("HughAnus");

    //for bot
    warrior warrior2("Norbert");
    mage mage2("Bob");
    archer archer2("PabloTheSecond");

    cout << "Choose ur character" << endl;
    cout << "1. Warrior" << endl;
    cout << "2. Archer" << endl;
    cout << "3. Mage" << endl << endl;
    select = getch();

    //character selection
    switch (select)
    {
    case '1':
    {
        warrior1.introduce();
        break;
    }
    case '2':
    {
        archer1.introduce();
        break;
    }
    case '3':
    {
        mage1.introduce();
        break;
    }
    }
    //choose enemy
    int selectEnemy;
    cout << "Wybierz przeciwnika: " << endl;
    cout << "1. Warrior" << endl;
    cout << "2. Archer" << endl;
    cout << "3. Mage" << endl << endl;
    selectEnemy = getch();

    //encounter

    switch (selectEnemy)
    {
    case '1':
    {
        warrior2.introduce();
        break;
    }
    case '2':
    {
        archer2.introduce();
        break;
    }
    case '3':
    {
        mage2.introduce();
        break;
    }
    }

    //fight

    /*while (character.isAlive())
    {
        player.hp
    }*/
}