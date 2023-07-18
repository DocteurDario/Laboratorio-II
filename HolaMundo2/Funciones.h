#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <string.h>
#include <string>
#include <iostream>
#include "Pais.h"
#include "Ciudad.h"
using namespace std;


void menu();
void opcionDeMenu();
void punto1();
void punto2();
void punto3();
void punto4();
void punto5();
void punto6();
void punto7();

int cantidadRegistrosPais();
int cantidadRegistrosCiudad();
Pais leer(int pos);
Ciudad leerCiudad(int pos);
bool existeCiudad(int nro);
bool guardarCiudad(Ciudad ciudad);
bool guardar(Pais reg, int posicionARemplazar);
int buscarPais(string codigo);




#endif // FUNCIONES_H
