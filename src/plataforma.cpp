#include "plataforma.h"
#include<random>
#include<algorithm>
#include<time.h>
#include<iostream>
void plataforma::destruirContenido()
{
	for (auto i : platform)
		delete i;
	platform.clear();
}

void plataforma::Genera()
{
	//este  código se encarga de generar las plataformas
	// de  manera coherente
	std::random_device rd;//genera un número random, útil para las semillas
	std::mt19937 gen(rd());//se obtiene la  generación de los números para las distribuciones
	std::normal_distribution<> distancia_entre_plataformas(3.6f, 0.1f);//distribución para la diferencia de alturas de las plataformas
	std::uniform_int_distribution<> sube_baja(0, 1);// distribución para sí sube o baja la siguiente plataforma

	// se tiene que generar forzadamente la primera plataforma para  conseguir coherencia
	
	pared* auxi = new pared(-10.0f, 3.0f, 10.0f);
	platform.push_back(auxi);
	std::srand(time(nullptr));

	for (auto i = 1; i < 60 - 3; i++) {

		// se crea la plataforma
			// primero se cargan los parámetros aleatorios
		auto dist = distancia_entre_plataformas(gen);
		auto op = sube_baja(gen);
		// se crean las paredes
		pared* aux = new pared(i * platform[i - 1]->GetLenght() + platform[0]->GetLim1().x, dist, platform[i - 1]->GetLenght());
		auto l1x = aux->GetLim1().x;
		auto l2x = aux->GetLim2().x;
		auto y = platform[i - 1]->GetLim1().y;
		// sí se está en alguno de los límites se arregla 
		if ((y - dist) < 3.0f) {
			aux->SetLim1(l1x, dist + y);
			aux->SetLim2(l2x, dist + y);
		}
		else if (y + dist > 15.0f) {
			aux->SetLim1(l1x, y - dist);
			aux->SetLim2(l2x, y - dist);
		}
		else {
			switch (op)
			{
			case 0:
				aux->SetLim1(l1x, y + dist);
				aux->SetLim2(l2x, y + dist);
				break;
			case 1:
				aux->SetLim1(l1x, y - dist);
				aux->SetLim2(l2x, y - dist);
				break;
			default:
			std::cout << "error";
				break;
			}
		}
		platform.push_back(aux);
	}
}

void plataforma::dibuja()
{
	for (auto a : platform) {
		Plataforma->setPos(a->GetLim1().x - 0.5f, (a->GetLim1().y - 1.5f - 0.5f));
		Plataforma->setSize(a->GetLenght(), 1.50f);
		a->dibuja();
		
		Plataforma->draw();
	}
}

void plataforma::agregar(pared* a)
{
	platform.push_back(a);
}

void plataforma::setTextura(const char* a)
{
	delete Plataforma;
	Plataforma = new ETSIDI::Sprite(a);
}

void plataforma::setTextura(std::string a)
{
	delete Plataforma;
	Plataforma = new ETSIDI::Sprite(a.c_str());
}
