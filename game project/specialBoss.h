#pragma once
#include "specialEnemey.h"
class specialBoss : public specialEnemey
{
private:
	int selfHealChance = 15;
	int selfHeal = 20;
public:
	int getSelfHealChance();
	int getSelfHealAmount();
	void healBoss(int);
};

