#ifndef VENTA_H
#define VENTA_H


class Venta
{
    private:
            int     _codigo;
            float   _precio;
            int     _cantidad;
    public:
        Venta();

        void setCodigo(int n)   { _codigo=n;  }
        void setPrecio(int n)   { _precio=n;   }
        void setCantidad(int n) { _cantidad=n;  }

        int getCodigo(){ return _codigo;}
        float getPrecio(){return _precio;}
        int getCantidad(){return _cantidad;}

        float getTotal(){ return _precio*_cantidad;}

        void Mostrar();
        void Cargar();
        void modificar();


};

#endif // VENTA_H
