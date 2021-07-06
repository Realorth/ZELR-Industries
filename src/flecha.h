#pragma once
#include "disparo.h"
class flecha :
    public disparo
{
protected:
	ETSIDI::Sprite S_Flecha;

public:
	flecha();
	virtual ~flecha();
	void dibuja();
};

