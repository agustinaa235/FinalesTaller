# Ejercicio 1
Escriba un programa (desde la inicialización hasta la liberación de los recursos) que escuche el puerto 120 y reciba paquetes de la forma: 
[CHAR_LIM]xxxxx.xxxxxxx[CHAR_LIM] donde [CHAR_LIM] puede ser cualquier caracter ASCII Al completar la recepción del paquete deberá imprimir el caracter con más 
apariciones del mismo (sin considerar [CHAR_LIM]). Al recibir un paquete vacío ([CHAR_LIM][CHAR_LIM]) debe cerrarse ordenadamente. No considere errores.

# Ejercicio 2
¿Qué función se utiliza para lanzar hilos?¿Qué parámetros tiene y para qué sirven? Ejemplifique.
En c++ podemos ejecutar/lanzar un hilo por medio de std::thread. Los parametros que se deben pasar es la funcion que queremos que ocurra en un hilo paralelo y sus 
parametris. Ej:
``` 
void f (int i);

std::thread(f,1);
```
# Ejercicio 3
¿Qué finalidad tiene la palabra virtual antepuesta a un método? Ejemplifique.

# Ejercicio 4
Implemente una función C++ denominada DUPLICAR que reciba dos listas de elementos y devuelva una nueva lista duplicando los elementos de la primera que están en 
la segunda: std::list Duplicar(std::list a,std::list b);

hecho en otro final como doblesegunda 

# Ejercicio 5
Declare una clase a elección considerando: - Atributos que son necesarios - Accesibilidad a la Clase - Incluir los operadores *, --(pre-decremento), 
++(post-incremento), << (impresión), >>(carga desde consola), functor

```C++
class Numero{
    private:
          int valor;
    public:
          Numero(int& valor); 
          int operador--();
          int operador++();
          std::istream operador>>(std::istream v, NUmero& numero);
          std::ostream operador<<(std::ostream v, NUmero& numero);
          ~Numero();
}
```
# Ejercicio 6
Explique qué es (a), (b), (c) y (d), haciendo referencia a su valor y momento de inicialización, su comportamiento y el area de memoria donde residen:
```C
extern int *a[25];
int b()
{
static float c; char d=70;
return c+(float) d;
}
``` 
* a: es un arreglo de tamanio 25 de punteros a int. Es externo por lo cual va a estar inicialializado en otro modulo y no se le asigna singun area de memoria. 
* b: b es una funcion sin paramtros que devuelve int. Se encuentra definida y recide en el data segment.
* c: es un static float, solo puede ser accedida en la funcion b ya que es local y static. Al ser una declaracion no se le resever memoria por lo que no redice en ninguna area de memoria. 
* d: es una variable del tipo char en la cual esta inicializada con valor correspondiente a la tabla ascci de 70. Recide en el stack

# Ejercicio 7
Escriba una rutina que dibuje un rombo verde que ocupe toda la ventana.
:(
# Ejercicio 8
¿Qué diferencia existe entre un constructor por copia y uno por movimiento? Ejemplifique.

El constructor por copia lo que hace es copiar cada atributo del objeto pasado por referencia para crear uno nuevo. Hace una copia de bit a bit del objeto. 
Mientras que el constructor por moviento cambia el ownership, es decir, no se hace una duplicacion de este sino que se mueven las referencias de los atributos 
haciendo que el objeto nuevo apunte a lo que aputnaba el objeto recibido y este se hace que sus atributos apunten a null. La gran diferencia es que al objeto 
pasado por el constructir por copai no puede ser modificado mientras que el utilizado por movimiento si. 
ej:
```C++
class Numero{
    public:
            Numero(int& valor); //constructor 
            Numero(const Numero& otro); //por copia 
            Numero(Numero&& otro); //por movimiento
}
```
# Ejercicio 9
Escriba una función ISO C que permita procesar sobre sí mismo (sin generar archivos intermedios ni cargar el archivo completo a memoria) un archivo texto con palabras separadas por espacios. El procesamiento consiste en duplicar las palabras que tengan al menos de 2 vocales.

Ejercicio 10
# Ejercicio 10
¿Qué es la compiLación condicional? Ejemplifique
La compilacion condicional es cuando ciertas partes del codigo van a ser compialdas o no dependiendo de si se encuentra definida. Muy util para cortar los includes cicliclos. Ej
```c
#ifndef _CLASS_
#defina _CLASS_
...
...
#endif
```
 
            

