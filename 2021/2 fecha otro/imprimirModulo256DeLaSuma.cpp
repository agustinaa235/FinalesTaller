/* Escriba un programa que reciba por línea de comandos un Puerto y una IP. El programa
debe conectarse al destino indicado y quedar en escucha de paquetes con la forma
“d..d|d..d|… >”. El programa debe imprimir en stdout el checksum (sumatoria módulo
256) de cada paquete. Cuando se reciba un paquete vacío se debe finalizar
ordenadamente */


int main(int argc, char** argv){
    const char* puerto = "8080";
    const char* ip = "127.0.0.1";

    struct addrinfo hints, *res, *ptr;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = 0;

    getaddrinfo(ip, puerto, &hints, &res);
    ptr = res;
    bool conecte = false;
    int socket_cliente = -1;
    while (!conecte){
        socket_server = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
        if (socket_cliente > 0){
            connect(socket_server, ptr->ai_addr, ptr->ai_addrlen);
            conecte = true;
        }
    }
    freeaddrinfo(res);
    std::string paquetes;
    char aux;
    bool termine = false;
    int acumulador = 0;
    while (!termine){
        ssize_t cant_recv = recv(socket_cliente, aux, sizeof(char), 0);
        if (cant_recv <= 0){
            termine = true;
        } else if (aux == '|'){
                int numero = std::stoi(paquetes);
                if (numero < 0){
                    numero = numero*-1;
                }
                acumulador+= numero;
                paquetes.clear();


        } else if (aux == '>'){
            if (acumulador == 0){
                termine = true;
            } else {
                int salida = acumulador % 256 // asumo que llega ddd|ddd|>
                std::cout << salida;
            }
        } else {
            paquetes.push_back(aux);
        }
    }
    shutdown(socket_cliente, SHUT_RDWR);
    close(socket_cliente);
    return 0;
}
