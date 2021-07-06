#pragma once
#include "vector2D.h"
#include "objetomovil.h"
#include"ColorRGB.h"
#include "ETSIDI.h" 

class disparo : public objetomovil
{
public:
	disparo();
	virtual ~disparo();

	virtual void dibuja();//Por sí existen balas especiales
	void SetOrigen(float ox, float oy);
	void SetColor(Byte r, Byte v, Byte b);
	void SetRadio(float r);
	float GetRadio();
	vector2D getOrigin() { return origen; }
	float GetLongitud();

	friend class Interaccion;//No
	friend class listadisparos;//No

protected:
	vector2D origen;
	float radio;
	ColorRGB color;
};
