#pragma once
#include "disparo.h"
class flecha :
    public disparo
{
protected:
	ETSIDI::sprite S_Flecha;

public:
	flecha();
	virtual ~flecha();
	void dibuja();
};

