 /* Escriba un programa que reciba paquetes de la forma nnn+nn+....+nnnn=
 (numeros separados por +, seguidos de =) e imprima el resultado de la suma de
 cada paquete por pantalla. Al recibir un paquete vacío (“=”) debe cerrarse
 ordenadamente. No considere errores. */

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

    const char* host = "127.0.0.1";
    const char* port = "8080";

    struct addrinfo hints, *res, *ptr;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = 0;

    getaddrinfo(host, port, &hints, &res);
    bool conecte = false;
    ptr = res;
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
    char aux;
    int numero = 0;
    std::string numeroTexto;
    int acumulador = 0;
    bool termine = false;
    bool hubo_un_error = false;
    while (!termine && !hubo_un_error){
        ssize_t cant_recv = recv(socket_cliente, &aux, sizeof(aux), 0);
        if (cant_recv < 0){
            hubo_un_error = true;
        } else if (aux == '='){
            if (acumulador == 0){
                termine = true;
            } else {
                numero = std::stoi(numeroTexto);
                acumulador += numero;
                std::cout << acumulador << "\n";
                acumulador = 0;
                numeroTexto.clear();
            }
        } else if (aux == '+'){
            numero = std::stoi(numeroTexto);
            acumulador += numero;
            numeroTexto.clear();
        } else {
            numeroTexto.push_back(aux);
        }
    }
    shutdown(socket_cliente, SHUT_RDWR);
    close(socket_cliente);
    return 0;
}
