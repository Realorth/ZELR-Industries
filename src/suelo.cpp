#include "suelo.h"


void suelo::Genera()
{
	//std::cout << "El máximo del lista es " << lista.size() << " Y el MAX " << MAX_LONG << " Y el de numero " << numero << std::endl;
//Generamos los  primeros  tres
	for (auto i = 0; i < 3; i++) {
		pared* aux = new pared(i * 10.0f - 10.0f, 0, 10.0f);
		lista.push_back(aux);
	}
	//Aleatoria
	srand(time(0));
	for (auto i = 3; i < 60 - 3; i++) {
		auto opcion = rand() % 2;
		if (opcion) {
			lista.push_back(nullptr);
	
		}
		else {
			pared* aux = new pared(i * 10.0f - 10.0f, 0, 10.0f);
			lista.push_back(aux);
		}

	}

	//Generamos los dos últimos bloques
	for (auto i = 60 - 3; i < 60; i++) {
		pared* aux = new pared(i * 10.0f - 10.0f, 0, 10.0f);
		lista.push_back(aux);
	}

}

void suelo::dibuja()
{
	for (auto i : lista) {
		sprite_ListaPared->setPos(i->GetLim1().x - 0.5F, i->GetLim1().y - 5);
		sprite_ListaPared->setSize(i->GetLim2().x - i->GetLim1().x, 5 - 0.45f);
		sprite_ListaPared->draw();
	}
}

