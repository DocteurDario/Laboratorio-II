#ifndef EXAMENEFINAL_H
#define EXAMENEFINAL_H
#include"Fecha.h"
#include <cstdio> // Biblioteca para manejar archivos.
#include <clocale>
#include <iostream>
#include <string.h>
#include <string>

using namespace std;

bool materiaNoAprobada(int legajo, int idmateria);
bool aproboTodasLasMaterua( int Legajo);

class ExameneFinal
{
     private:
        int _id; //(Autonumerico)
        int _legajo; //Legajo del alumno que realiza el examen
        char  _observacion[50];// Observación que realiza el profesor respecto al examen
        Fecha _fechaExamen; // del examen
        int _idMateria; //IDMateria [100; 109]
        int _nota; // Nota [1;10]

    public:
        ExameneFinal();
        void crearExamenFinal();
        int getCantidadRegistros();
        bool guardar( ExameneFinal reg);
        ExameneFinal leer(int nroRegistro);
        void setId( int n){_id=n;}
        void setLegajo( int n){_legajo=n;}
        void setObservacion (char *l){strcpy(_observacion,l);}
        void setFechaExamen( Fecha f){ _fechaExamen=f; }
        void setIdMateria (int n){_idMateria=n;}
        void setNota(int n){_nota=n;}

        int     getId           (){return _id;}
        int     getLegajo       (){return _legajo;}
        char    *getObservacion  (){return _observacion; }
        Fecha   getFecha        (){return _fechaExamen;}
        int     getIdMateria    (){return _idMateria;}
        int     getNota         (){return _nota; }

        void alumnosAprobados();
        void dificultadExamen();

};

#endif // EXAMENEFINAL_H
