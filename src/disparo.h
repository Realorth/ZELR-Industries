#pragma once
#include "vector2D.h"
#include "objetomovil.h"
#include"ColorRGB.h"
#include "ETSIDI.h" 
#include<string>
#include<cstring>
using namespace std;
class disparo : public objetomovil
{
public:
	//Constructores
	disparo();
	disparo(float x, float y, const char* b) ;
	disparo(vector2D a, const char* b);
	disparo(vector2D a, vector2D origen, const char* b);
	//Destructor
	virtual ~disparo();
	//Funciones
	void SetTextura(const char* b) { textura = b; }
	virtual void dibuja();//Por sí existen balas especiales
	void SetOrigen(float ox, float oy);
	void SetColor(Byte r, Byte v, Byte b);
	void SetRadio(float r);
	float GetRadio();
	vector2D getOrigin() { return origen; }
	float GetLongitud();
	string GetNombre() { return nombre; }
	void SetNombre(string a) { nombre = a; }
	friend class Interaccion;
	friend class listadisparos;

protected:
	string nombre="Normal";
	vector2D origen;
	float radio;
	ColorRGB color;
	ETSIDI::Sprite textura;//Textura que cambia según el tipo de disparo
};

