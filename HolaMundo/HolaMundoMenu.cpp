
#include <iostream>
#include "HolaMundoMenu.h"
#include "Funciones.h"

using namespace std;

void HolaMundoMenu::menuPrincipal()
{
    cout<<"-------------------------"<<endl;
    cout<<"-----MENU HOLA MUNDO-----"<<endl;
    cout<<"-------------------------"<<endl;
    cout<<"-----1-Exite Registo Pais"<<endl;
    cout<<"-----2-Agregar un pais---"<<endl;
    cout<<"-----3-Listar paises-----"<<endl;
    cout<<"-----4-Listar ciudades---"<<endl;
    cout<<"-----5-Listar paises-(%)-"<<endl;
    cout<<"-------------------------"<<endl;
    cout<<"Opcion : ";
    opciones();
}

void HolaMundoMenu::opciones(){
    int opc;

    do{
        cin>>opc;
            switch(opc)
            {
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
            default:
                break;
            }

    }
    while(opc!=0);

}
