//Materia:
//Nombre:
//TP N°:
//Ej N°:
//Comentario:
//____________________________________

#include <iostream>
#include "venta.h"

using namespace std;

Venta::Venta()
{
    //ctor
}
void Venta::Cargar(){
    cout<<"Codigo: ";
    cin>>_codigo;
    cout<<"Precio: ";
    cin>>_precio;
    cout<<"Cantidad: ";
    cin>>_cantidad;
}
void Venta::Mostrar(){
    cout<<"Codigo: "<< _codigo;
    cout<<",  Precio: "<< _precio;
    cout<<",  Cantidad :"<< _cantidad;
    cout<<",  Total :"<<_precio*_cantidad<<endl;
}
void Venta::modificar(){
    cout<<"Precio :";
    cin>>_precio;
    cout<<"Cantidad : ";
    cin>>_cantidad;
}

