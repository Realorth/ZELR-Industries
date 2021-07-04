#pragma once
#include "pared.h"
#include<vector>
#include<string>
#include<cstring>
#include"ETSIDI.h"
class plataforma :
    public pared
{
public:
	plataforma() :pared() {}
	plataforma(float x1, float y1, float x2, float y2) :pared(x1, y1, x2, y2) {}
	plataforma(vector2D v1, vector2D v2) :pared(v1, v2) {}
	plataforma(vector2D v1, float largo) :pared(v1, largo) {}
	plataforma(float x, float y, float lenght) :pared(x, y, lenght) {}
	~plataforma() {}
	void destruirContenido();
	void Genera();
	void dibuja();
	void agregar(pared*);
	void setTextura(const char*);
	void setTextura(std::string a);
	std::vector<pared*> getPlataforma() { return platform; }
	ETSIDI::Sprite getSprite() { return *Plataforma; }
private:
	std::vector<pared*> platform;
	ETSIDI::Sprite* Plataforma=nullptr;

};

