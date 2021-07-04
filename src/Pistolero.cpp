#include "Pistolero.h"

Pistolero::Pistolero() :spritepistolero("imagenes/gunboy.png", 3), hombre()
{
	spritepistolero.setCenter(1, 0);
	spritepistolero.setSize(2, 2);
	vida = 5;
	ataque = 1;
	aceleracion.x = aceleracion.y = 0;
}
Pistolero::~Pistolero()
{}
void Pistolero::dibuja()
{
	// TODO: Agregar aquí el código de implementación.
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(1.0f, 0.0f, 0.0f);
	//glutSolidSphere(altura, 20, 20);
	//gestion de direccion y animacion 
	if (velocidad.x > 0.01)spritepistolero.flip(false, false);
	if (velocidad.x < -0.01)spritepistolero.flip(true, false);
	if ((velocidad.x < 0.01) && (velocidad.x > -0.01))
		spritepistolero.setState(0);
	else if (spritepistolero.getState() == 0)
		spritepistolero.setState(1, false);
	spritepistolero.draw();
	glPopMatrix();
}