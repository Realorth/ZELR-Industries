#pragma once
#include "hombre.h"

class arquero : public hombre
{
protected:
	SpriteSequence spritearquero{ "imagenes/arquero1.png", 4 };

public:
	void dibuja();
	arquero();
	virtual ~arquero();
};

