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
	x_ojo = 9.5f;
	personaje->SetPos(x_ojo, 0.1f);
	personaje->SetAcel(0,-9.81);
	wolfy.SetPos(0, 9);														//---------------------
}

void Mundo::setMapa(int l)
{
	ptipo = tipo (l);
}
void Mundo::inicializa()
{
	x_ojo = 9.5;
	y_ojo = 7.5;
	z_ojo = 30;
	ojo.set(9.5, 7.5, 30);
	
	if(EleccionPersonaje==0)
		personaje = new Pistolero();
	else if(EleccionPersonaje==1)
		personaje = new arquero();
	else if(EleccionPersonaje==2)
		personaje = new mago();
	
	personaje->SetAltura(1.8f);
	//personaje->SetPos(9.5f, personaje->GetAltura());					IRRELEVANTE
	personaje->SetAcel(0, -9.81);
	personaje->Setvida(5);
	personaje->Setataque(1);
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	wolfy.SetPos(140.5f, 2.0f);								//es irrelevante
	wolfy.SetVel(1, 0);
	wolfy.SetAcel(0, -9.81);
	wolfy.SetVida(2);
	wolfy.SetAtaque(1);
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	fin = false;
	ncoin = 0;//Reestablecer a 0 cada vez que se inicializa el mapa
	
	
	Genera();
	llave.SetPos(Suelos.getSuelo().back()->GetLim1().x, 2);


}
void Mundo::dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
		x_ojo, 7.5, 0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    
	
	// Se dibujan todos las instancias
	personaje->dibuja();
	llave.dibuja();
	// Se dibujan todas las instancias de listas
	Suelos.dibuja();
	Fondo.dibuja();
	Plataformas.dibuja();
	disparos.dibuja();

	//Se dibuja las listas de bonus
	listaCoins.dibuja();
	listaArmaduras.dibuja();
	listaCorazones.dibuja();
	listaBFuego.dibuja();

	//Cantidad de vidas
	ETSIDI::setTextColor(1, 0, 0);
	ETSIDI::setFont("fuentes/Marlboro.ttf", 16);
	std::string vidaHombre = std::to_string(personaje->Getvida());
	ETSIDI::printxy("Vidas", -13 + x_ojo, 17);
	ETSIDI::printxy(vidaHombre.c_str(), -11 + x_ojo, 17);

	//Cantidad de armaduras
	ETSIDI::setTextColor(0.5, 0.5, 0.5);
	ETSIDI::setFont("fuentes/Marlboro.ttf", 16);
	std::string armHombre = std::to_string(personaje->GetArmadura());
	ETSIDI::printxy("Armaduras", 2 + x_ojo, 17);
	ETSIDI::printxy(armHombre.c_str(), 5 + x_ojo, 17);

	//Cantidad de monedas
	ETSIDI::setTextColor(1, 1, 0);
	ETSIDI::setFont("fuentes/Marlboro.ttf", 16);
	std::string s = std::to_string(ncoin);
	ETSIDI::printxy("Monedas", -9 + x_ojo, 17);
	ETSIDI::printxy(s.c_str(), -6 + x_ojo, 17);

	//Ataque a enemigos
	ETSIDI::setTextColor(1, 1, 1);
	ETSIDI::setFont("fuentes/Marlboro.ttf", 16);
	std::string ataqueHombre = std::to_string(personaje->GetAtaqueEs());
	ETSIDI::printxy("Ataque Especial", -5+ x_ojo, 17);
	ETSIDI::printxy(ataqueHombre.c_str(), 0 + x_ojo, 17);
	
	wolfy.dibuja();
}

void Mundo::mueve()
{
	disparos.mueve(0.015f);
	personaje->mueve(0.025f);
	
	wolfy.mueve(0.025f);
	wolfy.reacciona();
	wolfy.gira();

	//Interaccion de hombre-llaveFin
	if (Interaccion::colision(*personaje, llave)) {

		fin = true;

		if (ptipo != BASICO) {
			personaje->SetPos(9.5f, 0.1f);
		}
		else
			ETSIDI::play("sonidos/Ganar.wav");
		personaje->SetAcel(0, 0);

	}
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

	}

	bonusBolaFuego* auxB = listaBFuego.colision(*personaje);
	if (auxB != 0) {
		personaje->AumentarAtaqueEs();
		ETSIDI::play("sonidos/Bonus.wav");
		listaBFuego.eliminar(auxB);
	}

	// Interacción y eliminación de una moneda con el jugador
	coin* auxc = listaCoins.colision(*personaje);
	if (auxc != 0) {
		ETSIDI::play("sonidos/coin.wav");
		ncoin += 1;
		//std::cout << ncoin << "y" << pcoin << std::endl;
		listaCoins.eliminar(auxc);
	}

	// Muerte del jugador por caida
	if (Interaccion::muertecaida(*personaje) ==true )
		caida = true;


	for (int i = 0; i < disparos.getNumero(); i++) {
		if (disparos[i]->GetLongitud() > 20) {
			disparos.eliminar(disparos[i]);
		}
	}
	
	//Cuando el personaje se va hacia los bordes, la camara no se mueve
	if (personaje->GetPos().x > 9.5 && personaje->GetPos().x < 280)
		x_ojo = personaje->GetPos().x;


	Interaccion::rebote(*personaje, Suelos.getSuelo());
	Interaccion::rebote(*personaje, Plataformas.getPlataforma());
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Interaccion::rebote(wolfy, Suelos.getSuelo());
	Interaccion::rebote(wolfy, Plataformas.getPlataforma());
	Interaccion::proximidad(*personaje, wolfy);
	Interaccion::colision(*personaje, wolfy);
	/*ListaPerros::reaccion(hombre & h);
	ListaPerros::patrulla(pared & p);*/

}



void Mundo::tecla(unsigned char key)
{

	switch (key)
	{
	/*
	case 'd':
	case 'D':
		personaje->SetVel(personaje->GetVel().x + 5, personaje->GetVel().y);
		break;
	case 'a':
	case 'A':
		personaje->SetVel(personaje->GetVel().x - 5, personaje->GetVel().y);
		break;*/
	/*case'w' :
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
	case 'd':
	case 'D':
		if (personaje->GetAtaqueEs() > 0) {
			disparo1 = new disparoespecial(personaje->GetPos(),personaje->GetPos());
			//disparo1->SetOrigen(personaje->GetPos().x, personaje->GetPos().y);
			if (sentidoHombre)
				disparo1->SetAcel(9.8, 0);//Disparo hacia la derecha
			else
				disparo1->SetAcel(-9.8, 0);//Disparo hacia la izquierda
			if (disparos.agregar(disparo1))
			{
				ETSIDI::play("sonidos/BolaFuego.wav");
				personaje->DisminuirAtaqueEs();
			}
			else delete disparo1;
			
			}
			
		break;
	case ' ':
		{
		if (EleccionPersonaje == 0)
			disparo1 = new bala(personaje->GetPos(), personaje->GetPos());
		else if (EleccionPersonaje == 1)
			disparo1 = new flecha(personaje->GetPos(), personaje->GetPos());
		else if (EleccionPersonaje == 2)
			disparo1 = new Magia(personaje->GetPos(), personaje->GetPos());

		if (sentidoHombre)
			disparo1->SetAcel(9.8, 0);//Disparo hacia la derecha
		else
			disparo1->SetAcel(-9.8, 0);//Disparo hacia la izquierda
		if (disparos.agregar(disparo1))
		{
 			if (EleccionPersonaje == 0)
				ETSIDI::play("sonidos/pistola.wav");
			else if (EleccionPersonaje == 1)
				ETSIDI::play("sonidos/flecha.wav");
			else if (EleccionPersonaje == 2)
				ETSIDI::play("sonidos/magia.wav");
			personaje->SetVel(0, 0);
		}

		else delete disparo1;
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
		sentidoHombre = false;
		break;
	case GLUT_KEY_RIGHT:
		personaje->SetVel(5.0f, personaje->GetVel().y);
		sentidoHombre =true;
		break;
	case GLUT_KEY_UP:
        	vector2D ace = personaje->GetVel();
		if (ace.y == 0.0f)
		{
			personaje->SetVel(personaje->GetVel().x,10.0f);
			personaje->SetAcel(0, -9.81f);
		}
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
	int length = 0;
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
				
				float y = 20.0f * altura / height;
				if (y > 0) {

					switch (m) {
					case'm'://monedas
				
						listaCoins.agregar(new coin(x,y));
						x += longitud;
						std::cout << "Numero de monedas en la lista: " << listaCoins.getNumero() << "  " << listaCoins.getNumero() << std::endl;
						//delete auxiliarCoin;
						break;
					case'd'://disparo especial-bola de fuego
					
						listaBFuego.agregar(new bonusBolaFuego(x,y));
						x += longitud;
						break;
					case 'c'://corazones

						listaCorazones.agregar(new BonusCorazon(x,y));
						x += longitud;
						break;
					case'a'://armadura

						listaArmaduras.agregar(new BonusArmadura(x,y));
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
