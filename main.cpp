//
//  main.cpp
//
//  Project: UALR - Programming 2 - Spring 22 - Power Play 6
//  Created by: Mark McCorkle on 20220225
//  Based on: Code Provided by Sean Orme
//  IDE: CLion 2021.2.3     - VERIFIED WORKING
//  IDE: XCode              - VERIFIED/UNVERIFIED
//  IDE: Visual Studio 2022 - VERIFIED/UNVERIFIED
//  IDE: Linux via g++      - VERIFIED WORKING (g++ -std=c++17 -Wall main.cpp Item.cpp Monster.cpp Object.cpp Player.cpp -o main)
//
/*  OBJECTIVES:

    I’m going to help you:
        1)  Create and Object class                                                         -   Complete
        2)  Create a player and monster class that inherits from object                     -   Complete
            a)  Player gets Spell points and Heal costs 2SP                                 -   Complete
            b)  Monster gets an AC based upon its type.                                     -   Complete
        3)  create an item class.                                                           -   Complete

    You get to:
        4)  Create some operator overloads:                                                 -   Complete
            a)  << for the Object class (same as printObject function)                      -   Complete
            b)  << for the Item class (same as printItem function)                          -   Complete
            c)  < for the Item class (compares bonus values)                                -   Complete
            d)  += for the Item class (adds bonus values and an int and returns an int)     -   Complete
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//#include "Item.h"
#include "Monster.h"
#include "Player.h"

// TODO: Clean header file names (ifndef)

std::vector<Monster> createMonsters(const Player& player);
void bringOutYourDead(std::vector<Monster>& monsters);

void monsterAttack(Player& player, const std::vector<Monster>& monsters);
void playerAttack(const Player& player, std::vector<Monster>& monsters);

void displayBattle(const Player& player, const std::vector<Monster>& monsters);

int main()
{
    Player player;
    std::vector<Monster> monsters;

    while( !player.isDead() )
    {
        player.levelUp();
        monsters = createMonsters(player);

        std::cout << monsters.size() << " monster(s) approaches!!" << std::endl;
        system("pause");
        system("cls");

        while( !player.isDead() > 0 && monsters.size() > 0 )
        {

            displayBattle(player, monsters);

            std::cout << "What do you do? (a)ttack (h)eal ";
            char command{ 'x' };
            std::cin >> command;
            switch (command)
            {
                case 'a':
                {
                    playerAttack(player, monsters);
                    break;
                }
                case 'h' :
                    player.heal();
                    break;
                default:
                    std::cout << "please enter a or h" << std::endl;
                    break;
            }

            bringOutYourDead(monsters);

            monsterAttack(player, monsters);

            system("PAUSE");
            system("CLS");
        }
    }

    if( player.isDead() )
    {
        std::cout << "You Have Died" << std::endl;
    }
    if( player.isDead() && monsters.size() == 0 )
    {
        std::cout << "BUT" << std::endl;
    }
    if( monsters.size() == 0 )
    {
        std::cout << "You have killed the monsters!!!" << std::endl;
    }

    system("PAUSE");
}

void displayBattle(const Player& player, const std::vector<Monster>& monsters)
{
    player.battlePrint();
    std::cout << std::endl << "  Monsters: " << std::endl;
    {
        int i{ 1 };
        std::for_each(monsters.begin(), monsters.end(), [&](const Monster& monster)
        {
            std::cout << "   " << i << ". ";
            monster.battlePrint();
            i++;
        });
    }
}

std::vector<Monster> createMonsters(const Player& player)
{
    std::normal_distribution<double> randomNumMonsters((double)player.getLevel(), player.getLevel() / 2.0);
    std::vector<Monster> monsters(std::max(1, (int)randomNumMonsters(Object::engine)));
    std::generate(monsters.begin(), monsters.end(), [=]()
    {
        // Call the Monster class default constructor:
        return Monster(player);
    });
    return monsters;
}

void monsterAttack(Player& player, const std::vector<Monster>& monsters)
{
    std::cout << std::endl;
    std::for_each(monsters.begin(), monsters.end(), [&](const Monster& monster)
    {
        player.defend( monster.attack() );
    });
}

void playerAttack(const Player& player, std::vector<Monster>& monsters)
{
    std::cout << "Which Monster: ";
    int monsterNum{ 0 };
    std::cin >> monsterNum;
    if (monsterNum > 0 && monsterNum <= (int)monsters.size())
    {
        monsters[monsterNum - 1].defend(player.attack());
    }
}

void bringOutYourDead(std::vector<Monster>& monsters)
{
    monsters.erase(
    std::remove_if(monsters.begin(), monsters.end(),
                   [](const Monster& monster)
                   {
                       if( monster.isDead() )
                       {
                           monster.printName();
                           std::cout << " has died!!!" << std::endl << std::endl;
                           return true;
                       }
                       return false;
                   }),
    monsters.end());
}