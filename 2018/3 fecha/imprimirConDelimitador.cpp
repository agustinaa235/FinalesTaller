/* Escriba un programa (desde la inicialización hasta la liberación de los
  recursos) que reciba paquetes de texto delimitados por corchetes angulares
  (“<...>”) y los imprima completos por pantalla. Al recibir un paquete vacío
  (“<>”) debe cerrarse ordenadamente. No considere errores. */
  #include <netdb.h>
  #include <unistd.h>
  #include <sys/types.h>
  #include <sys/socket.h>
  #include <iostream>
  #include <string>
  #include <cstring>

int main(){
    const char* ip = "127.0.0.1";
    const char* puerto = "8080";

    struct addrinfo hints, *res, *ptr;
    memset(&hints,0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = 0;

    getaddrinfo(ip, puerto, &hints, &res);
    ptr = res;
    int socket_cliente = -1;
    bool conecte = false;
    while (!conecte){
        socket_cliente = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
        if (socket_cliente > 0){
            connect(socket_cliente, ptr->ai_addr, ptr->ai_addrlen);
            conecte =  true;
        } else {
            ptr = ptr->ai_next;
        }
    }
    freeaddrinfo(res);
    char aux;
    std::string paquete;
    bool termine = false;
    while (!termine){
        ssize_t cant_recv = recv(socket_cliente, &aux, sizeof(char), 0);
        if (cant_recv == 0){
            termine = true;
        } else if (aux == '<'){
            while (aux != '>' && !termine){
                cant_recv = recv(socket_cliente, &aux, sizeof(char), 0);
                if (cant_recv <= 0){
                    termine = true;
                } else{
                    paquete.push_back(aux);
                }
            }
            if (paquete.empty()){
                termine = true;
            } else {
                std::cout << paquete;
                paquete.clear();
            }
        } else {
            termine = true;
            // si no me llega < como primer caracte lo considero un error y salgo
        }
    }
    shutdown(socket_cliente, SHUT_RDWR);
    close(socket_cliente);
    return 0;
}
