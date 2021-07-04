#include "Mundo.h"
#include "freeglut.h"
#include <math.h>
#include "Interaccion.h"
#include "vector2D.h"
#include <iostream>
#include <fstream>
Mundo::Mundo()
{
}

Mundo:: ~ Mundo()
{

	disparos.destruirContenido();
	listaCoins.destruirContenido();
	listaArmaduras.destruirContenido();
	listaCorazones.destruirContenido();
	listaBFuego.destruirContenido();
	Fondo.destruirContenido();
	Plataformas.destruirContenido();
	Suelos.destruirContenido();
}

void Mundo::destruirMapa() {
	disparos.destruirContenido();
	Suelos.destruirContenido();
	Plataformas.destruirContenido();
	Fondo.destruirContenido();
	listaArmaduras.destruirContenido();
	listaBFuego.destruirContenido();
	listaCoins.destruirContenido();
	listaCorazones.destruirContenido();
}

void Mundo::inicializa()
{
	x_ojo = 0;
	y_ojo = 7.5;
	z_ojo = 30;
	ojo.set(0, 7.5, 30);

	personaje = new Pistolero();
	personaje->SetAltura(1.8f);
	personaje->SetPos(0, personaje->GetAltura());
	personaje->SetAcel(0, -9.81);
	personaje->Setvida(5);
	personaje->Setataque(1);

	fin = false;
	ncoin = 0; //Reestablecer a 0 cada vez que se inicializa el mapa
	bonusBolaFuego* bF1 = new bonusBolaFuego;
	bF1->SetPos(5.0f, 1.0f);
	std::cout << bF1->GetPos().x << " " << bF1->GetPos().y << std::endl;
	listaBFuego.agregar(bF1);
	std::cout << listaBFuego.getNumero() << std::endl;
	BonusCorazon* cor1 = new BonusCorazon;
	cor1->SetPos(8.0f, 1.0f);
	std::cout << cor1->GetPos().x << " " << cor1->GetPos().y << std::endl;
	listaCorazones.agregar(cor1);
	BonusArmadura* arm1 = new BonusArmadura;
	arm1->SetPos(0.0f, 2.0f);
	std::cout << arm1->GetPos().x << " " << arm1->GetPos().y << std::endl;
	listaArmaduras.agregar(arm1);
	coin* moneda1 = new coin;
	moneda1->SetPos(-3.0f, 1.0f);
	std::cout << moneda1->GetPos().x << " " << moneda1->GetPos().y << std::endl;
	listaCoins.agregar(moneda1);


	coin* moneda2 = new coin;
	moneda2->SetPos(-3.0f, 3.0f);
	std::cout << moneda2->GetPos().x << " " << moneda2->GetPos().y << std::endl;
	listaCoins.agregar(moneda2);
	/*for (int i = 0; i < 6; i++) {
		coin* aux = new coin;
		aux->SetPos(i, i + 1);
		listaCoins.agregar(aux);
	}*/

	
	Genera();
	llave.SetPos(10, 2);


}
void Mundo::dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
		x_ojo, 7.5, 0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    
	
	personaje->dibuja();
	disparos.dibuja();
	Suelos.dibuja();
	Fondo.dibuja();
	Plataformas.dibuja();
	llave.dibuja();



	listaCoins.dibuja();
	listaArmaduras.dibuja();
	listaCorazones.dibuja();
	listaBFuego.dibuja();

	//Cantidad de vidas
	ETSIDI::setTextColor(1, 0, 0);
	ETSIDI::setFont("fuentes/Marlboro.ttf", 16);
	std::string vidaHombre = std::to_string(personaje->Getvida());
	ETSIDI::printxy("Vidas", -13 + personaje->GetPos().x, 17);
	ETSIDI::printxy(vidaHombre.c_str(), -11 + personaje->GetPos().x, 17);

	//Cantidad de armaduras
	ETSIDI::setTextColor(0.5, 0.5, 0.5);
	ETSIDI::setFont("fuentes/Marlboro.ttf", 16);
	std::string armHombre = std::to_string(personaje->GetArmadura());
	ETSIDI::printxy("Armaduras", -1 + personaje->GetPos().x, 17);
	ETSIDI::printxy(armHombre.c_str(), 2 + personaje->GetPos().x, 17);

	//Cantidad de monedas
	ETSIDI::setTextColor(1, 1, 0);
	ETSIDI::setFont("fuentes/Marlboro.ttf", 16);
	std::string s = std::to_string(ncoin);
	ETSIDI::printxy("Monedas", -9 + personaje->GetPos().x, 17);
	ETSIDI::printxy(s.c_str(), -6 + personaje->GetPos().x, 17);

	//Ataque a enemigos
	ETSIDI::setTextColor(1, 1, 1);
	ETSIDI::setFont("fuentes/Marlboro.ttf", 16);
	std::string ataqueHombre = std::to_string(personaje->GetAtaque());
	ETSIDI::printxy("Ataque", -5+personaje->GetPos().x, 17);
	ETSIDI::printxy(ataqueHombre.c_str(), -3 + personaje->GetPos().x, 17);
}

void Mundo::mueve()
{
	disparos.mueve(0.015f);
	personaje->mueve(0.025f);


	BonusArmadura* auxA = listaArmaduras.colision(*personaje);
	if (auxA != 0) {
		personaje->AumentaArmadura();
		ETSIDI::play("sonidos/Bonus.wav");
		listaArmaduras.eliminar(auxA);
	}

	BonusCorazon* auxC = listaCorazones.colision(*personaje);
	if (auxC != 0) {
		personaje->AumentaVida();
		ETSIDI::play("sonidos/Bonus.wav");
		listaCorazones.eliminar(auxC);
		impacto = true;
	}

	bonusBolaFuego* auxB = listaBFuego.colision(*personaje);
	if (auxB != 0) {
		personaje->AumentaAtaque();
		ETSIDI::play("sonidos/Bonus.wav");
		listaBFuego.eliminar(auxB);
	}

	coin* auxc = listaCoins.colision(*personaje);
	if (auxc != 0) {
		ETSIDI::play("sonidos/coin.wav");
		ncoin += 1;
		//std::cout << ncoin << "y" << pcoin << std::endl;
		listaCoins.eliminar(auxc);
	}
	if (Interaccion::muertecaida(*personaje) ==true )
		caida = true;


	for (int i = 0; i < disparos.getNumero(); i++) {
		if (disparos[i]->GetLongitud() > 20) {
			disparos.eliminar(disparos[i]);
		}
	}
	x_ojo = personaje->GetPos().x;


	/*Interaccion::rebote(hombre, mapa.GetPlataforma());
	Interaccion::rebote(hombre,mapa.GetSuelo() );*/
	Interaccion::rebote(*personaje, Suelos.getSuelo());
	Interaccion::rebote(*personaje, Plataformas.getPlataforma());

	

}



void Mundo::tecla(unsigned char key)
{
	//hombre.tecla(key);

	switch (key)
	{
	case 'd':
		personaje->SetVel(personaje->GetVel().x + 5, personaje->GetVel().y);
		break;
	case 'a':
		personaje->SetVel(personaje->GetVel().x - 5, personaje->GetVel().y);
		break;
	case'w' :
		z_ojo += 1.0f;
		break;
	case 's':
		z_ojo -=1.0f;
		break;
	case 'e':
		y_ojo += 1.0F;
		break;
	case 'x':
		y_ojo -= 1.0f;
		break;
	case ' ':
	{
		disparo* d = new disparo();
		vector2D pos = personaje->GetPos();
		d->SetPos(pos.x, pos.y);
		d->SetOrigen(pos.x, pos.y);
		if (disparos.agregar(d))
		{
 			ETSIDI::play("sonidos/pistola.wav");
            personaje->SetVel(0, 0);
		}
			
		else delete d;
		break;
	}

	}

}

void Mundo::teclaEspecial(unsigned char key)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		personaje->SetVel(-5.0f, personaje->GetVel().y);
		break;
	case GLUT_KEY_RIGHT:
		personaje->SetVel(5.0f, personaje->GetVel().y);
		break;
	case GLUT_KEY_UP:
	{
        vector2D ace = personaje->GetVel();
		if (ace.y == 0.0f)
			{
			personaje->SetVel(personaje->GetVel().x,10.0f);
		personaje->SetAcel(0, -9.81f);
		}
		
	}
		
		break;
	case GLUT_KEY_DOWN:
		personaje->SetVel(0, 0);
		break;
	}
}

void Mundo::teclaEspecialUp(unsigned char key)
{
	
	switch (key)
	{
	case GLUT_KEY_LEFT:
		personaje->SetVel(0.0f, 0.0f);
		break;
	case GLUT_KEY_RIGHT:
		personaje->SetVel(0.0f, 0.0f);
		break;
	}
}

void Mundo::Genera()
{
	int height;
	int length=0;
	float longitud = 5.0f;//Distancia de cada punto del txt
	//Generamos las plataformas
	switch (ptipo) {
	case CEMENTERIO:
		Plataformas.setTextura("imagenes/GRAVEYARD/png/plataforma.png");
		Suelos.setTextura("imagenes/GRAVEYARD/png/suelo_m.png");
		break;
	case NIEVE:
		Plataformas.setTextura("imagenes/WINTER/png/plataforma.png");
		Suelos.setTextura("imagenes/WINTER/png/suelo_m.png");
		break;
	case BASICO:
		Plataformas.setTextura("imagenes/BASICO/png/plataforma.png");
		Suelos.setTextura("imagenes/BASICO/png/suelo_m.png");
		break;

	}
	std::ifstream a;
	if (ptipo == CEMENTERIO) {
		a.open("CEMENTERIO_.txt");
		Fondo.setTextura("imagenes/GRAVEYARD/png/BG.png");
	}
	else if (ptipo == NIEVE) {
		a.open("NIEVE_.txt");
		Fondo.setTextura("imagenes/WINTER/png/BG.png");
	}
	else if (ptipo == BASICO) {
		a.open("BASICO_.txt");
		Fondo.setTextura("imagenes/BASICO/png/BG.png");
	}

	if (a.is_open()) {
		bool flag = false;
		int contador = 0;
		float altura;//=static_cast<float>(height);
		float x = -longitud;
	//	std::vector<std::string> mapeo;//guarda todo el mapa
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
					case'm':
						listaCoins.agregar(new coin(x, y));
						x += longitud;

						break;
					case'd':
						listaBFuego.agregar(new bonusBolaFuego(x , y));
						x += longitud;

						break;
					case 'c':
						listaCorazones.agregar(new BonusCorazon(x , y));
						x += longitud;

						break;
					case'a':
						listaArmaduras.agregar(new BonusArmadura(x , y));
						x += longitud;

						break;
					case 'p':
						if (contador == 0)
							x += longitud;
						contador++;
						break;
					case '-':
						if (contador) {
							Plataformas.agregar(new pared(x - longitud, y, longitud * contador));
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
						Suelos.agregar(new pared(x, y, longitud));
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
	Fondo.Genera(length, longitud);
}
