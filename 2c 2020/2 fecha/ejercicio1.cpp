 /* Escriba un programa que escuche el puerto 120 y reciba paquetes de la forma:
  [CHAR_LIM]xxxxx.xxxxxxx[CHAR_LIM] donde [CHAR_LIM] puede ser cualquier
   caracter ASCII Al completar la recepción del paquete deberá imprimir el
   caracter con más apariciones del mismo (sin considerar [CHAR_LIM]). Al
   recibir un paquete vacío ([CHAR_LIM][CHAR_LIM]) debe cerrarse ordenadamente.
   No considere errores. */

   /* SERVIDOR CREO*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <string>

int main(){
    const char* puerto = "120";

    struct addrinfo hints;
    struct addrinfo* res, ptr;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = 0;

    getaddrinfo(NULL, puerto, &hints, &res);
    ptr = res;
    bool binie = false;
    int socket_server = -1;
    while (!binie){
        socket_server = socket_server(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
        if (socket_server > 0){
            bine(socket_server, ptr->ai_addr, ptr->ai_addrlen);
            listen(socket_server, 1);
        } else{
            ptr = prt->ai_next;
        }
    }
    freeaddrinfo(res);
    int peer = connect(socket_server, NULL,NULL);
    bool termine = false;
    bool hubo_un_error = false;
    char aux, buf;
    std::string caracteres;
    int cant_corchetes = 0;
    while (!termine && !hubo_un_error){
        ssize_t cant_recv = recv(peer, &aux, sizeof(aux), 0);
        if (cant_recv < 0){
            hubo_un_error = true;
        } else if (cant_recv == 0){
            termine = true;
        } else if (aux == '['){
            cant_corchetes++;
            i++;
            buf = aux;
        } else if (aux == ']'){
            if (cant_corchetes == 2 && caracter.empty()){ // condicion de corte
                  termine = true;
            } else{
                char mayor = ' ';
                char otro;
                int cant_mayor = 0;
                int cant_otro = 0;
                std::string::iterator it1;
                for (it1 = caracteres.begin(); it2 != caracteres.end(), ++it1){
                    std::string::iterator it2 = caracteres.begin();
                    otro = *it2;
                    for (;it2 != caracteres.end(); ++it2){
                        if (*it1 == *it2){
                            cant_otro++;
                        }
                    }
                    if (cant_otro > cant_mayor){
                        mayor = otro;
                        cant_mayor = cant_otro;
                    }
                    cant_otro = 0;
                }
                std::cout << "caracter con mas apariciones: " << mayor << "\n";
                caracteres.clear();
            }
        } else {
            caracteres.push_back(aux);
        }
    }
    shutdown(peer, SHUT_RDWR);
    close(peer);
    close(socket_server);
    return 0;
}
