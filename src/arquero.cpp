#include "arquero.h"

arquero::arquero() : hombre()
{
	vida = 4;
	ataque = 2;
	aceleracion.x = aceleracion.y = 0;
}

arquero::~arquero()
{}
void arquero::dibuja()
{
	// TODO: Agregar aquí el código de implementación.
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(1.0f, 0.0f, 0.0f);
	//glutSolidSphere(altura, 20, 20);
	//gestion de direccion y animacion 
	if (velocidad.x > 0.01)spritearquero.flip(false, false);
	if (velocidad.x < -0.01)spritearquero.flip(true, false);
	if ((velocidad.x < 0.01) && (velocidad.x > -0.01))
		spritearquero.setState(0);
	else if (spritearquero.getState() == 0)
		spritearquero.setState(1, false);
	spritearquero.draw();
	glPopMatrix();
}