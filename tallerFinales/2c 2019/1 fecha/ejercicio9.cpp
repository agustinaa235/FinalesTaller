/*Implemente una función C++ denominada Sacar que reciba dos listas de elementos y
devuelva una nueva lista con los elementos de la primera que no están en la segunda:
std::list Sacar(std::list a,std::list b);** std::list Sacar(std::list a, std::list b){*/
#include <list>
#include <algorithm>
#include <iostream>

template<class T>
std::list<T> sacar(std::list<T> a, std::list<T> b){
    std::list<T> listaNueva;
    for (T& elem: a){
        if (std::find(b.begin(), b.end(), elem) == b.end()){
              listaNueva.push_back(elem);
        } // si el elemnto no esta en b lo agrego a la nueva lista
    }
    return listaNueva;
}

int main(int argc, char** argv){
    std::list<int> uno;
    std::list<int> dos;
    uno.push_back(1);
    uno.push_back(2);
    uno.push_back(3);
    dos.push_back(2);
    dos.push_back(4);
    dos.push_back(7);
    std::list<int> tres;
    tres = sacar(uno, dos);
    for (std::list<int>::iterator i = tres.begin(); i != tres.end(); ++i){
          std::cout << *i << std::endl;
    }
    return 0;
}
