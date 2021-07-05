#include "Mundo.h"
#include "freeglut.h"
#include <math.h>
#include "Interaccion.h"
#include "vector2D.h"
#include <iostream>
#include "esfera.h"
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

void Mundo::setMapa(int l)
{
	ptipo = tipo (l);
}
void Mundo::inicializa()
{
	x_ojo = 0;
	y_ojo = 7.5;
	z_ojo = 30;
	ojo.set(0, 7.5, 30);

	hombre.SetAltura(1.8f);
	hombre.SetColor(255, 0, 0);
	hombre.SetPos(9.5f, 0.1f);
	hombre.SetAcel(0, 0);
	hombre.Setvida(5);
	hombre.Setataque(1);

	fin = false;
	ncoin = 0;//Reestablecer a 0 cada vez que se inicializa el mapa
	
	/*bonusBolaFuego* bF1 = new bonusBolaFuego;
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
	listaCoins.agregar(moneda2);*/
	/*for (int i = 0; i < 6; i++) {
		coin* aux = new coin;
		aux->SetPos(i, i + 1);
		listaCoins.agregar(aux);
	}*/

	llave.SetPos(15, 2);
	Genera();



}
void Mundo::dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
		x_ojo, 7.5, 0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    
	
	hombre.dibuja();
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
	std::string vidaHombre = std::to_string(hombre.Getvida());
	ETSIDI::printxy("Vidas", -13 + hombre.GetPos().x, 17);
	ETSIDI::printxy(vidaHombre.c_str(), -11 + hombre.GetPos().x, 17);

	//Cantidad de armaduras
	ETSIDI::setTextColor(0.5, 0.5, 0.5);
	ETSIDI::setFont("fuentes/Marlboro.ttf", 16);
	std::string armHombre = std::to_string(hombre.GetArmadura());
	ETSIDI::printxy("Armaduras", 2 + hombre.GetPos().x, 17);
	ETSIDI::printxy(armHombre.c_str(), 5 + hombre.GetPos().x, 17);

	//Cantidad de monedas
	ETSIDI::setTextColor(1, 1, 0);
	ETSIDI::setFont("fuentes/Marlboro.ttf", 16);
	std::string s = std::to_string(ncoin);
	ETSIDI::printxy("Monedas", -9 + hombre.GetPos().x, 17);
	ETSIDI::printxy(s.c_str(), -6 + hombre.GetPos().x, 17);

	//Ataque a enemigos
	ETSIDI::setTextColor(1, 1, 1);
	ETSIDI::setFont("fuentes/Marlboro.ttf", 16);
	std::string ataqueHombre = std::to_string(hombre.GetAtaqueEs());
	ETSIDI::printxy("Ataque Especial", -5+hombre.GetPos().x, 17);
	ETSIDI::printxy(ataqueHombre.c_str(), 0 + hombre.GetPos().x, 17);
}

void Mundo::mueve()
{
	disparos.mueve(0.015f);
	hombre.mueve(0.025f);

	//Interaccion de hombre-llaveFin
	if (Interaccion::colision(hombre, llave)) {
		
		fin = true;
		
		if (ptipo != BASICO) {
			hombre.SetPos(9.5f, 0.1f);
		}
		else
			ETSIDI::play("sonidos/Ganar.wav");
		hombre.SetAcel(0, 0);
		
	}

	BonusArmadura* auxA = listaArmaduras.colision(hombre);
	if (auxA != 0) {
		hombre.AumentaArmadura();
		ETSIDI::play("sonidos/Bonus.wav");
		listaArmaduras.eliminar(auxA);
	}

	BonusCorazon* auxC = listaCorazones.colision(hombre);
	if (auxC != 0) {
		hombre.AumentaVida();
		ETSIDI::play("sonidos/Bonus.wav");
		listaCorazones.eliminar(auxC);
	}

	bonusBolaFuego* auxB = listaBFuego.colision(hombre);
	if (auxB != 0) {
		hombre.AumentarAtaqueEs();
		ETSIDI::play("sonidos/Bonus.wav");
		listaBFuego.eliminar(auxB);
	}

	coin* auxc = listaCoins.colision(hombre);
	if (auxc != 0) {
		ETSIDI::play("sonidos/coin.wav");
		ncoin += 1;
		//std::cout << ncoin << "y" << pcoin << std::endl;
		listaCoins.eliminar(auxc);
	}
	if (Interaccion::muertecaida(hombre) == true) {
		caida = true;
		//Limpia las listas para la siguiente partida
	/*	listaArmaduras.destruirContenido();
		listaBFuego.destruirContenido();
		listaCoins.destruirContenido();
		listaCorazones.destruirContenido();*/
		//Personajes con armaduras, vidas por defecto
	}
		


	for (int i = 0; i < disparos.getNumero(); i++) {
		if (disparos[i]->GetLongitud() > 20) {
			disparos.eliminar(disparos[i]);
		}
	}
	x_ojo = hombre.GetPos().x;


	/*Interaccion::rebote(hombre, mapa.GetPlataforma());
	Interaccion::rebote(hombre,mapa.GetSuelo() );*/
	Interaccion::rebote(hombre, Suelos.getSuelo());
	Interaccion::rebote(hombre, Plataformas.getPlataforma());

	

}



void Mundo::tecla(unsigned char key)
{
	hombre.tecla(key);

	switch (key)
	{
	/*case 'd':
		hombre.SetVel(hombre.GetVel().x + 5, hombre.GetVel().y);
		break;
	case 'a':
		hombre.SetVel(hombre.GetVel().x - 5, hombre.GetVel().y);
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
		break;*/
	case ' ':
	{
		disparo* d = new disparo();
		vector2D pos = hombre.GetPos();
		d->SetPos(pos.x, pos.y);
		d->SetOrigen(pos.x, pos.y);
		if (disparos.agregar(d))
		{
 			ETSIDI::play("sonidos/pistola.wav");
            hombre.SetVel(0, 0);
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
		hombre.SetVel(-5.0f, hombre.GetVel().y);
		break;
	case GLUT_KEY_RIGHT:
		hombre.SetVel(5.0f, hombre.GetVel().y);
		break;
	case GLUT_KEY_UP:
	{
        vector2D ace = hombre.GetVel();
		if (ace.y == 0.0f)
			{
			hombre.SetVel(hombre.GetVel().x,10.0f);
		hombre.SetAcel(0, -9.81f);
		}
		break;
	}
		
		
	}
}

void Mundo::teclaEspecialUp(unsigned char key)
{
	
	switch (key)
	{
	case GLUT_KEY_LEFT:
		hombre.SetVel(0.0f, 0.0f);
		break;
	case GLUT_KEY_RIGHT:
		hombre.SetVel(0.0f, 0.0f);
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
	case Mundo::CEMENTERIO:
		Plataformas.setTextura("imagenes/GRAVEYARD/png/plataforma.png");
		Suelos.setTextura("imagenes/GRAVEYARD/png/suelo_m.png");
		break;
	case Mundo::NIEVE:
		Plataformas.setTextura("imagenes/WINTER/png/plataforma.png");
		Suelos.setTextura("imagenes/WINTER/png/suelo_m.png");
		break;
	case Mundo::BASICO:
		Plataformas.setTextura("imagenes/BASICO/png/plataforma.png");
		Suelos.setTextura("imagenes/BASICO/png/suelo_m.png");
		break;

	}
	std::ifstream a;
	if (ptipo == Mundo::CEMENTERIO) {
		a.open("CEMENTERIO_.txt");
		Fondo.setTextura("imagenes/GRAVEYARD/png/BG.png");
	}
	else if (ptipo == Mundo::NIEVE) {
		a.open("NIEVE_.txt");
		Fondo.setTextura("imagenes/WINTER/png/BG.png");
	}
	else if (ptipo == Mundo::BASICO) {
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
					coin* auxiliarCoin;
					bonusBolaFuego* auxiliarBF;
					BonusCorazon* auxiliarCorazon;
					BonusArmadura* auxiliarArmadura;
					switch (m) {
					case'm'://monedas
						auxiliarCoin =new coin();
						auxiliarCoin->SetPos(x, y);
						listaCoins.agregar(auxiliarCoin);
						x += longitud;
						std::cout <<"Numero de monedas en la lista: "<< listaCoins.getNumero()<<"  "<<listaCoins.getNumero()<<std::endl;
						//delete auxiliarCoin;
						break;
					case'd'://disparo especial-bola de fuego
						auxiliarBF = new bonusBolaFuego();
						auxiliarBF->SetPos(x, y);
						listaBFuego.agregar(auxiliarBF);
						x += longitud;
						break;
					case 'c'://corazones
						auxiliarCorazon = new BonusCorazon();
						auxiliarCorazon->SetPos(x, y);
						listaCorazones.agregar(auxiliarCorazon);
						x += longitud;
						break;
					case'a'://armadura
						auxiliarArmadura = new BonusArmadura();
						auxiliarArmadura->SetPos(x, y);
						listaArmaduras.agregar(auxiliarArmadura);
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
