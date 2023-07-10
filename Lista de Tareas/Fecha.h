#ifndef FECHA_CPP
#define FECHA_CPP
#include <string>

class Fecha
{
    private:
        int _dia;
        int _mes;
        int _anio;

        bool esFechaValida(int d, int m, int a);
        bool esBisiesto(int a);
        int obtenerDiasEnMes(int m, int a);
        void aumentarDia();
        void restarDia();

    public:
        Fecha(int d, int m, int a);
        Fecha();
        int getDia() ;
        int getMes()  ;
        int getAnio() ;
        void setDia(int d) ;
        void setMes(int m) ;
        void setAnio(int a);
        void agregarDias(int dias);
        std::string toString(std::string formato="DD/MM/YYYY");
};


#endif // FECHA_CPP
