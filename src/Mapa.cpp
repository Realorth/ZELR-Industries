#include "Mapa.h"
#include "ETSIDI.h"
#include<time.h>
#include<iostream>
#include<map>
#include<cmath>
#include<fstream>
#include<cstdlib>
#include<cstring>
#include<string>
Mapa::Mapa()
{

}
Mapa::Mapa(int l)
{
	tipo a = static_cast<tipo>(l); 
	ptipo = a;
}
Mapa::Mapa(tipo l)
{
	ptipo = l;
}
Mapa::~Mapa()
{
}
void Mapa::Agregar(pared* a)
{
	suelo.push_back(a);
	numero++;
}

void Mapa::Inicializa()
{
	
}



void Mapa::Genera_fondo()
{
	auto a = 2;
	auto l = 10.0f;

	for (auto i = -1; i < MAX_LONG; i+=a) {
		pared* aux = new pared(l*i,20.0f,a*l);
		fondo.push_back(aux);
	}

}
void Mapa::Genera_fondo(int longt,float longitud)
{
	auto l = 15.0f;
	int n_segmentos = longt / ((2*l)/longitud);
	for (auto i = 0; i < n_segmentos; i ++) {
		pared* aux = new pared(2*l * i-longitud, 20.0f, 2* l);
		fondo.push_back(aux);
	}

}

void Mapa::Genera()
{
	int height;
	int length;
	float longitud = 5.0f;//Distancia de cada punto del txt
	//Generamos las plataformas
	switch (ptipo) {
	case CEMENTERIO:
		delete Plataforma;
		Plataforma = new ETSIDI::Sprite("imagenes/GRAVEYARD/png/plataforma.png");
		delete Suelo;
		Suelo = new ETSIDI::Sprite("imagenes/GRAVEYARD/png/suelo_m.png");
		break;
	case NIEVE:
		delete Plataforma;
		Plataforma = new ETSIDI::Sprite("imagenes/WINTER/png/plataforma.png");
		delete Suelo;
		Suelo = new ETSIDI::Sprite("imagenes/WINTER/png/suelo_m.png");
		break;
	case BASICO:
		delete Plataforma;
		Plataforma = new ETSIDI::Sprite("imagenes/BASICO/png/plataforma.png");
		delete Suelo;
		Suelo = new ETSIDI::Sprite("imagenes/BASICO/png/suelo_m.png");
		break;

	}
	std::ifstream a;
	if (ptipo == CEMENTERIO) {
		a.open("CEMENTERIO.txt");
	}
	else if (ptipo == NIEVE) {
		a.open("NIEVE.txt");
	}
	else if (ptipo == BASICO) {
		a.open("BASICO.txt");
	}

	if (a.is_open()) {
		bool flag = false;
		int contador = 0;
		float altura;//=static_cast<float>(height);
		float x = -longitud;
		std::vector<std::string> mapeo;//guarda todo el mapa
		std::string aux;
		while (a.good()) {

			char m;
			if (flag == false)
				std::getline(a, aux);
			if (!std::strcmp(aux.c_str(), "height")) {
				std::getline(a, aux);
				height = atoi(aux.c_str());
				altura = height;
			}
			if (!std::strcmp(aux.c_str(), "length")) {
				std::getline(a, aux);
				length = atoi(aux.c_str());
			}
			if (!std::strcmp(aux.c_str(), "map") || flag == true) {
				a >> m;
				//std::getline(a, aux);
				//mapeo.push_back(aux);
				float y = 20.0f * altura / height;
				if (y > 0) {
					switch (m) {
					case 'p':
						if (contador == 0)
							x += longitud;
						contador++;
						break;
					case '-':
						if (contador) {
							plataforma.push_back(new pared(x - longitud, y, longitud * contador));
							x += longitud * contador;
							contador = 0;
						}
						else {
							x += longitud;
						}
						break;
					case'/':
						altura--;
						x = -longitud;
						contador = 0;
						break;
					}
				}
				else {
					switch (m) {
					case's':
						suelo.push_back(new pared(x, y, longitud));
					case '-':
						x += longitud;
						break;
					default:
						x = -longitud;
						altura = height;
						break;
					}
				}



				flag = true;
			}

		}

	}
	Genera_fondo(length, longitud);
	//	Genera_fondo();
		/*Genera_suelo();
		Genera_plataforma();*/

}

void Mapa::BorrarContenido()
{
	for (auto i : suelo)
		delete i;
	suelo.clear();
	for (auto i : plataforma)
		delete i;
	plataforma.clear();
	for (auto i : fondo)
		delete i;
	fondo.clear();
	delete Suelo;
	delete Plataforma;

	numero = 0;
}

void Mapa::Borrar(int index)
{

	if (index < 0 || index >= numero)
		return;
	delete suelo[index];
	suelo.erase(suelo.begin() + index);

}

void Mapa::Borrar_suelo(int index)
{
	for (auto i : suelo)
		delete i;
	suelo.clear();
}

void Mapa::dibuja()
{
	dibuja_fondo();
	dibuja_plataforma();
	dibuja_suelo();
	
}

void Mapa::SetTipo(int l)
{
	tipo a = static_cast<tipo>(l);
	ptipo = a;
}

void Mapa::dibuja_suelo()
{
	for (auto i : suelo) {
		Suelo->setPos(i->GetLim1().x - 0.5F, i->GetLim1().y - 5);
		Suelo->setSize(i->GetLim2().x - i->GetLim1().x, 5 - 0.45f);
		Suelo->draw();
	}
	
}

void Mapa::dibuja_fondo()
{
	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_TEXTURE_2D);
	switch (ptipo)
	{
	case Mapa::CEMENTERIO:
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/GRAVEYARD/png/BG.png").id);
		break;
	case Mapa::NIEVE:
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/WINTER/png/BG.png").id);
		break;
	case Mapa::BASICO:
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/BASICO/png/BG.png").id);
		break;
	}

	glDisable(GL_LIGHTING);

	for (auto i = 0; i < fondo.size(); i++) {
		polygon3D(fondo[i]);
	}
	glDisable(GL_BLEND);
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

void Mapa::dibuja_plataforma()
{
	for (auto a:plataforma) {
		Plataforma->setPos(a->GetLim1().x-0.5f, (a->GetLim1().y-1.5f-0.5f));
		Plataforma->setSize(a->GetLenght(),1.50f);
		a->dibuja();
		Plataforma->draw();
	}
	

}



void Mapa::textura_suelo(int op, pared* s)
{
	switch (ptipo) {
	case CEMENTERIO:
		switch (op) {
		case -1:
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/GRAVEYARD/png/Tiles/suelo_izq.png").id);
			break;
		case 0:
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/GRAVEYARD/png/Tiles/suelo_m.png").id);
			break;
		case 1:
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/GRAVEYARD/png/Tiles/suelo_dcha.png").id);
			break;
		}
		break;
	case NIEVE:
		switch (op) {
		case -1:
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/WINTER/png/Tiles/suelo_izq.png").id);
			break;
		case 0:
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/WINTER/png/Tiles/suelo_m.png").id);
			break;
		case 1:
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/WINTER/png/Tiles/suelo_dcha.png").id);
			break;
		}
		break;
	case BASICO:
		switch (op) {
		case -1:
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/BASICO/png/Tiles/suelo_izq.png").id);
			break;
		case 0:
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/BASICO/png/Tiles/suelo_m.png").id);
			break;
		case 1:
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes//png/Tiles/suelo_dcha.png").id);
			break;
		}

	}

	polygon(s);
	s->dibuja();
}


inline void Mapa::polygon(pared* s)
{
	auto v1 = s->GetLim1();
	auto v2 = s->GetLim2();
	glBegin(GL_POLYGON);
	glColor4f(1, 1, 1, 1);
	glTexCoord2d(1, 0); glVertex2f(v1.x, v1.y);
	glTexCoord2d(0, 0); glVertex2f(v2.x, v2.y);
	glTexCoord2d(0, 1); glVertex2f(v2.x,v2.y - 5);
	glTexCoord2d(1, 1); glVertex2f(v1.x, v1.y - 5);
	glEnd();
}

inline void Mapa::polygon3D(pared* s)
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

