/*Escribir un programa ISO C que procese el archivo de enteros de 2 bytes
bigendian cuyo nombre es recibido como parámetro. El procesamiento consiste en
eliminar los número múltiplos de 3, trabajando sobre el mismo archivo
(sin archivos intermedios ni en memoria) */


#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/types.h>
#include <arpa/inet.h>



int main(int argc, char** argv){
    FILE* lectura = fopen("binario.dat", "rb");
    FILE* escritura = fopen("binario.dat", "rb+");
    if (!lectura){
        printf("No se pudo abriri archivo lectura");
        return 0;
    }
    if (!escritura){
        fclose(lectura);
        printf(" No se oudo abrir archivo escritura");
    }
    uint16_t num;
    uint16_t aux;
    fread(&aux, sizeof(aux), 1, lectura);
    int bytes = 0;
    while (!feof(lectura)){
        num = htons(aux);
        if (!(num % 3 == 0)){
            fwrite(&num, sizeof(num), 1, escritura);
            bytes += sizeof(short);
        }
        fread(&aux, sizeof(aux), 1,lectura);
    }
    ftruncate(fileno(escritura),bytes);
    fclose(escritura);
    fclose(lectura);
    return 0;
}
