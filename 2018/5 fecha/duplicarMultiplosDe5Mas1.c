/* Escriba un programa C que reciba por argumento el nombre de un archivo
de numeros binarios de 16 bits y lo procese sobre si mismo.
El procesamiento consiste en repetir los numeros que sean "multiplos de 5 + 1"
(6, 11, 16...) */

#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/types.h>
#include <arpa/inet.h>


int main(){
    FILE* lectura = fopen("numeros.dat", "rb");
    FILE* escritura = fopen("numeros.dat", "rb+");

    int bytes = 0;
    uint16_t aux;
    int elementos = 0;
    while (!feof(lectura)){
        elementos += fread(&aux, sizeof(aux), 1, lectura);
    }
    int cantElementosEscritura = 0;
    rewind(lectura);
    fseek(escritura, 0, SEEK_END);
    while (cantElementosEscritura < elementos){
        fread(&aux, sizeof(aux), 1, lectura);
        fwrite(&aux, sizeof(aux), 1, escritura);
    }
    rewind(escritura);
    fseek(lectura, -elementos*sizeof(uint16_t), SEEK_END);
    fread(&aux, sizeof(aux), 1, lectura);
    while (!feof(lectura)){
        uint16_t numero = ntohs(aux);
        bytes += fwrite(&numero, sizeof(uint16_t), 1, escritura);
        if ((numero -1 )% 5 == 0){
            bytes += fwrite(&numero, sizeof(uint16_t), 1, escritura);
        }
        fread(&aux, sizeof(aux), 1, lectura);
    }
    ftruncate(fileno(escritura), bytes);
    fclose(escritura);
    fclose(lectura);
}
