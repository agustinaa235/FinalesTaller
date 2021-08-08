/* Escribir un programa ISO C que procese el archivo “nros2bytes.dat” sobre sí
mismo, duplicando los enteros de 2 bytes múltiplos de 3. */

#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/types.h>
#include <arpa/inet.h>


int main(int argc, char** argv){
    FILE* lectura = fopen("nros2bytes.dat", "rb");
    if (!lectura){
        return 0;
    }
    FILE* escritura = fopen("nros2bytes.dat", "rb+");
    if (!escritura){
        fclose(lectura);
        return 0;
    }
    int bytes = 0;
    uint16_t aux;
    uint16_t numero;
    fread(&aux, sizeof(aux), 1, lectura);
    while (!feof(lectura)){
        numero = htons(aux);
        fwrite(&numero, sizeof(numero), 1, escritura);
        bytes += sizeof(numero);
        if (/*sizeof(numero) == 2 && */(numero % 3) == 0){
              fwrite(&numero, sizeof(numero), 1, escritura);
              bytes += sizeof(numero);
        }
        fread(&aux, sizeof(aux), 1, lectura);
    }
    ftruncate(fileno(escritura), bytes);
    fclose(escritura);
    fclose(lectura);
    return 0;
}
