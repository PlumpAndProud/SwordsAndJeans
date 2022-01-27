#include <iostream>
#include <conio.h>
#include <ctime>
#include "character.h"
#include "warrior.h"
#include "mage.h"
#include "archer.h"
using namespace std;

int counter = 1;

string pickSomeoneElse(string repeat)
{
    // Character check for change
    cout << "Do you want to pick someone else? (Yes/No)" << endl;
    cin >> repeat;
    return repeat;
}

int enemyCharacterSelection(int selectEnemy)
{
    int getch();

    // choose enemy
    cout << "Choose ur enemy: " << endl
         << endl;
    cout << "1. Warrior" << endl;
    cout << "2. Archer" << endl;
    cout << "3. Mage" << endl
         << endl;
    selectEnemy = getch();
    system("cls");
    return selectEnemy;
}

int playerCharacterSelection(int select)
{
    int getch();

    // Character selection
    cout << "Choose ur Character" << endl
         << endl;
    cout << "1. Warrior" << endl;
    cout << "2. Archer" << endl;
    cout << "3. Mage" << endl
         << endl;
    select = getch();
    system("cls");
    return select;
}

int main()
{
    srand(time(NULL));
    int getch();

    // player and bot blank name template
    Character *player = new Warrior(" ");
    Character *enemy = new Warrior(" ");

    // Character selection
    string playerRepeat = "Yes";
    int select = 0;

    while (playerRepeat != "No")
    {
        select = playerCharacterSelection(select);

        switch (select)
        {
        case '1':
        {
            Character *player = new Warrior("Mareck");
            player->introduce();
            player->myStats();
            playerRepeat = pickSomeoneElse(playerRepeat);
            system("cls");
            break;
        }
        case '2':
        {
            Character *player = new Archer("Antonio");
            player->introduce();
            player->myStats();
            playerRepeat = pickSomeoneElse(playerRepeat);
            system("cls");
            break;
        }
        case '3':
        {
            Character *player = new Mage("HughAnus");
            player->introduce();
            player->myStats();
            playerRepeat = pickSomeoneElse(playerRepeat);
            system("cls");
            break;
        }
        }
    }

    system("cls");

    // enemy selector
    string enemyRepeat = "Yes";
    int selectEnemy = 0;

    while (enemyRepeat != "No")
    {
        selectEnemy = enemyCharacterSelection(selectEnemy);

        // encounter creator (select enemy type)
        switch (selectEnemy)
        {
        case '1':
        {
            Character *enemy = new Warrior("Norbert");
            enemy->introduce();
            enemy->myStats();
            enemyRepeat = pickSomeoneElse(enemyRepeat);
            system("cls");
            break;
        }
        case '2':
        {
            Character *enemy = new Archer("Bob");
            enemy->introduce();
            enemy->myStats();
            enemyRepeat = pickSomeoneElse(enemyRepeat);
            system("cls");
            break;
        }
        case '3':
        {
            Character *enemy = new Mage("PabloTheSecond");
            enemy->introduce();
            enemy->myStats();
            enemyRepeat = pickSomeoneElse(enemyRepeat);
            system("cls");
            break;
        }
        }
    }

    // fight

    int playerDefCd = 0;
    int enemyDefCd = 0;

    while (player->hp > 0 && enemy->hp > 0)
    {
        bool enemyBlock = false;
        bool enemyAttack = false;

        bool playertakeAction = false;
        bool playerBlock = false;
        int selectAction = 0;

        // bot action
        int action = (rand() % 10) + 1; // generation
        if (action <= 6)
        {
            enemyAttack = true;
        }
        else
        {
            enemyBlock = true;
            enemyDefCd = 2;
        }

        cout << "========================" << endl;
        cout << "        Round " << counter << "         " << endl;
        cout << "========================" << endl;
        cout << "Player hp:" << player->hp << endl;
        cout << "Enemy hp:" << enemy->hp << endl
             << endl;
        // player action
        cout << "Wybierz akcje: " << endl;
        cout << "1. Atak" << endl;
        cout << "2. Obrona" << endl;
        selectAction = getch();

        switch (selectAction)
        {
        case '1':
        {
            if (enemyBlock != true)
            {
                cout << "You attack and deal " << player->str << " dmg" << endl;
                enemy->hp = enemy->hp - player->str;
                playertakeAction = true;
                break;
            }
            else
            {
                cout << "Enemy blocked your attack" << endl;
                playertakeAction = true;
                break;
            }
        }
        case '2':
        {
            if (playerDefCd == 2)
            {
                cout << "You must rest 1 turn to block again" << endl;
                break;
            }
            else
            {
                cout << "You block enemy attack" << endl;
                playertakeAction = true;
                playerDefCd = 2;
                break;
            }
        }
        }

        if (enemyAttack == true && playerBlock == false)
        {
            player->hp = player->hp - enemy->str;
        }

        if (playerDefCd > 0)
        {
            playerDefCd--;
        }
        if (enemyDefCd > 0)
        {
            enemyDefCd--;
        }

        counter++;
    }

    system("cls");

    if (enemy->hp <= 0)
    {
        cout << "The enemy is slain, you have won" << endl;
    }
    else
    {
        cout << "You died..." << endl;
    }
}