
/*******
Escribir un programa ISO C que reciba por argumento el nombre de un archivo de texto y
lo procese sobre sí mismo (sin crear archivos intermedios ni subiendo todo su contenido
a memoria). El procesamiento consiste en eliminar las líneas de 1 sola palabra.
*******/

#include <stdio.h>
#include <string.h>
#define MAX_TAMANIO 1000

void eliminar_palabra(File* archivo, int tam_palabra){
  fseek(arrchivo, tam_palabra, SEEK_CUR);


}
void procesarArchivo(File* archivo){
    char palabra[MAX_TAMANIO];
    int tamanio_palabra;
    int cant_espacios;
    while(fgets(palabra, MAX_TAMANIO, archivo) != NULL){
        tamanio_palabra = strlen(palabra);
        cant_espacios = 0;
        for(int i = 0; i< tamanio_palabra; i++){
            if(palabra[i] == ' '){
                cant_espacios++;
            }
        }
        if (cant_espacios == 0){
          eliminar_palabra(archivo, tamanio_palabra); // es una linea de una sola palabra //borro
        }
    }
    return
}

int main(int argc, char const* argv[]){
    File* archivo = fopen(argv[1], "r+");
    if (archivo == NULL){
        return 0;
    }
    procesarArchivo(archivo);
    fclose(archivo);
    return 0;

}
