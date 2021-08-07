/*Escriba una función ISO C que permita procesar un archivo texto que contenga
frases (1 por línea) sobre sí mismo, sin generar archivos intermedios ni cargar
el archivo completo a memoria. El procesamiento consiste en eliminar las
palabras de más de 3 letras de cada línea.*/
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>


void procesar_archivo(const char nombre_archivo[800]){
    FILE* lectura = fopen(nombre_archivo, "r");
    FILE* escritura = fopen(nombre_archivo, "r+");
    if (!lectura || !escritura){
        printf(" error al abrir archivo\n");
        return;
    }
    int bytes_totales = 0;
    int cant_letras = 0;
    char aux;
    fread(&aux, sizeof(char), 1, lectura);
    while(!feof(lectura)){
        while (aux != ' ' && aux != '\n' && !feof(lectura)){
            cant_letras++;
            fwrite(&aux, sizeof(char), 1, escritura);
            fread(&aux, sizeof(char),1, lectura);
        }
        if (cant_letras > 3){
            fseek(escritura, -cant_letras, SEEK_CUR);
        } else {
            bytes_totales += cant_letras;
        }
        fwrite(&aux, sizeof(char),1, escritura);
        bytes_totales++;
        fread(&aux, sizeof(char),1, lectura);
        cant_letras = 0;
    }
    rewind(escritura);
    ftruncate(fileno(escritura), bytes_totales);
    fclose(escritura);
    fclose(lectura);
}

int main(int argc, char** argv){
    if (argc < 2){
          printf(" ERROR CANTIDAD DE ARGUMENTOS");
          return -1;
    }
    procesar_archivo(argv[1]);
    return 0;
}
