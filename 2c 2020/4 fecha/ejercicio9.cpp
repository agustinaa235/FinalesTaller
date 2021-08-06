/* Implemente una función C++ denominada Sacar que reciba dos listas de
elementos y devuelva una nueva lista con los elementos de la primera que no
están en la segunda */

#include <iostream>
#include <list>
#include <algorithm>


template <class T>
std::list<T> Sacar(std::list<T>& a, std::list<T>& b){
    std::list<T> nuevaLista;
    for (T& elem : a){
        if (std::find(b.begin(), b.end(), elem) == b.end()){ // elem no esta en b
            nuevaLista.push_back(elem);
        }
    }
    return nuevaLista;
}
int main(int argc, char** argv){
    std::list<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    std::list<int> b;
    b.push_back(2);
    std::list<int> c = Sacar(a,b);
    for (int valor: c){
          std::cout << valor;
    }
    return 0;
}
