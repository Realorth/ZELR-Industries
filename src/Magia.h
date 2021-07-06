#pragma once
#include "disparo.h"
class Magia:public disparo
{
public:
	Magia();
	virtual ~Magia();
	void dibuja();
protected:
	ETSIDI::Sprite SMagia;
};

