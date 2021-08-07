/* Escriba un programa que reciba por línea de comandos un Puerto y una IP.
El programa debe aceptar una única conexión e imprimir en stdout la sumatoria
de los enteros recibidos en cada paquete. Un paquete está definido como una
sucesión de números recibidos como texto, en decimal, separados por comas y
terminado con un signo igual (ej: “27,12,32=”). Al recibir el texto ‘FIN’ debe
finalizar el programa ordenadamente liberando los recursos. */
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
        printf("cant de argumentos invalida");
        return -1;
    }
    char* host = /*argv[1]*/ "127.0.0.1";
    char* port = /*argv[2]*/ "8080";
    struct addrinfo hints;
    struct addrinfo* res;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = 0;
    getaddrinfo(host, port, &hints, &res);
    bool bine = false;
    int socket_server = -1;
    while (!bine){
        socket_server = socket(res->ai_family, res->ai_socktype,
                                res->ai_protocol);
        if (socket_server > -1){
            bind(socket_server,res->ai_addr, res->ai_addrlen);
            listen(socket_server,1);
            bine = true;
        }
    }
    freeaddrinfo(res);
    int socket_aceptador = accept(socket_server,NULL, NULL);
    int acumulador = 0;
    char aux = ' ';
    bool termine = false;
    bool hubo_un_error = false;
    char key[3] = "FIN";
    int i = 0;
    while (!termine && !hubo_un_error){
        ssize_t cant_recv = recv(socket_aceptador, &aux, sizeof(aux), 0);
        if (cant_recv < 0){
              hubo_un_error = true;
        } else if (cant_recv == 0){
              termine = true;
        } else if (aux == '='){
              fprintf( stdout, "%i\n", acumulador);
              acumulador = 0;
        } else if (aux == key[i]){
                i++;
                if (i == 3){
                    termine = true;
                }
        } else {
              if (aux != ',' && aux != '\n'){
                  acumulador += aux - '0';
              }
        }
    }
    shutdown(socket_aceptador, SHUT_RDWR);
    close(socket_aceptador);
    close(socket_server);

}
