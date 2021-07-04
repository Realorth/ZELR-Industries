#include "Interaccion.h"
#include <math.h>
#include <iostream>

Interaccion::~Interaccion()
{
}



bool Interaccion::colision(disparo d, pared p)
{
	vector2D pos =d. GetPos();
	if ((pos.y >= p.limite1.y)&& (pos.x > p.limite1.x)&&(pos.x < p.limite2.x))
		return true;
	
	return false;
}


void Interaccion::colision(hombre& h, pared p)
{
	

	vector2D dir;
	float dif = p.distancia(h.posicion, &dir) -h.altura / 10;
	if (dif <= 0.0f)
	{
		//vector2D v_inicial = h.velocidad;
		h.velocidad.y=0 ;
		h.posicion = h.posicion - dir * dif;
		h.posicion.y += 0.001f;
	}


}

//bool Interaccion::colision(hombre h, bonus b)
//{
//	vector2D posHombre = h.GetPos(); //la posicion de la base del hombre
//	vector2D posBonus = b.GetPos();
//
//	//posHombre.y += h.GetAltura(); // 2.0f; //posicion del centro
//	float distancia = (posBonus - posHombre).modulo();
//	if (distancia<=0)//((posHombre.x==posBonus.x)&&(posHombre.y==posBonus.y))//distancia<posBonus.modulo())
//		return true;
//	else return false;
//	//pos.y += h.GetAltura() / 2.0f; //posicion del centro
//	//float distancia = (b.posicion - pos).modulo();
//	//if (distancia < b.radio)
//	//	return true;
//	//return false;
//	
//}


void Interaccion::rebote(hombre& h, std::vector<pared*> d)
{

	for (auto i : d) {
		if(i!=nullptr)
		colision(h, *i);
	}

}


//bool Interaccion::colision(hombre h, BonusArmadura b)
//{
//	vector2D pos = h.GetPos(); //la posicion de la base del hombre
//	vector2D posBonus = b.GetPos();
//	pos.y += h.GetAltura() / 2.0f; //posicion del centro
//	float distancia = (posBonus - pos).modulo();
//	if (distancia < 1.0f)
//		return true;
//	return false;
//
//}

//bool Interaccion::colision(hombre h, bonusBolaFuego b)
//{
//	vector2D pos = h.GetPos(); //la posicion de la base del hombre
//	vector2D posBonus = b.GetPos();
//	pos.y += h.GetAltura() / 2.0f; //posicion del centro
//	float distancia = (posBonus - pos).modulo();
//	if (distancia < 1.0f)
//		return true;
//	return false;
//
//}

bool Interaccion::colision(hombre h, bonus& b)
{
	vector2D pos = h.GetPos(); //la posicion de la base del hombre
	vector2D posBonus = b.GetPos();
	pos.y += h.GetAltura() / 2.0f; //posicion del centro
	float distancia = (posBonus - pos).modulo();
	if (distancia < 1.0f)
		return true;
	return false;
}
//
//bool Interaccion::colision(hombre h, BonusCorazon b)
//{
//	vector2D pos = h.GetPos(); //la posicion de la base del hombre
//	vector2D posBonus = b.GetPos();
//	pos.y += h.GetAltura() / 2.0f; //posicion del centro
//	float distancia = (posBonus - pos).modulo();
//	if (distancia < 1.0f)
//		return true;
//	return false;
//
//}
//
bool Interaccion::colision(hombre h, coin c)
{
	vector2D pos = h.GetPos(); //la posicion de la base del hombre
	vector2D posMoneda = c.GetPos();
	pos.y += h.GetAltura() / 2.0f; //posicion del centro
	float distancia = (posMoneda - pos).modulo();
	if (distancia < 1.0f)
		return true;
	return false;

}
bool Interaccion::muertecaida(hombre h)
{
	vector2D m = h.GetPos();
	if (m.y < -7.0f)
		return true;
	return false;
}

