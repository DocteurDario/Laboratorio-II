#include "Funciones.h"
#include <cstdio> // Biblioteca para manejar archivos.
#include <clocale>
#include <iostream>
#include <string.h>
#include <string>
#include "Parcial.h"
#include"Agente.h"
#include "AgenteArchivo.h"
#include "Fecha.h"
#include "Multa.h"
#include "MultaArchivo.h"
using namespace std;

bool tieneMulta2021(int nro){
    MultaArchivo archivo;
    Multa multa;
    int i,cant=archivo.getCantidadRegistros();

    for(i=0; i<cant;i++){
        multa=archivo.leer(i);
        if((nro==multa.getTipoInfraccion()&& multa.getFechaMulta().toString("YYYY/MM/DD")<"2022/01/01")&&
            (multa.getFechaMulta().toString("YYYY/DD/MM")>"2020/12/31"))
            {
            return true;
            }
    }
    return false;
}
bool multaMayorA25000(int id){
    MultaArchivo multaArchivo;
    Multa multa;
    int i,cantMulta=multaArchivo.getCantidadRegistros();
    for(i= 0; i < cantMulta; i++) {
        multa=multaArchivo.leer(i);
        if(id==multa.getIDAgente() && multa.getMonto()> 25000){
            return true;
        }
    }
    return false;
}
bool masDeUnaMultaMismoTipo(int id){
    MultaArchivo archivo;
    Multa multa;
    int i,cant=archivo.getCantidadRegistros();
    int vec[10]={0};
    for(i=0; i<cant;i++){
        multa=archivo.leer(i);
        if(id=multa.getIDAgente()&& multa.getFechaMulta().getAnio() == 2022 && multa.getEliminado()==false)
            {
             vec[multa.getIDMulta()-1]++;
            }
    }
    for(int j=0; j< 10; j++){
        if(vec[j]<=2){
            return true;
        }
    }
    return false;
}
