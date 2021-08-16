/* Implemente la función void ValorHex(char *hex, int *ent) que interprete la
cadena hex (de símbolos hexadecimales) y guarde el valor correspondiente en el
entero indicado por ent. */
#include <stdio.h>
#include <string.h>
int obtenerValorEnHexa(char valor){
    if (valor >= '0' && valor<= '9'){
        return (valor - '0');
    }
    if (valor == 'A' || valor == 'a'){
        return 10;
    } else if (valor == 'B' || valor == 'b'){
        return 11;
    } else if (valor == 'C' || valor == 'c'){
        return 12;
    } else if (valor == 'D' || valor == 'd'){
        return 13;
    } else if (valor == 'E' || valor == 'e'){
        return 14;
    } else {
        return 15;
    }
}
int valorHexa(char* hexa, int* ent){
    int tamanio = strlen(hexa);
    int potencia = 1;
    int aux = 0;
    printf("tamanio: %i ", tamanio);
    for (int i = tamanio - 1; i>=0; i--){
        int numero = obtenerValorEnHexa(hexa[i]);
        aux += numero*potencia;
        potencia = potencia*16;
    }
    *ent = aux;
    printf("valor en decimal %i ", aux);
    return 1;
}

int main(){
    char* hexa = "FFFF";
    int valor = 0;
    valorHexa(hexa, &valor);
    printf("valor en decimal %i ", valor);
    return 0;
}
