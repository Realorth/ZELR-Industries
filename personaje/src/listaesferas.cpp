#include "listaesferas.h"
#include "Interaccion.h"

listaesferas::listaesferas()
{
	numero = 0;
	for (int i = 0; i < MAX_ESFERAS; i++)
		lista[i] = 0;
}

listaesferas::~listaesferas()
{}

bool listaesferas::agregar(esfera* e)
{
	bool repite = false;
	for (int i = 0; i < numero; i++)
	{
		if(e == lista[i])
			repite = true;
	}
	if ((numero < MAX_ESFERAS) && (repite == false))
	{
        lista[numero++] = e; // último puesto sin rellenar
		return true; 
	}
		
	return false;
}
void listaesferas::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}

void listaesferas::mueve(float t)
{
	for (int i = 0; i < numero; i++)
		lista[i]->mueve(t);
}
void listaesferas::rebote(caja caja)
{
	for (int i = 0; i < numero; i++)
		Interaccion::rebote(*(lista[i]), caja);
}
void listaesferas::rebote(pared p)
{
	for (int i = 0; i < numero; i++)
		Interaccion::rebote(*(lista[i]), p);
}
void listaesferas::rebote()
{
	for (int i = 0; i < numero-1; i++) 
	{
		for (int j = i + 1; j < numero; j++)
		{
			Interaccion::rebote(*(lista[i]), *(lista[j]));
		}
	}
}
void listaesferas::destruirContenido()
{
	for (int i = 0; i < numero; i++) // destrucción de esferas contenidas
		delete lista[i];
	numero = 0; // inicializa lista
}

void listaesferas::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}
void listaesferas::eliminar(esfera* e)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == e)
		{
			eliminar(i);
			return;
		}
}
esfera* listaesferas::colision(hombre& h)
{
	for (int i = 0; i < numero; i++)
	{
		if (Interaccion::colision(*(lista[i]), h))
			return lista[i];
	}
	return 0; //no hay colisión

}
esfera* listaesferas::operator [](int i)
{
	if (i >= numero)//si me paso, devuelvo la ultima
		i = numero - 1;
	if (i < 0) //si el indice es negativo, devuelvo la primera
		i = 0;
	return lista[i];

}