#include <iostream>
#include <clocale>
#include "ListaDeTareas.h"
#include "Tarea.h"
#include "Fecha.h"
#include "Funciones.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    Tarea tarea;
    ListaDeTareas listaDeTareas;
    int opc=1;
    while(opc!=0)
    {
        cout<<"Opcion de 1 a 6 / con cero sale : "<<endl;
        cout<<"Opcion de 1 Cargar Tareas : "<<endl;
        cout<<"Opcion de 2: Agrega 10 tareas automaticamente : "<<endl;
        cout<<"Opcion de 3: Mostrar Lista : "<<endl;
        cout<<"Opcion de 4: Ordenar Lista : "<<endl;
        cout<<"Opcion de 5: Diferencia de Fechas : "<<endl;
        std::cin>>opc;
        switch(opc){
        case 1:{
                //tarea.CargarTarea();
                listaDeTareas.agregar(Tarea(agregarTarea()));


        }
            break;
        case 2:{
            listaDeTareas.agregar(Tarea(1,"Crear concepto del videojuego","Media",Fecha(30,4,2023),"hecho"));
            listaDeTareas.agregar(Tarea(2,"Diseñar niveles","Alta",Fecha(15,5,2023),"hecho"));
            listaDeTareas.agregar(Tarea(3,"Crear sprites","Media",Fecha(30,5,2023),"Pendiente"));
            listaDeTareas.agregar(Tarea(4,"Desarrollar la mecánica del juego","Alta",Fecha(15,6,2023),"Pendiente"));
            listaDeTareas.agregar(Tarea(5,"Programar el juego","Alta",Fecha(30,6,2023),"Pendiente"));
            listaDeTareas.agregar(Tarea(6,"Crear la música y efectos de sonido","Baja",Fecha(15,7,2023),"Pendiente"));
        }
            break;
        case 3:
            listaDeTareas.verListaDeTarea();
            break;
        case 4:
            listaDeTareas.ordenarLista();
            //listaDeTareas.verListaDeTarea();
            break;
        case 5:
            cout<<"diferencias Fechas: "<< diferenciasDeDias(Fecha(20,04,2023),Fecha(5,7,2024))<<endl;
            break;
        case 6:
            break;
        default:
            cout<<"Opcion incorrecta ..."<<endl;
            break;
        }

    }




/*

    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9 - i; j++) {
            // Obtener las fechas límite de las tareas
            Fecha fecha1 = tarea[j].getFechaLimite();
            Fecha fecha2 = tarea[j + 1].getFechaLimite();

            // Comparar las fechas manualmente
            if (fecha1.getAnio() > fecha2.getAnio() ||
                (fecha1.getAnio() == fecha2.getAnio() && fecha1.getMes() > fecha2.getMes()) ||
                (fecha1.getAnio() == fecha2.getAnio() && fecha1.getMes() == fecha2.getMes() && fecha1.getDia() > fecha2.getDia())) {
                // Intercambiar las tareas
                Tarea temp = tarea[j];
                tarea[j] = tarea[j + 1];
                tarea[j + 1] = temp;
            }
        }
    }

*/
    return 0;
}
