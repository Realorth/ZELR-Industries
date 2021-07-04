#pragma once
#include "ETSIDI.h"
#include "bonus.h"

class coin :public bonus
{
protected:
	ETSIDI::Sprite S_coin;
public:
	void dibuja();
	coin();
	coin(float x, float y);
	coin(vector2D a);
	virtual ~coin() {}
};

