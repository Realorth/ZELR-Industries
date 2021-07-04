#pragma once
#include"hombre.h"

class mago: public hombre
{
protected:
	SpriteSequence spritemago{ "imagenes/mago.png", 3 };

public:
	void dibuja();
	mago();
	virtual ~mago();
};

