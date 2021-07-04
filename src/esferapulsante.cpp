#include "esferapulsante.h"

esferapulsante::esferapulsante()
{
	//radio = 1;
	radio_max = 2.0f;
	radio_min = 0.5f;
	pulso = 0.5;
	SetPos(0.0f, 5.0f);
}
esferapulsante::~esferapulsante()
{}

void esferapulsante::mueve(float t)
{
	//posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	//velocidad = velocidad + aceleracion * t;
	esfera::mueve(t);
	if (radio > radio_max)
		pulso = -pulso;
	if (radio < radio_min)
		pulso = -pulso;
	radio += pulso * t;
	rojo = radio * 255;
	verde = 255 - radio * 100;
	azul = 100 + radio * 50;

}
