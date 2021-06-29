#pragma once

#include "bonus.h"
#include "ETSIDI.h"


class BonusArmadura :public bonus
{
protected:
	ETSIDI::Sprite S_arm;
public:
	void dibuja();//Virtual
	BonusArmadura();
	BonusArmadura(float, float);
	BonusArmadura(vector2D);
	virtual ~BonusArmadura();
};

