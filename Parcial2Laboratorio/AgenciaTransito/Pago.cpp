#include "Pago.h"
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

Pago::Pago()
{
    _id= 0;
    _fechaPago= Fecha(0,0,0);
    _idFormaPago= 0;  // de 1 a 5;
    _importe=0;
}
Pago::Pago(int id,Fecha f,int idFormaPago, float importe){
    _id=id;
    _fechaPago=f;
    _idFormaPago=idFormaPago;  // de 1 a 5;
    _importe=importe;
}
int Pago::getCantidadRegistros(){
        FILE *p;
        p=fopen("tareas.dat","rb");
            if(p==NULL){
                return 0;
            }
        fseek(p,0,SEEK_END);
        int bytes=ftell(p);
        fclose(p);
        return  bytes/sizeof(Pago);
}

bool Pago::guardar( Pago reg){
    FILE *p;
    p=fopen("pagos.dat","ab");
    if(p==NULL){
        return false;
    }
    bool pudoEcribir = fwrite(&reg,sizeof(Pago),1,p);
    fclose(p);
    return pudoEcribir;

}

Pago Pago::leer(int nroRegistro){
    Pago aux;
    FILE *p=fopen("pagos.dat","rb");
    if(p==NULL){
        return aux;
    }

    fseek(p,nroRegistro*sizeof(Pago),SEEK_SET);

    fread(&aux,sizeof(Pago),1,p);
    fclose(p);

    return aux;

}
void Pago::cargarPago(){
    int idMulta,idFormaPago, dia, mes, anio;
    Pago pago;
    cout<<"-----Cargar---------: "<<endl;
    cout<<"Id MULTA; ";
    cin>>idMulta;
    cout<<"Id Firma";
    cin>>idFormaPago;
    cout<<"DIA: ";
    cin>>dia;
    cout<<"Mes: ";
    cin>>mes;
    cout<<"Anio: ";
    cin>>anio;

    Fecha fecha(dia,mes,anio);


    pago.setId(idMulta);
    pago.setIdFormaPago(idFormaPago);
    pago.setFechaPago(fecha);

    Multa multa;
    MultaArchivo multaArchivo;
    int i,cantMulta=multaArchivo.getCantidadRegistros();

    bool existePago=0;

    for(i=0;i<cantMulta;i++)
    {
        multa=multaArchivo.leer(i);
       if(multa.getIDMulta()==idMulta){
            if(multa.getFechaMulta().getAnio()==anio && multa.getFechaMulta().getMes()==mes){
                cout <<"Aplica Descuento "<<endl;
                multa.setMonto(multa.getMonto()*0.8);
                pago.setImporte(multa.getIDMulta());
                existePago=true;
                break;
            }else{
                pago.setImporte(multa.getIDMulta());
                existePago=true;
                break;
            }
       }
    }
    if(existePago==true){
        pago.guardar(pago);
        //modificarMulta(int idMulta);
    }
}
bool modificarMulta (int idMulta){
    MultaArchivo multaArchivo;
    Multa multa;

    int posMulta=multaArchivo.buscar(idMulta);
    multa=multaArchivo.leer(posMulta);
    multa.setPagada(1);
    if(multaArchivo.guardar(multa,posMulta)){
        cout<<"Actualizado a pagada";
    }else{
        cout<<"No se puedo actualizar";
    }

}
