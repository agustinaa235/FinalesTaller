/*Escriba un programa que reciba por línea de comandos un Puerto y una IP.
El programa debe establecer una unica conexión, quedar en escucha e imprimir en
stdout todo lo recibido. Al recibir el texto ‘FINAL’ debe finalizar el programa
sin imprimir dicho texto.*/ /* CLIENTE */
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
        printf(" cant invalida de argumentos");
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

    // realizo una solo iteracion para intentar conectarme y logro concetacrme
    //por cuestiones de tiempos.
    getaddrinfo(NULL, port, &hints, &res);
    int socket_cliente = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (socket_cliente < 0){
        printf("no me pude concetar");
        freeaddrinfo(res);
        return 0;
    }
    if (connect(socket_cliente, res->ai_addr, res->ai_addrlen) < 0){
        printf(" no me pude concetar");
        freeaddrinfo(res);
        return 0;
    }
    freeaddrinfo(res);
    bool termine = false;
    char clave[10] = "FINAL\n";
    bool hubo_un_error = false;
    char buf = ' ';
    int i = 0;
    while (!termine && !hubo_un_error){
        ssize_t cant_rev = recv(socket_cliente, &buf, sizeof(buf), 0);
        if (cant_rev < 0){
            hubo_un_error = true;
        } else if (cant_rev == 0){
            termine = true;
        } else if (clave[i] == buf){
            i++;
            if(i == 5){
                termine = true;
            }
        } else {
            fwrite(&buf, sizeof(buf), 1, stdout);
            i = 0;
        }
    }
    shutdown(socket_cliente, SHUT_RDWR);
    close(socket_cliente);
    return 0;
}
