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
	pared* aux = new pared(0.0f, 0, 10.0f);
	test.push_back(aux);
	test[0]->SetColor(200,0,0);
	test[0]->SetPos(0,5,12,5);
}
caja::~caja()
{
	//borrar();
}

void caja::dibuja()
{
	// TODO: Agregar aquí el código de implementación.
	suelo.dibuja();
	techo.dibuja();
	pared_izq.dibuja();
	pared_dcha.dibuja();
	//dibujo del fondo 
	glDepthMask(GL_FALSE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/GRAVEYARD/png/BG.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor4f(1.0, 1.0, 1.0,1.0);
	glTexCoord2d(0, 1); glVertex3f(-10, 0,-0.5);
	glTexCoord2d(1, 1); glVertex3f(10, 0,-0.5);
	glTexCoord2d(1, 0); glVertex3f(10, 15,-0.5);
	glTexCoord2d(0, 0); glVertex3f(-10, 15,-0.5);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/GRAVEYARD/png/Tiles/suelo_izq.png").id);

	glBegin(GL_POLYGON);
	glColor4f(1, 1, 1,1);
	glTexCoord2d(0, 0);	glVertex2f(0,5);
	glTexCoord2d(1, 0);	glVertex2f(7,5);
	glTexCoord2d(1, 1);	glVertex2f(7,0);
	glTexCoord2d(0,1);	glVertex2f(0,0);
	glEnd();
	glDisable(GL_BLEND);
	glDepthMask(GL_TRUE);
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	test[0]->dibuja();
	dibuja_test();
}

void caja::dibuja_test()
{
	auto limite1 = test[0]->GetLim1();
	auto limite2 = test[0]->GetLim2();
	glDepthMask(GL_FALSE);//No sé para qué sirve
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	// Empieza la textura
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/GRAVEYARD/png/Tiles/plataforma_izq.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor4f(1.0, 1.0, 1.0, 1.0);
	glTexCoord2d(0, 0);	glVertex2f(limite1.x, limite1.y);
	glTexCoord2d(1, 0);	glVertex2f((limite2.x + limite1.x) / 2, limite2.y);
	glTexCoord2d(1, 1);	glVertex2f((limite1.x + limite2.x) / 2, limite2.y - 3);
	glTexCoord2d(0, 1);	glVertex2f(limite1.x, limite1.y - 3);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/GRAVEYARD/png/Tiles/plataforma_dcha.png").id);

	glBegin(GL_POLYGON);
	glColor4f(1.0, 1.0, 1.0, 1.0);
	glTexCoord2d(0, 0);	glVertex2f((limite2.x + limite1.x) / 2, limite1.y);
	glTexCoord2d(1, 0);	glVertex2f(limite2.x, limite2.y);
	glTexCoord2d(1, 1);	glVertex2f(limite2.x, limite2.y - 3);
	glTexCoord2d(0, 1);	glVertex2f((limite2.x + limite1.x) / 2, limite1.y - 3);
	glEnd();
	glDisable(GL_BLEND);
	glDepthMask(GL_TRUE);
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

void caja::textura_test(pared* s)
{
}

void caja::borrar()
{
	for (auto i = 0; i < test.size(); i++) {
		delete[] test[i];
		test[i] = nullptr;
	}
	test.clear();// Elimina todo el contenido
}
