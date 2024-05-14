#include "specialBoss.h"

int specialBoss::getSelfHealChance()
{
	return selfHealChance;
}

int specialBoss::getSelfHealAmount()
{
	return selfHeal;
}

void specialBoss::healBoss(int heal)
{
	health = health + heal;
}
