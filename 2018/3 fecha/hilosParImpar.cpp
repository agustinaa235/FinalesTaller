/* Escriba un programa que imprima por salida estándar los números entre 1 y 100,
 en orden ascendente. Se pide que los números sean contabilizados por una
 variable global única y que los pares sean escritos por un hilo mientras que
 los impares sean escritos por otro. Contemple la correcta sincronización entre
 hilos y la liberación de los recursos utilizados. */
 #include <condition_variable>
 #include <mutex>
 #include <thread>
 #include <iostream>

class Contador{
private:
    int numero = 1;
    std::mutex m;
    std::condition_variable cv_par, cv_impar;

public:
        Contador(){}
        ~Contador(){}
        bool imprimirPar(){
        std::unique_lock<std::mutex> lock(m);
        while ((numero % 2) != 0){
            cv_par.wait(lock);
        }
        if (numero > 100){
            numero++;
            cv_impar.notify_all();
            return false;
        }
        std::cout << numero << ' ';
        numero++;
        cv_impar.notify_all();
        return true;
    }

    bool imprimirImpar(){
        std::unique_lock<std::mutex> lock(m);
        while (numero % 2 == 0){
            cv_impar.wait(lock);
        }
        if (numero > 100){
            numero++;
            cv_par.notify_all();
            return false;
        }
        std::cout << numero << ' ';
        numero++;
        cv_par.notify_all();
        return true;
    }
};
/* cuando se llegue a 100 el hilo par le avisa al hilo impar y aumenta a 101
este se da cuenta que se paso incrementa y le avisa al hilo par que le llega 102
este finaliza, entonces ambos hilos finalizan y joinean. */

 int main(){
    Contador contador;
    std::thread hiloImpar([&](){
        while (contador.imprimirImpar()){
            continue;
        }
    });
    std::thread hiloPar([&](){
        while (contador.imprimirPar()){
            continue;
        }
    });
    hiloImpar.join();
    hiloPar.join();
    return 0;
 }
