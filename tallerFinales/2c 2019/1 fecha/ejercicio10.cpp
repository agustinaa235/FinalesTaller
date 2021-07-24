/*Escriba un programa que reciba por línea de comandos un Puerto y una IP. El programa debe
establecer una unica conexión, quedar en escucha e imprimir en stdout todo lo recibido. Al
recibir el texto ‘FINAL’ debe finalizar el programa sin imprimir dicho texto.*/
#include <string>
#include <sstream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <utility>
#include <iostream>


void procesar_respuesta_servidor(int& clientSK){
    char buffer[100] = "";
    bool termine = false;
    bool hubo_un_error = false;
    char palabraClave[6] = "FINAL";
    int pos = 0;
    int cant_recibidos = 0;
    std::stringstream respuesta;
    while (!termine && !hubo_un_error){
        int verificacion = ::reciv(clientSK, &buffer[cant_recibidos],
                              (100 - cant_recibidos), 0));
        if (verificacion < 0){
            hubo_un_error = true;
        } else if (palabraClave[pos] == buffer){
            pos++;
            if (pos == 5){ // recibi final
                termine = true;
            }
        } else {
            respuesta.write(buffer, verificacion);
        }
    }
    std::string respuesta_aux = respuesta.str();
    std::cout << respuesta_aux;
}

int main(int argc, char** argv){
    std::string puerto(argv[1]);
    std::string ip(argv[2]);
    struct addrinfo* hints;
    struct addrinfo* resultados, aux;
    memset(hints, 0, sizeof(struct addrinfo));
    hints->ai_family = AF_INET;
    hints->ai_socktype = SOCK_STREAM;
    hints->ai_flags = 0;
    int clientSK = -1;
    if (getaddrinfo(puerto, ip, &hints, &resultados) != 0){
        return -1;
    }
    aux = resultados;
    bool noConecte = true;
    while (aux != NULL && noConecte){
        int file_descriptor = socket(aux->ai_family, aux->ai_socktype, aux->ai_protocol);
        if (file_descriptor == -1){
            noConecte = true;
        } else {
            if (::conect(file_descriptor, aux->ai_addr, aux->ai_addrlen) == -1){
                  ::close(file_descriptor);
                  noConecte = true;
            } else {
                noConecte = false;
                clientSK = file_descriptor;
            }
        }
        aux = aux->ai_next;
    }
    freeaddrinfo(resultados);
    procesar_respuesta_servidor(&clientSK);




}
