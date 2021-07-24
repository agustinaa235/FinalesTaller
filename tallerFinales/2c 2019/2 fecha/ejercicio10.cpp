
/*Implemente una función C++ denominada DobleSiNo que reciba dos listas de
elementos y devuelva una nueva lista duplicando los elementos de la primera que
no están en la segunda*/

#include <list>
#include <algorithm>
#include <iterator>
#include <iostream>



std::list<T> DobleSiNo(std::list<int>lista1, std::list<int> lista2){
    std::list<int> listaNueva;
    std::list<int>::iterator it;
    for (it = lista1.begin(); it != lista1.end(); ++it){
      // si el elemento no esta en la lista b
        if (std::find(lista2.begin(), lista2.end(), *it) == lista2.end()){
           listaNueva.push_back(*it);
           listaNueva.push_back(*it);
        }
    }
    return listaNueva;
}
int main(int argc, char** argv){
  std::list<int> a;
 a.push_back(1);
 a.push_back(2);
 a.push_back(3);
 a.push_back(4);
 std::list<int> b;
 b.push_back(1);
 b.push_back(5);
 b.push_back(3);
 b.push_back(4);

 std::list<int> c = DobleSiNo(a,b);
 std::list<int>::iterator it;
 for (it = c.begin(); it != c.end(); ++it){
   std::cout << *it << "\n";
 }
 return 0;
}
