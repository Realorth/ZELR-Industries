#pragma once
#include "vector2D.h"
#include "objetomovil.h"
#include "ETSIDI.h"

class bonus : public objetomovil
{
	
public:
	bonus();
	bonus(float x , float y):objetomovil(x,y){}
	bonus(vector2D a) :objetomovil(a) {}
	virtual ~bonus();

	// funcion principal de dibujo del bonus
	virtual void dibuja() = 0;//Función virtual pura
	void SetPos(float x, float y) { posicion.x = x; posicion.y = y; }
	void SetPos(vector2D a) { posicion = a; }


protected:


};