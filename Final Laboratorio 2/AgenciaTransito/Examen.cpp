#include "Examen.h"
#include "Reclamo.h"
#include <cstdio> // Biblioteca para manejar archivos.
#include <clocale>
#include <iostream>
#include <string.h>
#include <string>
#include "AgenteArchivo.h"
#include "Fecha.h"
#include "Multa.h"
#include "MultaArchivo.h"
#include "MultaManager.h"

using namespace std;

void Examen::Punto3(){
    Multa multa;
    MultaArchivo multaArchivo;
    int i,cantMulta=multaArchivo.getCantidadRegistros();
    Reclamo reclamo;
    int cantReclamo= reclamo.getCantidadRegistros();




    for(i=0;i<cantMulta;i++)
    {
        multa=multaArchivo.leer(i);
        if( multa.getEliminado()== true){
            cout<<" ----------------" <<endl;
            cout<< multa.getIDMulta()<<endl;
            cout<< multa.getTipoInfraccion()<<endl;
            cout<< multa.getFechaMulta().toString()<<endl;
            cout<< multa.getIDAgente()<<endl;
            cout<< multa.getIDLocalidad()<<endl;
            cout<< multa.getMonto()<<endl;
            cout<< multa.getPatente()<<endl;
            cout<< multa.getEliminado()<<endl;
            cout<< multa.getPagada()<<endl;


            for(int j=0; j< cantReclamo; j++)
            {
                reclamo.leer(j);

                if(multa.getIDMulta()==reclamo.getIdMulta())
                {
                    cout<< "Motivo: "<<reclamo.getMotivo();
                }
            }


        }


    }







}
