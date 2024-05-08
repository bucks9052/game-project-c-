#include "playerType.h"

void playerType::setPlayerdata(int h, int m, char mL, char jL, char vL, char eL, std::string final)
{
	health = h;
	money = m;
	mercuryLetter = mL;
	jupiterLetter = jL;
	venusLetter = vL;
	earthLetter = eL;
	finalWord = final;
}

int playerType::getHealth()
{
	return health;
}

void playerType::heal(int amountHealed)
{
	health = health + amountHealed;
}

int playerType::getCurrency()
{
	return money;
}

void playerType::addMoney(int moneyGained)
{
	money = money + moneyGained;
}

void playerType::dealPlayerDamage(int damageDealt)
{
	health = health - damageDealt;
}

int playerType::getQuickDamageNumber()
{
	return quickDamage;
}

int playerType::getHeavyDamageNumber()
{
	return heavyDamage;
}
