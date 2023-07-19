#include <iostream>
#include "Parcial.h"
using namespace std;

int main(){
    Parcial parcial;
    int opc;
    cout<< "-----------------"<<endl;
    cout<< "----indice-------"<<endl;
    cout<< "-----------------"<<endl;
    cout<< "--Puntos del 1 al 4: -"<<endl;
    do{

        cin>> opc;
        switch(opc){
        case 1:
            parcial.Punto1();
            break;
        case 2:
            parcial.Punto2();
            break;
        case 3:
            parcial.Punto3();
            break;
        case 4:
            parcial.Punto4();
            break;
        case 0:
            cout<<"SAlio "<<endl;
            break;
        default :
            break;
        }
    }while(opc!=0);
   //parcial.Punto1();
    //parcial.Punto2();
    //parcial.Punto3();

  return 0;
}
