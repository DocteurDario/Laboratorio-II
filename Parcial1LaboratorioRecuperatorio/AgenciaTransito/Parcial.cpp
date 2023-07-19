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
using namespace std;

void Parcial::Punto1(){
    AgenteArchivo agenteArchivo;
    int i,cantAgente= agenteArchivo.getCantidadRegistros(),cont;
    Agente agente, auxAgente;

    for(int indice=0;indice < 10; indice ++){
            cont=0;

            for(i=0;i < cantAgente; i++){
                agente=agenteArchivo.leer(i);
                if(cont==0){
                    auxAgente=agente;
                    //auxAgente.setSueldo(5);
                    cont++;
                }
                if(indice+1 == agente.getCategoria()){

                    if(agente.getSueldo()<auxAgente.getSueldo())
                        auxAgente=agente;
                    }
            }
            cout<<"-----------------------"<<endl;
            cout<<"Categoria: "<< indice+1 <<endl;
            cout<<"Sueldo Minimo: " << auxAgente.getSueldo()<<endl;
    }
}
void Parcial::Punto2(){
    MultaArchivo multaArchivo;
    Multa multa;
    int cantMulta=multaArchivo.getCantidadRegistros();

    int *vec= new int[cantMulta]{0};
    Multa *auxMulta=new Multa[cantMulta];
    multaArchivo.leer(auxMulta,cantMulta);
    cout<<"--------------------: "<<endl;
    /*
    for(int ind=0;ind<cantMulta;ind++)
    {
        multa=multaArchivo.leer(ind);
        //cout<<multa.getIDMulta()<<endl;
        cout<<multa.getIDLocalidad()<<endl;
    }
    */
    for(int ind=0;ind<cantMulta;ind++)
    {

        for(int i=0;i<cantMulta;i++){
            if(ind+1==auxMulta[i].getIDLocalidad()&&auxMulta[i].getEliminado()==0){
                    vec[ind]++;
            }
        }

    }
    cout<<"---------------: "<<endl;
     int mayor=vec[0], indiceMayor=0;
     for (int i = 1; i < cantMulta; i++) {
        if (vec[i] > mayor) {
            mayor = vec[i]; // Si encontramos un elemento mayor, actualizamos el valor de mayor
            indiceMayor = i; // También actualizamos el índice del mayor
        }
    }
    cout<<"Localidad con mayor cantidad de Multas: "<< indiceMayor+1<<endl;
    cout<<"Cantidad de multas : "<<mayor <<endl;
    delete []auxMulta;
    delete []vec;
}
void Parcial::Punto3(){
    int anio;
    cout<<"Ingresar Antiguedad : "<<endl;

    cout<<"Anio :";
    cin>>anio;
//    Fecha antiguedad(dia,mes,anio);
    AgenteArchivo agenteArchivo;
    Agente agente;
    int i,cantAgente=agenteArchivo.getCantidadRegistros();

    for(i=0;i< cantAgente; i++){
        agente=agenteArchivo.leer(i);
        if(agente.getAnioIngreso()<anio){
                cout<<agente.getApellidos()<<" "<<cantidadDeMultas(agente.getIdAgente())<<endl;

        }

    }



}
int cantidadDeMultas(int IdAgente){
    Multa multa;
    MultaArchivo multaArchivo;
    int i,cantMulta=multaArchivo.getCantidadRegistros();
    int contador=0;
    for(i=0;i<cantMulta;i++)
    {
        multa=multaArchivo.leer(i);
        if(multa.getIDAgente()==IdAgente && multa.getEliminado()==0){
            contador++;
        }
    }
    return contador;
}
void Parcial::Punto4()
{
    AgenteArchivo agenteArchivo;
    Agente agente;
    int i,cantAgente=agenteArchivo.getCantidadRegistros();

    for(i=0;i< cantAgente; i++){
        agente=agenteArchivo.leer(i);
        cout<<agente.getApellidos()<<" "<<agente.getNombres()<<" ";
        for(int j=0; j<10; j++){
            if(registraIDinfracion(j+1,agente.getIdAgente())){
                cout<<j+1<<" ";
            }
        }
        cout<<endl;
    }
}
bool registraIDinfracion( int idInfraccion, int IdAgente){
    Multa multa;
    MultaArchivo multaArchivo;
    int i,cantMulta=multaArchivo.getCantidadRegistros();
    int contador=0;
    for(i=0;i<cantMulta;i++)
    {
        multa=multaArchivo.leer(i);
        if(multa.getIDAgente()==IdAgente && multa.getTipoInfraccion()==idInfraccion && multa.getEliminado()==0){
            return true;
        }
    }
    return false;
}
