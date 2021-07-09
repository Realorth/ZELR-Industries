#include "fondo.h"


void fondo::dibuja()
{

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(ImagenFondo).id);
	
	glDisable(GL_LIGHTING);

	for (auto i = 0; i < lista.size(); i++) {
		polygon3D(lista[i]);
	}
	glDisable(GL_BLEND);
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}


inline void fondo::polygon3D(pared* s)
{
	auto z = -0.1f;
	auto v1 = s->GetLim1();
	auto v2 = s->GetLim2();
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glTexCoord2d(0, 1); glVertex3f(v1.x, 0, z);
	glTexCoord2d(1, 1); glVertex3f(v2.x, 0, z);
	glTexCoord2d(1, 0); glVertex3f(v2.x, v2.y, z);
	glTexCoord2d(0, 0); glVertex3f(v1.x, v1.y, z);
	glEnd();
}



void fondo::Genera()
{
	auto a = 2;
	auto l = 10.0f;

	for (auto i = -1; i < MAX_LONG; i += a) {
		pared* aux = new pared(l * i, 20.0f, a * l);
		lista.push_back(aux);
	}

}
void fondo::Genera(int longt, float longitud)
{
	auto l = 15.0f;
	int n_segmentos = longt / ((2 * l) / longitud);
	for (auto i = 0; i < n_segmentos; i++) {
		pared* aux = new pared(2 * l * i - longitud, 20.0f, 2 * l);
		lista.push_back(aux);
	}

}