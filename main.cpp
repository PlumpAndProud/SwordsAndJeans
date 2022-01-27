#include <iostream>
#include <conio.h>
#include "character.h"
#include "warrior.h"
#include "mage.h"
#include "archer.h"

int main()
{
    int select = 0;
    int getch();

    // for player
    // Character* player = new Warrior(" ");

    Warrior Warrior1("Marek");
    Mage Mage1("Antonio");
    Archer Archer1("HughAnus");

    // for bot
    Warrior Warrior2("Norbert");
    Mage Mage2("Bob");
    Archer Archer2("PabloTheSecond");

    cout << "Choose ur Character" << endl;
    cout << "1. Warrior" << endl;
    cout << "2. Archer" << endl;
    cout << "3. Mage" << endl
         << endl;
    select = getch();

    // Character selection
    switch (select)
    {
    case '1':
    {
        Warrior1.introduce();
        break;
    }
    case '2':
    {
        Archer1.introduce();
        break;
    }
    case '3':
    {
        Mage1.introduce();
        break;
    }
    }
    // choose enemy
    int selectEnemy;
    cout << "Wybierz przeciwnika: " << endl;
    cout << "1. Warrior" << endl;
    cout << "2. Archer" << endl;
    cout << "3. Mage" << endl
         << endl;
    selectEnemy = getch();

    // encounter

    switch (selectEnemy)
    {
    case '1':
    {
        Warrior2.introduce();
        break;
    }
    case '2':
    {
        Archer2.introduce();
        break;
    }
    case '3':
    {
        Mage2.introduce();
        break;
    }
    }

    // fight

    /*while (Character.isAlive())
    {
        player.hp
    }*/
}
