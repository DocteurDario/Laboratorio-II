#ifndef LISTADETAREAS_H
#define LISTADETAREAS_H
#include "Tarea.h"

class ListaDeTareas
{
    private:
        Tarea _listaTareas[10];
        int _cantidad;

    public:
        ListaDeTareas();
        void agregar(Tarea tarea);
        void verListaDeTarea();
        void ordenarLista();



};

#endif // LISTADETAREAS_H
