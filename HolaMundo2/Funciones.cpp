#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include "Funciones.h"

using namespace std;

class Mundo{
    private:
    char _codigo[4];
    char _nombre[45];
    char _NombreCiudad[45];
    int _poblacion;

    public:
    void setCodigo(const char *);
    void setNombre(const char *);
    void setNombreCiudad(const char *);
    void setPoblacion(int);
    //get
    char * getCodigo();
    char * getNombre();
    char * getNombreCiudad();
    int getPoblacion();

    bool guardar(Mundo mundo);
    int getCantidadRegistros();
    Mundo leer(int nroRegistro);


};
//get
char * Mundo::getCodigo()
{
    return _codigo;
}
char * Mundo::getNombre()
{
    return _nombre;
}
char * Mundo::getNombreCiudad()
{
    return _NombreCiudad;
}
int  Mundo::getPoblacion()
{
    return _poblacion;
}
//set
void Mundo::setCodigo(const char *codigo){
    strcpy(_codigo, codigo);
}
void Mundo::setNombre(const char *nombre){
    strcpy(_nombre, nombre);
}
void Mundo::setNombreCiudad(const char *nombreCiudad){
    strcpy(_NombreCiudad, nombreCiudad);
}
void Mundo::setPoblacion(int val)
{
    _poblacion = val;
}
bool Mundo::guardar( Mundo reg){
    FILE *p;
    p=fopen("mundo.dat","ab");
    if(p==NULL){
        return false;
    }
    bool pudoEcribir = fwrite(&reg,sizeof(Mundo),1,p);
    cout<<reg.getNombre()<<"Archivo"<<endl;
    fclose(p);
    return pudoEcribir;
}
int Mundo::getCantidadRegistros(){
        FILE *p;
        p=fopen("mundo.dat","rb");
            if(p==NULL){
                return 0;
            }
        fseek(p,0,SEEK_END);
        int bytes=ftell(p);
        fclose(p);
        return  bytes/sizeof(Mundo);
}

Mundo Mundo::leer(int nroRegistro){
    Mundo aux;
    FILE *p=fopen("mundo.dat","rb");
    if(p==NULL){
        return aux;
    }

    fseek(p,nroRegistro*sizeof(Mundo),SEEK_SET);

    fread(&aux,sizeof(Mundo),1,p);
    fclose(p);

    return aux;
}
//-------------------------------------------------------------------------------
void menu(){
    cout<<"-------------------------"<<endl;
    cout<<"-----MENU HOLA MUNDO-----"<<endl;
    cout<<"-------------------------"<<endl;
    cout<<"-1-----------------------"<<endl;
    cout<<"-2-----------------------"<<endl;
    cout<<"-3-----------------------"<<endl;
    cout<<"-4-----------------------"<<endl;
    cout<<"-5-----------------------"<<endl;
    cout<<"-6-----------------------"<<endl;
    cout<<"OPCION : ";
}
void opcionDeMenu(){
    menu();
    int opc=0;

    do{
        cin>>opc;
        switch(opc){
        case 1:
                punto1();
            break;
        case 2:
                punto2();
            break;
        case 3:
                punto3();
            break;
        case 4:
                punto4();
            break;
        case 5:
                punto5();
            break;
        case 6:
                punto6();
            break;
        case 7:
                punto7();
            break;
        case 0:
            cout<<"Salio del programa!...";
            break;
        default:
                cout<<"Error al ingresar opcion!...";
            break;
        }

    }while(opc!=0);

}

int cantidadRegistrosCiudad(){
    FILE *p;
    p=fopen("ciudades.dat","rb");
    if(p==NULL){
        cout<<"Error 1 ciudad...";
        return -1;
    }
    fseek(p,0,SEEK_END);
    int byte=ftell(p);
    fclose(p);
    return byte/sizeof(Ciudad);
}
int cantidadRegistrosPais(){
    FILE *p;
    p=fopen("paises.dat","rb");
    if(p==NULL){
        cout<<"ERROR 1 ARCHIVO PAIS...";
        return -1;
    }
    fseek(p,0,SEEK_END);
    int byte=ftell(p);
    fclose(p);
    return byte/sizeof(Pais);
}
Ciudad leerCiudad(int reg){
    Ciudad aux;
    FILE *p= fopen("ciudades.dat","rb");
    if(p==NULL){
        cout<<"Error Archivo ciudad 2... ";
        return aux;
    }
    fseek(p,reg*sizeof(Ciudad),SEEK_SET);
    fread(&aux,sizeof(Ciudad),1,p);
    fclose(p);
    return aux;
}
Pais leer(int reg){
    Pais aux;
    FILE *p;
    p=fopen("paises.dat","rb");
    if(p==NULL){
        cout<<"ERROR 2 ARCHIVO PAIS..";
        return aux;
    }
    fseek(p,reg*sizeof(Pais),SEEK_SET);
    fread(&aux,sizeof(Pais),1,p);
    fclose(p);
    return aux;
}
void leer( Pais *vec, int cantidadRegistros){
    FILE *p=fopen("paises.dat","rb");
    if(p==NULL){
        cout<<"ERROR AL LEER TODO..";
        return ;
    }
    fread(vec,sizeof(Pais),cantidadRegistros,p);
    fclose(p);
}
void leerCiudad( Ciudad *vec, int cantidadRegistros){
    FILE *p= fopen("ciudades.dat","rb");
    if(p==NULL){
        cout<<"ERROR AL LEER TODO CIUDAD...";
        return;
    }
    fread( vec,sizeof(Ciudad),cantidadRegistros,p);
    fclose(p);
}
int buscarPais(string codigo){
    Pais pais;
    int i,cantidad=cantidadRegistrosPais();
    for(i=0;i<cantidad;i++)
    {
        pais=leer(i);
        if(codigo==pais.getCodigo())
        {
            return i;
        }
    }
    return -1;
}
void punto1(){
    int mayor, cantidadPais=cantidadRegistrosPais();
    Pais aux, *vec= new Pais[cantidadPais];
    leer(vec,cantidadPais);
    for(int i=0; i<cantidadPais-1; i++){
        mayor=i;
        for(int j=i+1;j<cantidadPais;j++){
            if(vec[j].getPoblacion()>vec[mayor].getPoblacion()){
            mayor=j;
            }
        }
        aux=vec[i];
        vec[i]=vec[mayor];
        vec[mayor]=aux;
    }
    for(int i=0;i<cantidadPais;i++){
        cout<< vec[i].getCodigo()   <<endl;
        cout<< vec[i].getNombre()   <<endl;
        cout<< vec[i].getPoblacion()<<endl;
        cout<<"--------------------"<<endl;
    }
}
void punto2(){
//Ciudad::Ciudad(int id, const char *nombre, const char *idpais,int poblacion){
    Ciudad ciudad(5000,"Dario","ARG",25);
    if(existeCiudad(ciudad.getID())){
        cout<<"La ciudad ya exite, no se puede guardar"<<endl;
    }
    else{
        cout<<"La ciudad no existe, se puede agregar"<<endl;
        if(guardarCiudad(ciudad)){
            cout<<"Ciduad Guardada!..."<<endl;
        }
        else{
            cout<<"No Se Guardo. Algo fallo..."<<endl;
        }

    }
}
bool existeCiudad(int nro){
    Ciudad ciudad;
    int i, cantidadCiudad=cantidadRegistrosCiudad();

    for(i=0;i<cantidadCiudad;i++){
        ciudad=leerCiudad(i);
        if(ciudad.getID()==nro){
            return true;
        }
    }
    return false;
}
bool guardarCiudad(Ciudad ciudad){
    FILE *p=fopen("ciudades.dat","ab");
    if(p==NULL){
        cout<<"ERROR AL GUARDAR CIUDAD 23";
    }
    bool pudo= fwrite(&ciudad,sizeof(Ciudad),1,p);
    fclose(p);
    return pudo;
}
bool guardar(Pais reg, int posicionARemplazar){
    FILE *p=fopen("paises.dat","rb+");
    if(p==NULL){
        return false;
    }
    fseek(p,posicionARemplazar*sizeof(Pais),SEEK_SET);
    bool pudoEscribir=fwrite(&reg,sizeof(Pais),1,p);
    fclose(p);
    return pudoEscribir;
}
void punto3(){
 //  3 - Agregar una función global que solicite el nombre de una ciudad y la población e
 //informe qué posición ubicaría si se hiciese un ranking mundial ordenado por población de manera decreciente.
    string ciudad;
    float poblacion;
    int i, mayor,cantidaCiudad=cantidadRegistrosCiudad();

    cout<< " Indicar Ciudad : ";
    cin>>ciudad;
    cout<< "Indicar Poblacion : ";
    cin>>poblacion;

    Ciudad aux,*vec =new Ciudad[cantidaCiudad];
    leerCiudad(vec,cantidaCiudad);
    for(i=0; i<cantidaCiudad;i++){
        mayor=i;
        for(int j=i+1;j<cantidaCiudad;j++){
            if(vec[j].getPoblacion()>vec[mayor].getPoblacion())
            {
                mayor=j;
            }
        }
        aux=vec[i];
        vec[i]=vec[mayor];
        vec[mayor]=aux;
    }

    for(int pos=0; pos < cantidaCiudad ; pos++){
        string nombreAux=vec[pos].getNombre();
        if(nombreAux==ciudad ){ // Le saque la comparacion de poblacion para no perden tiempo en buscar: && vec[pos].getPoblacion())
            cout<<"Posicion :"<<pos+1 <<endl;
        }
    }
}
void punto4(){
    string codigo;
    Pais pais, aux;
    int poblacion,pos;
    cout<<"Ingresar Codigo: ";
    cin>> codigo;

    pos=buscarPais(codigo);
    if(pos>=0){
        pais=leer(pos);
        pais.mostrar();
        cout<<"---------------------:";
        cout<<"poblacion a modificar:";
        cin>> poblacion;
        pais.setPoblacion(poblacion);
        if(guardar(pais,pos)){
            cout<<"Se Pudo modificar...";
            pais=leer(pos);
            pais.mostrar();
           }else{
            cout<<"No modificado...";
           }

    }else{
        cout<<"---------------------:";
        cout<<"Codigo no entontrado :";
    }
}

void punto5(){
    Mundo mundo;
    int regitroMundo=mundo.getCantidadRegistros();
    Pais pais;
    int regitroPais=cantidadRegistrosPais();
    Ciudad ciudad,aux;
    int registroCiudad=cantidadRegistrosCiudad();
    int i, pobl=-1;
    for(i=0; i<regitroPais; i++){
        pais=leer(i);
        string paisCodigo=pais.getCodigo();
        for(int j= 0; j< registroCiudad;j++){
             ciudad=leerCiudad(j);
             if(paisCodigo== ciudad.getIDPais()){
                cout<<"--------SI-----------"<<endl;
                if(ciudad.getPoblacion()> pobl){
                    aux=ciudad;

                    cout<<"-------------------"<<endl;
                    ciudad.mostrar();
                    aux.mostrar();
                    pobl=aux.getPoblacion();
                    cout<<pobl<<endl;
                    //cout<<"------------------------";
                }
            }
        }

        mundo.setCodigo(pais.getCodigo());
        mundo.setNombre(pais.getNombre());
        mundo.setNombreCiudad(aux.getNombre());
        mundo.setPoblacion(aux.getPoblacion());
        mundo.guardar(mundo);
        cout<<mundo.getNombre()<<endl;;
        pobl=-1;
    }
}
void punto6()
{
    Mundo mundo;
    int cantidad=mundo.getCantidadRegistros();

    for(int i;i< cantidad;i++){
        mundo= mundo.leer(i);
        cout<< mundo.getCodigo()<<endl;
        cout<< mundo.getNombre()<<endl;
        cout<< mundo.getNombreCiudad()<<endl;
        cout<< mundo.getPoblacion()<<endl;
        cout<< "-----------------------"<<endl;
    }
}
void punto7(){
    Pais aux;
    int cant=cantidadRegistrosCiudad();

    for(int i=0;i<cant;i++){
        aux=leer(i);
        aux.mostrar();
    }
}
