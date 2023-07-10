#ifndef TAREA_H
#define TAREA_H
#include "Fecha.h"
#include <string>

class Tarea
{
    public:
        Tarea();
        Tarea(int id, std::string p1,std::string p2, Fecha f,std::string p3);
        void setId(int id);
        void setDescripcion(std::string palabra);
        void setDificultad(std::string palabra);
        void setFechaLimite(Fecha f);
        void setEstado (std::string palabra);

        int getId();
        std::string getDescripcion();
        std::string getDificultad();
        Fecha getFechaLimite();
        std::string getEstado();

        void CargarTarea();

        void mostrarTarea();

    private:
        int _id;
        std::string _descripcion;
        std::string _dificultad;
        Fecha _fechaLimite;
        std::string _estado;
};

#endif // TAREA_H
