#include "Unit.h"

Mage::Mage(int x, int y)
{
	_point.setPoint(x, y);
	_health.setHealth(5);
	_armor.setArmor(7);
	_attack.setAttack(1000);
	_symbol = 'M';
	_floor = 'B';
}

Illusionist::Illusionist(int x, int y)
{
	_point.setPoint(x, y);
	_health.setHealth(6);
	_armor.setArmor(6);
	_attack.setAttack(8);
	_symbol = 'I';
	_floor = 'B';
}

Cleric::Cleric(int x, int y)
{
	_point.setPoint(x, y);
	_health.setHealth(8);
	_armor.setArmor(7);
	_attack.setAttack(5);
	_symbol = 'C';
	_floor = 'B';
}

Druid::Druid(int x, int y)
{
	_point.setPoint(x, y);
	_health.setHealth(6);
	_armor.setArmor(7);
	_attack.setAttack(7);
	_symbol = 'D';
	_floor = 'B';
}

Fighter::Fighter(int x, int y)
{
	_point.setPoint(x, y);
	_health.setHealth(8);
	_armor.setArmor(2);
	_attack.setAttack(10);
	_symbol = 'F';
	_floor = 'B';
}

Ranger::Ranger(int x, int y)
{
	_point.setPoint(x, y);
	_health.setHealth(6);
	_armor.setArmor(5);
	_attack.setAttack(7);
	_symbol = 'R';
	_floor = 'B';
}

//Fabric function
Unit* Unit::createUnit(int id, int x, int y)
{
	Unit* newUnit = NULL;
	switch (id)
	{
	case Mage_ID:
		newUnit = new Mage(x, y);
		break;
	case Illusionist_ID:
		newUnit = new Illusionist(x, y);
		break;
	case Cleric_ID:
		newUnit = new Cleric(x, y);
		break;
	case Druid_ID:
		newUnit = new Druid(x, y);
		break;
	case Fighter_ID:
		newUnit = new Fighter(x, y);
		break;
	case Ranger_ID:
		newUnit = new Ranger(x, y);
		break;
	}
	return newUnit;
}

int Unit::getSymbol()
{
	return _symbol;
}

void Unit::getInformation()
{
	std::cout << ". Class: ";
	switch (_symbol)
	{
	case 'M':
		std::cout << "Mage";
		break;
	case 'I':
		std::cout << "Illusionist";
		break;
	case 'C':
		std::cout << "Cleric";
		break;
	case 'D':
		std::cout << "Druid";
		break;
	case 'F':
		std::cout << "Fighter";
		break;
	case 'R':
		std::cout << "Ranger";
		break;
	}
	std::cout << ". Coordinates: (" << getX() << ", " << getY() << "). ";
	std::cout << "Health: " << _health.getHealth() << ". Armor: " << _armor.getArmor() << ". Atack: " << _attack.getAttack() << '\n';
}

int Unit::getX()
{
	return _point.getX();
}

int Unit::getY()
{
	return _point.getY();
}

int Unit::getHealth()
{
	return _health.getHealth();
}

int Unit::getArmor()
{
	return _armor.getArmor();
}

int Unit::getAttack()
{
	return _attack.getAttack();
}

int Unit::getMoney()
{
	return _money.getMoney();
}

char Unit::getFloor()
{
	return _floor;
}

void Unit::setFloor(char symbol)
{
	_floor = symbol;
}

void Unit::beAttacked(int unitAttack)
{
	_health.changeHealth((-1) * int(unitAttack/_armor.getArmor()));
	if (_health.getHealth() < 0) _health.setHealth(0);
}

void Unit::changeCoordinates(int x, int y)
{
	_point.setPoint(x, y);
}

void Unit::changeMoneyNumber(int number)
{
	_money.changeMoney(number);
}

void Unit::changeHealthNumber(int number)
{
	_health.changeHealth(number);
}

void Unit::Drink()
{
	_health.changeHealth(-2);
	_attack.changeAttack(1);
}

void Unit::setNewArmor()
{
	_money.changeMoney(-5);
	_armor.setArmor(2);
}

void Unit::moveUnit(int number)
{
	if (number == 1) changeCoordinates(getX(), getY() - 1);
	else if (number == 2) changeCoordinates(getX() + 1, getY());
	else if (number == 3) changeCoordinates(getX(), getY() + 1);
	else if (number == 4) changeCoordinates(getX() - 1, getY());
}

Unit::~Unit()
{
	_point.setPoint(NULL, NULL);
	_health.setHealth(0);
	_armor.setArmor(0);
	_attack.setAttack(0);
	_symbol = NULL;
}

//Skills
void Warrior::uniqueSkill()
{
	_attack.changeAttack(2);
}

void Priest::uniqueSkill()
{
	_health.changeHealth(2);
}

void Wizard::uniqueSkill()
{
	_money.changeMoney(3);
}