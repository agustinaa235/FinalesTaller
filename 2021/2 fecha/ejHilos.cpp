
/*Implemente un programa de 2 threads (producer-consumer) que genere e imprima los
números del 100 al 1.*/
#include <condition_variable>
#include <mutex>
#include <thread>
#include <iostream>
#include <queue>
#include <chrono>
class Numero{
  private:
  std::mutex mutex;
  std::condition_variable cond_variable;
  std::queue<int> valores;
  bool termine = false;
  bool notify = false;

public:
    Numero(){}
    ~Numero(){}
    void productor(){
        for (int i = 100; i>=1; i--){
          std::unique_lock<std::mutex> lock(mutex);
          valores.push(i);
          notify = true;
          cond_variable.notify_all();
        }
        cond_variable.notify_all();
    }
    void consumidor(){
        std::unique_lock<std::mutex> lock(mutex);
        while(!termine){
            while (valores.empty()){
                std::cout << "espero" << "\n";
                cond_variable.wait(lock);
            }
            while (!valores.empty()){
                std::cout << valores.front() << " ";
                valores.pop();
            }
            termine = true;
            notify = true;
        }
    }
};
void producir(Numero& numero){
    numero.productor();
}
void imprimir(Numero& numero){
    numero.consumidor();
}

int main(){
    Numero numero;
    std::thread hilo1(&Numero::productor, &numero);
    std::thread hilo2(&Numero::consumidor, &numero);
    hilo1.join();
    hilo2.join();
    return 0;
}
