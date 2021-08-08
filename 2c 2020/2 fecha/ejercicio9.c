/* Escriba una función ISO C que permita procesar sobre sí mismo (sin generar
  archivos intermedios ni cargar el archivo completo a memoria) un archivo
  texto con palabras separadas por espacios. El procesamiento consiste en
  duplicar las palabras que tengan al menos de 2 vocales. */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void procesarArchivo(const char* nombre){
    FILE* lectura = fopen(nombre, "r");
    FILE* escritura = fopen(nombre, "r+");

    int bytes = 0;
    char aux = ' ';
    char leido[1000];
    fread(&aux, sizeof(aux), 1, lectura);
    while (!feof(lectura)){
        int i = 0;
        int vocales = 0;
        while (aux != ' ' && aux != '\n'){ // leo una palabra y cuento las vocales
            leido[i] = aux;
            i++;
            if (aux == 'a' || aux == 'e' || aux == 'i' || aux == 'o' || aux == 'u'){
                vocales++;
            }
            if (aux == 'A' || aux == 'E' || aux == 'I' || aux == 'O' || aux == 'U'){
                vocales++;
            }
            fread(&aux, sizeof(aux),1, lectura);
        }
        fwrite(&leido, sizeof(char), i, escritura); // escribo la palabra
        fwrite(&aux, sizeof(char), 1, escritura); // escribo el espacio o el \n
        bytes += i + 1;
        if (vocales >= 2){
            fwrite(&leido, sizeof(char),i, escritura); // palabra otra vez
            fwrite(&aux, sizeof(char), 1, escritura); // escribo el espacio o el \n
            bytes += i + 1;
        }
        fread(&aux, sizeof(char), 1, lectura); // leo la sieguiente linea 
    }
    ftruncate(fileno(escritura), bytes);
    fclose(escritura);
    fclose(lectura);
}

int main(int argc, char** argv){
    const char* nombre = "prueba.txt";
    procesarArchivo(nombre);
    return 0;
}
