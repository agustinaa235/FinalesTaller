/***
Escribir un programa C que procese el archivo “numeros.txt” sobre sí mismo
(sin crear archivos intermedios y sin subir
el archivo a memoria). El procesamiento consiste en leer grupos de 4 caracteres
hexadecimales y reemplazarlos por los correspondientes dígitos decimales
(que representen el mismo número leído pero en decimal).
***/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void procesar(const char* nombre){
    FILE* lectura = fopen("numero.txt", "r");
    if (!lectura){
        printf("no se pudo abrir archivo lectira");
        return;
    }
    FILE* escritura = fopen("numero.txt", "r+");
    if (!escritura){
        printf("no se pudo abrir archivo escritura");
        fclose(lectura);
        return;
    }
    unsigned char hexa[6];
    int cant_leido = 0;
    int numero = 0;
    int potencia = 1;
    int bytes = 0;
    char enter "\n";
    cant_leido = fread(hexa, sizeof(hexa), 5, lectura);
    while (feof(lectura)){
        // paso de hexa a decimal
        char numeroTexto[10];
        for (int i = cant_leido - 2; i>= 0; i--){
            int caracter = ((int)(hexa[i]) - '0');
            if (caracter > 10){
                caracter -= 7;
            }
            numero += caracter* potencia;
            potencia = potencia << 4;
        }
        bytes += sprintf(numeroTexto, "%d", numero);
        fwrite(numeroTexto, sizeof(numeroTexto), bytes, escritura);
        fwrite(enter, sizeof(enter), 1, escritura);
        bytes++;
        numero = 0;
        potencia = 1;
        cant_leido = fread(hexa, sizeof(hexa), 5, lectura);
    }
    rewind(escritura);
    ftruncate(fileno(escritura), bytes -1);
    fclose(escritura);
    fclose(lectura);
}

int main(int argc, char** argv){
    if (argc < 2){
        return 0;
    }
    procesar(argv[1]);
    return 0;
}
