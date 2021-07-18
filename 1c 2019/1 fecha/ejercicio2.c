
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
/*** Escriba una función ISO C llamada Replicar que reciba 1 cadena (S),
dos índices (I1 e I2) y una cantidad (Q). La función debe retornar una copia de
S salvo los caracteres que se encuentran entre los índices I1 e I2 que serán
duplicados Q veces.Ej. replicar(“Hola”, 1, 2, 3) retorna “Hololola”. ***/
char* replica(char cadena[100], int indice1, int indice2, int Qveces){
    char *aux = malloc (sizeof (char) * 1000);
    char* aux2;
    int longitud_a_copiar = indice2 - indice1 + 1;
    int indiceAux = 0;
    bool nocopie = true;
    for(int i = 0; i< strlen(cadena); i++){
        printf (" i: %i\n", i);
        if (i>= indice1 && i<= indice2 ){
          printf("longitud_a_copiar: %i\n", longitud_a_copiar);
          if (nocopie){
              for (int j = 0; j< Qveces; j++){
                  strncpy((void*)&aux[indiceAux], (void*)&cadena[indice1], longitud_a_copiar);
                  indiceAux += longitud_a_copiar;
              }
              nocopie = false;
          }
          printf("la copiaes: %s\n: ", aux);
        }else{
            strncpy((void*)&aux[indiceAux], (void*)&cadena[i],1);
            indiceAux++;
            printf("indiceAux: %i ", indiceAux);
            printf("la copiaes: %s\n: ", aux);
        }
    }
    printf("la copiaes: %s\n: ", aux);
    return aux;
}

int main(int argc, const char* argv[]){
  char cadena[100] = "hola";
  replica(cadena, 2, 3, 3);
  //printf("la copia es: %s", copia);
  return 0;
}
