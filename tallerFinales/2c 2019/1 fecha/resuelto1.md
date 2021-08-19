# Ejercicio 1
Explique breve y concretamente qué es f:
``int (*f) (short int *, char[3]);``
# Ejercicio 2
Explique qué es cada uno de los siguientes, haciendo referencia a su inicialización, su comportamiento y el area de memoria donde residen:
    1. Una variable global static. 
    2. Una variable local static. 
    3. Un atributo de clase static.

1. variable global static, es una variable en la cual puede ser accedida durante toda la ejecucion del programa, esta se inicializa al incio del programa en cero si no se le especifica ningun valor 
con el valor correspondiente. El area de memoria que le corresponde es el data segmentent. Su visibilidad es en todo el porgrama, es decir puede ser accedida en cualquier momento.
2. variable local static, es una variable que solo puede ser accedida en el llamado dela funcion que se encuentra, es decir dura el tiempo de ejecucion de la funcion, una vez que 
termina de ejecutarse la funcion, ya no se la puede llamar mas. El area de memoria correspondiente es tambien el data segment y su inicializacion es de todos ceros. 
3. un atributo de clase static

# Ejercicio 3
Escribir un programa ISO C que procese el archivo “nros2bytes.dat” sobre sí mismo, duplicando los enteros de 2 bytes múltiplos de 3.
HECHO
# Ejercicio 4
¿Cómo se logra que 2 threads accedan (lectura/escritura) a un mismo recurso compartidon sin que se generen problemas de consistencia? Ejemplifique.

Para que no halla probelmas de consistencia entre dos hilos, es decir, no halla una raice condition es necesario proteger al recurso compartido. Esto se hace mediante a un mutex. El mutex lo que permite es tener dos estados bloqueado y liberado. Cuando un hilo accede a un recurso compartido se debe hacer un lock del mutex, esto lo que haces es bloquear al mutex hasta que el hilo termine de usar el recurso y recine ahi se libera el mutex y ahi puede otro hilo acceder al recurso.
ej:
``` C++
class ListaProtegida{
        private:
            std::mutex m;
            std::list<int> list;
        public:
            void agregarSiNoContiene(int valor){
                m.lock();
                if(!lista.has(valor)){
                        list.push_back(valor);
                 }
                 m.unlock();
             }
}
```


# Ejercicio 5 
Escriba el .H de una biblioteca de funciones ISO C para cadenas de caracteres. Incluya, al menos, 4 funciones.
#ifndef _cadena_caracteres_H
#define _cadena_caracteres_H
```C
typedef struc cadena_caracteres{
    vector_t vector;
    int tamanio;
 }cadena_caracteres_t
 
 void inicializar_cadena(int tamanioInicial);
 void destruir_cadena();
 void agregarCaracter(const char caracter);
 int obtenerLargoCadena();
 int sacarCaracter(const char caracter);
 bool compararCadenas(const char* cadena);
 
 #endif _cadena_caracteres_H
 ```
 
 # Ejercicio 6 
 ¿Qué es una macro de C? Detalle las buenas prácticas para su definición. Ejemplifique
 Una macro es una instruccion que se realiza en forma de directiva al preprocesador del compilador de c, con el objetivo de expandir todas las apariciones del simbolo asociado a la macro de forma literal. Las macros pueden estar definidas en funcion de una variable, y como las macros son expandidas de forma literal, es importante que las varaibles se encuentren entre parentesis para evitar problemas. Otra buena practica es tener un nombre descriptivo. 
 ej:
 ``` #define DOBLE(A) 2*(A)```

 # Ejercicio 7 
 Describa el proceso de transformación de código fuente a un ejecutable. Precise las etapas y las tareas desarrolladas en cada una de ellas.
 Como primer paso está el preprocesamiento donde se realiza la expansión de macros y se resuelven las directivas del preprocesador(#define, #ifndef, #ifdef, ect), luego en el proceso de compilación consiste en transformar el código fuente al código assembly, un lenguaje de menor nivel.Antes de pasar a código assembly, el código  creado por el programador pasa por una etapa de parseo en la cual se lleva ese código del programador a código c puro.
 Luego se pasa por el ensamblador que este proceso consiste de dos pasadas. En la primera pasada se crea la tabla de símbolos y luego en la segunda pasada se generará el  código objeto utilizando los datos de la tabla de símbolos. Por último, pasamos por el link-edition en la cual su trabajo consiste en linkear(enlazar) distintos código  objeto(bibliotecas) dentro de un mismo módulo y generar el archivo ejecutable.
 # Ejercicio 8
 Indique la salida del siguiente programa: class A{ A(){cout << “A()” << endl;} ~A(){ cout << “~A()” << endl;} }
class B : public A { B(){cout << “B()” << endl;} ~B(){ cout << “~B()” << endl;} }
int main () { B b; return 0;}

la salida es
```
A()
B()
~B()
~A()
```


# Ejercicio 9 
Implemente una función C++ denominada Sacar que reciba dos listas de elementos y devuelva una nueva lista con los elementos de la primera que no están en la 
segunda: std::list Sacar(std::list a,std::list b);**

```C++
std::list<T> Sacar(std::list a, std::list b){
    std::list<T> nueva;
    for (T& elem: a){
          // si no esta la agrego a la lista nueva
        if (std::find(b.begin(), b.end(), elem) == b.end()){
                    nueva.push_back();
        }
     }
     return nueva;
}
```

# Ejercicio 10 
Escriba un programa que reciba por línea de comandos un Puerto y una IP. El programa debe establecer una unica conexión, quedar en escucha e imprimir en stdout 
todo lo recibido. Al recibir el texto ‘FINAL’ debe finalizar el programa sin imprimir dicho texto.
HECHO

