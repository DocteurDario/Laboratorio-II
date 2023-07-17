#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "Pais.h"
#include "Ciudad.h"

void punto1();
void punto2();
void punto3();
void punto4();
void punto5();
bool existeRegistro(char *);  //1
int cantidadRegistroPais();
Pais leerPais(int pos);
bool guardar(Pais pais);
int cantidadRegistrosCiudad();
Ciudad leerCidudad(int registro);
//bool guardar(Pais pais); //2
//void leerPais(int reg); //3
//void leerCidudad(int reg);//4
//void porcentajeSuperficiePais(); //5




#endif // FUNCIONES_H
