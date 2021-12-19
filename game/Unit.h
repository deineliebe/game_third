#include <iostream>
#include <stdio.h>
#include "UnitAtributes.h"
#pragma once

enum Unit_ID
{
	Mage_ID = 1, Illusionist_ID, Cleric_ID, Druid_ID, Fighter_ID, Ranger_ID
};

class Unit
{
protected:
	Point _point;
	Health _health;
	Armor _armor;
	Attack _attack;
	Money _money;
	char _symbol;
	char _floor;
public:
	virtual ~Unit();
	static Unit* createUnit(int id, int x, int y);
	virtual int getSymbol();
	virtual void getInformation();
	virtual int getX();
	virtual int getY();
	virtual int getHealth();
	virtual int getArmor();
	virtual int getAttack();
	virtual int getMoney();
	virtual char getFloor();
	virtual void setFloor(char symbol);
	virtual void beAttacked(int unitAttack);
	virtual void changeMoneyNumber(int number);
	virtual void changeHealthNumber(int number);
	virtual void Drink();
	virtual void setNewArmor();
	virtual void changeCoordinates(int x, int y);
	virtual void moveUnit(int number);
	virtual void uniqueSkill() {};
};

//Some classes are empty now, but in future there'll be special function for every of them
class Wizard : public Unit
{
	void uniqueSkill();
};

class Mage : public Wizard
{
public:
	Mage(int x, int y);
};

class Illusionist : public Wizard
{
public:
	Illusionist(int x, int y);
};

class Priest : public Unit
{
	void uniqueSkill();
};

class Cleric : public Priest
{
public:
	Cleric(int x, int y);
};

class Druid : public Priest
{
public:
	Druid(int x, int y);
};

class Warrior : public Unit
{
	void uniqueSkill();
};

class Fighter : public Warrior
{
public:
	Fighter(int x, int y);
};

class Ranger : public Warrior
{
public:
	Ranger(int x, int y);
};