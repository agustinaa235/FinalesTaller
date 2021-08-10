/* Escriba un programa que reciba por línea de comandos un Puerto y una IP.
El programa debe conectarse y quedar en escucha de paquetes con la forma
“d..d+d..d+...=”. El programa debe imprimir en stdout cada suma hasta que la
misma sea 0 (cero). En ese caso debe finalizar ordenadamente. */ /* CLIENTE */
#include <iostream>
#include <stdbool.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string>
#include <ostream>
#include <cstring>

int main(int argc, char** argv){
    if (argc < 3){
        printf("cant insufienciente de argumentos \n");
        return 0;
    }
    const char* host = "127.0.0.1";
    const char* port = "8080";

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
    int acumulador = 0;
    bool termine = false;
    bool hubo_un_error = false;
    int numero;
    std::string numeroTexto;
    while (!termine && !hubo_un_error){
        ssize_t cant_recv = recv(socket_cliente, &aux, sizeof(aux), 0);
        if (cant_recv < 0){
            hubo_un_error = true;
        } else if (cant_recv == 0){
              termine = true;
        } else if (aux == '='){
              if (acumulador == 0){
                  termine = true;
              } else {
                  numero = std::stoi(numeroTexto);
                  acumulador += numero;
                  numeroTexto.clear();
                  std::cout << "me llego un = \n";
                  std::cout << acumulador << std::endl;
                  acumulador = 0;
              }
        } else if (aux == '+'){
            numero = std::stoi(numeroTexto);
            acumulador += numero;
            std::cout << " valor acumulador: \n" << acumulador;
            numeroTexto.clear();
        } else {
            if (aux != '\n'){
              numeroTexto.push_back(aux);
              std::cout << "numero que me llega: \n"<< numeroTexto;
            }
        }

    }
    shutdown(socket_cliente, SHUT_RDWR);
    close(socket_cliente);
    return 0;
}
