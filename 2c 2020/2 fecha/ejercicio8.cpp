/*Implemente una función C++ denominada SoloMuliplos que reciba una lista de
elementos numéricos y un elemnto numérico x. La función debe devolver una nueva
lista con los elementos de la primera que sean múltiplos de x:*/

#include <iostream>
#include <list>
#include <algorithm>

template <class T>

std::list<T> SoloMultiplos(std::list<T> a,T x){
      std::list<T> nuevaLista;
      for (T& elem: a){
          if (elem % x == 0){
                nuevaLista.push_back(elem);
          }

      }
      return nuevaLista;
}

int main(int argc, char** argv){
    std::list<int> a;
    a.push_back(4);
    a.push_back(6);
    a.push_back(7);
    a.push_back(9);
    a.push_back(10);
    std::list<int> c = SoloMultiplos(a, 2);
    for (int valor: c){
        std::cout << valor;
    }
    return 0;
}
