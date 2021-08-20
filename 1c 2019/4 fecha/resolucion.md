# Ejercici0 1
¿Qué es una macro de C? Enumere buenas prácticas para su definición.
Una macro es una instruccion que es realiza en forma de directiva del precompialdor de compilador de c, con el objetivo de expandir todas las apariciones del simbolo asociado a la macro de forma literal (en donde aparece el simbolo de la macro copia literalmente su contenido). La macros pueden estar en funcion de variables, y como estas son expandidas de forma literal, es importante que las variables se encuentren entre parentesis para evitar problemas o errores. Otra buena practica es el uso de un buen nombre descriptivo. 
ej:
` #define DOBLE(A) 2*(A)`

# Ejercicio 2
Describa el proceso de transformación de código fuente a un ejecutable. Precise las etapas y las tareas desarrolladas en cada una de ellas
para pasar del codigo fuente a un codigo ejecutable tenemos distintas etapas:
 - Preproceso: 
    Es la etapa donde se procesan las macros, lo que se hace es copiar el codigo de la macro en todo lugar al que fue llamado. tambien se procesan las directivas del precompialdor. En esta estapa se borrarn los completarios
 - Compilacion: 
    En esta etapa se pasa de codigo fuente c a codigo assembly. se realiza un parceo, analisis sintatico, ect. 
 -  Ensambablado: 
    Una vez generado el codigo assembly, se debe pasar a codigo objeto. En esta etapa consta de dos pasadas. En la primer pasada se crea una tabla de simbolos en 
    la cual se cargan todos los simbolos(variables, ctes, etc) y luego en la segunda pasada es donde se genera el codigo objeto. 
 - Linkeo:
    Una vez generado el codigo objeto, lo que se hace es linkear/juntar los distintos modulos objetos dentro un mismo modulo y generar el archivo .exc
# Ejercicio 3
Explique breve y concretamente qué es f:
```
  char (*f) (int *, char[3]);
```
es una declaracion de un puntero a una funcion f que devuelve como tipo de dato char y recibe como parametro un dato del tipo int puntero y un vector de 
de tipo de dato char de 3 elementos.

# Ejercicio 4
Escribir un programa ISO C que procese el archivo “nros_2bytes_bigendian.dat” sobre sí mismo, eliminando los número múltiplos de 7.
# Ejercicio 5
Implemente una función C++ denominada DobleSegunda que reciba dos listas de elementos y devuelva una nueva lista duplicando los elementos de la primera si 
están en la segunda:
```
std::list<T> DobleSegunda(std::list<T> a,std::list<T> b);
```
# Ejercicio 6
Escriba un programa que reciba por línea de comandos un Puerto y una IP. El programa debe aceptar una unica conexión e imprimir en stdout todo lo recibido. 
Al recibir el texto ‘FIN’ debe finalizar el programa sin imprimir dicho texto.

# Ejercicio 7
Escriba el .H de una biblioteca de funciones ISO C para números complejos. Incluya, al menos, 4 funciones.

# Ejercicio 8
Explique qué es cada uno de los siguientes, haciendo referencia a su inicialización, su comportamiento y el area de memoria donde residen: 
 1. Una variable global static
 2. Una variable local static 
 3. Un atributo de clase static.
1. La variable sera global en el modulo que se la declaro, pero no en otro. Es decir solo puede ser accedida en el archivo donde se la declaro, como es static no puede ser exportada por el linker. El area en el cual reside es en la de datasegment y si no la defino con un valor explicito se la inicialiara con null. Su vida duarara lo que dure el archivo en el que fue declarada. 
2. la variable local sera solo accedida en la funcion donde se la declaro por ser local y mantiene su valor entre llamados de distitas funciones. Por ser static reside en el datasegment y si no es inicialziada por el programado se inicializa en cero o nuul.
3. Este atrubuto se encuentra en el datasegment, y puede ser accedida en todo el programa. tambein la inicializa el compilador en ceor o null en caso de no estar inicializada por el programador. Su lifetime sera de todo el programa. 
# Ejercicio 9
¿Cómo se logra que 2 threads accedan (lectura/escritura) a un mismo recurso compartido sin que se generen problemas de consistencia? Ejemplifique.
   Para que dos hilos puedan acceder a un mismo recurso compartido sin que ocurra una race condition hay que porteger al recurso compartido, esto se hace por medio de un mutex( el cual debe ser unico para el recurso) cuando el hilo accede al recurso debe lockear el mutex para que ningun otro hilo pueda acceder al recurso mientras el lo esta usando. Cuando termina de usarlo debe unlockear el mutex porque sino se tendria un dead lock. Se recomienda fuertemente usar un lock raii en la cual se hace un ,lock en el contrscutor y un unlock cuando se invoca al destructor de esta forma el porgramador no se olvida de liberar el recurso. 
   Ej: Para un alista portegida 
 ```
   class ListaProtegida{
   private:
          std::list<int> lista;
          std::mutex m;
   public:
          void agregarSiNoFueAgregado(int x){
             m.lock();
             if (!lista.has(x)){
                  lista.pushback(x);
             }
             m.unlock();
          }
 ```
 

# Ejercicio 10   
Indique la salida del siguiente programa: 
```   
   class A { 
   A(){cout << “A()” << endl;} 
   ~A(){ cout << “~A()” << endl;} }
class B : 
  public A { 
      B(){cout << “B()” << endl;}
      ~B(){ cout << “~B()” << endl;} 
      }
      
int main () {
B b; 
return 0;
}
```
salida es: A()B()~B()~A()
cuando se instacia b como esta hereda de a primero se llama al constructor de a y luego al de b y cuando se va a destruir primero se destruye el constructor de b y luego del de a. 

    
