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
		if (key == 'c') {
			mundo.setcaida(false);
			mundo.setImpacto(false);//Para reiniciar el juego			
			estado = INICIO;

		}
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
	static bool flagLecturaMonedas = true;

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
		ETSIDI::printxy("Monedas Disponibles: ", -3, 14);
		//Impresión de las monedas disponibles en pantalla
		if (flagLecturaMonedas) {
			LecturaMonedas::leer(a);
			m = a.c_str();
			cout << m;
			flagLecturaMonedas = false;
		}
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy(m, 5, 14);
	}
	else if (estado == JUEGO){
		mundo.dibuja();
		if (mundo.getImpacto() || mundo.getcaida()) 
		estado = GAMEOVER;
		
}
	else if (estado == GAMEOVER) {
		static bool flag = true;
		mundo.dibuja();
		auto ojo = mundo.getOjo();
		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("GAMEOVER: Has perdido...", ojo.x-5, 10);
		ETSIDI::printxy("PULSE LA TECLA -C- PARA CONTINUAR", ojo.x-5, 5);
		//Almacenamiento de las monedas adquiridas en el ficehro .txt
		if (flag) {
			ofstream dato("monedas.txt");
			int inicial = atoi(m);//Convierte const char* a int para realizar la suma
			if (dato.is_open()) {
				dato << mundo.getnCoin() + inicial;
				dato.close();
			}
			else cout << "Unable to open file";
			flag = false;
		}
		//Vuelve a establecer el flag a true para que
		//cuando se vuelva a la pantalla de inicio aparezca las monedas totales
		flagLecturaMonedas = true;
	}
	else if (estado == FIN) {
		static bool flag = true;
		mundo.dibuja();
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("ENHORABUENA:¡¡Has triunfado!!", -5, 10);
		ETSIDI::printxy("PULSE LA TECLA -C- PARA CONTINUAR", -5, 9);

		//Almacenamiento de las monedas adquiridas en el ficehro .txt
		if (flag) {
			ofstream dato("monedas.txt");
			int inicial = atoi(m);//Convierte const char* a int para realizar la suma
			if (dato.is_open()) {
				dato << mundo.getnCoin() + inicial;
				dato.close();
			}
			else cout << "Unable to open file";
			flag = false;
		}
		//Vuelve a establecer el flag a true para que
		//cuando se vuelva a la pantalla de inicio aparezca las monedas totales
		flagLecturaMonedas = true;
	}

}
