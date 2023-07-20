#ifndef PAGO_H
#define PAGO_H
#include "Fecha.h"

bool modificarMulta (int idMulta);

class Pago
{

    private:
        int _id;
        Fecha _fechaPago;
        int _idFormaPago; // ID de Forma 1 a 5;
        float _importe;

    public:
        Pago();
        Pago(int id,Fecha f,int idFormaPago, float importe);
        //setters
        void setId( int n){_id=n; }
        void setFechaPago(Fecha fecha){_fechaPago=fecha;}
        void setIdFormaPago( int n){_idFormaPago=n; }
        void setImporte(float n){_importe=n;}
        //getters
        int getId(){return _id; }
        Fecha getFechaPago(){return _fechaPago; }
        int getIdFormaPago(){return _idFormaPago; }
        float getImporte() {return _importe;}
        int getCantidadRegistros();
        bool guardar( Pago reg);
        Pago leer(int nroRegistro);
        void cargarPago();


};

#endif // PAGO_H
