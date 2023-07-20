#include "ExameneFinal.h"
#include "EstudiantesArchivo.h"
#include "Estudiante.h"
#include "Fecha.h"

ExameneFinal::ExameneFinal()
{
    //ctor
}
void crearExamenFinal(){
    /*
    - No se puede registrar examen con un alumno que no existe en el sistema.
- Solo pueden registrar exámenes en materias donde el alumno aún no haya aprobado.
- No puede registrar un examen a una materia que no existe.
(30- Puntos)
*/
ExameneFinal exf,aux;
    int id,legajo, dia, mes ,anio, nota, idmateria;
    string obsevacion;

    cin>>legajo;
    cin>>idmateria;
    cin>> dia;
    cin>> mes;
    cin>>anio;
    cin>>nota;
    id=exf.getCantidadRegistros();
    exf.setId(id);
    exf.setLegajo(legajo);
    exf.setIdMateria(idmateria);
    exf.setFechaExamen(Fecha(dia, mes, anio));
    exf.setNota(nota);

    EstudiantesArchivo arch;

    if( arch.buscar(legajo)>=0)
    {
        if(materiaNoAprobada(legajo,idmateria)==true){
                exf.guardar(exf);
        }
    }
}
int ExameneFinal::getCantidadRegistros(){
        FILE *p;
        p=fopen("finales.dat","rb");
            if(p==NULL){
                return 0;
            }
        fseek(p,0,SEEK_END);
        int bytes=ftell(p);
        fclose(p);
        return  bytes/sizeof(ExameneFinal);
}

bool ExameneFinal::guardar( ExameneFinal reg){
    FILE *p;
    p=fopen("finales.dat","ab");
    if(p==NULL){
        return false;
    }
    bool pudoEcribir = fwrite(&reg,sizeof(ExameneFinal),1,p);
    fclose(p);
    return pudoEcribir;

}

ExameneFinal ExameneFinal::leer(int nroRegistro){
    ExameneFinal aux;
    FILE *p=fopen("finales.dat","rb");
    if(p==NULL){
        return aux;
    }

    fseek(p,nroRegistro*sizeof(ExameneFinal),SEEK_SET);

    fread(&aux,sizeof(ExameneFinal),1,p);
    fclose(p);

    return aux;

}
bool materiaNoAprobada(int legajo, int idmateria)
{

}

void ExameneFinal::alumnosAprobados(){
        EstudiantesArchivo estudiantesArchivo;
        Estudiante estudiante;
        int cantEst=estudiantesArchivo.getCantidad();



        for(int i=0; i < cantEst;i ++){
            estudiante=estudiantesArchivo.leer(i);
            if( aproboTodasLasMaterua(estudiante.getLegajo()))
            {
                cout<<estudiante.getNombres()<<endl;
            }
        }
}
bool aproboTodasLasMaterua( int legajo){

    ExameneFinal archEx;
    int cant=archEx.getCantidadRegistros();
    int v[10]={0};

    for(int j=0; j < cant; j ++ ){
        archEx=archEx.leer(j);
        if( legajo==archEx.getLegajo() && archEx.getNota()<7)
        {
            v[archEx.getIdMateria()-100]=-1;
        }
    }
    for(int j=0; j < cant; j ++ ){
        archEx=archEx.leer(j);
        if( legajo==archEx.getLegajo() && archEx.getNota()>6)
        {
            v[archEx.getIdMateria()-100]=1;
        }
    }
    bool aprobotodo=true;
    for (int i=0; i<10;i++){
        if(v[i]<0){
            aprobotodo=false;
        }
    }
    return aprobotodo;
}

void ExameneFinal::dificultadExamen(){
    int anio;
    cin>>anio;

    ExameneFinal archEx;
    int cant=archEx.getCantidadRegistros();
    int v[10]={0};
    int contarTotal=0;
    int contarAprobados;
    int contarDesaprobados;

    for( int i=0; i<10;i++){
            for(int j=0; j < cant; j ++ ){
            archEx=archEx.leer(j);
                if(archEx.getFecha().getAnio()==anio && archEx.getIdMateria()== (100+i)){
                    contarTotal++;
                    if( archEx.getNota()>=7){
                        contarAprobados++;
                    }
                    if( archEx.getNota() < 7){
                        contarDesaprobados++;
                    }
                }
            }
    }
    cout<< " Aprobados : "<< (contarAprobados * 100) / contarTotal<< endl;
    cout<< " Aprobados : "<< (contarDesaprobados * 100) / contarTotal<< endl;

}
