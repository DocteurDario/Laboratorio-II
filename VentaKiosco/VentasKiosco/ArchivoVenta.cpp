//Materia:
//Nombre:
//TP N°:
//Ej N°:
//Comentario:
//____________________________________

#include <iostream>
#include "ArchivoVenta.h"
#include "venta.h"

using namespace std;
ArchivoVenta::ArchivoVenta()
{
    //ctor
}
void ArchivoVenta::guardar(Venta venta)
{
    FILE* pFile=guardarArchivo();
    fwrite(&venta,sizeof(Venta),1,pFile);
    fclose(pFile);
}
float ArchivoVenta::totalRecaudado()
{
    FILE* pFile=leerArchivo();

    Venta venta;
    float total=0;
    while(fread(&venta,sizeof (Venta),1,pFile))// tembie se puede usar distinto de cero
    {
        total+=venta.getTotal();
    }
    fclose(pFile);
    return total;
}
int ArchivoVenta::cantidadVentas(){
    Venta ventas;
    int cantidad=0;

    FILE *pFile = leerArchivo();
    fseek (pFile,0,SEEK_END);// Mueve el cursor al final del archivo

    cantidad=ftell(pFile)/sizeof(Venta);// obtiene la cantidad
    fclose (pFile);
    return cantidad;
}

void ArchivoVenta::obtenerVentas(Venta *ventas, int cantidad){
    FILE* pFile=leerArchivo();
    fread(ventas,sizeof(Venta),cantidad,pFile);
    fclose(pFile);
}
Venta ArchivoVenta::obtenerVenta(int posicion){
    Venta venta;
    FILE *pFile=leerArchivo();

    fseek(pFile,posicion*sizeof(Venta),SEEK_SET);// muevo el cursor
    fread(&venta,sizeof(Venta),1,pFile);
    fclose(pFile);
    return venta;

}
FILE* ArchivoVenta::leerArchivo(){

    FILE* pFile;
    pFile=fopen("ventas.dat","rb");
        if(pFile==nullptr){
            exit(1550);
        }
    return pFile;
}
FILE* ArchivoVenta::guardarArchivo(){
    FILE *pFile;
    pFile= fopen("ventas.dat","ab");
    if(pFile==nullptr){
            cout<<"No se pudo abrir el archivo "<<endl;
        exit(1550);
    }
    return pFile;
}

int ArchivoVenta::buscarPorCodigo(int codigo){
    int posicion=-1,i=0;
    Venta venta;
    FILE* pFile=leerArchivo();

    while(fread(&venta,sizeof (Venta),1,pFile)==1 && posicion==-1)
    {
     if(codigo==venta.getCodigo())
        {
        posicion=i;
        }
        i++;
    }
    fclose(pFile);
    return posicion;
}
bool ArchivoVenta::guardar(Venta venta, int posicion){
     FILE *pFile;
     pFile=fopen("ventas.dat","rb+");
     if(pFile==nullptr){
        cout<<"Error al abrir el acrivo"<<endl;
        exit(1500);
     }
     fseek(pFile,(posicion*sizeof(Venta)),SEEK_SET);
     fwrite(&venta,sizeof(Venta),1,pFile);
     fclose(pFile);

     return true;
}
//------------------------------------
