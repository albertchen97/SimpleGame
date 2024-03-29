// SeeWhatYouGot.cpp : Defines the entry point for the console application.
// Randomly coding to see what skills I've got and what kind of project I can build.
// Let's start with making a simple console text game.
/* Setting: you can choose charactors with different properties, you can buy items, you can kill enemies to earn golds and experience; experience can level you up.*/
#include "stdafx.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>
using namespace std;

class Character
{
private:
	string NAME;
	int DAMAGE;
	int HP;
public:
	Character() {};
	Character(string name, int damage, int hp)
	{
		NAME = name;
		DAMAGE = damage;
		HP = hp;
	}
	void setHP(int hp) { HP = hp; }
	string getName() { return NAME; }
	int getDamage() { return DAMAGE; }
	int getHP() { return HP; }
};
void setup(Character&c)
{
	cout << "1. Name: David | Damage: 100 | HP: 100 \n2. Name: Adam | Damage: 80 | HP: 120 \n";
	int choice = 0;
	cin >> choice;
	if (choice == 1)
	{
		c = Character("David", 100, 100);
	}
	else if (choice == 2)
	{
		c = Character("Adam", 80, 120);
	}
}
void display(Character&c)
{
	cout << "Name: " << c.getName() << endl;
	cout << "Damage: " << c.getDamage() << endl;
	cout << "HP: " << c.getHP() << endl;
}
void start(Character&c)
{
	int choice = 0;
	int enemy_hp = 150 + 100 % rand();
	int enemy_damage = 50 + 50 % rand();
	cout << "A bad guy is coming!(HP:"<<enemy_hp<<"damage:"<< enemy_damage<<")" << endl;
	cout << "1. Fight" << endl;
	cout << "2. Run" << endl;
	cin >> choice;
	if (choice == 1)
	{
		int random = 0;
		int round = 0;
		while (c.getHP() > 0 && enemy_hp > 0)
		{
			cout << "Your HP: " << c.getHP() << endl;
			cout << " Enemy's HP:" << enemy_hp << endl;
			round++;
			random = rand()%2;
			if (random == 0)
			{
				cout << "Round " << round << ":" << "You beat the bad guy first! (enemy HP:" << enemy_hp - c.getDamage() << ")" << endl;
				enemy_hp = -c.getDamage();
			}
			else if (random == 1)
			{
				cout << "Round " << round << ":" << "Bad guy beat you first! (Your HP:" << c.getHP() - enemy_damage << ")" << endl;
				c.setHP(c.getHP() - enemy_damage);
			}
			//need to find a way to set a timer
		}
		if (c.getHP() <= 0)
		{
			cout << "You lost!" << endl;
		}
		else if (enemy_hp <= 0)
		{
			cout << "You win!" << endl;
			cout << "You gain " << 50 + rand() % 50 << " gold and " << 100 + rand() % 20 << " experience! " << endl;
		}
	}
}
int main()
{
	Character character;
	int choice = 0;
	// Welcome Page
	while (choice != 2) 
	{
		cout << "Welcome to the simple game!\n" << "1. Choose Character \n2. Exist Game \n";
		cin >> choice;
		if (choice == 1)
		{
			setup(character);
			display(character);
			start(character);
		}
		else
			return 0;
	}

    return 0;
}

