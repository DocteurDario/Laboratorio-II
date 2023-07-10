#include "Fecha.h"
#include <iostream>
#include <string>


Fecha::Fecha()
{
    _dia=1;
    _mes=1;
    _anio=2023;
}
Fecha::Fecha(int d, int m, int a){

      if(esFechaValida(d,m,a)==true){
        _dia=d;
        _mes=m;
        _anio=a;
    }
    else
    {
        _dia=1;
        _mes=1;
        _anio=2023;
    }
}
bool Fecha::esFechaValida(int d, int m, int a){

    if( d>=1 && d >= 31 || m>= 1 && m<=12 || a>=1900 && a<=3000 ){
        return true;
    }
    else
    {
        return false;
    }
}
int Fecha::getDia(){
    return _dia;
    }
int Fecha::getMes(){
    return _mes;
    }
int Fecha::getAnio(){
    return _anio;
    }
void Fecha::setDia(int n){
    bool correcto=false;
    while(correcto!=true){
        if(n>0 && n<31){
            _dia=n;
            correcto=true;
        }
        else
        {
            correcto=false;
            std::cout<<"Error al ingresar un dia !."<<std::endl;
        }
    }
}
void Fecha::setMes(int n){
    bool correcto=false;
    while(correcto!=true){
        if(n>=1 && n<=12){
            _mes=n;
            correcto=true;
        }
        else
        {
            correcto=false;
            std::cout<<"Error al ingresar un mes !."<<std::endl;
        }
    }
}
void Fecha::setAnio(int n){
    bool correcto=false;
    while(correcto!=true){
        if(n>=1900&& n<=3000){
           _anio=n;
            correcto=true;
        }
        else
        {
            correcto=false;
            std::cout<<"Error al ingresar un año !."<<std::endl;
        }
    }
}

void Fecha::aumentarDia(){
    int diasEnMes=obtenerDiasEnMes(_mes,_anio);
    if(_dia==diasEnMes)
    {
        _dia=1;
        if(_mes==12){

            _mes=1;
            _anio++;
        }else{
        _mes++;
        }
    }
    else{
        _dia++;
    }
}
void Fecha::restarDia(){
    if(_dia==1){
        if( _mes==1)
        {
         _mes--;
         _anio--;
         _dia=obtenerDiasEnMes(_mes,_anio);
        }else{
         _dia--;
         _mes--;
        }
    }else{
    _dia--;
    }
}

bool Fecha::esBisiesto(int a){

    if((a%4==0 && a%100!=0)|| a%400==0) {
        return true;
    }
    else{
        return false;
    }
}
int Fecha::obtenerDiasEnMes(int m, int a){
    if(m==2){
        if(Fecha::esBisiesto(a)){
            return 29;
        }
        else{
            return 28;
        }
    }
    if(m==4||m == 6|| m==9 || m==11)
    {
        return 30;
    }
    if(m==1||m == 3|| m==5 || m==7|| m== 8 || m==10|| m==12)
    {
        return 31;
    }
}
void Fecha::agregarDias(int dias)
{
    if(dias>0){
        for(int i=0;i<dias;i++)
        {
            aumentarDia();
        }
    }
    if(dias<0){
        for(int i=0;i<dias;i++)
        {
            restarDia();
        }
    }
}
std::string Fecha::toString(std::string formatoFecha){
    //std::string formatoFecha = "DD/MM/YYYY ";
    std::string DD= std::to_string(_dia);
    std::string MM= std::to_string(_mes);
    std::string YYYY= std::to_string(_anio);

    if(_dia<10){
        DD="0"+std::to_string(_dia);
    }
    if(_mes<10){
        MM="0"+std::to_string(_mes);
    }
    if(formatoFecha=="DD/MM/YYYY"){
        formatoFecha=DD+"/"+MM+"/"+YYYY;
    }
    else if(formatoFecha== "YYYY/MM/DD"){
        formatoFecha=YYYY+"/"+MM+"/"+DD;
    }
    else {
         formatoFecha=DD+"/"+MM+"/"+YYYY;
    }

return formatoFecha;
}
