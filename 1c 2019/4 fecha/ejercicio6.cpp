

#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string>



int main(int argc, char** argv){
    char* puerto = argv[1];
    char* ip = argv[2];
    struct addrinfo hints;
    struct addrinfo *resultados;
    memset(&hints,0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = 0;
    getaddrinfo(NULL, puerto, &hints, &resultados);
    // se deberia iterar hasta lograr una conexcion pero por falta de tiempo
    // asumo que se logra la conexion en la primera.
    int socket_server = socket(resultados->ai_family, resultados->ai_socktype,
                                resultados->ai_flags);
    connect(socket_server, resultados->ai_addr, resultados->ai_addrlen);
    freeaddrinfo(resultados);

    // leo lo que me mandan
    char buff[100];
    bool hubo_un_error = false;
    bool termine = false;
    char finalizar[4] = "FIN"
    std::stringstream respuesta;
    while (!hubo_un_error && !termine){
        size_t cant_recibidos = recv(socket_server, &buff, sizeof(buff),0);
        if (cant_recibidos < 0){
            hubo_un_error = true;
        } else if(std::find(buff, finalizar) == 0){
            termine = true;
        } else {
            respuesta.write(buff, cant_recibidos);
        }

    }
    std::string aux = respuesta.str();
    std::cout << aux;

}
