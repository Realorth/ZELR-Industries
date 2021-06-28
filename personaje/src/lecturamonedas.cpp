#pragma once
#include "lecturamonedas.h"
#include <string>
#include <cstring>

using namespace std;

void LecturaMonedas::leer(string& m)
{
	string line;
	const char* cadena;
	ifstream myfile("monedas.txt");
	if (myfile.is_open())
	{
		getline(myfile, line);
		
		myfile.close();
	}
	cadena = line.c_str();
	m = cadena;
	//return cadena;
	//char* cadena;
	//ifstream dato;
	//dato.open("monedas.txt");
	////if (!dato)return nullptr;
	//if (!dato.is_open()) return nullptr;
	//while (!dato.eof()) {
	//	//char a;
	//	dato >> cadena;
	//	//cadena = &a;
	//	
	//}
	////char cadena[128];
	////string cadena;
	///*char* cadena;
	//cadena = 0;
	//dato.getline(cadena,1);*/

	////while (!dato.eof()) {
	////	dato >> cadena;

	////	//cout << cadena << endl;
	////}
	//dato.close();
	////const char* c= cadena.c_str();
	///*if (dato.is_open())
	//{
	//	while (getline(myfile, line))
	//	{
	//		cout << line << '\n';
	//	}
	//	myfile.close();
	//}*/
	//
	//return cadena;
	////cout << cadena << endl;
}
