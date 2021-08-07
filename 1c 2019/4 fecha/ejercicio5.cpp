/*Implemente una función C++ denominada DobleSegunda que reciba dos listas de
elementos y devuelva una nueva lista duplicando los elementos de la primera si
están en la segunda */

#include <list>
#include <iostream>
#include <algorithm>

template<class T>

std::list<T> DobleSegunda(std::list<T> a, std::list<T> b){
    std::list<T> listaNueva;
    for (T& elemento: a){
        if (!(std::find(b.begin(), b.end(), elemento) == b.end())){
              listaNueva.push_back(elemento);
              listaNueva.push_back(elemento);
        }
    }
    return listaNueva;
}

int main(int argc, char** argv){
     std::list<int> a;
     a.push_back(1);
     a.push_back(2);
     a.push_back(7);
     a.push_back(4);
     std::list<int> b;
     b.push_back(1);
     b.push_back(5);
     b.push_back(3);
     b.push_back(4);

     std::list<int> c = DobleSegunda(a,b);
     std::list<int>::iterator it;
     for (it = c.begin(); it != c.end(); ++it){
       std::cout << *it << "\n";
     }
     return 0;
}
