/* Escriba una clase template llamada Sumador que reciba por constructor un
vector de elementos genericos. La clase Sumador debe incluir un metodo
llamado sumar que acumule los valores del tipo recibido y retorne un nuevo
objeto del tipo generico. */
#include <iostream>
#include <vector>
template <class T>

class Sumador{
private:
      std::vector<T> valores;
public:
        Sumador(std::vector<T> elem) : valores(elem){}
        ~Sumador(){}
        T sumar(){
            int i = 0;
            T valor;
            for (T& elem: valores){
                if (i == 0){
                    valor = elem;
                } else {
                    valor += elem;
                }
                i++;
            }
            return valor;
        }
};

int main(){
    std::vector<int> elementos {1, 2, 3, 4};
    Sumador<int> sumatoria(elementos);
    std::cout << sumatoria.sumar() << " ";;
    return 0;
}
