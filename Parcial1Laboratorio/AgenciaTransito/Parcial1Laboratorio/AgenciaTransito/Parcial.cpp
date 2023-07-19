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
#include "Funciones.h"
using namespace std;


void Parcial::Punto1(){

    MultaArchivo multaArchivo;
    int i,cantidadRegistroMulta=multaArchivo.getCantidadRegistros();
    Multa multa, *multa2021=new Multa[cantidadRegistroMulta];
    int vidMulta[10]={0};

    for(i=0;i<cantidadRegistroMulta;i++){
            multa=multaArchivo.leer(i);
            if(multa.getFechaMulta().getAnio()==2022){
                    if(tieneMulta2021(multa.getTipoInfraccion())){
                        //cout<<multa.getTipoInfraccion()<<endl;
                    }else{
                        //cout<<multa.getTipoInfraccion()<<endl;
                        vidMulta[multa.getTipoInfraccion()-1]++;
                    }
            }
    }
    for(int idm=0;idm<10;idm++){
        if(vidMulta[idm]>0){
            cout<< idm+1<<endl;
        }
    }
}
void Parcial::Punto2(){
    MultaArchivo multaArchiivo;
    int i,mayor,cantidadMultas=multaArchiivo.getCantidadRegistros();
    Multa aux,*vec=new Multa[cantidadMultas];
    multaArchiivo.leer(vec,cantidadMultas);
    for(i=0;i<cantidadMultas;i++){
        mayor=i;
        for(int j=i+1;j<cantidadMultas;j++){
            if(vec[j].getMonto()>vec[mayor].getMonto()){
                mayor=j;
            }
        }
        aux=vec[i];
        vec[i]=vec[mayor];
        vec[mayor]=aux;
    }
    int pos;
    for(int j=0;j<cantidadMultas;j++){
            if( vec[j].getPagada()==1 && vec[j].getEliminado()==0){
                pos=j;
                j=cantidadMultas;
            }
    }

    //pos=2;
    cout<<vec[pos].getEliminado()<<endl;
    AgenteArchivo agenteArchivo;
    Agente agente;
    cout<<vec[pos].getIDMulta() <<" / "<<vec[pos].getMonto() <<" / "<<vec[pos].getEliminado()<<" / "<<vec[pos].getPagada()<<endl;
    int posAgente=agenteArchivo.buscar(vec[pos].getIDAgente());
    agente=agenteArchivo.leer(posAgente);
    cout<< agente.getApellidos()<<endl;
    cout<< agente.getNombres()<<endl;
}
void Parcial::Punto3(){
    AgenteArchivo agenteArchivo;
    Agente agente;
    int i,cantAgente=agenteArchivo.getCantidadRegistros(),contadorAgentes=0;

    for(i=0;i< cantAgente; i++){
        agente=agenteArchivo.leer(i);
        cout<<agente.getIdAgente()<<endl;
        if(multaMayorA25000(agente.getIdAgente())){
            contadorAgentes++;
        }
    }
    cout<<"Punto 3----"<<endl;
    cout<<"Cantidad de Agentes qeu realizo multa por mas de 25000 : "<<contadorAgentes<<endl;
}
void Parcial::Punto4(){
    AgenteArchivo agenteArchivo;
    Agente agente;
    int i, cantAgente=agenteArchivo.getCantidadRegistros();
    cout<<"Punto 4 : "<<endl;

    for(i=0 ; i < cantAgente; i++){
        agente=agenteArchivo.leer(i);
        if(masDeUnaMultaMismoTipo(agente.getIdAgente())){
                cout<< "-------------------"<<endl;
                cout<< agente.getIdAgente()<<endl;
                cout<< agente.getApellidos()<<endl;
                cout<< agente.getNombres()<<endl;
        }

    }
}
