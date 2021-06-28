#include "Mundo.h"
#include "freeglut.h"
#include <math.h>
#include "Interaccion.h"
#include "vector2D.h"
#include <iostream>
#include "esfera.h"


Mundo:: ~ Mundo() 
{
	esferas.destruirContenido();
	disparos.destruirContenido();
	//listaBonus.destruirContenido();
	listaCoins.destruirContenido();
	listaArmaduras.destruirContenido();
	listaCorazones.destruirContenido();
	listaBFuego.destruirContenido();
}
void Mundo::rotarOjo()
{
	float dist=sqrt(x_ojo*x_ojo+z_ojo*z_ojo);
	float ang=atan2(z_ojo,x_ojo);
	ang+=0.05f;
	x_ojo=dist*cos(ang);
	z_ojo=dist*sin(ang);
}

void Mundo::inicializa()
{
	x_ojo = 0;
	y_ojo = 7.5;
	z_ojo = 30;

	impacto = false;
	hombre.SetAltura(1.8f);
	hombre.SetColor(255, 0, 0);
	hombre.Setvida(5);
	hombre.Setataque(1);
	plataforma.SetPos(-5.0f, 9.0f, 5.0f, 9.0f);

	bonusBolaFuego* bF1 = new bonusBolaFuego;
	bF1->SetPos(5.0f, 0.0f);
	std::cout << bF1->GetPos().x << " " << bF1->GetPos().y << std::endl;
	listaBFuego.agregar(bF1);
	std::cout << listaBFuego.getNumero() << std::endl;
	BonusCorazon* cor1 = new BonusCorazon;
	cor1->SetPos(8.0f, 0.0f);
	std::cout << cor1->GetPos().x << " " << cor1->GetPos().y << std::endl;
	listaCorazones.agregar(cor1);
	BonusArmadura* arm1 = new BonusArmadura;
	arm1->SetPos(0.0f, 2.0f);
	std::cout << arm1->GetPos().x << " " << arm1->GetPos().y << std::endl;
	listaArmaduras.agregar(arm1);
	coin* moneda1 = new coin;
	moneda1->SetPos(-3.0f, 0.0f);
	std::cout << moneda1->GetPos().x << " " << moneda1->GetPos().y << std::endl;
	listaCoins.agregar(moneda1);
	coin* moneda2 = new coin;
	moneda2->SetPos(-3.0f, 3.0f);
	std::cout << moneda2->GetPos().x << " " << moneda2->GetPos().y << std::endl;
	listaCoins.agregar(moneda2);



	//esfera* e1 = new esfera(1, 2, 4, 5, 15); // esfera1
	//e1->SetColor(150, 150, 150);
	//esferas.agregar(e1); // esfera1 a la lista
	//esfera* e2 = new esfera(2, -2, 4, -5, 15); // esfera2
	//e2->SetColor(0, 155, 155);
	//esferas.agregar(e2);
	//
	//for (int i = 0; i < 6; i++)
	//{
	//	esfera* aux = new esfera;
	//	aux->SetPos(i, 1 + i);
	//	aux->SetVel(i, i);
	//	aux->SetRadio(0.75 + i * 0.25);
	//	esferas.agregar(aux); // agregar a la lista
	//}

	//for (int i = 0; i < esferas.getNumero(); i++)
	//	if ((esferas[i]->GetPos()).y > 11)
	//		esferas[i]->SetColor(255, 0, 0);
	//	else
	//		esferas[i]->SetColor(255, 255, 255);



}
void Mundo::dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
			0.0, 6.5, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    
	
	hombre.dibuja();
	disparos.dibuja();
	caja.dibuja();
	plataforma.dibuja();
	//listaBonus.dibuja();
	listaCoins.dibuja();
	listaArmaduras.dibuja();
	listaCorazones.dibuja();
	listaBFuego.dibuja();

	//Cantidad de vidas
	ETSIDI::setTextColor(1, 0, 0);
	ETSIDI::setFont("fuentes/Marlboro.ttf", 16);
	std::string vidaHombre = std::to_string(hombre.Getvida());
	ETSIDI::printxy("Vidas", -10, 16);
	ETSIDI::printxy(vidaHombre.c_str(), -8, 16);

	//Cantidad de armaduras
	ETSIDI::setTextColor(1, 0, 0);
	ETSIDI::setFont("fuentes/Marlboro.ttf", 16);
	std::string armHombre = std::to_string(hombre.GetArmadura());
	ETSIDI::printxy("Armaduras", -10, 14);
	ETSIDI::printxy(armHombre.c_str(), -7, 14);

	//Cantidad de monedas
	ETSIDI::setTextColor(1, 1, 0);
	ETSIDI::setFont("fuentes/Marlboro.ttf", 16);
	std::string s = std::to_string(ncoin);
	ETSIDI::printxy("Monedas", -6, 16);
	ETSIDI::printxy(s.c_str(), -3.5, 16);

	//Ataque a enemigos
	ETSIDI::setTextColor(1, 1, 1);
	ETSIDI::setFont("fuentes/Marlboro.ttf", 16);
	std::string ataqueHombre = std::to_string(hombre.GetAtaque());
	ETSIDI::printxy("Ataque", -2, 16);
	ETSIDI::printxy(ataqueHombre.c_str(), 0, 16);
}

void Mundo::mueve()
{
	disparos.mueve(0.015f);
	hombre.mueve(0.025f);
	Interaccion::rebote(hombre, caja);
	Interaccion::colision(hombre, plataforma);
	//disparos.colision(caja);
	//disparos.colision(plataforma);

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
		impacto=true;
	}

	bonusBolaFuego* auxB = listaBFuego.colision(hombre);
	if (auxB != 0) {
		hombre.AumentaAtaque();
		ETSIDI::play("sonidos/Bonus.wav");
		listaBFuego.eliminar(auxB);
	}

	coin* auxc = listaCoins.colision(hombre);
	if (auxc != 0) {
		ETSIDI::play("sonidos/coin.wav");
		ncoin += 1;
		std::cout << ncoin << "y" << pcoin << std::endl;
		listaCoins.eliminar(auxc);
	}

	disparo* auxd = disparos.colision(caja);
	if (auxd != 0) {
		disparos.eliminar(auxd);
	}


}



void Mundo::tecla(unsigned char key)
{
	hombre.tecla(key);

	switch (key)
	{
	/*case '1':
		esferas.agregar(new esfera(0.5f, 0, 10));
		break;
	case '2':
		esferas.agregar(new esfera(1.0f, 0, 10));
		break;
	case '3':
		esferas.agregar(new esfera(1.5f, 0, 10));
		break;
	case '4':
		esferas.agregar(new esfera(2.0f, 0, 10));
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
	//case 'j':
	//{
	//	disparoespecial* d = new disparoespecial();
	//	vector2D pos = hombre.GetPos();
	//	d->SetPos(pos.x, pos.y);
	//	d->SetOrigen(pos.x, pos.y);
	//	if (disparos.agregar(d))
	//	{
	//		ETSIDI::play("sonidos/disparo.WAV");
	//		hombre.SetVel(0, 0);
	//	}

	//	else delete d;
	///	break;
	//}
	}

}

void Mundo::teclaEspecial(unsigned char key)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		hombre.SetVel(-5.0f, 0.0f);
		break;
	case GLUT_KEY_RIGHT:
		hombre.SetVel(5.0f, 0.0f);
		break;
	case GLUT_KEY_UP:
		hombre.SetVel(0.0f,10.0f);
		hombre.SetAcel(0.0f, -9.81f);
		break;
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
