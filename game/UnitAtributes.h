#include <iostream>
#include <stdio.h>
#include "Point.h"
#pragma once

class Health
{
private:
	int _health;
public:
	void setHealth(int number);
	int getHealth();
	void changeHealth(int number);
};

class Armor
{
private:
	int _armor;
public:
	void setArmor(int number);
	int getArmor();
	void changeArmor(int number);
};

class Attack
{
private:
	int _attack;
public:
	void setAttack(int number);
	int getAttack();
	void changeAttack(int number);
};

class Money
{
private:
	int _money;
public:
	void setMoney(int number);
	int getMoney();
	void changeMoney(int number);
};