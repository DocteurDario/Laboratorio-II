#include "Ciudad.h"
#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;

Ciudad::Ciudad(){
    //--------
}
Ciudad::Ciudad(int id, const char *nombre, const char *idpais,int poblacion){
    _ID=id;
    strcpy(_nombre,nombre);
    strcpy(_idpais,idpais);
    _poblacion=poblacion;
}
int  Ciudad::getID()
{
    return _ID;
}
char * Ciudad::getNombre()
{
    return _nombre;
}
char * Ciudad::getIDPais()
{
    return _idpais;
}
int  Ciudad::getPoblacion()
{
    return _poblacion;
}
void Ciudad::setID(int val)
{
    _ID = val;
}
void Ciudad::setNombre(const char * val)
{
    strcpy(_nombre, val);
}
void Ciudad::setIDPais(const char * val)
{
    strcpy(_idpais, val);
}
void Ciudad::setPoblacion(int val)
{
    _poblacion = val;
}
void Ciudad::mostrar(){
    cout << _ID << " " << _idpais << " " << _nombre << " " << _poblacion << endl;
}


