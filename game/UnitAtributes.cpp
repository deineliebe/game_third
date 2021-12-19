#include "UnitAtributes.h"

//Functions for health
void Health::setHealth(int number)
{
	_health = number;
}

int Health::getHealth()
{
	return _health;
}

void Health::changeHealth(int number)
{
	_health += number;
}

//Functions for armor
void Armor::setArmor(int number)
{
	_armor = number;
}

int Armor::getArmor()
{
	return _armor;
}

void Armor::changeArmor(int number)
{
	_armor += number;
}

//Functions for attack
void Attack::setAttack(int number)
{
	_attack = number;
}

int Attack::getAttack()
{
	return _attack;
}

void Attack::changeAttack(int number)
{
	_attack += number;
}

//Functions for money
void Money::setMoney(int number)
{
	_money = number;
}

int Money::getMoney()
{
	return _money;
}

void Money::changeMoney(int number)
{
	_money += number;
}