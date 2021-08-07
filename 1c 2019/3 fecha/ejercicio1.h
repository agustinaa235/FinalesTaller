#ifndef _NUMERO_
#define _NUMERO_
#include <iostream>

class Numero{
    private:
          int valor;
    public:
          Numero(int& valor);
          Numero operador+(Numero& otroNumero);
          int operador long();
          Numero operador++(); //incremento
          Numero operador--(); // desincremento
          Numero operador+(Numero& otroNumero);
          std::istream& operador>>(std::istream& in,Numero& otroNumero){
              otroNumero.valor >> in;
              return in;
          }
          std::ostream& operador<<(std::ostream& out, NUmero& otroNumero){
              out << otroNumero.valor;
              return out;
          }

}
#endif _NUMERO_
