# Ejercicio 1

Describa con exactitud las siguientes declaraciones/definiciones globales:
● extern char *(*A)();
● float *(*C)[5];
● short *B(){return NULL;}

1. A es una declaracion de un puntero a una funcion que no recibe paraemtros y devuelve el tipo char*. Por ser extern esta no va a tener luagr en memoria, es decir esta se encuentra en otro archivo. 
2. C es una definicion de un un puntero a un array de tamnio 5 cuyo elementos son punteros a float. 
3. b es una definicion de una funcion que no rebie oaraemtros y devuelve el tipo short puneto. En este casodevuelve siemore NULL.

# Ejercicio 2

 Escriba una rutina que dibuje un cuadrado amarillo centrado y de ⅓ del alto de la
ventana.

# Ejercicio 3

¿Se puede evitar que un objeto de una clase sea copiado?¿y clonado?. En caso afirmativo
explique cómo puede hacerse. En caso negativo explique por qué no se puede
Si se puede evitar. Para eso hay que indicarle al programa que no se pueda usar el constructor por copia y el operador= por copia y eso se hace de la siguiente manera:
``` Numero(const Numero& otroNUmero) = delate;
    Numero& operador=(const Numero& otroNumero) = delate;
```
de esta manera se puede evitar que se realize una copia ya que el constrcutor po copia devuelve una copia de la instancia recibida.

# Ejercicio 4

 Declare la clase NumeroGrande para almacenar Numeros de 1000 dígitos, considerando:
● Atributos que considere necesarios
● Accesibilidad a la Clase
● Incluir los operadores -, ++ (post-incremento), --(pre-incremento), >> (impresión),
<< (carga desde consola), float
```C++
class NumeroGrande{
  private:
        long int valor;
  public:
      NumeroGrande (const NumeroGrande& numero);
      NumeroGrande (long int unValor);
      ~NumeroGrande();
      NumeroGrande& operator-(NumeroGrande& numero);
      NumeroGrande& operaror++(int);
      NumeroGrande& operatot--();
      std::istream& operador>>(std::istream& in, NumeroGrande& numero);
      std::ostream& operador<< (std::ostream& out, NumeroGrande& numero);
      operator float() const;
```

# Ejercicio 5 

 Mediante una porción de código ejemplifique el uso de un constructor por copia. Expliqué
el por qué de la necesidad de su uso.

Un constrcutor por copia es cuando se devuelve una copia de la instancia recibida por parametro del constructor. Realiza una copia de bit a bit. Si no se define por el programador el compilador crea uno por default.
un ejemplo en la cual se utiliza es:
``` void imprimir(Numero numero){}```
en esa funcion la instancia pasada es por copia no por referencia por lo que se invoco al constructor por copia internamente. Para evitar eso se deberia implmenetar el constructor por movimiento y pasarlo por referencia. 
otro ejemplo de uso es:
``` Foo uno = Foo(1);
    Foo otro = uno 
 ``` 
 aca se esta invocando al operador= por copia;
 
 # Ejercicio 6
 
 ¿Qué es la STL?¿Qué recursos (funciones, algoritmos, etc.) ofrece?¿Qué ventaja nos da su
uso?
STL es un connjunto de librerias estandar de c++ que ya tienen inplementadas ciertas funciones ,algoritmos conocidos como de busqueda o estructras (lista, cola, vectores, mapa, etc) y le permite a los porgramodres utilizarl todas la funciones que tienen sin la necesidad de que el porgramodr se tenga que poner a programarlas. Estan para usarlas como una herramienta para utilizar en nuestro peograma. A su vez nos solucionas ciertos problemas como manejos de memoria o refrencias como con una cola, al hacer #include <queue> simplemnete utilizamos la cola y sus funciones y nos nos preocumaos de la memoria o si la cola esta vacia puedo hacer pop ya que eso ya esta implemnetado y verificado.

# Ejercicio 7

 Escriba un programa que reciba por línea de comandos un Puerto y una IP. El programa
debe conectarse al destino indicado y quedar en escucha de paquetes con la forma
“d..d|d..d|… >”. El programa debe imprimir en stdout el checksum (sumatoria módulo
256) de cada paquete. Cuando se reciba un paquete vacío se debe finalizar
ordenadamente

# Ejercicio 8
  
¿Qué es un Deadlock? Ejemplifique con código que constituya un indefectible caso
  
 Un deadlock es cuando se tienen hilos bloqueados. Esto ocurre cuando se tiene un recurso compartido progretigo en la cual se realizo un lock dle mutex que permite que si un hilo lo accede otros no lo puedan acceder a el hasta que sea liberado es decir hasta que se realice un unlock del mutex. Pero cuando tenemos un deadlock, lo que paso es que nunca se libero el recurso (nunca se hizo un unlock) por lo que el hilo que estaba usando el recurso ya no lo usa mas pero al no haberse hecho un unlock ningun otro hilo puede acceder al recurso.
 
# Ejercicio 9
  
 Escribir un programa ISO C MULTIPLATAFORMA que procese el archivo “bigEndian.dat”
sobre sí mismo, leyendo nros. de 4 bytes Big-Endian y triplicando (escribirlos 3 veces) los
múltiplos de 3
 
# Ejercicio 10
 
Implemente un programa de 2 threads (producer-consumer) que genere e imprima los
números del 1 al 100.
  
  
