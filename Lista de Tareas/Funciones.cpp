//Materia:
//Nombre:
//TP N°:
//Ej N°:
//Comentario:
//____________________________________

#include <iostream>
#include "Tarea.h"
#include "Funciones.h"

using namespace std;


Tarea agregarTarea(){
    int id, dia, mes, anio;
    std::string descripcion, dificultad, estado;

    std::cout<< " cargar tarea : "<<std::endl;
    std::cout<< " ID : ";
    std::cin>> id;
    std::cout<< " Descripcion : ";
    std::cin>>descripcion;
    //setDescripcion(descripcion);
    std::cout<< " Dificultad : ";
    std::cin>> dificultad;
    //setDificultad(dificultad);
    // uso el constructor para pasar la fecha cada vez que cargo una fecha,
    std::cout<< " dia : ";
    std::cin>>dia;
    std::cout<< " mes : ";
    std::cin>>mes;
    std::cout<< " Anio : ";
    std::cin>>anio;
    std::cout<< " Estado : ";
    std::cin>>estado;
/*
    Tarea aux;
    aux.setId(id);
    aux.setDescripcion(descripcion);
    aux.setDificultad(dificultad);
    Fecha fecha(dia,mes, anio);
    aux.setFechaLimite(fecha);
    aux.setEstado(estado);


*/

   return Tarea(id,descripcion,dificultad,Fecha(dia,mes,anio),estado);
}

int diferenciasDeDias(Fecha fechaInicial, Fecha fechaFinal){
        int contador=0;
        bool primerFechaMayor= fechaInicial.toString("YYYY/MM/DD")>fechaFinal.toString("YYYY/MM/DD");
        if(primerFechaMayor){
            Fecha aux= fechaInicial;
            fechaInicial=fechaFinal;
            fechaFinal=fechaInicial;
        }
        while(fechaInicial.toString()!=fechaFinal.toString()){
            fechaInicial.agregarDias(1);
            contador++;
        }

         if(primerFechaMayor){
            return -contador;
         }else{
            return contador;
         }

}
