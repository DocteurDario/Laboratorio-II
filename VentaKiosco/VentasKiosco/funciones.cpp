#include <iostream>
#include "funciones.h"
#include "venta.h"
#include "ArchivoVenta.h"
using namespace std;

void mostrarVentas(){
    ArchivoVenta archivoVenta;
    int cantidadVentas=archivoVenta.cantidadVentas();
    Venta* ventas=new Venta [cantidadVentas];
    archivoVenta.obtenerVentas(ventas,cantidadVentas);

    for(int i=0;i<cantidadVentas;i++){

        ventas[i].Mostrar();
        cout<<endl;
    }
    delete[] ventas;
}
void mostrarVentas2(){
    ArchivoVenta archivoVenta;
    int cantidadVentas=archivoVenta.cantidadVentas();

    for (int i=0; i<cantidadVentas;i++){
       Venta venta=archivoVenta.obtenerVenta(i);
       venta.Mostrar();
    }
}
void buscarCodigo(){
    int codigo=0, posicion=0;
    ArchivoVenta archivoVenta;
    cout<<"Ingresar Codigo: ";
    cin>>codigo;

    posicion=archivoVenta.buscarPorCodigo(codigo);
        if(posicion==-1){
            cout<<"No se encontro esa venta "<<endl;
        }
        else{
            Venta venta=archivoVenta.obtenerVenta(posicion);
            venta.Mostrar();
        }
}

void modificarVenta(){
    int codigo=0, posicion=0;
    ArchivoVenta archivoVenta;
    cout<<"Ingresar Codigo: ";
    cin>>codigo;

    posicion=archivoVenta.buscarPorCodigo(codigo);
        if(posicion!=-1){
           Venta venta=archivoVenta.obtenerVenta(posicion);
           cout<<"------------------"<<endl;
           venta.Mostrar();
           cout<<"------------------"<<endl;
           venta.modificar();
           archivoVenta.guardar(venta,posicion);
        }
}
//---------------------------

