#pragma once
#include "vector2D.h"
#include "objetomovil.h"
#include "ETSIDI.h"
#include <string>
#include <cstring>
using namespace std;
class bonus : public objetomovil
{
protected:
	string nombreBonus="Moneda";//por defecto se llama moneda
public:
	bonus();//de serie carga la moneda
	bonus(float x, float y, const char* b);
	bonus(vector2D a, const char* b);
	virtual ~bonus();

	// funcion principal de dibujo del bonus
	virtual void dibuja();
	void SetTextura(const char* b) { textura = b ; }
	
protected:
	ETSIDI::Sprite textura;//Textura que cambia según el tipo de bonus
	
};
