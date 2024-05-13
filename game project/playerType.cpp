#include "playerType.h"
#include <iostream>
#include <fstream>
void playerType::setPlayerdata(int h, int m, char mL, char jL, char vL, char eL, std::string final)     //overloaded set function
{
	health = h;
	money = m;
	mercuryLetter = mL;
	jupiterLetter = jL;
	venusLetter = vL;
	earthLetter = eL;
	finalWord = final;
}

int playerType::getHealth()             //get health value
{
	return health;
}

void playerType::heal(int amountHealed)     //heal player
{
	health = health + amountHealed;
}

int playerType::getCurrency()       //get moeny value for shop system
{
	return money;
}

void playerType::addMoney(int moneyGained)      //add money to account for future shop system
{
	money = money + moneyGained;
}

void playerType::dealPlayerDamage(int damageDealt)          //deal damage to player
{
	health = health - damageDealt;
}

int playerType::getQuickDamageNumber()          //get the quick damage attack value for the player attacks
{
	return quickDamage;
}

int playerType::getHeavyDamageNumber()  //get the heavy damage attack value for the player attacks
{
	return heavyDamage;
}
void playerType::removeMoney(int cost)                  //remove money
{
	money = money - cost;
}
void playerType::saveGame()                  //binary file system for save games i think works well needs tested more
{
    std::string save = "save.dat";
    std::ofstream file(save, std::ios::out | std::ios::binary);
    if (file.is_open())
    {
        // Write player data to the file
        file.write(reinterpret_cast<const char*>(&health), sizeof(int));
        file.write(reinterpret_cast<const char*>(&money), sizeof(int));
        file.write(reinterpret_cast<const char*>(&mercuryLetter), sizeof(char));
        file.write(reinterpret_cast<const char*>(&jupiterLetter), sizeof(char));
        file.write(reinterpret_cast<const char*>(&venusLetter), sizeof(char));
        file.write(reinterpret_cast<const char*>(&earthLetter), sizeof(char));
        file.write(finalWord.c_str(), finalWord.size() + 1);
        file.close();
    }
    else
    {
        std::cerr << "Error: Unable to save game data to file " << save << std::endl;
    }
}

// Load game function
void playerType::loadGame()
{
    std::string save = "save.dat";
    std::ifstream file(save, std::ios::in | std::ios::binary);
    if (file.is_open())
    {
        // Read player data from the file
        file.read(reinterpret_cast<char*>(&health), sizeof(int));
        file.read(reinterpret_cast<char*>(&money), sizeof(int));
        file.read(reinterpret_cast<char*>(&mercuryLetter), sizeof(char));
        file.read(reinterpret_cast<char*>(&jupiterLetter), sizeof(char));
        file.read(reinterpret_cast<char*>(&venusLetter), sizeof(char));
        file.read(reinterpret_cast<char*>(&earthLetter), sizeof(char));

        // Read finalWord as a string
        std::getline(file, finalWord);

        file.close();
    }
    else
    {
        std::cerr << "Error: Unable to load game data from file " << save << std::endl;
    }
}
void playerType::setKeyWord() {
    finalWord = "MOON";
}

std::string playerType::getKeyWord()
{
    return finalWord;
}
