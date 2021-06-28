#include "caja.h"

caja::caja()
{
	suelo.SetColor(0, 200, 0);
	suelo.SetPos(-10.0f, 0, 10.0f, 0);

	techo.SetColor(0, 200, 0);
	techo.SetPos(-10.0f, 15.0f, 10.0f, 15.0f);

	pared_dcha.SetColor(0, 255, 0);
	pared_dcha.SetPos(-10.0f, 0, -10.0f, 15.0f);

	pared_izq.SetColor(0, 255, 0);
	pared_izq.SetPos(10.0f, 0, 10.0f, 15.0f);
}
//caja::~caja()
//{}

void caja::dibuja()
{
	// TODO: Agregar aquí el código de implementación.
	suelo.dibuja();
	techo.dibuja();
	pared_izq.dibuja();
	pared_dcha.dibuja();
	//dibujo del fondo 
	//glEnable(GL_TEXTURE_2D);
	//glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondo.png").id);
	//glDisable(GL_LIGHTING);
	//glBegin(GL_POLYGON);
	//glColor3f(1, 1, 1);
	//glTexCoord2d(0, 1); glVertex2f(-10, 0);
	//glTexCoord2d(1, 1); glVertex2f(10, 0);
	//glTexCoord2d(1, 0); glVertex2f(10, 15);
	//glTexCoord2d(0, 0); glVertex2f(-10, 15);
	//glEnd();
	//glEnable(GL_LIGHTING);
	//glDisable(GL_TEXTURE_2D);

}
