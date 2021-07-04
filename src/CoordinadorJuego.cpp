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
	if (estado == JUEGO || estado == MAPA2 || estado == MAPA3)
		mundo.teclaEspecial(key);

}

void CoordinadorJuego::teclaEspecialUp(unsigned char key)
{
	if (estado == JUEGO || estado == MAPA2 || estado == MAPA3)
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
	else if (estado == JUEGO || estado == MAPA2 || estado == MAPA3) {
		mundo.tecla(key);
	}
	else if (estado == GAMEOVER) {
		if (key == 'c') {
			mundo.setcaida(false);//Para reiniciar el juego
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
	if (estado == JUEGO || estado == MAPA2 || estado == MAPA3) {
		mundo.mueve();
	}

}

void CoordinadorJuego::dibuja()
{
	static bool flagLecturaMonedas = true;//Flag para la lectura de las monedas(leer una vez)
	static bool flagGameOver = true;//Flag para el game over
	static bool flagMapa = true;//Flag para cambio de mapa

	if (estado == INICIO) {
		flagGameOver = true;
		gluLookAt(0, 7.5, 30,//posicion ojo
			0.0, 7.65, 0.0,//hacia donde mira
			0.0, 1.0, 0.0);//definimos hacia arriba eje y

		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("JUEGO DE PLATAFORMAS", -5, 8);

		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("PULSE LA TECLA -E- PARA EMPEZAR A JUGAR CON PISTOLERO", -9, 7);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -5, 4);
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

		if (atoi(m) >= 500)
			ETSIDI::printxy("PULSE LA TECLA -R- PARA EMPEZAR A JUGAR CON ARQUERO", -9, 6);

		if (atoi(m) >= 1000)
			ETSIDI::printxy("PULSE LA TECLA -T- PARA EMPEZAR A JUGAR CON MAGO", -9, 5);

		ETSIDI::setTextColor(1, 0, 0);
		if (atoi(m) < 500)
			ETSIDI::printxy("JUGADOR ARQUERO NO DISPONIBLE>>DESBLOQUEO CON 500 MONEDAS", -10, 6);
		if (atoi(m) < 1000)
			ETSIDI::printxy("JUGADOR MAGO NO DISPONIBLE>>DESBLOQUEO CON 1000 MONEDAS", -10, 5);
	}
	else if (estado == JUEGO) {
		//mundo.setFin(false);
		mundo.setMapa(0);
		mundo.dibuja();

		if (mundo.getImpacto() || mundo.getcaida()) {
			flagMapa = true;
			estado = GAMEOVER;
		}

		if (mundo.getFin()) {
			mundo.setFin(false);//Reinicia el Fin para que pueda usarse en el mapa2
			estado = MAPA2;
			flagMapa = true;
		}
	}
	else if (estado == MAPA2) {

		if (flagMapa == true) {
			mundo.setFin(false);
			mundo.setHombrePosicion(0, 0);
			flagMapa = false;
			mundo.setMapa(1);
		}

		mundo.dibuja();

		if (mundo.getImpacto() || mundo.getcaida()) {
			estado = GAMEOVER;
			flagMapa = true;//Para que pueda cambiar el mapa en la siguiente partida
		}

		if (mundo.getFin()) {
			mundo.setFin(false);//Reiniciar el Fin para que se pueda usar en el mapa3
			estado = MAPA3;
			flagMapa = true;//Para que pueda cambiar el mapa en la siguiente partida
		}
	}


	else if (estado == MAPA3) {

		//static bool flag = true;
		if (flagMapa == true) {
			mundo.setHombrePosicion(0, 0);
			mundo.setFin(false);
			flagMapa = false;
		}
		mundo.setMapa(2);
		mundo.dibuja();

		if (mundo.getImpacto() || mundo.getcaida()) {
			flagMapa = true;
			estado = GAMEOVER;
		}
		if (mundo.getFin()) {
			mundo.setFin(false);
			estado = FIN;
			flagMapa = true;
		}

	}

	else if (estado == GAMEOVER) {
		static bool flag = true;
		//bool flagSonido = true;

		mundo.dibuja();
		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("GAMEOVER: Has perdido...", -5 + mundo.getHombrePosicion().x, 10);
		ETSIDI::printxy("PULSE LA TECLA -C- PARA CONTINUAR", -5 + mundo.getHombrePosicion().x, 5);
		/*if (flagSonido) {
			ETSIDI::play("sonidos/GameOver.wav");
			flagSonido = false;
		}*/

		//Almacenamiento de las monedas adquiridas en el fichero .txt
		if (flagGameOver) {
			ETSIDI::play("sonidos/GameOver.wav");//Solo suena una vez cuando se pierde
			ofstream dato("monedas.txt");
			int inicial = atoi(m);//Convierte const char* a int para realizar la suma
			if (dato.is_open()) {
				dato << mundo.getnCoin() + inicial;
				dato.close();
			}
			else cout << "Unable to open file";
			flag = false;
			flagGameOver = false;
		}
		//Vuelve a establecer el flag a true para que
		//cuando se vuelva a la pantalla de inicio aparezca las monedas totales
		flagLecturaMonedas = true;
	}
	else if (estado == FIN) {
		static bool flag = true;
		mundo.dibuja();
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("ENHORABUENA:¡¡Has triunfado!!", -5 + mundo.getHombrePosicion().x, 10);
		ETSIDI::printxy("PULSE LA TECLA -C- PARA CONTINUAR", -5 + mundo.getHombrePosicion().x, 9);

		//Almacenamiento de las monedas adquiridas en el fichero .txt
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
