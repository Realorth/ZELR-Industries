#include "ListaCoins.h"



ListaCoins::ListaCoins()
{
	numero = 0;//Se vacía la lista
	for (int i = 0; i < MAX_MONEDAS; i++)
		lista[i] = 0;//limpia todos los punteros de la lista
}

ListaCoins::~ListaCoins()
{
}

bool ListaCoins::agregar(coin* c)
{
	bool comprueba = false;
	for (int i = 0; i < numero; i++) {
		if (c == lista[i])
			comprueba = true;//La direccion ya existe
	}

	//Se agrega el bonus si hay espacio en la lista y si comprueba es false
	if ((numero < MAX_MONEDAS) && (comprueba == false)) {
		lista[numero++] = c;//Se rellena en el ultimo puesto y aumenta en una und el contador
		return true;
	}
	return false;
}

void ListaCoins::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();//Se accede al metodo mediante flecha, porque es un puntero
}

void ListaCoins::destruirContenido()
{
	//destruccion de bonus contenidos
	for (int i = 0; i < numero; i++)
		delete lista[i];
	//inicializa la lista
	numero = 0;
}
void ListaCoins::eliminar(int index) {
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}
void ListaCoins::eliminar(coin* c)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == c) {
			eliminar(i);
			return;
		}
}

coin* ListaCoins::colision(hombre& h)
{
	for (int i = 0; i < numero; i++)
	{
		if (Interaccion::colision(h, *(lista[i])))
			return lista[i];
		
	}
	return 0; //no hay colisión
}



coin* ListaCoins::operator[](int i)
{

	if (i > numero)//si me paso, devuelvo el ultimo
		i = numero - 1;
	if (i < 0)
		i = 0;//Si es negativo, devuelve el primero

	return lista[i];
}