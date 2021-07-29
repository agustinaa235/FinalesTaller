

class Numero{
  private:
      unsigned long valor;
  public:
      Numero(unsigned long numero);
      Numero();
      Numero(Numero&& otroNumero);
      Numero& operador=(Numero&& otroNumero);
      int operator long();
      void operator ++();
      Numero operator(unsigned long numero);
      std::istream& operator>>(std::istream& in, Numero& numero){
          in >> numero;
          return in;
      }
      std::ostream& operator<<(std::ostream& out, Numero& numero);

      ~Numero();

}
