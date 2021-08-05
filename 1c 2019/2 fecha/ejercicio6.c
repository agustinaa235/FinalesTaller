/*Escriba un programa C que tome 2 cadenas por línea de comandos: A y B; e
imprima la cadena A después de haber duplicado todas las ocurrencias de B.. ej.
: reemp.exe “Este es el final” final -----> Este es el final final*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
void verificarDuplicados(char* cadena1, char* cadena2){
    //printf("Entre", cadena1[i]);
    int largo_cadena1 = strlen(cadena1);
    int pos_aux1 = 0;
    bool esta = false;
    for (int i = 0; i< largo_cadena1; i++){
        pos_aux1 = i;
        int pos_cadena2 = 0;
        if (cadena1[pos_aux1] == cadena2[pos_cadena2]){ // si primer caracter coincide

            esta = true;
            pos_aux1++;
            pos_cadena2++;
            while (esta && pos_cadena2 < strlen(cadena2)){
                  if (!(cadena1[pos_aux1] == cadena2[pos_cadena2])){ // si algun caracter no coincide no va
                      esta = false;
                  }
                  pos_aux1++;
                  pos_cadena2++;
            }
            if (esta){
                printf("%s ", cadena2);
                esta = false;
            }
        }

        printf("%c", cadena1[i]);
    }
}


int main(int argc, char** argv){
    if (argc != 3){
        return -1;
    }
    char* cadena1 = "Este es el final";
    char* cadena2 = "final";
    verificarDuplicados(cadena1, cadena2);
    return 0;
}
