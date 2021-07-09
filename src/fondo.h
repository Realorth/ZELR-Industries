#pragma once
#include"ListaPared.h"
#include<string>
#include<cstring>
#include<vector>
#include"ETSIDI.h"
#define MAX_LONG 50
class fondo:
	public ListaPared
{
public:
	fondo() :ListaPared(),ImagenFondo("imagenes/GRAVEYARD/png/BG.png") {}
	virtual ~fondo() {}
	void Genera();
	void Genera(int , float);
	void dibuja();
	void setFondo(const char* a) {ImagenFondo = a; }
	const char* getFondo() { return ImagenFondo; }
private:
	const char* ImagenFondo;
	inline void polygon3D(pared* s);
};

