#include "ListaBolaFuego.h"


ListaBolaFuego::ListaBolaFuego()
{
	numero = 0;//Se vacía la lista
	for (int i = 0; i < MAX_BOLASFUEGO; i++)
		lista[i] = 0;//limpia todos los punteros de la lista
}

ListaBolaFuego::~ListaBolaFuego()
{
}

bool ListaBolaFuego::agregar(bonusBolaFuego* b)
{
	bool comprueba = false;
	for (int i = 0; i < numero; i++) {
		if (b == lista[i])
			comprueba = true;//La direccion ya existe
	}

	//Se agrega el bonus si hay espacio en la lista y si comprueba es false
	if ((numero < MAX_BOLASFUEGO) && (comprueba == false)) {
		lista[numero++] = b;//Se rellena en el ultimo puesto y aumenta en una und el contador
		return true;
	}
	return false;
}

void ListaBolaFuego::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();//Se accede al metodo mediante flecha, porque es un puntero
}

void ListaBolaFuego::destruirContenido()
{
	//destruccion de bonus contenidos
	for (int i = 0; i < numero; i++)
		delete lista[i];
	//inicializa la lista
	numero = 0;
}
void ListaBolaFuego::eliminar(int index) {
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}
void ListaBolaFuego::eliminar(bonusBolaFuego* b)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == b) {
			eliminar(i);
			return;
		}
}

bonusBolaFuego* ListaBolaFuego::colision(hombre& h)
{
	for (int i = 0; i < numero; i++)
	{
		if (Interaccion::colision(h, *(lista[i])))
			return lista[i];

	}
	return 0; //no hay colisión
}



bonusBolaFuego* ListaBolaFuego::operator[](int i)
{

	if (i > numero)//si me paso, devuelvo el ultimo
		i = numero - 1;
	if (i < 0)
		i = 0;//Si es negativo, devuelve el primero

	return lista[i];
}