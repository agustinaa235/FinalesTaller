/* Escriba un programa que escriba por salida estandar los numeros entre
0 y 1000 ordenadamente. Se pide que los numeros pares sean escritos por un
hilo mientras los impares sean escritos por otro.
Contemple la correcta sincronizacion entre los hilos y la liberacion de los
recursos utilizados.*/
#include <condition_variable>
#include <mutex>
#include <thread>
#include <iostream>

class Numero{
private:
    std::mutex m;
    int contador = 0;
    std::condition_variable cv_par, cv_impar;

public:
      Numero(){}
      ~Numero(){}
      bool imprimirNumerosPares(){
          std::unique_lock<std::mutex> l(m);
          if (contador % 2 != 0){
              cv_par.wait(l);
          }
          if (contador > 1000){
              contador++;
              cv_impar.notify_all();
              return true;
          }
          std::cout << contador << ' ';
          contador++;
          cv_impar.notify_all();
          return false;
      }
      bool imprimirNumerosImpares(){
          std::unique_lock<std::mutex> l(m);
          if (contador % 2 == 0){
              cv_impar.wait(l);
          }
          if (contador > 1000){
              contador++;
              cv_par.notify_all();
              return true;
          }
          std::cout << contador << ' ';
          contador++;
          cv_par.notify_all();
          return false;
      }
};

void imprimirPares(Numero& numero){
    bool termine = false;
    while (!termine){
        termine = numero.imprimirNumerosPares();
    }
}
void imprimirImpares(Numero& numero){
    bool termine = false;
    while (!termine){
        termine = numero.imprimirNumerosImpares();
    }
}

int main(){
    Numero numero;
    std::thread hiloPar(imprimirPares, std::ref(numero));
    std::thread hiloImpar(imprimirImpares, std::ref(numero));
    hiloPar.join();
    hiloImpar.join();
    return 0;
}
