#include "Interaccion.h"
#include <math.h>
#include <iostream>

bool Interaccion::rebote(esfera& e, pared p)
{
	vector2D dir;
	float dif = p.distancia(e.posicion, &dir) - e.radio;
	if (dif <= 0.0f)
	{
		vector2D v_inicial = e.velocidad;
		e.velocidad = v_inicial - dir * 2.0 * (v_inicial * dir);
		e.posicion = e.posicion - dir * dif;
		return true;
	}
	return false;
	}
void Interaccion::rebote(esfera& e, caja c) 
{
	rebote(e, c.techo);
	rebote(e, c.suelo);
	rebote(e, c.pared_izq);
	rebote(e, c.pared_dcha);
}
bool Interaccion::rebote(esfera& e, esfera& e2)
{
	//Vector que une los centros
	vector2D dif = e2.posicion - e.posicion;
	float d = dif.modulo();
	float dentro = d - (e.radio + e2.radio);

	if (dentro < 0.0f)//si hay colision
	{
		//El modulo y argumento de la velocidad de la pelota1
		float v1 = e.velocidad.modulo();
		float ang1 = e.velocidad.argumento();

		//El modulo y argumento de la velocidad de la pelota2
		float v2 = e2.velocidad.modulo();
		float ang2 = e2.velocidad.argumento();

		//el argumento del vector que une los centros
		float angd = dif.argumento();

		//Separamos las esferas, lo que se han incrustado
		//la mitad cada una
		vector2D desp(dentro / 2 * cos(angd), dentro / 2 * sin(angd));
		e.posicion = e.posicion + desp;
		e2.posicion = e2.posicion - desp;

		angd = angd - 3.14159f / 2;//la normal al choque

		//El angulo de las velocidades en el sistema relativo antes del choque
		float th1 = ang1 - angd;
		float th2 = ang2 - angd;

		//Las componentes de las velocidades en el sistema relativo ANTES del choque
		float u1x = v1 * cos(th1);
		float u1y = v1 * sin(th1);
		float u2x = v2 * cos(th2);
		float u2y = v2 * sin(th2);

		//Las componentes de las velocidades en el sistema relativo DESPUES del choque
		//la componente en X del sistema relativo no cambia
		float v1x = u1x;
		float v2x = u2x;

		//en el eje Y, rebote elastico
		float m1 = e.radio;
		float m2 = e2.radio;
		float py = m1 * u1y + m2 * u2y;//Cantidad de movimiento inicial ejey
		float ey = m1 * u1y * u1y + m2 * u2y * u2y;//Energia cinetica inicial ejey

		//los coeficientes y discriminante de la ecuacion cuadrada
		float a = m2 * m2 + m1 * m2;
		float b = -2 * py * m2;
		float c = py * py - m1 * ey;
		float disc = b * b - 4 * a * c;
		if (disc < 0)disc = 0;

		//las nuevas velocidades segun el eje Y relativo
		float v2y = (-b + sqrt(disc)) / (2 * a);
		float v1y = (py - m2 * v2y) / m1;

		//Modulo y argumento de las velocidades en coordenadas absolutas
		float modv1, modv2, fi1, fi2;
		modv1 = sqrt(v1x * v1x + v1y * v1y);
		modv2 = sqrt(v2x * v2x + v2y * v2y);
		fi1 = angd + atan2(v1y, v1x);
		fi2 = angd + atan2(v2y, v2x);

		//Velocidades en absolutas despues del choque en componentes
		e.velocidad.x = modv1 * cos(fi1);
		e.velocidad.y = modv1 * sin(fi1);
		e2.velocidad.x = modv2 * cos(fi2);
		e2.velocidad.y = modv2 * sin(fi2);
	}
	return false;
}

bool Interaccion::colision(esfera e, hombre h)
{
	vector2D pos = h.GetPos(); //la posicion de la base del hombre
	pos.y += h.GetAltura() / 2.0f; //posicion del centro
	float distancia = (e.posicion - pos).modulo();
	if (distancia < e.radio)
		return true;
	return false;
}

bool Interaccion::colision(disparo d, pared p)
{
	vector2D pos =d. GetPos();
	if ((pos.y >= p.limite1.y)&& (pos.x > p.limite1.x)&&(pos.x < p.limite2.x))
		return true;
	
	return false;
}

//bool Interaccion::colision(disparo d, caja c)
//{
//	vector2D pos = d.GetPos();
//	if (pos.y >= c.techo.limite1.y)
//		return true;
//
//	return false;
//}

void Interaccion::colision(hombre& h, pared p)
{

	//vector2D dir;
	vector2D v_inicial = h.velocidad;
	float ymin = p.limite1.y;
	//float xmax = p.limite2.x;
	//float dif = p.distancia(h.posicion, &dir) - h.altura;
	

	if ((h.posicion.x < p.limite2.x) && (h.posicion.x > p.limite1.x)) {

		if (h.posicion.y == ymin ) {//problema:cuando salta encima de la plataforma, rebota???
			h.posicion.y = ymin + h.altura / 2;
			h.velocidad.y = 0;
		}
		if ((h.posicion.y + h.altura) > ymin &&h.posicion.y<ymin) {
			h.velocidad.y=  v_inicial.y * -1;
		}
		
	}

	
	
}

bool Interaccion::colision(hombre h, BonusArmadura b)
{
	vector2D pos = h.GetPos(); //la posicion de la base del hombre
	vector2D posBonus = b.GetPos();
	pos.y += h.GetAltura() / 2.0f; //posicion del centro
	float distancia = (posBonus - pos).modulo();
	if (distancia < 1.0f)
		return true;
	return false;

}

bool Interaccion::colision(hombre h, bonusBolaFuego b)
{
	vector2D pos = h.GetPos(); //la posicion de la base del hombre
	vector2D posBonus = b.GetPos();
	pos.y += h.GetAltura() / 2.0f; //posicion del centro
	float distancia = (posBonus - pos).modulo();
	if (distancia < 1.0f)
		return true;
	return false;

}

bool Interaccion::colision(hombre h, BonusCorazon b)
{
	vector2D pos = h.GetPos(); //la posicion de la base del hombre
	vector2D posBonus = b.GetPos();
	pos.y += h.GetAltura() / 2.0f; //posicion del centro
	float distancia = (posBonus - pos).modulo();
	if (distancia < 1.0f)
		return true;
	return false;

}

bool Interaccion::colision(hombre h, coin c)
{
	vector2D pos = h.GetPos(); //la posicion de la base del hombre
	vector2D posMoneda = c.GetPos();
	pos.y += h.GetAltura() / 2.0f; //posicion del centro
	float distancia = (posMoneda - pos).modulo();
	if (distancia < 1.0f)
		return true;
	return false;

}

bool Interaccion::colision(disparo d,caja c)
{
	vector2D posDisparo = d.GetPos();

	if (posDisparo.x > c.pared_izq.limite1.x || posDisparo.x>c.pared_izq.limite2.x)
		return true;
	return false;	

}
void Interaccion::rebote(hombre& h, caja c)
{
	float xmax = c.suelo.limite2.x;
	float xmin = c.suelo.limite1.x;
	float ymin = c.suelo.limite1.y;
	if (h.posicion.y < ymin)
		h.posicion.y = ymin;
	
	if (h.posicion.x > xmax)h.posicion.x = xmax;
	if (h.posicion.x < xmin)h.posicion.x = xmin;
    

}
