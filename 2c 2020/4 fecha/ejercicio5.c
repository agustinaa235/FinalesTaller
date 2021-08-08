/* Escriba un programa que reciba por línea de comandos un Puerto y una IP.
El programa debe conectarse y quedar en escucha de paquetes con la forma
“d..d+d..d+...=”. El programa debe imprimir en stdout cada suma hasta que la
misma sea 0 (cero). En ese caso debe finalizar ordenadamente. */ /* CLIENTE */
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>

int main(int argc, char** argv){
    if (argc < 3){
        printf("cant insufienciente de argumentos \n");
        return 0;
    }
    char* host = /*argv[1]*/ "127.0.0.1";
    char* port = /*argv[2]*/ "8080";

    struct addrinfo hints;
    struct addrinfo* res;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = 0;

    getaddrinfo(NULL, port, &hints, &res);

    int socket_cliente = socket(res->ai_family, res->ai_socktype,
                                res->ai_protocol);
    if (socket_cliente < 0 ){
          printf(" Falla al crear socket");
          freeaddrinfo(res);
          return 0;
    }
    if (connect(socket_cliente, res->ai_addr, res->ai_addrlen) < 0){
        printf(" No se pudo conectar :(");
        freeaddrinfo(res);
        close(socket_cliente);
        return 0;
    }
    freeaddrinfo(res);
    char aux = ' ';
    int sumaTotal = 0;
    bool termine = false;
    bool hubo_un_error = false;
    while (!termine && !hubo_un_error){
        ssize_t cant_recv = recv(socket_cliente, &aux, sizeof(aux), 0);
        if (cant_recv < 0){
            hubo_un_error = true;
        } else if (cant_recv == 0){
              termine = true;
        } else if (aux != '+' && aux != '='){
            sumaTotal += (int)aux;
        } else if (aux == '='){
            if (sumaTotal != 0){
                printf("cantidad suma: %i\n", sumaTotal);
                char aux2 = (char)sumaTotal;
                fwrite(&aux2, sizeof(aux2), 1, stdout);
                sumaTotal = 0;
            } else {
                termine = true;
            }
        } else {
              termine = false;
        }
    }
    shutdown(socket_cliente, SHUT_RDWR);
    close(socket_cliente);
    return 0;
}
