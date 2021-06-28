#pragma once
#include "ETSIDI.h"
#include "bonus.h"

class coin :public objetomovil
{
protected:
	ETSIDI::Sprite S_coin;
public:
	void dibuja();
	coin();
	coin(float x, float y);
};

