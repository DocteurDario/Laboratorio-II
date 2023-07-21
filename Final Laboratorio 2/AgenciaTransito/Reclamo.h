#ifndef RECLAMO_H
#define RECLAMO_H
#include "Fecha.h"
#include <cstdio> // Biblioteca para manejar archivos.
#include <clocale>
#include <iostream>
#include <string.h>
#include <string>

bool noExiteReclamo(int idMulta);
bool eliminarMulta(int idMulta);



class Reclamo
{
    private:
        int     _idMulta;
        Fecha   _fechaReclamo;
        int     _idSucursal;
        char    _motivo[100];
        bool    _aceptado;

    public:
        Reclamo();
        Reclamo( int id, Fecha f, int idSucursal, char * motivo, bool aceptado);
        //Setters
        void setIdMulta         ( int n ){ _idMulta=n;}
        void setFecgaReclamo    ( Fecha f ){ _fechaReclamo=f;}
        void setIdSucursal      ( int n ){ _idSucursal=n;}
        void setMotivo          ( char *motivo){  strcpy(_motivo,motivo);}
        void setAceptado         ( bool n ){ _aceptado=n;}

        //Getters
        int     getIdMulta      (){return   _idMulta;       }
        Fecha   getFecgaReclamo (){return   _fechaReclamo;  }
        int     getIdSucursal   (){return   _idSucursal;    }
        char  * getMotivo       (){return   _motivo;        }
        bool    getAceptado     () {return   _aceptado;     }

        int getCantidadRegistros();
        bool guardar( Reclamo reg);
        Reclamo leer(int nroRegistro);
        bool guardar(Reclamo reg, int posicionARemplazar);
        int buscar(int id);
        void cargarReclamo();

};

#endif // RECLAMO_H
