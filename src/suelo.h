#pragma once
#include"pared.h"
#include<vector>
#include<time.h>
#include"ETSIDI.h"
#include<string>
#include<cstring>
class suelo:public pared
{
public:
	suelo() :pared() {}
	suelo(float x1, float y1, float x2, float y2) :pared(x1, y1, x2, y2) {}
	suelo(vector2D v1, vector2D v2) :pared(v1, v2) {}
	suelo(vector2D v1, float largo) :pared(v1, largo) {}
	suelo(float x, float y, float lenght) :pared(x, y, lenght) {}
	virtual ~suelo() { this->destruirContenido(); }
	void destruirContenido();
	void Genera();
	void dibuja();
	void agregar(pared*);
	void setTextura(const char *);
	void setTextura(std::string a);
	std::vector<pared*> getSuelo() { return floor; }
	ETSIDI::Sprite getSprite() { return *Suelo; }
private:
	std::vector<pared*> floor;
	ETSIDI::Sprite* Suelo = nullptr;
};

