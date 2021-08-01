/*Escriba un programa C que tome 2 cadenas por línea de comandos: A y B; e
imprima la cadena A después de haber duplicado todas las ocurrencias de B. ej.:
reemp.exe “El final está aprobado” aprobado -----> El final está aprobado
aprobado */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void procesarCadenas(char* cadena1, char* cadena2){
    for (int i = 0; i< strlen(cadena1); i++){
        bool esta = false;
        int pos1 = i;
        int pos2 = 0;
        if (cadena1[pos1] == cadena2[pos2]){ //primer letra es igual
            esta = true;
            pos1++;
            pos2++;
            while (esta && pos2 < strlen(cadena2)){ //verficio las otras
                if (cadena1[pos1] != cadena2[pos2]){
                    esta = false; // no se verifican las otras letras;
                }
                pos1++;
                pos2++;
            }
            if (esta && (pos1 - i) == strlen(cadena2)){// verifico la cantidad de letras
                  printf("%s ", cadena2);
            }
        }
        printf("%c", cadena1[i]);
    }
}



int main(int argc, char** argv){
    if (argc < 3){
        printf(" ERROR, NO HAY CANTIDAD SUFICIENTE DE ARGUMENTOS");
        return 0;
    }
    char* cadena1 = "El final esta aprobado"/*argv[1]*/;
    char* cadena2 = "aprobado" /*argv[2]*/;
    procesarCadenas(cadena1, cadena2);
    return 0;
}
