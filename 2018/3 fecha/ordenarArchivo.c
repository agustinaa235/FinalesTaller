/* Escriba una función ISO C que permita procesar un archivo texto sobre sí
mismo, que contenga una palabra por línea. El procesamiento consiste en ordenar
las palabras (líneas) alfabéticamente considerando que el archivo no entra en
memoria. */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdbool.h>
int leoPalabra( char* palabra, FILE* lectura){

    char* ret = fgets(palabra, 1000, lectura);
    if (!ret ){
        return 0;
    }
}
int minPalabras(int sizePalabra1, int sizePalabra2){
    if (sizePalabra1 > sizePalabra2){
        return sizePalabra2;
    }
    return sizePalabra1;
}

int main(){
    FILE* lectura = fopen("texto.txt", "r");
    FILE* escritura = fopen("texto.txt", "r+");
    int bytes = 0;
    char buf1[1000];
    char buf2[1000];
    const char* enter = "\n";
    bool ordenado = false;
    bool eof = false;
    while (!ordenado){
      ordenado = true;
      eof = false;
        while (!eof){
            int sizePalabra1 = leoPalabra(buf1, lectura);
            int sizePalabra2 = leoPalabra(buf2, lectura);
            if (sizePalabra1 == 0 || sizePalabra2 == 0){
                eof = true;
            }
            if (strncmp(buf1, buf2, minPalabras(sizePalabra1, sizePalabra2)) > 0){
                // hago el switch
                printf("estre al switch\n");
                ordenado = false;
                bytes += fwrite(buf2, sizeof(char), sizePalabra2, escritura);
                bytes += fwrite(&enter, sizeof(char), 1, escritura);
                bytes += fwrite(buf1, sizeof(char), sizePalabra1, escritura);
            }
        }
    }
    ftruncate(fileno(escritura), bytes);
    fclose(escritura);
    fclose(lectura);
    return 0;
}
