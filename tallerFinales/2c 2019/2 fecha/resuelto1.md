# Ejercicio 1
Escriba un programa (desde la inicialización hasta la liberación de los recursos) que reciba paquetes de la forma nnn+nn+....+nnnn= (numeros separados por +, seguidos de =) 
e imprima el resultado de la suma de cada paquete por pantalla. Al recibir un paquete vacío (“=”) debe cerrarse ordenadamente. No considere errores.

# Ejercicio 2
Explique breve y concretamente qué es f:
```
    int (*f) (short *, char[4]);
```

f es la declaracion de un puntero a una funcion, en la cual este rebibe un short puntero y un array de chars de tamanio 4 y devuelve el tipo int.

# Ejercicio 3
Analice el siguiente código y determine lo que se imprime (valor de Pi)
```C++
    main(){
    int *Pi=1000;
    Pi++;
    printf(“Pi apunta a la dirección: %l”, (long)Pi);
    }
```

En este codigo tenemos un puntero pi que apunta a la direccion 1000, como se trata de un puntero int cuando se va a incrementar pi este va aumentar en 4 bytes ya que un int ocupa 4 bytes(suponiendo que estamos en una arquitectura de 32 bits) por lo que de la posicion 1000 se pasa a la posicion 1004.

# Ejercicio 4
¿Qué es un functor? ¿Qué ventaja ofrece frente a una función convencional? Ejemplifique.
Un functor es una clase que sobrecarga el operador().  Se utiliza para definir objetos que pueden ser llamados como funciones, se puede decir que acutua como "funcion". La ventaja que tiene que es que es un objeto, entonces ademas de tener el comportamiento de una funciones, este puede ir cambiando su estado a memdia de la ejecucion de la funcion. Ademas perte desacoplar el momento en el que se realiza el pasaje de parametros a una funcion mientras es ejecutada.
ej: 
```C++
    class Sumador{
            private:
               std::list<int> m;
               int acumulador = 0;
            public:
                Sumador(std::list<int> numeros);
                void operador(){
                    for (auto it = m.begin(); it != m.end(); ++it){
                            acumulador += *it;
                     }
                     std::cout << acumulador;
                     acumulador = 0;
                 }
```
# Ejercicio 5
¿Cómo se logra que 2 threads accedan (lectura/escritura) a un mismo recurso compartido sin que se generen problemas de consistencia? Ejemplifique.
rta en otro fina. 
En un programa de multithreading cuando dos hilos compraten un mismo recurso, este debe estar protegido para asi se evitan problemas de concurrencia. La proteccion 
es pormedio del objeto mutex. Este posee dos estado bloqueado o liberado. Cuando un hilo accede al recurso debe bloquear al mutex para que ningun otro hilo pueda acceder a ese recurso mientras el lo este usando(esto lo hace por medio de la funcion lock) luego cuando finaliza de utilizarlo debe liberar al mutex para asi otro hilo puede acceder al recurso. 
ej:
```C++
class ListaProtegida{
    private:
        std::mutex m;
        std::list<int> lista;
    public:
        void agregarSiNoEsta(int elem){
            m.lock();
            if (!lista.has(elem)){
                    lista.push_back();
            }
            m.unlock();
         }
}
```
# Ejercicio 6
Describa el concepto de loop de eventos (events loop) utilizado en programación orientada a eventos y, en particular, en entornos de interfaz gráfica (GUIs).

El loop de eventos es un bucle que consiste en ir procesando todos los eventos que llegan a la cola de eventos. Es un patron muy utilizado en aplicaciones donde se tiene interaccion con el usuario de forma grafica ya que un evento podria ser desde un click o arrastre del mouse hasta una pulsacion de una tecla. El loop consiste en ir iterando hasta que le llegue un evento de finaliza/ salir y mientras va iterando debe manejar cada eveneto que le llega, es decir derivar al evento a su correspondiente handler que va a saber que hacer con el evento que le llega.
Ejemplo en pseudocodigo 
while(continuo){
    evento = ObtenerEventoDELaCola()
    if (evento == SALIR){
        continuo = false;
     } else {
        manejarEvento(evento);
      }
}

# Ejercicio 7

Considere la estructura struct ejemplo { int a; char b;}. ¿Es verdad que sizeof (ejemplo)=sizeof(a) +sizeof(b)? Justifique.
Esto es falso, Si tomamos por separado lo que ocupa en memoria un int en una arquitecura de 32 bits es 4 bytes mientras que un char en la misma arquitectura ocupa 1 byte en la cual la suma de estos dos por separado da 5 bytes mientras que si tomamos al struct completo estas se alojan en direcciones de muliplos de 4(32 bits arquitectura) en direcciones de memoria contiguas( ya que utiliza padding) por lo que en el caso de char se estraia "despediciando" espacio en tipo de datos que opcuan menos de 4 bytes. Entonces tendriamos que el struct ocupario 8 bytes que es muy distinto a 5 bytes.

# Ejercicio 8
¿En qué consiste el patrón de diseño RAII? Ejemplifique.
El disenio raiii es un patron que tiene encapsulado la creacion y la destruccion de un objeto. Dentro del constructor es donde se realiza la creacion del objeto y es donde se inicializan todos sus recursos  y se reserve la memoria necesaria dejandolo valido para uso mientras que el destructor es donde se liberan todos los recursos del objeto. De esta forma evitamos tener leeks dentro de un objeto y tener un codigo mas robusto.
ej:
```C++
class Lock{
    private:
        std::mutex m;
    public:
        Lock(){
            m.lock();
        }
        ~Lock(){
            m.unlock();
        }
}        
 ``` 

# Ejercicio 9 
Escribir un programa ISO C que procese el archivo de enteros de 2 bytes bigendian cuyo nombre es recibido como parámetro. El procesamiento consiste en eliminar 
 los número múltiplos de 3, trabajando sobre el mismo archivo (sin archivos intermedios ni en memoria).
 
# Ejercicio 10
Implemente una función C++ denominada DobleSiNo que reciba dos listas de elementos y devuelva una nueva lista duplicando los elementos de la primera que no están
```C++
std::list<T> dobleSiNo(std::list<T> a, std::list<T>b){
    std::list<T> nueva;
    for (T& elem: a){
        if (std::find(b.begin(), b.end(), elem) == b.end()){
                nueva.psuh_back(elem);
                nueva.push_back(elem);
        }
    }
    return nueva;
}
```
