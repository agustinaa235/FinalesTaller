Escribir un programa ISO C MULTIPLATAFORMA que procese el archivo “bigEndian.dat”
sobre sí mismo, leyendo nros. de 4 bytes Big-Endian y triplicando (escribirlos 3 veces) los
múltiplos de 3.


int main(){
    FILE* lectura = fopen("bigEndian.dat","rb");
    FILE* escritura = fopen("bigEndian.dat", "rb+");

    int elementos = 0;
    uint32_t aux;
    while (!feof(lectura)){
        elementos += fread(&aux, sizeof(uint32_t), 1, lectura);
    }
    rewind(lectura);
    fseek(escritura, 0, SEEK_END);
    int elementosEscritura = 0;
    while (elementosEscritura < elementos){
        fread(&aux, sizeof(uint32_t), 1, lectura);
        write(&aux, sizeof(uint32_t), 1, escritura);
    }
    rewind(lectura);
    fseek(escritura, 0, SEEK_END);
    elementosEscritura = 0;
    while (elementosEscritura < elementos){
        fread(&aux, sizeof(uint32_t), 1, lectura);
        write(&aux, sizeof(uint32_t), 1, escritura);
    }
    rewind(escritura);
    fseek(lectura, -elementos*sizeof(uint32_t), SEEK_CUR);
    uint32_t numero;
    int bytes;
    fread(&aux, sizeof(uint32_t), 1, lectura);
    while(!feof(lectura)){
        numero = ntohs(aux);
        bytes += fwrite(&numero, sizeof(uint32_t), 1, escritura);
        if (numero % 3 == 0){
              bytes += fwrite(&numero, sizeof(uint32_t), 1, escritura);
              bytes += fwrite(&numero, sizeof(uint32_t), 1, escritura);
        }
        fread(&aux, sizeof(uint32_t), 1, lectura);
    }
    ftruncate(fileno(escritura), bytes);
    fclose(escritura);
    fclose(lectura);
    return 0;
}
