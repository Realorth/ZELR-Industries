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
	listaBonus.destruirContenido();

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
	ojo.set(0, 7.5, 30);

	hombre.SetAltura(1.8f);
	hombre.SetColor(255, 0, 0);
	hombre.SetPos(0, hombre.GetAltura());
	plataforma.SetPos(-5.0f, 9.0f, 5.0f, 9.0f);
	//Problema: no se está dibujando en la posición correcta
	bonusBolaFuego* bF1 = new bonusBolaFuego(5.0f,0.0f);
	//bF1->SetPos(5.0f, 0.0f);
	std::cout << "Bola de Fuego "<<bF1->GetPos().x << " " << bF1->GetPos().y << std::endl;
	listaBonus.agregar(bF1);
	std::cout << listaBonus.getNumero() << std::endl;
	BonusCorazon* cor1 = new BonusCorazon(8.0f,0.0f);
	//cor1->SetPos(8.0f, 0.0f);
	std::cout <<"Corazon" << cor1->GetPos().x << " " << cor1->GetPos().y << std::endl;
	listaBonus.agregar(cor1);
	BonusArmadura* arm1 = new BonusArmadura(0.0f,8.0f);
	//arm1->SetPos(0.0f, 8.0f);
	std::cout << "Armadura" << arm1->GetPos().x << " " << arm1->GetPos().y << std::endl;
	listaBonus.agregar(arm1);

	mapa.Genera();
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
		x_ojo, 7.5, 0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    
	
	hombre.dibuja();
	disparos.dibuja();
	caja.dibuja();
	plataforma.dibuja();


	//glClearColor(1.0, 1.0, 1.0, 1.0);
	

	//glDisable(GL_DEPTH_TEST);

	listaBonus.dibuja();

	//esfera1.dibuja();
	//esfera2.dibuja();
    //disparogrande.dibuja();
	//disparo1.dibuja();
	//esferas.dibuja();
	//esferaspulsantes.dibuja();
	mapa.dibuja();
}

void Mundo::mueve()
{
	disparos.mueve(0.015f);
	hombre.mueve(0.025f);
	//Interaccion::rebote(hombre, caja);
	Interaccion::colision(hombre, plataforma);
	//disparos.colision(caja);
	//disparos.colision(plataforma);

	bonus* auxb = listaBonus.colision(hombre);
	if (auxb != 0) {
		ETSIDI::play("sonidos/Bonus.wav");
		listaBonus.eliminar(auxb);
	}
	disparo* auxd = disparos.colision(caja);
	if (auxd != 0) {
		disparos.eliminar(auxd);
	}
	x_ojo = hombre.GetPos().x;

	//Interaccion entre plataforma y hombre
	Interaccion::rebote(hombre, mapa.GetPlataforma());

	/*disparogrande.mueve(0.025f);
	esferas.mueve(0.025f);
	esferaspulsantes.mueve(0.025f);*/
	//esferas.rebote(); // rebote de las esferas entre sí
	//esferas.rebote(caja); // rebote de las esferas con la caja
	//esferas.rebote(plataforma); // rebote con la plataforma

	
	//esfera* aux = esferas.colision(hombre);
	//if (aux != 0)//si alguna esfera ha chocado
	//{
	//       ETSIDI::play("sonidos/impacto.wav"); //linea agregada 
	//	esferas.eliminar(aux);
	//}
	

	

}



void Mundo::tecla(unsigned char key)
{
	hombre.tecla(key);

	switch (key)
	{
	case 'd':
		x_ojo += 1.0f;
		break;
	case 'a':
		x_ojo -= 1.0f;
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
		hombre.SetVel(-5.0f, hombre.GetVel().y);
		break;
	case GLUT_KEY_RIGHT:
		hombre.SetVel(5.0f, hombre.GetVel().y);
		break;
	case GLUT_KEY_UP:
		hombre.SetVel(hombre.GetVel().x,10.0f);
		hombre.SetAcel(0.0f, -9.81f);
		break;
	}
}

void Mundo::teclaEspecialUp(unsigned char key)
{
	Mundo::teclaEspecial(key);
}
