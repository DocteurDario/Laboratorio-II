//Materia:
//Nombre:
//TP N°:
//Ej N°:
//Comentario:
//____________________________________

#include <iostream>
#include <windows.h>
#include "venta.h"
#include "ArchivoVenta.h"
#include "funciones.h"

using namespace std;

int main(void)
{
    Venta venta;
    ArchivoVenta archivoVenta;
    int opcion=0;
    do{
        cout<<" Ingresa opcion :"<<endl;
        cout<<" 1. Cargar venta : "<<endl;
        cout<<" 2. Mostrar total recaudado :"<<endl;
        cout<<" 3. Mostrar ventas:"<<endl;
        cout<<" 4. Mostrar ventas sin memoria dinamica :"<<endl;
        cout<<" 5. Buscar Articulo por codigo :"<<endl;
        cout<<" 6. Modificar Venta :"<<endl;
        cout<<" 0. Salir :"<<endl;
        cout<<" OPCION: ";
        cin>>opcion;
            switch(opcion)
                {
                case 1:
                    venta.Cargar();
                    archivoVenta.guardar(venta);
                    break;
                case 2:
                    cout<<"Total recuadado :"<<archivoVenta.totalRecaudado()<<endl;
                    break;
                case 3:{
                    mostrarVentas();
                    system("pause");
                    }break;
                case 4:{
                    mostrarVentas2();
                    system("pause");
                    }break;
                case 5: {
                    buscarCodigo ();
                    system("pause");
                    }break;
                case 6:
                    modificarVenta();
                    break;
                case 0:
                    cout<< "Gracias por usar el programa "<<endl;
                    break;
                default:
                    cout<<" Opcion incorrecta "<<endl;
                    break;
                }
                Sleep(800);
                system("cls");
        }while(opcion!=0);


return 0;
}
