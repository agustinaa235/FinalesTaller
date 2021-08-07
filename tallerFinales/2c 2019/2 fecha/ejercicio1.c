/* Escriba un programa (desde la inicialización hasta la liberación de los
recursos) que reciba paquetes de la forma nnn+nn+....+nnnn= (numeros separados
por +, seguidos de =) e imprima el resultado de la suma de cada paquete por
pantalla. Al recibir un paquete vacío (“=”) debe cerrarse ordenadamente. No
considere errores. */

/* no aclara si es cliente o servidor, hago cliente */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>

int main(int argc, char** argv){
    if (argc < 3){
        printf(" cantidad invalida de argumentos");
        return 0;
    }
    char *host = "127.0.0.1";
    char *port = "8080";
    struct addrinfo hints;
    struct addrinfo* res;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = 0;
    getaddrinfo(host, port, &hints, &res);
    bool conecte = false;
    int socket_cliente = -1;
    while (!conecte){
        socket_cliente = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
        if (socket_cliente < 0){
            printf ("falla de creacion de socket");
        } else {
            if (connect(socket_cliente, res->ai_addr, res->ai_addrlen) < 0){
                printf("Falla en conexion");
            } else {
                conecte = true;
            }
        }
    }
    freeaddrinfo(res);
    char aux = ' ';
    bool termine = false;
    bool hubo_un_error = false;
    int acumulador = 0;
    int contador = 0;
    while (!termine &&!hubo_un_error){
        ssize_t cant_recv = recv(socket_cliente, &aux, sizeof(aux), 0);
        contador++;
        if (cant_recv < 0){
            hubo_un_error = true;
        } else if (cant_recv == 0){
              termine = true;
        } else if (aux == '='){
              if (contador == 2){
                  termine = true;
              } else{
                  printf("la suma total: %i\n", acumulador);
                  acumulador = 0;
                  contador = 0;
              }
        } else{
            if (aux != '+' && aux !='\n'){
                int aux2 = aux - '0';
                printf("valor que llega: %i\n", aux2);
                acumulador += (aux - '0');
            }
        }
    }
    shutdown(socket_cliente, SHUT_RDWR);
    close(socket_cliente);
    return 0;
}
