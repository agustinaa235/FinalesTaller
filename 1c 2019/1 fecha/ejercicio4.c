
/*******
Escribir un programa ISO C que reciba por argumento el nombre de un archivo de texto y
lo procese sobre sí mismo (sin crear archivos intermedios ni subiendo todo su contenido
a memoria). El procesamiento consiste en eliminar las líneas de 1 sola palabra.
*******/

#include <stdio.h>
#include <string.h>
#include <unistd.h>

void procesarArchivo(FILE* lectura, FILE* escritura){
    char aux = ' ';
    int bytes = 0;
    int cantidad_espacios = 0;
    int cant_letras = 0;
    fread(&aux,sizeof(char),1,lectura);
    while (!feof(lectura)){
        printf("letra: %c\n", aux);
        while (aux != '\n' && aux != feof(lectura)){
              if (aux == ' '){
                  cantidad_espacios++;
              }
              cant_letras++;
              fwrite(&aux, sizeof(aux),1, escritura);
              fread(&aux, sizeof(aux),1, lectura);
              printf("letra: %c\n", aux);
        }
        if (cantidad_espacios == 0){
              printf("entre");
              fseek(escritura, -cant_letras, SEEK_CUR);
        } else{
              bytes += cant_letras;
        }
        fwrite(&aux,sizeof(char),1,escritura);
        bytes++;
        fread(&aux,sizeof(char),1,lectura);
        cant_letras = 0;
        cantidad_espacios = 0;

    }
    rewind(escritura);
    ftruncate(fileno(escritura), bytes);
    return;
}
int main(int argc, char const* argv[]){
    FILE* lectura = fopen("archivo.txt"/*argv[1]*/, "r+");
    FILE* escritura = fopen("archivo.txt"/*argv[1]*/, "r+");
    if (lectura == NULL){
        printf("error");
        return 0;
    }
    if (escritura == NULL){
        printf("error");
        fclose(lectura);
        return 0;
    }
    procesarArchivo(lectura, escritura);
    fclose(escritura);
    fclose(lectura);
    return 0;

}
