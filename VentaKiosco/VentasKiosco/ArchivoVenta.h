#ifndef ARCHIVOVENTA_H
#define ARCHIVOVENTA_H
#include "venta.h"
class ArchivoVenta
{
        public:
        ArchivoVenta();
        void guardar(Venta venta);
        bool guardar(Venta venta, int posicion);
        float totalRecaudado();
        int cantidadVentas();
        void obtenerVentas(Venta *ventas, int cantidadVentas);
        Venta obtenerVenta(int posicion);
        int buscarPorCodigo(int codigo);
        FILE* leerArchivo();
        FILE* guardarArchivo();
        void modificar();


};

#endif // ARCHIVOVENTA_H
