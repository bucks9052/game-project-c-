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
