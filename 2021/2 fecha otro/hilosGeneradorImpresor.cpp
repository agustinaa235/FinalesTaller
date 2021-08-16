/* Implemente un programa de 2 threads (producer-consumer) que genere e imprima los
números del 1 al 100 */
#include <iostream>
#include <thread>
#include <utility>
#include <mutex>

class Numero{
private:
    std::mutex m;
    int contador = 0;
    bool pude_imprimir = true;
    bool pude_incrementar = true;
public:
    Numero (){

    }
    ~Numero(){}
    bool incrementar(){
        std::lock_guard<std::mutex> lock(this->m);
        if (pude_incrementar){
            contador++;
            pude_imprimir = true;
            pude_incrementar = false;
        }
        if (contador == 100){
            return true;
        } else {
            return false;
        }
    }
    bool imprimir(){
        std::lock_guard <std::mutex> lock(this->m);
        if (pude_imprimir){
            std::cout << contador << ' ';
            pude_imprimir = false;
            pude_incrementar = true;
        }
        if (contador == 100){
            return true;
        } else {
            return false;
        }
    }
};

void producir(Numero& numero){
    int termine = false;
    while (!termine){
        termine = numero.incrementar();
    }
}

void consumir(Numero& numero){
    int termine = false;
    while (!termine){
        termine = numero.imprimir();
    }
}

int main(){
    Numero numero;
    std::thread hilo1 (producir, std::ref(numero));
    std::thread hilo2 (consumir, std::ref(numero));
    hilo1.join();
    hilo2.join();
    return 0;
}
