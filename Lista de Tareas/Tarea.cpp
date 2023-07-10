//Materia: TAREA
#include "Tarea.h"
#include <iostream>
#include "Fecha.h"


Tarea::Tarea()
{
    //ctor
}

Tarea::Tarea(int id, std::string p1,std::string p2, Fecha f,std::string p3)
{
    _id=id;
    _descripcion=p1;
    _dificultad=p2;
    //Fecha f(dd,mm,yyyy);
    _fechaLimite=f;
    _estado=p3;
}
int Tarea::getId(){return _id;}
std::string  Tarea::getDescripcion(){return _descripcion;}
std::string  Tarea::getDificultad(){return _dificultad;}
Fecha        Tarea::getFechaLimite(){return _fechaLimite;}
std::string  Tarea::getEstado(){return _estado;}

void Tarea::setId(int id){ _id=id;}
void Tarea::setDescripcion(std::string palabra){ _descripcion=palabra; }
void Tarea::setDificultad(std::string palabra){_dificultad=palabra; }
void Tarea::setFechaLimite(Fecha f){_fechaLimite=f;}
void Tarea::setEstado (std::string palabra){_estado=palabra;}

void Tarea::CargarTarea(){
    int id, dia, mes, anio;
    std::string descripcion, dificultad, estado;

    std::cout<< " cargar tarea : "<<std::endl;
    std::cout<< " ID : ";
    std::cin>> id;
    setId( id);
    std::cout<< " Descripcion : ";
    std::cin>>_descripcion;
    //setDescripcion(descripcion);
    std::cout<< " Dificultad : ";
    std::cin>> _dificultad;
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

    Fecha fecha(dia,mes, anio);
    setFechaLimite(fecha);
    setEstado(estado);
}
void Tarea::mostrarTarea() {
    std::cout << "ID Tarea: " << getId() << std::endl;
    std::cout << "Descripción: " << getDescripcion() << std::endl;
    std::cout << "Dificultad: " << getDificultad() << std::endl;
    std::cout << "Fecha Límite: " << getFechaLimite().toString("DD/MM/YYYY")<< std::endl;
    std::cout << "Estado: " << getEstado() << std::endl;
}

