#include "mago.h"

mago::mago() :spritemago("imagenes/mago1.png", 3), hombre()
{
	spritemago.setCenter(1, 0);
	spritemago.setSize(2.5f,2.5f);
	vida = 3;
	ataque = 3;
	aceleracion.x = aceleracion.y = 0;
	
}
mago::~mago()
{}
void mago::dibuja()
{
	// TODO: Agregar aquí el código de implementación.
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(1.0f, 0.0f, 0.0f);
	//glutSolidSphere(altura, 20, 20);
	//gestion de direccion y animacion 
	if (velocidad.x > 0.01)spritemago.flip(false, false);
	if (velocidad.x < -0.01)spritemago.flip(true, false);
	if ((velocidad.x < 0.01) && (velocidad.x > -0.01))
		spritemago.setState(0);
	else if (spritemago.getState() == 0)
		spritemago.setState(1, false);
	spritemago.draw();
	glPopMatrix();
}
