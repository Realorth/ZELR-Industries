#pragma once
#include "vector2D.h"
#include "objetomovil.h"
#include "ETSIDI.h" 

class disparo : public objetomovil
{
public:
	disparo();
	virtual ~disparo();

	void dibuja();
	void SetOrigen(float ox, float oy);
	void SetColor(unsigned char r, unsigned char v, unsigned char b);
	void SetRadio(float r);
	float GetRadio();


	friend class Interaccion;
	friend class listadisparos;

protected:
	ETSIDI::Sprite sprite;
	vector2D origen;
	float radio;
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
};
