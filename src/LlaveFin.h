#pragma once
#include "bonus.h"
class LlaveFin :public bonus
{
protected:
	
public:
	LlaveFin();
	LlaveFin(float, float);
	LlaveFin(vector2D);
	virtual ~LlaveFin();
	void dibuja();
};
