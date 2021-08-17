/*La clase Oracion utiliza un char *a para almacenar un string terminado en \0.
Escriba la declaracion de esta clase no olvidando: constructor por default,
constructor por copia, operadores +, -, =, >> y <<. Implemente el operador = y
el operador -. Este ultimo debe eliminar de la primer cadena todas las
ocurrencias de la segunda.*/
#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>

class Oracion{
private:
    char* a;
public:
    Oracion(const char* aux){
        int tam = strlen(aux);
        this->a = new char[tam +1];
        this->a[tam] = '\0';
        memcpy(this->a, aux, tam);
    }
    Oracion(const Oracion& oracion){
        int tam = strlen(opracion.a)
        this->a = new char[tam +1];
        this->a[tam] = '\0';
        memcoy(this->a, other.a, tam);
    }
    Oracion& operador=(const Oracion& oracion){
        if (this != oracion){
            delate this->a;
            int tam = strlen(oraciones.a);
            this->a = new char[tam +1];
            this->a[tam] = '\0';
            memcpy(this->a, oracion.a, tam);
        }
        return *this;
    }
    std::istream& operator>>(std::istream& in, Oracion& otraOracion){
        char* aux;
        in >> aux;
        otraOracion.set(aux);
        return aux;
    }
    std::ostream& operator<<(std::ostream& out, Oracion& otraOracion){
        out << otraOracion.a;
        return out;
    }
    Oracion operator-(const Oracion& otraOracion){
        std::string aux1(this->a);
        std::string aux2(otraOracion.a);
        bool encontre = true;
        while (encontre){
            int pos = aux1.find(aux2);
            if (pos == std::string::npos){
                encontre = false;
            } else {
                aux1.erase(pos, auxb.lengh());
            }
        }
        Oracion oracion(aux1.c_str());
        return oracion;
    }
    Oracion operator+(const Oracion& otraOracion);
    ~Oracion(){
        delate this->a;
    }

};
