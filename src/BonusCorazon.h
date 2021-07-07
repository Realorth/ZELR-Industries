#pragma once
#include "bonus.h"
#include "ETSIDI.h"

class BonusCorazon :public bonus
{

protected:

public:
	BonusCorazon();
	BonusCorazon(float, float);
	BonusCorazon(vector2D);
	virtual ~BonusCorazon();

};

