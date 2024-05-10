#include "specialEnemey.h"

int specialEnemey::getCritChance()
{
	return critChance;
}

int specialEnemey::getcritDamage()
{
	return critDamage;
}

int specialEnemey::getHealth()
{
	return health;
}

int specialEnemey::getDamage()
{
	return damage;
}

void specialEnemey::dealDamage(int damageDealt)
{
	health = health - damageDealt;
}
