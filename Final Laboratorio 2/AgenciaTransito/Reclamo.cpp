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

Reclamo::Reclamo()
{
    _idMulta=0;
    Fecha f;
    _fechaReclamo=f;
    _idSucursal=0;
    strcpy( _motivo," ");
    _aceptado=0;

}
Reclamo::Reclamo( int id, Fecha f, int idSucursal, char * motivo, bool aceptado){
    _idMulta= id;
    _fechaReclamo=f;
    _idSucursal=idSucursal;
    strcpy( _motivo,motivo);
    _aceptado=aceptado;

}
int Reclamo::getCantidadRegistros(){
        FILE *p;
        p=fopen("reclamos.dat","rb");
            if(p==NULL){
                return 0;
            }
        fseek(p,0,SEEK_END);
        int bytes=ftell(p);
        fclose(p);
        return  bytes/sizeof(Reclamo);
}

bool Reclamo::guardar( Reclamo reg){
    FILE *p;
    p=fopen("reclamos.dat","ab");
    if(p==NULL){
        return false;
    }
    bool pudoEcribir = fwrite(&reg,sizeof(Reclamo),1,p);
    fclose(p);
    return pudoEcribir;

}

Reclamo Reclamo::leer(int nroRegistro){
    Reclamo aux;
    FILE *p=fopen("reclamos.dat","rb");
    if(p==NULL){
        return aux;
    }

    fseek(p,nroRegistro*sizeof(Reclamo),SEEK_SET);

    fread(&aux,sizeof(Reclamo),1,p);
    fclose(p);

    return aux;

}

bool Reclamo::guardar(Reclamo reg, int posicionARemplazar){
    FILE *p=fopen("reclamos.dat","rb+");
    if(p==NULL){
        return false;
    }
    fseek(p,posicionARemplazar*sizeof(Reclamo),SEEK_SET);
    bool pudoEscribir=fwrite(&reg,sizeof(Reclamo),1,p);
    fclose(p);
    return pudoEscribir;
}
int Reclamo::buscar(int id){
    int i, cantidadRegistros=this->getCantidadRegistros();
    Reclamo aux;
    for(i=0; i< cantidadRegistros;i++ )
    {
         aux=this->leer(id);
            if(aux.getIdMulta()==id){
                return i;
            }
    }
    return -1;
}
void Reclamo::cargarReclamo(){
    int idMulta,dia, mes , anio, idSucural;
    bool aceptado;
    char reclamo[100];
    cout<<"Cargar Id multa ";
    cin>> idMulta;
    cout<<"dia:  ";
    cin>> dia;
    cout<<"Mes:  ";
    cin>>mes;
    cout<<"Anio : ";
    cin>>anio;
    cout<<"Reclamo Aceptado o no 0 o 1 :";
    cin>>aceptado;
    cout<<"Reclamo ";
    cin>>reclamo;



    Fecha fecha(dia, mes, anio);
    Reclamo rec;
    rec.setIdMulta(idMulta);
    rec.setIdSucursal(idSucural);
    rec.setFecgaReclamo(fecha);
    rec.setAceptado(aceptado);
    rec.setMotivo(reclamo);

    if( noExiteReclamo(idMulta)== false){
        rec.guardar(rec);
         if(rec.getAceptado()==true ){
            eliminarMulta(idMulta);
        }
    } else{
      cout<< " Reclamo ya existe ;";
    }

}
bool noExiteReclamo( int idMulta){
    Reclamo reclamo;
    int cant=reclamo.getCantidadRegistros();
    bool exite;

    for( int i= 0; i <cant; i++){
        reclamo.leer(i);
        if(reclamo.getIdMulta()==idMulta){
            return true;
        }
    }
    return false;
}
bool eliminarMulta( int idMulta){

    MultaArchivo multaArchivo;
    Multa multa;

    int posMulta=multaArchivo.buscar(idMulta);
    multa=multaArchivo.leer(posMulta);
    multa.setEliminado(1);
    if(multaArchivo.guardar(multa,posMulta)){
        cout<<"Multa Eliminada";
    }else{
        cout<<"No se puedo actualizar";
    }

}

