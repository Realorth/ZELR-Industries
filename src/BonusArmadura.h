#pragma once

#include "bonus.h"
#include "ETSIDI.h"


class BonusArmadura :public bonus
{
protected:

public:
	BonusArmadura();
	BonusArmadura(float, float);
	BonusArmadura(vector2D);
	virtual ~BonusArmadura();


};


