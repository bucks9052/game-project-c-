#pragma once
class specialEnemey
{
protected:
	int health = 250;
	int damage = 25;
	int critChance = 10;
	int critDamage = 70;
	
public:
	int getCritChance();
	int getcritDamage();
	int getHealth();
	int getDamage();
};

