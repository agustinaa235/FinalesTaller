//Escriba el .H de una biblioteca de funciones ISO C para números complejos.
//Incluya, al menos, 4 funciones.

#ifndef _COMPLEJO_
#define _COMPLEJO_

typedef complejo{
    int numeroReal;
    int numeroImaginario;
}Complejo_t;

void crearComplejo(int numeroReal, int numeroImaginario);
int obtenerAngulo();
int obtenerModulo();
int distanciaEntreOtroComplejo(Complejo_t otroComplejo);
void DestruirComplejo();


#endif _COMPLEJO_
