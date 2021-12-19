#include <iostream>
#include <stdio.h>
#include "Point.h"
#include "UnitAtributes.h"
#pragma once

class FightersNumber
{
private:
	int _number;
public:
	FightersNumber() { _number = 0; }
	void addUnit() { _number += 1; }
	void deleteUnit() { _number -= 1; }
	int getUnitsStatistic() { return _number; }
	int getUnitsResources() { return _number; };
};

class RangersNumber
{
private:
	int _number;
public:
	RangersNumber() { _number = 0; }
	void addUnit() { _number += 1; }
	void deleteUnit() { _number -= 1; }
	int getUnitsStatistic() { return _number; }
	int getUnitsResources() { return _number; };
};

class MagesNumber
{
private:
	int _number;
public:
	MagesNumber() { _number = 0; }
	void addUnit() { _number += 1; }
	void deleteUnit() { _number -= 1; }
	int getUnitsStatistic() { return _number; }
	int getUnitsResources() { return _number; };
};

class IllusionistsNumber
{
private:
	int _number;
public:
	IllusionistsNumber() { _number = 0; }
	void addUnit() { _number += 1; }
	void deleteUnit() { _number -= 1; }
	int getUnitsStatistic() { return _number; }
	int getUnitsResources() { return _number; };
};

class ClericsNumber
{
private:
	int _number;
public:
	ClericsNumber() { _number = 0; }
	void addUnit() { _number += 1; }
	void deleteUnit() { _number -= 1; }
	int getUnitsStatistic() { return _number; }
	int getUnitsResources() { return _number; };
};

class DruidsNumber
{
private:
	int _number;
public:
	DruidsNumber() { _number = 0; }
	void addUnit() { _number += 1; }
	void deleteUnit() { _number -= 1; }
	int getUnitsStatistic() { return _number; }
	int getUnitsResources() { return _number; };
};

class WarriorsNumber
{
private:
	int _number;
	FightersNumber _fightersNumber;
	RangersNumber _rangersNumber;
public:
	WarriorsNumber() { _number = 0; }
	void addUnit(int caseNumber);
	void deleteUnit(int caseNumber);
	void getUnitsStatistic();
	int getUnitsResources();
};

class WizardsNumber
{
private:
	int _number;
	MagesNumber _magesNumber;
	IllusionistsNumber _illusionistsNumber;
public:
	WizardsNumber() { _number = 0; }
	void addUnit(int caseNumber);
	void deleteUnit(int caseNumber);
	void getUnitsStatistic();
	int getUnitsResources();
};

class PriestsNumber
{
private:
	int _number;
	ClericsNumber _clericsNumber;
	DruidsNumber _druidsNumber;
public:
	PriestsNumber() { _number = 0; }
	void addUnit(int caseNumber);
	void deleteUnit(int caseNumber);
	void getUnitsStatistic();
	int getUnitsResources();
};

class UnitsNumber
{
private:
	int _number;
	WarriorsNumber _warriorsNumber;
	WizardsNumber _wizardsNumber;
	PriestsNumber _priestsNumber;
public:
	UnitsNumber() { _number = 0; }
	void addUnit(int caseNumber);
	void deleteUnit(int caseNumber);
	void getUnitsStatistic();
	int getUnitsResources(int caseNumber);
};

class Base
{
protected:
	Point _point;
	Health _health;
	Armor _armor;
	int _maxWarriorsNumber;
	int _maxWizardsNumber;
	int _maxPriestsNumber;
	UnitsNumber _unitsNumber;
public:
	Base() {};
	void createBase(int x, int y, int square);
	void showBaseStatistic();
	void showArmyStatistic();
	UnitsNumber getUnitsNumber();
	void addUnit(int caseNumber);
	void deleteUnit(int caseNumber);
	~Base();
};