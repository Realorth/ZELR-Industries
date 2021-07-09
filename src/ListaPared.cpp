#include "ListaPared.h"

void ListaPared::destruirContenido()
{
	for (auto i : lista)
		delete i;
	lista.clear();
}

void ListaPared::dibuja()
{
	for (auto i : lista) {
		sprite_ListaPared->setPos(i->GetLim1().x - 0.5F, i->GetLim1().y - 5);
		sprite_ListaPared->setSize(i->GetLim2().x - i->GetLim1().x, 5 - 0.45f);
		sprite_ListaPared->draw();
	}
}

void ListaPared::agregar(pared* a)
{
	lista.push_back(a);
}

void ListaPared::setTextura(const char* a)
{
	delete sprite_ListaPared;
	sprite_ListaPared = new ETSIDI::Sprite(a);
}

void ListaPared::setTextura(std::string a)
{
	delete sprite_ListaPared;
	sprite_ListaPared = new ETSIDI::Sprite(a.c_str());
}
