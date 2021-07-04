#pragma once
#include"pared.h"
#include<string>
#include<cstring>
#include<vector>
#include"ETSIDI.h"
#define MAX_LONG 50
class fondo:
	public pared
{
public:
	fondo() :pared(),Fondo(nullptr) {}
	fondo(float x1,float y1, float x2,float y2) :pared( x1,  y1,  x2, y2),Fondo(nullptr){}
	fondo(vector2D v1, vector2D v2):pared( v1,  v2), Fondo(nullptr) {}
	fondo(vector2D v1,float largo) :pared( v1,  largo), Fondo(nullptr) {}
	fondo(float x,float y,float lenght) :pared( x, y,  lenght), Fondo(nullptr) {}
	~fondo() {}
	void destruirContenido();
	void Genera();
	void Genera(int , float);
	void dibuja();
	void agregar(pared*);
	void setTextura(const char*);
	void setTextura(std::string a);
	std::vector<pared*> getFondo() { return Background; }
	const char* getTextura() { return Fondo; }
private:
	std::vector<pared*> Background;
	const char* Fondo;
	inline void polygon3D(pared* s);
};

