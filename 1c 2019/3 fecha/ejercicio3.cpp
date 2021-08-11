/***
Escriba un programa que imprima por salida estándar los números entre 1 y 100, en orden ascendente.
Se pide que los números sean contabilizados por una variable global única y que los pares sean escritos
por un hilo mientras que los impares sean escritos por otro.
Contemple la correcta sincronización entre hilos y la liberación de los recursos utilizados.
***/
#include <iostream>
#include <thread>
#include <utility>
#include <mutex>

class NumerosProtegidos{
    private:
      std::mutex mutex;
      int numero[100];
      int posicionImpar = 0;

    public:
        NumerosProtegidos(){
            for (int i = 0; i < 100; i++){
                  this->numero[i] = i + 1;
            }
        }
        bool imprimirSiEsPar(){
            std::lock_guard<std::mutex> lock(this->mutex);
            if (this->posicionImpar % 2 == 0 && this->posicionImpar < 100){
                std::cout << this->numero[this->posicionImpar] << ' ';
                this->posicionImpar++;
            }
            if (this->posicionImpar >= 100){
                return true;
            }
            return false;
        }
        bool imprimirSiEsImpar(){
          std::lock_guard<std::mutex> lock(this->mutex);
          if (this->posicionImpar % 2 != 0 && this->posicionImpar < 100){
              std::cout << this->numero[this->posicionImpar] << ' ';
              this->posicionImpar++;
          }
          if (this->posicionImpar >= 100){
              return true;
          }
          return false;
        }

};

void imprimirNumerosPares(NumerosProtegidos& numero){
    bool termine = false;
    while(!termine){
        termine = numero.imprimirSiEsPar();
    }
}
void imprimirNumerosImpares(NumerosProtegidos& numero){
    bool termine = false;
    while(!termine){
        termine = numero.imprimirSiEsImpar();
    }
}

int main(){
    NumerosProtegidos numero;
    std::thread hiloPar(imprimirNumerosPares, std::ref(numero));
    std::thread hiloImpar(imprimirNumerosImpares, std::ref(numero));
    
    hiloPar.join();
    hiloImpar.join();
    return 0;
}
