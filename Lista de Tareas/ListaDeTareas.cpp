//Materia:CPP
#include <iostream>
#include "ListaDeTareas.h"
#include "Tarea.h"
#include "Fecha.h"
#include <string>
#include "Funciones.h"

ListaDeTareas::ListaDeTareas()
{
    _cantidad=0;
}
void ListaDeTareas::agregar(Tarea tarea){
    if(_cantidad < 10)
    {
        _listaTareas[_cantidad]=tarea;
        _cantidad++;
    }
}
void ListaDeTareas::verListaDeTarea(){
    std::cout<<"----------------------------"<<std::endl;
    std::cout<<"      Lista de Tareas  "<<std::endl;
    std::cout<<"----------------------------"<<std::endl;
    for(int i=0; i< _cantidad ; i++ ){
       _listaTareas[i].mostrarTarea();
       //std::cout<< "Dias Restantes: " << diferenciasDeDias( fecha,_listaTareas[i].getFechaLimite();
       std::cout<<"----------------------------"<<std::endl;
    }
}
void ListaDeTareas::ordenarLista(){
    int mayor=0;
    Tarea aux;

    for(int i=0 ; i < _cantidad-1; i++)
    {
        mayor=i;
        for(int j=i+1; j < _cantidad -1; j++)
        {
            if(_listaTareas[j].getFechaLimite().toString("YYYY/MM/DD") < _listaTareas[mayor].getFechaLimite().toString("YYYY/MM/DD")){
              /*if((_listaTareas[j].getFechaLimite().getAnio() > _listaTareas[mayor].getFechaLimite().getAnio()) ||
                (_listaTareas[j].getFechaLimite().getAnio() == _listaTareas[mayor].getFechaLimite().getAnio() && _listaTareas[j].getFechaLimite().getMes() > _listaTareas[mayor].getFechaLimite().getMes()) ||
                (_listaTareas[j].getFechaLimite().getAnio() == _listaTareas[mayor].getFechaLimite().getAnio() && _listaTareas[j].getFechaLimite().getMes() == _listaTareas[mayor].getFechaLimite().getMes() && _listaTareas[j].getFechaLimite().getDia() > _listaTareas[mayor].getFechaLimite().getDia()))
                {*/
                    mayor=j;
                }
        }
        if(i!=mayor){
            aux =_listaTareas[i];
            _listaTareas[i]=_listaTareas[mayor];
            _listaTareas[mayor]=aux;
        }

    }
}
