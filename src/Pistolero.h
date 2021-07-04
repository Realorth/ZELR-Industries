#pragma once
#include "hombre.h"
class Pistolero :
    public hombre
{
protected:
    ETSIDI::SpriteSequence spritepistolero{ "imagenes/gunboy.png", 3 };
public:
	void dibuja();
	Pistolero();
	virtual ~Pistolero();
};

