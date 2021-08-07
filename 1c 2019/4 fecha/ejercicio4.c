/*Escribir un programa ISO C que procese el archivo “nros_2bytes_bigendian.dat”
sobre sí mismo, eliminando los número múltiplos de 7*/

#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/types.h>
#include <arpa/inet.h>

int main(int argc, char** argv){
    FILE* lectura = fopen("nros_2bytes_bigendian.dat", "rb");
    FILE* escritura = fopen("nros_2bytes_bigendian.dat", "rb+");
    // chequear que se puedan abrir, ahora no tengo ganas

    uint16_t aux;
    uint16_t numero;
    int bytes = 0;
    fread(&aux, sizeof(aux), 1, lectura);
    while (!feof(lectura)){
        numero = htons(aux);
        if (numero % 7 != 0){
            fwrite(&numero, sizeof(numero),1, escritura);
            bytes += sizeof(numero);
        }
        fread(&aux, sizeof(aux), 1, lectura);
    }
    ftruncate(fileno(escritura), bytes);
    fclose(escritura);
    fclose(lectura);
    return 0;
}
