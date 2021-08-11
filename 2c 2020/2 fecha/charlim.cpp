/* Escriba un programa (desde la inicialización hasta la liberación de los
  recursos) que escuche el puerto 120 y reciba paquetes de la forma:
  [CHAR_LIM]xxxxx.xxxxxxx[CHAR_LIM] donde [CHAR_LIM] puede ser cualquier
  caracter ASCII Al completar la recepción del paquete deberá imprimir el
  caracter con más apariciones del mismo (sin considerar [CHAR_LIM]). Al
  recibir un paquete vacío ([CHAR_LIM][CHAR_LIM]) debe cerrarse ordenadamente.
  No considere errores. */
#include <iostream>
#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string>
#include <ostream>
#include <cstring>

int main(){
    const char* puerto = "8080";
    const char* host = "127.0.0.1";
    struct addrinfo hints, *res, *ptr;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = 0;

    getaddrinfo(host, puerto, &hints, &res);

    ptr = res;
    int socket_server = -1;
    bool binie = false;
    while (!binie){
        socket_server = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
        if (socket_server > 0){
            bind(socket_server, ptr->ai_addr, ptr->ai_addrlen);
            listen(socket_server, 1);
            binie = true;
        } else {
            ptr = ptr->ai_next;
        }
    }
    int peer = accept(socket_server, NULL, NULL);
    freeaddrinfo(res);

    bool termine = false;
    char charlim;
    char buf;
    ssize_t cant_recv = recv(peer, &charlim, sizeof(char), 0);
    std::cout << charlim << "\n";
    if (cant_recv < 0){
        termine = true;
    }
    std::string texto;
    while (!termine){
        cant_recv = recv(peer, &buf, sizeof(char), 0);
        if (cant_recv == 0){
              termine = true;
        } else if (buf != charlim){ // char lim no va estar en el medio
              texto.push_back(buf);
              std::cout << buf << "\n";
        } else {
            termine = true;
        }
    }
    int mayor = 0;
    int actual = 0;
    char caracterActual = ' ';
    char caracterMayor = ' ';
    for (int i = 0; i< texto.size(); i++){
        caracterActual = texto[i];
        for (int j = 0; j < texto.length(); j++){
            if (caracterActual == texto[j]){
                actual++;
            }
        }
        if (actual >= mayor){
            mayor = actual;
            caracterMayor = caracterActual;
        }
    }
    std::cout << "El caracter mayor es: " << caracterMayor;
    shutdown(socket_server, SHUT_RDWR);
    shutdown(peer, SHUT_RDWR);
    close(peer);
    close(socket_server);
    return 0;
}
