#pragma once
#include <fstream>
#include <iostream>

using namespace std;
class LecturaMonedas {
	
public:

	static void leer(string& cadena);
	static void leerPerDes(string& cadena);
	static void escribir(string& m);
	static void escribirPerDes(string& lhs,const char* rhs);
};
