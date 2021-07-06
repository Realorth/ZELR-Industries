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
	//Para que no se salga el hombre del mapa
	if (h.GetPos().x < -3.5f)
		h.posicion.x = -3.5f;
	if (h.GetPos().x > 293)
		h.posicion.x = 293;
	
	

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



void Interaccion::rebote(hombre& h, std::vector<pared*> d)
{
	for (auto i : d) 
		colision(h, *i);
}

void Interaccion::colision_border(hombre& h, std::vector<pared*> p){

	auto margenSeguridad = 0.1f;
	if (h.GetPos().x <= p.front()->GetLim1().x + margenSeguridad)
		h.posicion.x = p.front()->GetLim1().x + 0.5f;
	if (h.GetPos().x >= p.back()->GetLim2().x - margenSeguridad)
		h.posicion.x = p.back()->GetLim2().x - 0.5f;
}


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

