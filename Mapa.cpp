#include "Mapa.h"
#include "ETSIDI.h"
#include<time.h>
#include<iostream>
#include<map>
#include<cmath>
#include<fstream>
Mapa::Mapa()
{

}
Mapa::Mapa(int l)
{
	tipo a = static_cast<tipo>(l); 
	ptipo = a;
}
Mapa::Mapa(tipo l)
{
	ptipo = l;
}
Mapa::~Mapa()
{
}
void Mapa::Agregar(pared* a)
{
	suelo.push_back(a);
	numero++;
}

void Mapa::Inicializa()
{
	
}

void Mapa::Genera_suelo()
{
	//std::cout << "El máximo del fondo es " << fondo.size() << " Y el MAX " << MAX_LONG << " Y el de numero " << numero << std::endl;
//Generamos los  primeros  tres
	for (auto i = 0; i < 3; i++) {
		pared* aux = new pared(i*10.0f-10.0f,0,10.0f);
		suelo.push_back(aux);
		numero++;
	}
	//Aleatoria
	srand(time(0));
	for (auto i = 3; i < 2*fondo.size()-3; i++) {
		auto opcion = rand()%2;
		if (opcion) {
			suelo.push_back(nullptr);
			numero++;
		}
		else {
			pared* aux=new pared(i*10.0f-10.0f,0,10.0f);
			suelo.push_back(aux);
			numero++;
		}
		
	}

	//Generamos los dos últimos bloques
	for (auto i = 2*fondo.size()-3; i < 2*fondo.size(); i++) {
		pared* aux = new pared(i * 10.0f-10.0f, 0, 10.0f);
		suelo.push_back(aux);
		numero++;
	}

	/*std::ofstream a;
	a.open("suelo.txt");
	if (a.is_open()) {
		switch (ptipo) {
		case tipo::CEMENTERIO:
			a << "CEMENTERIO\n";
			break;
		case tipo::NIEVE:
			a << "NIEVE\n";
			break;
		case tipo::BASICO:
			a << "BASICO\n";
		}
		for (auto i : suelo) {
			if (i == nullptr)
				a << 0;
			else
				a << 1;
		}	
		a.close();	
	}*/

}

void Mapa::Genera_plataforma()
{
	////este  código se encarga de generar las plataformas
	//// de  manera coherente
	//std::random_device rd;//genera un número random, útil para las semillas
	//std::mt19937 gen(rd());//se obtiene la  generación de los números para las distribuciones
	//std::normal_distribution<> distancia_entre_plataformas(3.6f, 0.1f);//distribución para la diferencia de alturas de las plataformas
	//std::uniform_int_distribution<> sube_baja(0, 1);// distribución para sí sube o baja la siguiente plataforma

	//// se tiene que generar forzadamente la primera plataforma para  conseguir coherencia
	////int i=0;
	////while (suelo[i]!=nullptr) {// se obtiene la posicion del primer espacio
	////	i++;
	////}
	//pared* auxi = new pared(suelo[3]->getlim1().x, 3.0f, 10.0f);
	//plataforma.push_back(auxi);
	//std::srand(time(nullptr));

	//for (auto i = 1; i < 2 * fondo.size() + 5; i++) {

	//// se crea la plataforma
	//	// primero se cargan los parámetros aleatorios
	//	auto dist = distancia_entre_plataformas(gen);
	//	auto op = sube_baja(gen);
	//	// se crean las paredes
	//	pared* aux = new pared(i * plataforma[i - 1]->getlenght() + plataforma[0]->getlim1().x, dist,plataforma[i-1]->getlenght());
	//	auto l1x = aux->getlim1().x;
	//	auto l2x = aux->getlim1().x;
	//	auto y = plataforma[i - 1]->getlim1().y;
	//// sí se está en alguno de los límites se arregla 
	//	if((y-dist) < 3.0f){
	//		aux->setlim1(l1x, dist+y);
	//		aux->setlim2(l2x, dist + y);
	//	}else if(y+dist>15.0f){
	//		aux->setlim1(l1x, y - dist);
	//		aux->setlim2(l2x, y - dist);
	//	}else {
	//		switch (op)
	//		{
	//		case 0:
	//			aux->setlim1(l1x, y + dist);
	//			aux->setlim2(l2x, y + dist);
	//			break;
	//		case 1:
	//			aux->setlim1(l1x, y-dist);
	//			aux->setlim2(l2x, y-dist);
	//			break;
	//		default:
	//			std::cout<<"error";
	//			break;
	//		}
	//	}
	//	plataforma.push_back(aux);
	//}

	




	std::random_device rd;
	std::mt19937 gen(rd());
	std::normal_distribution<> normal(3*1.8f,0.1);
	// Se generan las plataformas,eee solo variando un poco la altura y de sí sube o baja
	std::uniform_int_distribution<> di(0
		/*Sería la altura del presonaje*/, 1);


	pared* aux = new pared(suelo[2]->GetLim1().x,3.0f , 10.0f);
	plataforma.push_back(aux);
	std::srand(time(nullptr));
	for (auto i = 1; i < 2*fondo.size()-5; i++) {
		auto op = di(gen) ;//std::rand()%2;
		auto altura = normal(gen);//Diferencia de altura
		pared* aux = new pared(10.0f * i+plataforma[0]->GetLim1().x, altura, 10.0f);
		auto l1x = aux->GetLim1().x;
		auto l2x = aux->GetLim2().x;
		//Factor de conversion de alturas
		auto f = 3.0f;
		//Solo se modificará las y
		if (plataforma[i - 1]->GetLim1().y - altura < altura) {
			aux->SetLim1(l1x, altura * f);
			aux->SetLim2(l2x, altura * f);
		}
		else {
		if (op) {
			//Hacia abajo
			if ((plataforma[i - 1]->GetLim1().y - altura) < altura) {
				aux->SetLim1(l1x, f*altura);
				aux->SetLim2(l2x, f*altura);
			}
			else {
				aux->SetLim1(l1x, plataforma[i - 1]->GetLim1().y - altura);
				aux->SetLim2(l2x, plataforma[i - 1]->GetLim2().y - altura);
			}
		}
		else {
			//Hacia arriba
			if ((plataforma[i - 1]->GetLim1().y + altura) > 15.0f) {
				aux->SetLim1(l1x, 15.0f-1.8f);
				aux->SetLim2(l2x, 15.0f-1.8f);
			}
			else {
				aux->SetLim1(l1x, plataforma[i - 1]->GetLim1().y + altura);
				aux->SetLim2(l2x, plataforma[i - 1]->GetLim2().y + altura);
			}
		}
		
		}


		
		plataforma.push_back(aux);
		
	}
	
}

void Mapa::Genera_fondo()
{
	auto a = 2;
	auto l = 10.0f;

	for (auto i = -1; i < MAX_LONG; i+=a) {
		pared* aux = new pared(l*i,20.0f,a*l);
		fondo.push_back(aux);
	}

}


void Mapa::Genera()
{
	//Generamos las plataformas
	switch (ptipo) {
	case CEMENTERIO:
		delete Plataforma;
		Plataforma = new ETSIDI::Sprite("imagenes/GRAVEYARD/png/plataforma.png");
		delete Fondo;
		Fondo = new ETSIDI::Sprite("imagenes/GRAVEYARD/png/BG.png");
		break;
	case NIEVE:
		delete Plataforma;
		Plataforma = new ETSIDI::Sprite("imagenes/WINTER/png/plataforma.png");
		delete Fondo;
		Fondo = new ETSIDI::Sprite("imagenes/GRAVEYARD/png/BG.png");
		break;
	case BASICO:
		delete Plataforma;
		Plataforma = new ETSIDI::Sprite("imagenes/BASICO/png/plataforma.png");
		delete Fondo;
		Fondo = new ETSIDI::Sprite("imagenes/GRAVEYARD/png/BG.png");
		break;
	
	}
	for (auto i = 0; i < MAX_LONG-6;i++) {
		
	}
	Genera_fondo();
	Genera_suelo();
	Genera_plataforma();

}

void Mapa::BorrarContenido()
{
	for (auto i = (numero - 1); i >= 0; i--) {
		Borrar(i);
	}
	numero = 0;
}

void Mapa::Borrar(int index)
{

	if (index < 0 || index >= numero)
		return;
	delete suelo[index];
	suelo.erase(suelo.begin() + index);

}

void Mapa::dibuja()
{
	dibuja_fondo();
	dibuja_plataforma();
	dibuja_suelo();
	
}

void Mapa::SetTipo(int l)
{
	tipo a = static_cast<tipo>(l);
	ptipo = a;
}

void Mapa::dibuja_suelo()
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	auto numero = suelo.size();
	for (auto i = 0; i < numero; i++) {
		if (suelo[i] != nullptr) {
			if (i >= 2 && i <= (numero - 2)) {
				if (suelo[i - 1] == nullptr)
					textura_suelo(-1, suelo[i]);
				else if (suelo[i + 1] == nullptr)
					textura_suelo(1, suelo[i]);
				else
					textura_suelo(0, suelo[i]);
			}
			else {
				textura_suelo(0, suelo[i]);
			}
		}
	}
	
	glDisable(GL_BLEND);
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

void Mapa::dibuja_fondo()
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/GRAVEYARD/png/BG.png").id);
	glDisable(GL_LIGHTING);
	
	for (auto i = 0; i < fondo.size(); i++) {
		polygon3D(fondo[i]);
	}
	glDisable(GL_BLEND);
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

void Mapa::dibuja_plataforma()
{
	for (auto a:plataforma) {
		Plataforma->setPos(a->GetLim1().x-0.5f, (a->GetLim1().y - a->GetLenght()/5-0.5f));
		Plataforma->setSize(a->GetLenght(),a->GetLenght()/5);
		a->dibuja();
		Plataforma->draw();
	}
	

}



void Mapa::textura_suelo(int op, pared* s)
{
	switch (ptipo) {
	case CEMENTERIO:
		switch (op) {
		case -1:
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/GRAVEYARD/png/Tiles/suelo_m.png").id);
			break;
		case 0:
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/GRAVEYARD/png/Tiles/suelo_m.png").id);
			break;
		case 1:
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/GRAVEYARD/png/Tiles/suelo_m.png").id);
			break;
		}
		break;
	case NIEVE:
		switch (op) {
		case -1:
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/WINTER/png/Tiles/suelo_izq.png").id);
			break;
		case 0:
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/WINTER/png/Tiles/suelo_m.png").id);
			break;
		case 1:
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/WINTER/png/Tiles/suelo_dcha.png").id);
			break;
		}
		break;
	case BASICO:
		break;

	}

	polygon(s);
	s->dibuja();
}


inline void Mapa::polygon(pared* s)
{
	auto v1 = s->GetLim1();
	auto v2 = s->GetLim2();
	glBegin(GL_POLYGON);
	glColor4f(1, 1, 1, 1);
	glTexCoord2d(1, 0); glVertex2f(v1.x, v1.y);
	glTexCoord2d(0, 0); glVertex2f(v2.x, v2.y);
	glTexCoord2d(0, 1); glVertex2f(v2.x,v2.y - 5);
	glTexCoord2d(1, 1); glVertex2f(v1.x, v1.y - 5);
	glEnd();
}

inline void Mapa::polygon3D(pared* s)
{
	auto z = -0.1f;
	auto v1 = s->GetLim1();
	auto v2 = s->GetLim2();
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glTexCoord2d(0, 1); glVertex3f(v1.x, 0, z);
	glTexCoord2d(1, 1); glVertex3f(v2.x, 0, z);
	glTexCoord2d(1, 0); glVertex3f(v2.x, v2.y, z);
	glTexCoord2d(0, 0); glVertex3f(v1.x, v1.y, z);
	glEnd();
}

