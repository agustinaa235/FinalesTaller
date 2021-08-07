#include "stdio.h"






int main(int argc, char** argv){

    char* puerto = argv[1];
    char* ip = argv[2];
    struct addrinfo hints;
    struct addrinfo *res;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = 0;
    // considero que se conecta en la primer iteracion por eso no itero
    if (getaddrinfo(NULL, puerto, &hints, &res) < 0){
        return -1;
    }

    int socket_client = socket(res->ai_family, res->ai_socktype, res->ai_protocol)
    if (socket_client < 0){
        return -1;
    }
    connect(socket_client, res->ai_addr, res->ai_addrlen);
    freeaddrinfo(res);

    char array;
    bool termine = false;
    bool hubo_un_error = false;
    int acumulador = 0;
    char aux = '0';
    while (!termine && !hubo_un_error){
        ssize_t cant_recv = recv(socket_client, &array, sizeof(array), 0);
        if (cant_recv < 0 ){
            hubo_un_error = true;
        }
        if (array == '['){
            aux = array;
        }else if(array == ']'){
            if (aux == array){
                termine = true;

            }else{
                printf("El resultado de la suma es: %i\n",acumulador);
                acumuldor = 0;
            }
      } else {
          if (array != '+' && array != "["){
              acumulador += (array - '0');
          }
          aux = '0';
      }
    }
    shutdown(socket_client, SHUT_RDWR);
    close(socket);
    return 0;  
}
