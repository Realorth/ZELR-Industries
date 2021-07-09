#pragma once
#include"pared.h"
#include<vector>
#include<time.h>
#include"ETSIDI.h"
#include<string>
#include<cstring>
class ListaPared
{
public:
	ListaPared() :sprite_ListaPared(nullptr) {}
	virtual ~ListaPared() { this->destruirContenido(); }
	void destruirContenido();
	virtual void Genera() = 0;
	virtual void dibuja();
	void agregar(pared*);
	void setTextura(const char*);
	void setTextura(std::string a);
	std::vector<pared*> getListaPared() { return lista; }
	ETSIDI::Sprite getSprite() { return *sprite_ListaPared; }
protected:
	std::vector<pared*> lista;
	ETSIDI::Sprite* sprite_ListaPared = nullptr;
};

