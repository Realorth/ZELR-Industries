#include "ListaEnemigos.h"

ListaEnemigos::ListaEnemigos()
{
	numero = 0;//Se vacía la lista
	for (int i = 0; i < MAX_ENEMIGOS; i++)
		lista[i] = 0;//limpia todos los punteros de la lista
}

ListaEnemigos::~ListaEnemigos() {}

bool ListaEnemigos::agregar(Enemigos* e)
{
	bool comprueba = false;
	for (int i = 0; i < numero; i++) {
		if (e == lista[i])
			comprueba = true;//La direccion ya existe
	}

	//Se agrega el bonus si hay espacio en la lista y si comprueba es false
	if ((numero < MAX_ENEMIGOS) && (comprueba == false)) {
		lista[numero++] = e;//Se rellena en el ultimo puesto y aumenta en una und el contador
		return true;
	}
	return false;
}

void ListaEnemigos::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();//Se accede al metodo mediante flecha, porque es un puntero
}

void ListaEnemigos::mueve(float t)
{
	for (int i = 0; i < numero; i++) 
		lista[i]->mueve(t);
	
}

void ListaEnemigos::destruirContenido()
{
	//destruccion de bonus contenidos
	for (int i = 0; i < numero; i++)
		delete lista[i];
	//inicializa la lista
	numero = 0;
}
void ListaEnemigos::eliminar(int index) {
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}
void ListaEnemigos::eliminar(Enemigos* e)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == e) {
			eliminar(i);
			return;
		}
}


Enemigos* ListaEnemigos::operator[](int i)
{

	if (i > numero)						//si me paso, devuelvo el ultimo
		i = numero - 1;
	if (i < 0)
		i = 0;							//Si es negativo, devuelve el primero

	return lista[i];
}

void ListaEnemigos::rebote(std::vector<pared*> d)
{
	for (int i = 0; i < numero; i++)
		Interaccion::rebote(*lista[i], d);
}

Enemigos* ListaEnemigos::colision(disparo& d)				// supone que debe ser una interacción de hombre, dado que es el unico que se modificaría?
{
	for (int i = 0; i < numero; i++)
	{
		//if ((Interaccion::colision(d, *lista[i])))
			//return lista[i];
	}
	return 0; //no hay colisión
}
