#include "Funciones.h"
#include <iostream>
#include <string.h>
#include "Pais.h"
#include "Ciudad.h"
#include <cstdio>
#include "Funciones.h"


using namespace std;
void punto1(){
    char registro[4];
    cout<<endl<<" Indicar el registro: ";
    cin>>registro;
    if(existeRegistro(registro))
    {
        cout<<endl<<" EXISTE!..";
    }else{
        cout<<endl<<"NO HAY REGISTRO!..";
    }
}
bool existeRegistro(char *registro){
    int i, cantidadRegistros=cantidadRegistroPais();
    Pais pais;
    for (i=0;i< cantidadRegistros; i++)
    {
       pais=leerPais(i);
       string codigo=pais.getCodigo();
       if(registro==codigo )
       {
           return true;
       }
    }
    return false;
}
int cantidadRegistroPais(){

    FILE *p;
    p=fopen("paises.dat","rb");
    if(p==NULL){
        cout<<"ERROR de ARCHIVO";
    }
    fseek(p,0,SEEK_END);
    int bytes= ftell(p);
    fclose(p);

    return bytes/sizeof(Pais);
}
Pais leerPais(int reg){
    Pais pais;
    FILE *p= fopen("paises.dat","rb");
    if(p==NULL){
        cout<<"Error de Archivo 1";
    }
    fseek(p,reg*sizeof(Pais),SEEK_SET);
    fread(&pais,sizeof(Pais),1,p);
    fclose(p);
    return pais;

}
bool guardar(Pais pais){
    FILE *p;
    p=fopen("paises.dat","ab");
    if(p==NULL){
        cout<< "ERROR 2";
        return -1;
    }
    bool pudo=fwrite(&pais,sizeof (Pais),1,p);
    fclose(p);
    return pudo;
}
void punto2(){
    Pais pais( "HOL","HO","HOL","Europa",83600,2441000,1971, 74.1, 65);
    if(guardar(pais)){
        cout<<"Se Guardo ";
    }else{
        cout<<"No se Guardo";
    }
}
void punto3(){
    Pais pais;
    int i, cantidaRegistros=cantidadRegistroPais();
    for(i=0;i<cantidaRegistros;i++){
        pais=leerPais(i);
        pais.mostrar();
    }
}
void punto4(){
    int i,cantidadRegistroCiudad=cantidadRegistrosCiudad();
    string idPais, idPaisClase;
    Ciudad ciudad;
    cout<<"Ingresar ID PAIS y Listar ciudades: ";
    cin>>idPais;
    for(i=0;i<cantidadRegistroCiudad;i++){
            ciudad=leerCidudad(i);
            idPaisClase= ciudad.getIDPais();
            if(idPais==idPaisClase){
                ciudad.mostrar();
                cout<<endl;
            }
    }
}
int cantidadRegistrosCiudad(){

    FILE *p;
    p=fopen("ciudades.dat","rb");
    if(p==NULL){
        cout<<"ERROR 3 CIUDAD..";
    }
    fseek(p,0,SEEK_END);
    int bytes=ftell(p);
    fclose(p);
    cout<< bytes/sizeof(Ciudad);
    return bytes/sizeof(Ciudad);
}
Ciudad leerCidudad(int registro){
    Ciudad ciudad;
    FILE *p=fopen("ciudades.dat","rb");
    if(p==NULL){
        cout<<"Error archivo coudad 4";

    }
    fseek(p,registro*sizeof(Ciudad),SEEK_SET);
    fread(&ciudad,sizeof(Ciudad),1,p);
    fclose(p);
    return ciudad;
}
void punto5(){
    Pais pais;
    float acumuladorSuperficie=0;
    int i, cantidadRegistrosPais=cantidadRegistroPais();
    for(i=0;i<cantidadRegistrosPais; i++){
            pais=leerPais(i);
            acumuladorSuperficie+=pais.getSuperficie();
    }
    cout<< " Superficie TOTAL: "<< acumuladorSuperficie;
    for(i=0;i<cantidadRegistrosPais; i++){
            pais=leerPais(i);
            cout<<"------------------------------------"<<endl;
            cout<<"NOMBRE PAIS: "<<pais.getNombre()<<endl;
            cout<<"Superficie : "<< pais.getSuperficie() <<endl;
            cout<<"Porcentaje : "<< (pais.getSuperficie()/acumuladorSuperficie)*100<<endl;
            //Porcentaje = (Superficie del país / Suma total de las superficies) * 100
    }

}
