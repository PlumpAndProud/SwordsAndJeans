#include <iostream>
#include <conio.h>
#include <ctime>
#include "character.h"
#include "warrior.h"
#include "mage.h"
#include "archer.h"
using namespace std;

// player and bot blank name template
Character* player;
Character* enemy;
//counter for rounds
int counter = 1;

void roundGui(int counter)
{
    cout << "========================" << endl;
    cout << "        Round " << counter << "         " << endl;
    cout << "========================" << endl
        << endl;
    cout << "Player hp:" << ::player->hp << endl;
    cout << "Enemy hp:" << ::enemy->hp << endl
        << endl;
}

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
            ::player = player;
            player->introduce();
            player->myStats();
            playerRepeat = pickSomeoneElse(playerRepeat);
            system("cls");
            break;
        }
        case '2':
        {
            Character *player = new Archer("Antonio");
            ::player = player;
            player->introduce();
            player->myStats();
            playerRepeat = pickSomeoneElse(playerRepeat);
            system("cls");
            break;
        }
        case '3':
        {
            Character *player = new Mage("HughAnus");
            ::player = player;
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
            ::enemy = enemy;
            enemy->introduce();
            enemy->myStats();
            enemyRepeat = pickSomeoneElse(enemyRepeat);
            system("cls");
            break;
        }
        case '2':
        {
            Character *enemy = new Archer("Bob");
            ::enemy = enemy;
            enemy->introduce();
            enemy->myStats();
            enemyRepeat = pickSomeoneElse(enemyRepeat);
            system("cls");
            break;
        }
        case '3':
        {
            Character *enemy = new Mage("PabloTheSecond");
            ::enemy = enemy;
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

    while (::player->hp > 0 && ::enemy->hp > 0)
    {
        bool enemyBlock = false;
        bool enemyAttack = false;

        bool playerBlock = false;
        bool playerAttack = false;
        bool playertakeAction = false;
        int selectAction = 0;

        // bot action
        int action = (rand() % 10) + 1; // generation
        if (action > 6 && enemyDefCd == 0)
        {
            enemyBlock = true;
            enemyDefCd = 2;
        }
        else
        {
            enemyAttack = true;
        }

        roundGui(::counter);
        
        while (playertakeAction == false)
        {
            // player action
            cout << "Choose action: " << endl;
            cout << "1. Attack" << endl;
            cout << "2. Defend" << endl
                << endl;
            selectAction = getch();

            switch (selectAction)
            {
            case '1':
            {
                playerAttack = true;
                playertakeAction = true;
                break;
            }
            case '2':
            {
                if (playerDefCd >= 1)
                {
                    cout << "You must rest for 1 turn to be able to block again" << endl;
                    break;
                }
                else
                {
                    playerBlock = true;
                    playertakeAction = true;
                    break;
                }
            }
            }
        }

        //actions
        if (enemyAttack == true)
        {
            if (playerBlock == false)
            {
                cout << "Enemy attacks and deals " << ::enemy->str << " dmg" << endl;
                ::player->hp -= ::enemy->str;
            }
        }

        if (playerAttack == true)
        {
            cout << "You attack";
            if (enemyBlock == true)
            {
                cout << " but enemy blocks" << endl
                     << endl;
            }
            else
            {
                cout << " and deal " << ::player->str << " dmg" << endl
                     << endl;
                ::enemy->hp -= ::player->str;
            }
        }
        else if(playerBlock == true)
        {
            cout << "You block";
            if (enemyBlock == true)
            {
                cout << " so does the enemy ..." << endl << "The round ends with both of you staring at each other" << endl;
            }
            else
            {
                cout << endl << endl;
            }
        }

        //cooldowns
        if (playerDefCd > 0)
        {
            playerDefCd--;
        }
        if (enemyDefCd > 0)
        {
            enemyDefCd--;
        }
        ::counter++;
    }

    if (::enemy->hp <= 0)
    {
        cout << "The enemy is slain, you have won" << endl;
    }
    else
    {
        cout << "You died..." << endl;
    }
}
