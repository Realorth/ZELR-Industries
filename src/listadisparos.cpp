#include "listadisparos.h"
#include "Interaccion.h"


listadisparos::listadisparos()
{
	numero = 0;
	for (int i = 0; i < MAX_DISPAROS; i++)
		lista[i] = 0;// null_ptr
}
listadisparos::~listadisparos()
{}
bool listadisparos::agregar(disparo* d)
{
	bool repite = false;
		for (int i = 0; i < numero; i++)
		{
			if (d == lista[i])
				repite = true;
		}
		if ((numero < MAX_DISPAROS) && (repite == false))
		{
			lista[numero++] = d; // último puesto sin rellenar
			return true;
		}

		return false;
}

void listadisparos::destruirContenido()
{
	for (int i = 0; i < numero; i++) // destrucción de esferas contenidas
		delete lista[i];
	numero = 0; // inicializa lista
}
void listadisparos::mueve(float t)
{
	for (int i = 0; i < numero; i++)
		lista[i]->mueve(t);
}
void listadisparos::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}
void listadisparos::colision(pared& p)
{
	for (int i = 0; i < numero; i++)
		if (Interaccion::colision(*(lista[i]), p))
			lista[i]->SetPos(lista[i]->posicion.x, p.limite1.y);

}

void listadisparos::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}
void listadisparos::eliminar(disparo* d)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == d)
		{
			eliminar(i);
			return;
		}
}

disparo* listadisparos::operator[](int i)
{
	if (i > numero)//si me paso, devuelvo el ultimo
		i = numero - 1;
	if (i < 0)
		i = 0;//Si es negativo, devuelve el primero

	return lista[i];
}
