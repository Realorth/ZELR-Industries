#include "ListaAcolitos.h"


Enemigos* ListaAcolitos::setsentido(hombre& h) {
	for (int i = 0; i < numero; i++)
	{
		if (Interaccion::deteccion(h, *(lista[i])))
			lista[i]->SetSentido(1);							//mirar� a la derecha
		else 
			lista[i]->SetSentido(-1);							//mirar� a la izquierda
	}
	return 0;
}