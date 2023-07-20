#include <iostream>
#include "Pago.h"
#include "Parcial.h"
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

int main(){
    Pago pago;
    Parcial parcial;
    Multa multa;


    MultaArchivo multaArchivo;
    int i,cantMulta=multaArchivo.getCantidadRegistros();

    for(i=0;i<cantMulta;i++)
    {
        multa=multaArchivo.leer(i);
        cout<< "----------------"<<endl;
        cout<< multa.getPatente()<<endl;
        cout<< multa.getPagada()<<endl;

    }

   parcial.Punto3();

  return 0;
}
