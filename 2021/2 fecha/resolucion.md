# Ejercicio 1
Escriba un programa que reciba por línea de comandos un Puerto y una IP. El programa
debe establecer una unica conexión, y enviar todo el texto ingresado por stdin. Cuando
se ingrese el texto ‘FIN’ debe finalizar el programa sin enviar dicho texto
# Ejercicio 2
 ¿Qué es una Condition Variable? Ejemplifique mediante código.
 Es una varible utilizada en sicronizacion de hilos en la cual permite bloquear un hilo o multiples hilos hasta que le llegue alguna senial. Esta senial puede ser que pase un determiando tiempo o  una notificacion de otro hilo. Basicamente se utiliza para tener una cordinacion entre dos o mas hilos con un mismo recurso. 
 Poseen los metodos de wait() y notyfy_all(, entre otros. El primero lo que hace es decirle al hilo que espere o a que le llegue una senialientras que notyfy_all le avisa al resto de los hilos que ya pueden ser ejecutados, es decir, pasaria a ser la senial. 
 ```C++
 class ColaBloqueante:
    
    std::queue<int> cola
    std::condition_variable cv;
    bool vacia = true;
    
    void pop(){
      while (vacia){
            cv.wait();
       }
       cola.pop();
      }
      
      void push(int elem){
        cola.push(elem);
        cv.notify_all();
       }
 ``` 
 # Ejercicio 3
  Escribir un programa ISO C MULTIPLATAFORMA que procese el archivo “valores.txt” sobre
sí mismo. El procesamiento consiste en leer números separados por 1 espacio que se
encuentran en base 3 y escribirlos en 4 símbolos base hexadecimales, también separados
por 1 espacio.

# Ejercicio 4
Implemente un programa de 2 threads (producer-consumer) que genere e imprima los
números del 100 al 1

# hecho

# Ejercicio 5
Implemente una función C++ denominada PurgarMapa que reciba un mapa (clave-valor)
por referencia y le quite los elementos cuyos valores están repetidos.
    
# Ejercicio 6
Explique y ejemplifique el uso de la directiva de precompilación #include

La directiva de precompilacion #include permite incluir archivos/ encabezados. SE utiliza para incluir los arhcivos en donde se encuentran todas las referencias a funciones, variables constantes, etc para si poder usar esas funciones o variables en nuestro codgio sin tener que nosotros implemnetarlas ahi en ese modulo. Si este no se relalizar y se utlizara alguna funcion de ese archivo habria porblemas de compilacion. 
ej:
```C++
#include <list>

int main(){
 std::list<int> a;
 ... // puedo invocar a todas las funciones que se encuentren en el archivo list declaradas.
 a.push_back();
 a.size();
}
```

# Ejercicio 7
Explique qué es cada uno de los siguientes, haciendo referencia a su inicialización, su
comportamiento y el area de memoria donde residen:
a) Una variable global static
b) Una variable local static
c) Un atributo de clase static.

a) Es una vraible que va a ser inicializada al inico del programa, por ser globla static puede ser accedida por todo el modulo en el que se encuentra, si no es inicializada por el porgramador va a ser inicializada poren cero, su lifetime es la duracion del todo el programa y recide en el data segment.
b) Es una variable que si el porgramador no la inicializo se inicializa en cero. Va a poder ser accedida solo en la funcion que fue declarada y su duracion o lifetime es lo que dure la funcion , es decir, el tiempo de ejecucuion de la funcion cuando esa funcion sale del scope esa variable muere y recide en el data segment por ser static. 
c) Un atributo de clase static puede ser accedida solo por la correspondiente clase si es privada, si es publica podra accederse por fuera de la clase. Se inicializa en cero en caso de no estar especificado su valor inicial, su duracion es hasta que se invoque al destructor de la instacia y recibe en el data segment. 

# Ejercicio 8
¿Qué es un template? Ejemplifique

Un template es una plantillas de clases, sirve para poder generar codigo generico para cualquier tipo de dato. Es muy util ya que permie que no se tenga que volver a escribir codigo para una funcion solo por el tipo de dato, es decir, nos ahorramos codigo duplicado. 
ej:
```C++
void imprimirLista(std::list<T> lista){
   for (auto it =  lista.begin(); it != lista.end(); ++it){
     std::cout  << *it << "\n;
     }
```
# Ejercicio 9
 Indique la salida del siguiente programa:
class A { A(){cout << “A()” << endl;} ~A(){ cout << “~A()” << endl;} }
class B : public A { B(){cout << “B()” << endl;} ~B(){ cout << “~B()” << endl;} }
int main () { B b; return 0;}
salida:
A()
B()
~B()
~A()

# Ejercicio 10
Escriba una rutina que dibuje un rombo verde centrado y de ¼ del alto de la ventana.
# hecho
