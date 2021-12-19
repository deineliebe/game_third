#include "Facade.h"
#include <limits>


//Functions for class "game"
Game::Game()
{
	_field = new Field();
	_isExist = 0;
}

void Game::createGame()
{
	int height, width;
	std::cout << "Enter height and width of field: ";
	std::cin >> height >> width;
	if (!std::cin)
	{
		std::cout << "Wrong height or width. They must be integers";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return;
	}
	if (height < 4)
	{
		std::cout << "Wrong height: it must be more than three";
		return;
	}
	if (width < 4)
	{
		std::cout << "Wrong height: it must be more than three";
		return;
	}
	_field = new Field(width, height);
	_base.createBase(1, 1, (width - 2) * (height - 2));
	_isExist = 1;
	_observer = new Observer(_units._subject);
	_units.attach(_observer);
}

void Game::addElement()
{
	int number;
	std::cout << "Write class of unit:\n";
	std::cout << "1. Mage\n";
	std::cout << "2. Illusionist\n";
	std::cout << "3. Cleric\n";
	std::cout << "4. Druid\n";
	std::cout << "5. Fighter\n";
	std::cout << "6. Ranger\n";
	std::cin >> number;
	if (!std::cin)
	{
		std::cout << "Wrong class. You must write a number";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return;
	}
	if ((number > 0) and (number < 7))
	{
		//Adding element to vector of units
		_units.addUnit(Unit::createUnit(number, 1, 1));
		_base.addUnit(_observer->getValue());
	}
	else std::cout << "Wrong number. It must be between 1 and 6\n";
}

void Game::replaceElement()
{
	Mediator mediator;
	int number, x, y;
	int lengthOfUnits = _units.getSize();
	for (int i = 0; i < lengthOfUnits; i++)
	{
		std::cout << i + 1;
		_units.getUnit(i)->getInformation();
	}
	std::cout << "Write number of unit:\n";
	std::cin >> number;
	if (!std::cin)
	{
		std::cout << "Wrong unit. You must write a number";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return;
	}
	if ((number > 0) and (number <= lengthOfUnits))
	{
		x = _units.getUnit(number - 1)->getX();
		y = _units.getUnit(number - 1)->getY();
		_observer->setValue(0);
		mediator.makeStep(_units.getUnit(number - 1), _units, _field, x, y, _observer);
		if (_observer->getValue() != 0) _base.deleteUnit((-1) *_observer->getValue());
	}
	else std::cout << "Wrong number. It must be between 1 and " << lengthOfUnits << '\n';
}

void Game::useUniqueSkill()
{
	int number, x, y;
	int lengthOfUnits = _units.getSize();
	for (int i = 0; i < lengthOfUnits; i++)
	{
		std::cout << i + 1;
		_units.getUnit(i)->getInformation();
	}
	std::cout << "Write number of unit:\n";
	std::cin >> number;
	if (!std::cin)
	{
		std::cout << "Wrong unit. You must write a number";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return;
	}
	if ((number > 0) and (number <= lengthOfUnits))
	{
		_units.getUnit(number - 1)->uniqueSkill();
	}
	else std::cout << "Wrong number. It must be between 1 and " << lengthOfUnits << '\n';
}

int Game::getWidth() { return _field->getWidth(); }

int Game::getHeight() { return _field->getHeight(); }

bool Game::ifExist() { return _isExist; }

void Game::show() { _field->showField(); }

Game::~Game()
{
	_field->~Field();
	_units.~Units();
	_isExist = 0;
}

//Functions for subject
void Subject::attach(Observer* observer) {
	_observers.push_back(observer);
}

void Subject::detach(Observer* observer) { _observers.remove(observer); }

void Subject::notify(int caseNumber)
{
	std::list<Observer*>::iterator iterator = _observers.begin();
	while (iterator != _observers.end()) 
	{
		(*iterator)->getNotify(caseNumber);
		++iterator;
	}
}

//Functions for units
Units::Units()
{
}

void Units::addUnit(Unit* unit) 
{ 
	_units.push_back(unit); 
	switch (unit->getSymbol())
	{
	case 'F':
		_subject.notify(1);
		break;
	case 'R':
		_subject.notify(2);
		break;
	case 'M':
		_subject.notify(3);
		break;
	case 'I':
		_subject.notify(4);
		break;
	case 'C':
		_subject.notify(5);
		break;
	case 'D':
		_subject.notify(6);
		break;
	}
}

void Units::deleteUnit(int number) 
{ 
	switch (getUnit(number)->getSymbol())
	{
	case 'F':
		_subject.notify(-1);
		break;
	case 'R':
		_subject.notify(-2);
		break;
	case 'M':
		_subject.notify(-3);
		break;
	case 'I':
		_subject.notify(-4);
		break;
	case 'C':
		_subject.notify(-5);
		break;
	case 'D':
		_subject.notify(-6);
		break;
	}
	_units.erase(_units.begin() + number - 1); 
}

int Units::getSize() { return _units.size(); }

Unit* Units::getUnit(int number) { return _units[number]; }

int Units::getUnitNumber(int x, int y)
{
	for (int i = 0; i < getSize(); i++)
	{
		if ((x == getUnit(i)->getX()) and (y == getUnit(i)->getY()))
		{
			return i;
		}
	}
	return -1;
}

void Units::moveUnit(int i, int number) { _units[i]->moveUnit(number); }

void Units::attach(Observer* observer)
{
	_subject.attach(observer);
}

Units::~Units()
{
	_units.clear();
}

//Functions for observer
Observer::Observer(Subject& subject)
{
	_subject = subject;
	subject.attach(this);
}

void Observer::getNotify(int caseNumber)
{
	_value = caseNumber;
}

int Observer::getValue()
{
	return _value;
}

void Observer::setValue(int number)
{
	_value = number;
}

void Observer::removeObserver() { _subject.detach(this); }

//Functions for Strategies
void PubStrategy::doAlgorithm(Unit* unit)
{
	if (unit->getHealth() < 3) { std::cout << "It's dangerous to drink in your condition... You must go to the temple\n"; }
	else
	{
		int number;
		std::cout << "Do you want to drink?\n";
		std::cout << "1. Yes (health: -2, attack: +1)\n";
		std::cout << "2. No\n";
		std::cin >> number;
		if (!std::cin)
		{
			std::cout << "Wrong number";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return;
		}
		if (number == 1)
		{
			unit->Drink();
			std::cout << "Good drink! Now your health: " << unit->getHealth() << " heart(s)\n";
		}
	}
}

void TempleStrategy::doAlgorithm(Unit* unit)
{
	if (unit->getMoney() < 5)
	{
		std::cout << "Welcome to the temple! Unit's health now: " << unit->getHealth() << " heart(s)\n";
		unit->changeHealthNumber(2);
	}
	else
	{
		int number;
		std::cout << "Choose number:\n";
		std::cout << "1. Free medicine: +2 hearts";
		std::cout << "2. 5 coins: +8 hearts\n";
		std::cin >> number;
		if (!std::cin)
		{
			std::cout << "Wrong number";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return;
		}
		if (number == 1) unit->changeHealthNumber(2);
		if (number == 2)
		{
			unit->changeHealthNumber(8);
			unit->changeMoneyNumber(-5);
		}
		std::cout << "Unit's health now: " << unit->getHealth() << "heart(s)\n";
	}
}

void ArmoryStrategy::doAlgorithm(Unit* unit)
{
	if (unit->getMoney() < 5) { std::cout << "You have too less money. Find job centre to earn 5 coins\n"; }
	else
	{
		int number;
		std::cout << "Do you want to buy new armor?\n";
		std::cout << "1. Yes (armor: +2, money: -5)\n";
		std::cout << "2. No\n";
		std::cin >> number;
		if (!std::cin)
		{
			std::cout << "Wrong number";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return;
		}
		if (number == 1)
		{
			unit->setNewArmor();
			std::cout << "Good armor! Now it's value is: " << unit->getArmor() << '\n';
		}
	}
}

void JobCentreStrategy::doAlgorithm(Unit* unit)
{
	int number = rand() % 10;
	std::cout << "Conratulations!! You recieved " << number <<" coin(s)\n";
	unit->changeMoneyNumber(number);
}

void Strategy::chooseStrategy(Unit* unit, char symbol)
{
	PubStrategy pStrategy;
	TempleStrategy tStrategy;
	ArmoryStrategy aStrategy;
	JobCentreStrategy jStrategy;
	switch (symbol)
	{
	case 'P':
		pStrategy.doAlgorithm(unit);
		break;
	case 'T':
		tStrategy.doAlgorithm(unit);
		break;
	case 'A':
		aStrategy.doAlgorithm(unit);
		break;
	case 'J':
		jStrategy.doAlgorithm(unit);
		break;
	}
}

//Mediator function
void Mediator::makeStep(Unit* unit, Units& units, Field *field, int x, int y, Observer* observer)
{
	Strategy strategy;
	int number, newX, newY;
	newX = x;
	newY = y;
	std::cout << "Choose a number:\n";
	if (field->getSymbol(x, y - 1) != 'X') std::cout << "1. Up\n";
	if (field->getSymbol(x + 1, y) != 'X') std::cout << "2. Right\n";
	if (field->getSymbol(x, y + 1) != 'X') std::cout << "3. Down\n";
	if (field->getSymbol(x - 1, y) != 'X') std::cout << "4. Left\n";
	std::cin >> number;
	if (!std::cin)
	{
		std::cout << "Wrong number";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return;
	}
	switch (number)
	{
	case 1:
		newY--;
		break;
	case 2:
		newX++;
		break;
	case 3:
		newY++;
		break;
	case 4:
		newX--;
		break;
	}
	char symbol = field->getSymbol(newX, newY);
	switch (symbol)
	{
	case 'P':
	case 'T':
	case 'A':
	case 'J':
		strategy.chooseStrategy(unit, symbol);
		break;
	case '*':
	case '~':
		field->replaceElement(x, y, newX, newY, unit->getSymbol(), unit->getFloor());
		unit->moveUnit(number);
		unit->setFloor(symbol);
		break;
	case '^':
		std::cout << "Sorry, unit can't go through trees\n";
		break;
	case 'M':
	case 'I':
	case 'C':
	case 'D':
	case 'F':
	case 'R':
		if (unit->getFloor() == '*')
		{
			Unit* secondUnit = units.getUnit(units.getUnitNumber(newX, newY));
			secondUnit->beAttacked(unit->getAttack());
			if (!secondUnit->getHealth())
			{
				std::cout << "This unit:\n";
				secondUnit->getInformation();
				std::cout << "is dead\n";
				field->removeElement(newX, newY, secondUnit->getFloor());
				units.deleteUnit(units.getUnitNumber(newX, newY) + 1);
			}
			else
			{
				std::cout << "This unit:\n";
				secondUnit->getInformation();
				std::cout << "was attacked\n";
			}
		}
		else std::cout << "Sorry, unit can't attack from there\n";
		break;
	}
}

//Functions for commands
void CommandCreateGame::execute(Game &game) { game.createGame(); }

void CommandAddElement::execute(Game& game)
{

	if (!game.ifExist()) std::cout << "Game don't exist\n";
	else game.addElement();
}

void CommandReplaceElement::execute(Game& game)
{
	if (!game.ifExist()) std::cout << "Game don't exist\n";
	else game.replaceElement();
}

void CommandUseUniqueSkill::execute(Game& game)
{
	if (!game.ifExist()) std::cout << "Game don't exist\n";
	else game.useUniqueSkill();
}

void CommandShowBaseStatistic::execute(Game& game)
{
	game._base.showBaseStatistic();
}

void CommandShowArmyStatistic::execute(Game& game)
{
	game._base.showArmyStatistic();
};

void CommandShowUniqueSkills::execute(Game& game)
{
	std::cout << "Unique skills:\n";
	std::cout << "For Mages and Illusionists: Magic wallet (money: +3 coins)\n";
	std::cout << "For Druids and Clerics: Healing (health: +2 hearts)\n";
	std::cout << "For Fighters and Rangers: Rage (attack: +2 points)\n";
};

int BaseSubsystem::chooseFunction(Game& game)
{
	int number;
	std::cout << "Write a number:\n";
	std::cout << "1. State of base\n";
	std::cout << "2. State of army\n";
	std::cout << "3. Add new unit\n";
	std::cout << "4. Unique skills\n";
	std::cout << "0. Return\n";
	std::cin >> number;
	if (!std::cin)
	{
		std::cout << "Wrong number. It must be an integer";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return 2;
	}
	switch (number)
	{
	case 1: _showBaseStatistic.execute(game);
		break;
	case 2: _showArmyStatistic.execute(game);
		break;
	case 3: _addElement.execute(game);
		break;
	case 4: _showUniqueSkills.execute(game);
		break;
	case 0: return 0;
	default: std::cout << "Wrong number";
	}
	return 1;
}

int UnitSubsystem::chooseFunction(Game& game)
{
	int number;
	std::cout << "Write a number:\n";
	std::cout << "1. Move unit\n";
	std::cout << "2. Use skill\n";
	std::cout << "0. Return\n";
	std::cin >> number;
	if (!std::cin)
	{
		std::cout << "Wrong number. It must be an integer";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return 2;
	}
	switch (number)
	{
	case 1: _replaceElement.execute(game);
		break;
	case 2: _useUniqueSkill.execute(game);
		break;
	case 0: return 0;
	default: std::cout << "Wrong number";
	}
	return 1;
}

//Function for facade
Facade::Facade()
{
}

int Facade::chooseFunction(BaseSubsystem baseSubsystem, UnitSubsystem unitSubsystem, Game &game)
{
	int number;
	std::cout << "Write a number:\n";
	std::cout << "1. Control base\n";
	std::cout << "2. Control units\n";
	std::cout << "3. Load game (unactive)\n";
	std::cout << "4. Save game (unactive)\n";
	std::cout << "5. Choose step (unactive)\n";
	std::cout << "6. Start a new game\n";
	std::cout << "0. Exit\n";
	std::cin >> number;
	if (!std::cin)
	{
		std::cout << "Wrong number. It must be an integer";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return 2;
	}
	switch (number)
	{
	case 1: baseSubsystem.chooseFunction(game);
		break;
	case 2: unitSubsystem.chooseFunction(game);
		break;
	case 6: _createGame.execute(game);
		break;
	case 0: return 0;
	default: std::cout << "Wrong number";
	}
	return 1;
}