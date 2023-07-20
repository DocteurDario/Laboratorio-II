#include "Parcial.h"
#include <cstdio> // Biblioteca para manejar archivos.
#include <clocale>
#include <iostream>
#include <string.h>
#include <string>
#include "Agente.h"
#include "AgenteArchivo.h"
#include "Multa.h"
#include "MultaArchivo.h"
#include "MultaManager.h"
#include "Fecha.h"
#include "Pago.h"
using namespace std;

void Parcial::Punto3(){
    string patente;
    cin>> patente;
    Multa multa;
    MultaArchivo multaArchivo;
    int i,cantMulta=multaArchivo.getCantidadRegistros(),contador=0;
    bool si=0;


    for(i=0;i<cantMulta;i++)
    {
        multa=multaArchivo.leer(i);
            if(patente==multa.getPatente()){
            si=1;
               if( multa.getPagada()==true){
                contador++;
               }

            }

    }
    if(si=1){
        cout<<"Patente"<<patente<<" "<< contador <<endl;
    }else{
      cout<<" NO existe patente... " <<endl;
    }
}
/*
int cantidadMultas(string patente){
    Multa multa;
    MultaArchivo multaArchivo;
    int i,cantMulta=multaArchivo.getCantidadRegistros();

    for(i=0;i<cantMulta;i++)
    {
        multa=multaArchivo.leer(i);
            if(patente==multa.getPatente()){
                cout<<cantidadMultas(patente);
            }

    }

}
*/
