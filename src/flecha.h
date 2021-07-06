#pragma once
#include "disparo.h"

class flecha : public disparo
{
protected:
	ETSIDI::Sprite sprite;
public:
	flecha();
	virtual ~flecha();
	void dibuja();
};

