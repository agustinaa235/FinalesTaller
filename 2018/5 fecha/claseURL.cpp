/* Defina la clase URL para permitir almacenar las siguientes propiedades:
protocolo (http), host (fi.uba.ar), port (80), y file (index.php o resources/img/logo.png)
A su vez se pide que implemente los siguientes operadores: operator<<, operator==
y operator=.*/

class Url{
private:
    std::string protocolo;
    std::string host;
    std::string puerto;
    std::string archivo;
public:
    Url(std::string protocolo, std::string host, std::string puerto, std::string archivo):
        protocolo(protocolo),
        host(host),
        puerto(puerto),
        archivo(archivo){}
    ~Url();
    std::ostream& operator<<(std::ostream& out, Url& unaUrl){
        out << "protocolo " << unaUrl.protocolo << std::endl;
        out << "host " << unaUrl.host << std::endl;
        out << "puerto " << unaUrl.puerto << std::endl;
        out << "archivo " << unaUrl.archivo << std::endl;
        return out;
    }
    bool operator==(Url& unaUrl){
        return (this->protocolo == unaUrl.protocolo && this->host == unaUrl.host
                && this->puerto == unaUrl.puerto && this->archivo == unaUrl.archivo);
    }
    Url& operator=(const Url& unaUrl){
        if (this != &unaUrl){
            this->protocolo = unaUrl.protocolo;
            this->host = unaUrl.host;
            this->puerto = unaUrl.puerto;
            this->archivo = unaUrl.archivo
        }
        return *this;
    }
};
