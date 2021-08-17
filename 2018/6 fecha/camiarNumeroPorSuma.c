/* Escriba una rutina que procese un archivo binario indicado por parametro sobre
si mismo sumarizando los listados de numeros que posee almacenado. La sumarizacion
 consiste en recorrer los valores enteros de 32 bits con signo grabados en formato
big-endian y acumular sus valores hasta encontrar el valor 0xffffffff que se
considera un separador entre listados. Todos los valores enteros detectados son
reemplazados por su sumatoria (en el mismo formati) manteniendo luego el
elemento separador. Considere archivos bien formados.*/

/* ARCHIVO SE ACHICA */
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>
#include <inttypes.h>
#include <arpa/inet.h>

void gen_file(const char* filename) {
    FILE* file = fopen(filename, "wb");
    uint32_t numbers[11] = {1,1,1,1,1, 0xffffffff, 2,2,2,2, 0xffffffff};
    for (int i = 0; i < 11; i++) {
    	int32_t numb = htonl(numbers[i]);
    	fwrite(&numb, sizeof(int32_t), 1, file);
    }

    fclose(file);
}
void read_answer(FILE* file) {
    long int seek = 0; int32_t number;
    printf("leo archivo ");
    fseek(file, 0, SEEK_SET);
    while (fread(&number, sizeof(number), 1, file) == 1) {
    	   number = ntohl(number);
         if (number != 0xffffffff){
            printf("%" PRIu32 "\n", number);
        }

    }
    printf("\n");
}

int main(){
    gen_file("sumaNumeros.dat");
    FILE* lectura = fopen("sumaNumeros.dat", "rb");
    FILE* escritura = fopen("sumaNumeros.dat", "rb+");

    int32_t aux;
    int bytes = 0;
    int32_t suma = 0;
    fread(&aux, sizeof(aux), 1, lectura);
    while (!feof(lectura)){
        while (aux != 0xffffffff){

            suma += ntohl(aux);
            fread(&aux, sizeof(aux), 1, lectura);
        }
        printf("suma :%d \n", suma);
        int32_t sumaAux = htonl(suma);
        fwrite(&sumaAux, sizeof(sumaAux), 1, escritura);
        fwrite(&aux, sizeof(aux), 1, escritura);
        bytes += 2*sizeof(int32_t);
        fread(&aux, sizeof(aux), 1, lectura);
        suma = 0;
    }
    ftruncate(fileno(escritura), bytes);
    read_answer(lectura);
    fclose(escritura);
    fclose(lectura);
    return 0;
}
