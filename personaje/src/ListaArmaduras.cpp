#include "ListaArmaduras.h"


ListaArmaduras::ListaArmaduras()
{
	numero = 0;//Se vacía la lista
	for (int i = 0; i < MAX_ARMADURAS; i++)
		lista[i] = 0;//limpia todos los punteros de la lista
}

ListaArmaduras::~ListaArmaduras()
{
}

bool ListaArmaduras::agregar(BonusArmadura* b)
{
	bool comprueba = false;
	for (int i = 0; i < numero; i++) {
		if (b == lista[i])
			comprueba = true;//La direccion ya existe
	}

	//Se agrega el bonus si hay espacio en la lista y si comprueba es false
	if ((numero < MAX_ARMADURAS) && (comprueba == false)) {
		lista[numero++] = b;//Se rellena en el ultimo puesto y aumenta en una und el contador
		return true;
	}
	return false;
}

void ListaArmaduras::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();//Se accede al metodo mediante flecha, porque es un puntero
}

void ListaArmaduras::destruirContenido()
{
	//destruccion de bonus contenidos
	for (int i = 0; i < numero; i++)
		delete lista[i];
	//inicializa la lista
	numero = 0;
}
void ListaArmaduras::eliminar(int index) {
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}
void ListaArmaduras::eliminar(BonusArmadura* b)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == b) {
			eliminar(i);
			return;
		}
}

BonusArmadura* ListaArmaduras::colision(hombre& h)
{
	for (int i = 0; i < numero; i++)
	{
		if (Interaccion::colision(h, *(lista[i])))
			return lista[i];

	}
	return 0; //no hay colisión
}



BonusArmadura* ListaArmaduras::operator[](int i)
{

	if (i > numero)//si me paso, devuelvo el ultimo
		i = numero - 1;
	if (i < 0)
		i = 0;//Si es negativo, devuelve el primero

	return lista[i];
}