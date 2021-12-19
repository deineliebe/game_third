#include <iostream>
#include <stdio.h>
#include "Field.h"
#include "Unit.h"
#include <vector>
#include <list>
#pragma once

class Subject
{
private:
	std::list<class Observer*> _observers;
public:
	Subject() {};
	void attach(Observer* observer);
	void detach(Observer* observer);
	void notify(int caseNumber);
	~Subject() { _observers.clear(); }
};

class Observer
{
private:
	Subject _subject;
	int _value;
public:
	Observer(Subject& subject);
	void getNotify(int caseNumber);
	int getValue();
	void setValue(int nember);
	void removeObserver();
};

class Units : public Unit
{
private:
	Subject _subject;
	std::vector<Unit*> _units;
public:
	Units();
	void addUnit(Unit* unit);
	void deleteUnit(int number);
	int getSize();
	Unit* getUnit(int number);
	int getUnitNumber(int x, int y);
	void moveUnit(int i, int number);
	void attach(Observer* observer);
	~Units();

	friend class Game;
};

class Game
{
private:
	Field *_field;
	Base _base;
	Units _units;
	bool _isExist;
	Observer* _observer;
public:
	Game();
	void createGame();
	void addElement();
	void replaceElement();
	void useUniqueSkill();
	int getWidth();
	int getHeight();
	bool ifExist();
	void show();
	~Game();

	friend class Mediator;
	friend class CommandShowBaseStatistic;
	friend class CommandShowArmyStatistic;
	friend class Units;
};

class Strategy
{
public:
	void chooseStrategy(Unit* unit, char symbol);
	virtual void doAlgorithm(Unit* unit) {}
};

class PubStrategy : public Strategy
{
public:
	void doAlgorithm(Unit* unit);
};

class TempleStrategy
{
public:
	void doAlgorithm(Unit *unit);
};

class ArmoryStrategy
{
public:
	void doAlgorithm(Unit *unit);
};

class JobCentreStrategy
{
public:
	void doAlgorithm(Unit *unit);
};

class Mediator
{
public:
	void makeStep(Unit* unit, Units& units, Field *field, int x, int y, Observer* observer);
};

class Command
{
public:
	virtual void execute(Game& game) = 0;
};

class CommandCreateGame : public Command
{
public:
	CommandCreateGame() {};
	void execute(Game& game);
};

class CommandAddElement : public Command
{
public:
	CommandAddElement() {};
	void execute(Game& game);
};

class CommandReplaceElement : public Command
{
public:
	CommandReplaceElement() {};
	void execute(Game& game);
};

class CommandUseUniqueSkill : public Command
{
public:
	CommandUseUniqueSkill() {};
	void execute(Game& game);
};

class CommandShowBaseStatistic : public Command
{
public:
	CommandShowBaseStatistic() {};
	void execute(Game& game);
};

class CommandShowArmyStatistic : public Command
{
public:
	CommandShowArmyStatistic() {};
	void execute(Game& game);
};

class CommandShowUniqueSkills : public Command
{
public:
	CommandShowUniqueSkills() {};
	void execute(Game& game);
};

class BaseSubsystem
{
private:
	CommandShowBaseStatistic _showBaseStatistic;
	CommandShowArmyStatistic _showArmyStatistic;
	CommandAddElement _addElement;
	CommandShowUniqueSkills _showUniqueSkills;
public:
	BaseSubsystem() {};
	int chooseFunction(Game& game);
};

class UnitSubsystem
{
private:
	CommandReplaceElement _replaceElement;
	CommandUseUniqueSkill _useUniqueSkill;
public:
	UnitSubsystem() {};
	int chooseFunction(Game& game);
};

class Facade
{
private:
	CommandCreateGame _createGame;
public:
	Facade();
	int chooseFunction(BaseSubsystem baseSubsystem, UnitSubsystem unitSubsystem, Game &game);
};