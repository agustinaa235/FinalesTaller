/* Defina un rutina en C que se conecte a la IP 10.9.8.7, puero 7777 y procese
la informacion recibida. El proceso consiste en recibir textos numericos
utilizando '\n' como caracter delimitador.
Para cada entero recibido se debe enviar su valor convertido en 32 bits
big-endian en modo binario sin delimitadores. El proceso finaliza al recibir
el valor 0.*/
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string>
#define MAX 1024

int main(){
    const char* ip = "10.9.8.7";
    const char* puero "7777";

    struct addrinfo hints, *res, *ptr;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hinst.ai_socktype = SOCK_STREAM;
    hints.ai_flags = 0;

    getaddrinfo(ip, puerto, &hints, &res);
    ptr = res;
    bool conecte = false;
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
    char buf[MAX];
    memset(buf, '\0', MAX);
    bool termine = false;
    char aux;
    int pos = 0;
    while (!termine){
        ssize_t cant_recv = recv(socket_cliente, &aux, sizeof(char), 0);
        if (cant_recv <=0){
            termine = true;
        } else if (aux != '\n'){
              buf[pos] = aux;
              pos++
        } else {
            if (atoi(buf) == 0){
                termine = true;
            } else{
                bool envie = false;
                int bytes_enviados = 0;
                int32_t numero = atoi(buf);
                numero = htonls(numero);
                while (envie && bytes_enviados < sizeof(numero)){
                    ssize_t cant_envidad = send(socket_cliente, &numero, sizeof(numero), 0);
                    if (cant_envidad <= 0){
                        envie = true;
                    } else {
                        bytes_enviados += cant_envidad;
                    }
                }
            }

        }
    }
    shutdown(socket_cliente, SHUT_RDWR);
    close(socket_cliente);
    return 0;
}
