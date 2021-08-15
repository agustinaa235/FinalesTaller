
/*Escribir un programa ISO C MULTIPLATAFORMA que procese el archivo “valores.txt” sobre
sí mismo. El procesamiento consiste en leer números separados por 1 espacio que se
encuentran en base 3 y escribirlos en 4 símbolos base hexadecimales, también separados
por 1 espacio*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

char pasoAHexa(int numero){
    int aux = numero % 16;
    printf(" resto : %i\n", aux);
    if (aux == 10){
        return 'A';
    } else if (aux == 11){
      return 'B';
    } else if (aux == 12){
        return 'C';

    } else if (aux == 13){
        return 'D';
    } else if (aux == 14){
        return 'E';
    } else if (aux == 15){
        return 'F';
    } else {
        return (aux + '0');
    }
}

int main(int argc, char** argv){
      FILE* lectura = fopen("valores.txt", "r");
      FILE* escritura = fopen("valores.txt", "r+");

      int bytes = 0;
      char aux;
      char numeroHexa[4];
      rewind(lectura);
      fread(&aux, sizeof(char), 1, lectura);
      char espacio = ' ';
      while (!feof(lectura)){
          int digitos = 0;
          int numero = 0;
          int base3 = 1;
          printf(" leo un numero \n");
          while (aux != ' ' && aux != '\n' && !feof(lectura)){
              digitos++;
              printf("primer lectura: %c ", aux);
              fread(&aux, sizeof(char), 1, lectura);
          }
          fseek(lectura, -2, SEEK_CUR);
          for (int i = digitos-1; i>=0; i--){
              fread(&aux, sizeof(char), 1, lectura);
              int valor = (int)(aux - '0');
              printf("valor leido: %i\n", valor);
              numero += valor*base3;
              printf("numero %i \n", numero);
              base3 = base3*3;
              fseek(lectura, -2, SEEK_CUR);
          }
          fseek(lectura, digitos -1, SEEK_CUR);
          fread(&aux, sizeof(char), 1, lectura);
          printf(" leo aux %c\n", aux);
          for (int j = 0; j<4; j++){
              char digitoHexa = pasoAHexa(numero);
              numero = numero / 16;
              printf("numero en hexa %c \n", digitoHexa);
              numeroHexa[j] = digitoHexa;
          }
          for (int a = 3; a >=0; a--){
              printf("valor a escirbir %c ", numeroHexa[a]);
              bytes += fwrite(&numeroHexa[a], sizeof(char), 1, escritura);
          }
          bytes += fwrite(&aux, sizeof(char), 1, escritura);
          fread(&aux, sizeof(char), 1, lectura);
      }
      ftruncate(fileno(escritura), bytes);
      fclose(lectura);
      fclose(escritura);
}
