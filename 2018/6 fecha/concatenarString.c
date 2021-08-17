/* Escriba una funcion de C llamada strncat_new que reciba tres parametros: dos
punteros a caracter constante (S1 y S2) y un entero sin signo (L).
La funcion debe concatenar S1 con S2 y retornar una nueva cadena de caracteres
considerando L como tamaño maximo para cualquiera de los elementos (S1, S2 y la
 nueva cadena). La funcion debe detectar condiciones de erro respecto de la
 longitud y retornar NULL en cualquier caso. */

 #include <string.h>
 #include <stdio.h>
 #include <stdlib.h>

char* strncat_new(const char* s1, const char* s2, unsigned int l){
    int largo1 =  strlen(s1);
    int largo2 = strlen(s2);
    int largoTotal = (largo1 + largo2);
    if (largo1 > l || largoTotal > l || largo2 > l){
        return NULL;
    }
    char* aux = malloc(sizeof(char)*(largoTotal + 1));
    aux[largoTotal] = '\0';
/*
    for (int i = 0; i< l; i++){
        if (i != largo2){
            strncat(s1, &s2[i], largo1 + i);
        }
    }*/
    memcpy(aux, s1, largo1);
    memcpy(&aux[largo1], s2, largo2);
    return aux;
}

int main(){
    const char* cad1 = "HOLA ";
    const char* cad2 = "como estas";
    char* nuevaCadena = strncat_new(cad1, cad2, 20);
    printf("%s ", nuevaCadena);
    free(nuevaCadena);
    return 0;
}
