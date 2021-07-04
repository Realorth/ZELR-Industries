#include "suelo.h"

void suelo::destruirContenido()
{
	for (auto i : floor)
		delete i;
	floor.clear();
}

void suelo::Genera()
{
	//std::cout << "El máximo del floor es " << floor.size() << " Y el MAX " << MAX_LONG << " Y el de numero " << numero << std::endl;
//Generamos los  primeros  tres
	for (auto i = 0; i < 3; i++) {
		pared* aux = new pared(i * 10.0f - 10.0f, 0, 10.0f);
		floor.push_back(aux);
	}
	//Aleatoria
	srand(time(0));
	for (auto i = 3; i < 60 - 3; i++) {
		auto opcion = rand() % 2;
		if (opcion) {
			floor.push_back(nullptr);
	
		}
		else {
			pared* aux = new pared(i * 10.0f - 10.0f, 0, 10.0f);
			floor.push_back(aux);
		}

	}

	//Generamos los dos últimos bloques
	for (auto i = 60 - 3; i < 60; i++) {
		pared* aux = new pared(i * 10.0f - 10.0f, 0, 10.0f);
		floor.push_back(aux);
	}

}

void suelo::dibuja()
{
	for (auto i : floor) {
		Suelo->setPos(i->GetLim1().x - 0.5F, i->GetLim1().y - 5);
		Suelo->setSize(i->GetLim2().x - i->GetLim1().x, 5 - 0.45f);
		Suelo->draw();
	}
}

void suelo::agregar(pared* a)
{
	floor.push_back(a);
}

void suelo::setTextura(const char* a)
{
	delete Suelo;
	Suelo = new ETSIDI::Sprite(a);
}

void suelo::setTextura(std::string a)
{
	delete Suelo;
	Suelo = new ETSIDI::Sprite(a.c_str());
}
