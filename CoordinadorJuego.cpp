#include "CoordinadorJuego.h"

CoordinadorJuego::CoordinadorJuego()
{
	estado = INICIO;
}

CoordinadorJuego::~CoordinadorJuego()
{
}

void CoordinadorJuego::teclaEspecial(unsigned char key)
{
	if (estado == JUEGO)
		mundo.teclaEspecial(key);

}

void CoordinadorJuego::teclaEspecialUp(unsigned char key)
{
	if (estado == JUEGO)
		mundo.teclaEspecialUp(key);
}

void CoordinadorJuego::tecla(unsigned char key)
{
	if (estado == INICIO) {
		if (key == 'e') {
			mundo.inicializa();
			estado = JUEGO;
		}
		if (key == 's')
			exit(0);
	}
	else if (estado == JUEGO) {
		mundo.tecla(key);
	}
	else if (estado == GAMEOVER) {
		if (key == 'c')
			estado = INICIO;
	}
	else if (estado == FIN) {
		if (key == 'c')
			estado = INICIO;
	}
}

void CoordinadorJuego::mueve()
{
	if (estado == JUEGO) {
		mundo.mueve();
		//si se ha acabado el mapa, estado=FIN
		//si se ha caido el hombre, o se ha quedado sin vidas, estado=GAMEOVER
	}
		
}

void CoordinadorJuego::dibuja()
{

	if (estado == INICIO) {
		gluLookAt(0, 7.5, 30,//posicion ojo
			0.0, 7.65, 0.0,//hacia donde mira
			0.0, 1.0, 0.0);//definimos hacia arriba eje y

		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("JUEGO DE PLATAFORMAS", -5, 8);

		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("PULSE LA TECLA -E- PARA EMPEZAR", -5, 7);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -5, 6);
		ETSIDI::printxy("ZERL INDUSTRIES", 2, 1);
	}
	else if (estado == JUEGO)
		mundo.dibuja();
	else if (estado == GAMEOVER) {
		mundo.dibuja();
		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("GAMEOVER: Has perdido...", -5, 10);
		ETSIDI::printxy("PULSE LA TECLA -C- PARA CONTINUAR", -5, 5);
	}
	else if (estado == FIN) {
		mundo.dibuja();
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("ENHORABUENA:¡¡Has triunfado!!", -5, 10);
		ETSIDI::printxy("PULSE LA TECLA -C- PARA CONTINUAR", -5, 9);

	}

}
