/* Defina una rutina en C que se conecte a la IP 8.8.8.8, al puerto 8192 y
reciba un archivo binario. El archivo recibido debe ser descargado a un archivo
llamado recibido.bin cuidando el uso de recursos de memoria. El archivo
finaliza al detectar conexion cerrada. */


int main(){
    const char* ip = "8.8.8.8";
    const char* puerto = "8192";
    FILE* escritura = fopen("recibido.bin", "wb");

    struct addrinfo hints, *res, *ptr;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = 0;

    getaddrinfo(ip, puerto &hints, &res);
    ptr = res;
    bool conecte =false
    int socket_cliente = -1;
    while (!conecte){
        socket_cliente = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
        if (socket_cliente > 0){
            connect(socket_cliente, ptr->ai_addr, ptr->ai_addrlen);
            conecte = true;
        } else {
            ptr = ptr->ai_next;
        }
    }
    freeaddrinfo(res);
    bool termine = false;
    char aux;
    while (!termine){
        ssize_t cant = recv(socket_cliente, &aux, sizeof(aux), 0);
        if (cant <= 0){
            termine = true;
        } else {
              fwrite(&aux, sizeof(aux), 1, escritura);
        }
    }
    shutdown(socket_cliente, SHUT_RDWR);
    close(socket_cliente);
    fclose(escritura);
    return 0;
}
