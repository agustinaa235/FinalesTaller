/* Escribir un programa ISO C MULTIPLATAFORMA que procese el archivo
“bigEndian.dat” sobre sí mismo, leyendo nros. de 4 bytes Big-Endian y
triplicando los impares. */


#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/types.h>
#include <arpa/inet.h>

int main(){
    FILE* lectura = fopen("bigEndian.dat", "rb");
    if (!lectura){
        return 0;
    }
    FILE* escritura = fopen("bigEndian.dat", "rb+");
    if (!escritura){
        fclose(lectura);
        return 0;
    }
    uint32_t aux;
    uint32_t numero;
    int bytes = 0;
    fread(&aux, sizeof(aux), 1, lectura);
    while (!feof(lectura)){
        numero =  htons(aux);
        fwrite(&numero, sizeof(numero), 1, escritura);
        bytes += sizeof(numero);
        if (numero % 2 == 1){
          fwrite(&numero, sizeof(numero), 1, escritura);
          bytes += sizeof(numero);
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
