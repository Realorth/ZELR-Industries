#pragma once
#include "vector2D.h"
#include"ColorRGB.h"
class pared
{
public:
	pared();
	//Constructores para plataforma específica
	pared(float x1, float y1, float x2, float y2) :limite1(x1, y1), limite2(x2, y2),color() {}
	pared(vector2D v1,vector2D v2):limite1(v1),limite2(v2){}
	// Constructores  para una separación definida
	pared(vector2D v1, float largo):limite1(v1),largo(largo),limite2(v1+largo),color(){}
	pared(float x, float y, float lenght) :limite1(x, y), largo(lenght), limite2(x + lenght,y) {}
	virtual ~pared();
	// Resto de métodos
	virtual void dibuja();

	void SetColor(Byte , Byte, Byte);
	void SetPos(float x1, float y1, float x2, float y2);

	void SetLim1(float x, float y) { limite1.x = x; limite1.y = y; }
	vector2D GetLim1() { return limite1; }

	void SetLim2(float x, float y) { limite2.x = x; limite2.y = y; }
	vector2D GetLim2() { return limite2; }

	void setLenght(float a) { largo = a; }
	float GetLenght() { return largo; }

	void SetAncho(float a) { ancho = a; }
	float GetAncho() { return ancho; }

	float distancia(vector2D punto, vector2D* direccion = 0);

	float dist_pto_recta(vector2D c);
	float Distancia(vector2D p1, vector2D p2);

	ColorRGB GetColor() { return color; }

	

	friend class Interaccion;
	friend class listadisparos;//Sín sentido


protected:
	ColorRGB color;
    vector2D limite1;
	// Dá libertad al  programador  para  usar las paredes de 
	// diferentes maneras
	vector2D limite2;
	float largo=10.0f;//Es siempre determinado para suelo
	float ancho = 0.1f;
};

