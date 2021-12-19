#include "FieldObjects.h"

void UnitsNumber::addUnit(int _caseNumber)
{
	switch (_caseNumber)
	{
	case 1:
	case 2: _warriorsNumber.addUnit(_caseNumber);
		break;
	case 3:
	case 4:  _wizardsNumber.addUnit(_caseNumber - 2);
		break;
	case 5:
	case 6: _priestsNumber.addUnit(_caseNumber - 4);
		break;
	}
}

void UnitsNumber::deleteUnit(int _caseNumber)
{
	switch (_caseNumber)
	{
	case 1:
	case 2: _warriorsNumber.deleteUnit(_caseNumber);
		break;
	case 3:
	case 4:  _wizardsNumber.deleteUnit(_caseNumber - 2);
		break;
	case 5:
	case 6: _priestsNumber.deleteUnit(_caseNumber - 4);
		break;
	}
}

void UnitsNumber::getUnitsStatistic()
{
	_warriorsNumber.getUnitsStatistic();
	_wizardsNumber.getUnitsStatistic();
	_priestsNumber.getUnitsStatistic();
}

int UnitsNumber::getUnitsResources(int caseNumber)
{
	if (caseNumber == 1) return _warriorsNumber.getUnitsResources();
	if (caseNumber == 2) return _wizardsNumber.getUnitsResources();
	if (caseNumber == 3) return _priestsNumber.getUnitsResources();
}

void WarriorsNumber::addUnit(int _caseNumber)
{
	switch (_caseNumber)
	{
	case 1: _fightersNumber.addUnit();
		break;
	case 2: _rangersNumber.addUnit();
		break;
	}
}

void WarriorsNumber::deleteUnit(int _caseNumber)
{
	switch (_caseNumber)
	{
	case 1: _fightersNumber.deleteUnit();
		break;
	case 2: _rangersNumber.deleteUnit();
		break;
	}
}

void WarriorsNumber::getUnitsStatistic()
{
	std::cout << "Warriors :: Fighters: " << _fightersNumber.getUnitsStatistic() << " -_- Rangers: " << _rangersNumber.getUnitsStatistic() << '\n';
}

int WarriorsNumber::getUnitsResources()
{
	return _fightersNumber.getUnitsResources() + _fightersNumber.getUnitsResources();
}

void WizardsNumber::addUnit(int _caseNumber)
{
	switch (_caseNumber)
	{
	case 1: _magesNumber.addUnit();
		break;
	case 2: _illusionistsNumber.addUnit();
		break;
	}
}

void WizardsNumber::deleteUnit(int _caseNumber)
{
	switch (_caseNumber)
	{
	case 1: _magesNumber.deleteUnit();
		break;
	case 2: _illusionistsNumber.deleteUnit();
		break;
	}
}

void WizardsNumber::getUnitsStatistic()
{
	std::cout << "Wizards :: Mages: " << _magesNumber.getUnitsStatistic() << " -_- Illusionists: " << _illusionistsNumber.getUnitsStatistic() << '\n';
}

int WizardsNumber::getUnitsResources()
{
	return _magesNumber.getUnitsResources() + _illusionistsNumber.getUnitsResources();
}

void PriestsNumber::addUnit(int _caseNumber)
{
	switch (_caseNumber)
	{
	case 1: _clericsNumber.addUnit();
		break;
	case 2: _druidsNumber.addUnit();
		break;
	}
}

void PriestsNumber::deleteUnit(int _caseNumber)
{
	switch (_caseNumber)
	{
	case 1: _clericsNumber.deleteUnit();
		break;
	case 2: _druidsNumber.deleteUnit();
		break;
	}
}

void PriestsNumber::getUnitsStatistic()
{
	std::cout << "Priests :: Clerics: " << _clericsNumber.getUnitsStatistic() << " -_- Druids: " << _druidsNumber.getUnitsStatistic() << '\n';
}

int PriestsNumber::getUnitsResources()
{
	return _clericsNumber.getUnitsResources() + _druidsNumber.getUnitsResources();
}

void Base::createBase(int x, int y, int square)
{
	_point.setPoint(x, y);
	_health.setHealth(100);
	_armor.setArmor(10);
	_maxWarriorsNumber = square / 2;
	_maxWizardsNumber = square / 2;
	_maxPriestsNumber = square / 4;
}


void Base::showBaseStatistic()
{
	std::cout << "Health of base: " << _health.getHealth() << '\n';
	std::cout << "Resourses on warriors: " << _maxWarriorsNumber - _unitsNumber.getUnitsResources(1) << '\n';
	std::cout << "Resourses on wizards: " << _maxWizardsNumber - _unitsNumber.getUnitsResources(2)  << '\n';
	std::cout << "Resourses on priests: " << _maxPriestsNumber - _unitsNumber.getUnitsResources(2) << '\n';
}

void Base::showArmyStatistic()
{
	std::cout << "Count of army: " << '\n';
	std::cout << "Among them:\n";
	_unitsNumber.getUnitsStatistic();
}

UnitsNumber Base::getUnitsNumber()
{
	return _unitsNumber;
}

void Base::addUnit(int caseNumber)
{
	_unitsNumber.addUnit(caseNumber);
}

void Base::deleteUnit(int caseNumber)
{
	_unitsNumber.deleteUnit(caseNumber);
}

Base::~Base()
{
	_point.setPoint(NULL, NULL);
	_health.setHealth(0);
	_armor.setArmor(0);
}