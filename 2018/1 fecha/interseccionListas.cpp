/* Implemente una función C++ denominada Interseccion que reciba dos listas de
elementos y devuelva una nueva lista con los elementos que se encuentran en
ambas listas: std::list Interseccion(std::list a,std::list b);*/

#include <iostream>
#include <list>
#include <algorithms>

template <class T>
std::list<T> Interseccion(std::list<T> a, std::list<T> b){
    std::list<T> nuevaLista;
    for (T& elem: a){
        if (std::find(b.begin(), b.end(), elem) != b.end()){
            nuevaLista.push_back(elem);
        }
    }
    return nuevaLista;
}
