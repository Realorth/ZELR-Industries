#pragma once
#include "disparo.h"
#include "objetomovil.h"
#include "vector2D.h"
#include "ETSIDI.h"

class disparoespecial : public disparo
{
protected:
	ETSIDI::Sprite AtaqueBFuego;
public:
	disparoespecial();
	~disparoespecial();
	void dibuja();
	
};
