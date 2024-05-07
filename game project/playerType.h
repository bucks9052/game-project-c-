#pragma once
#include <string>
class playerType
{
private:
	int health = 100;
	int money = 0;
	int quickDamage = 50;
	int heavyDamage = 90;
	char mercuryLetter = ' ';
	char jupiterLetter = ' ';
	char venusLetter = ' ';
	char earthLetter = ' ';
	std::string finalWord;
public:
	void setPlayerdata(int, int, char, char, char, char, std::string);
	int getHealth();
	void heal(int);
	int getCurrency();
	void addMoney(int);
	void dealPlayerDamage(int);
	int getQuickDamageNumber();
	int getHeavyDamageNumber();
};

