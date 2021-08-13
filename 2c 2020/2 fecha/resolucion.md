# Ejercicio 1
Escriba un programa (desde la inicialización hasta la liberación de los recursos) que escuche el puerto 120 y reciba paquetes de la forma: 
[CHAR_LIM]xxxxx.xxxxxxx[CHAR_LIM] donde [CHAR_LIM] puede ser cualquier caracter ASCII Al completar la recepción del paquete deberá imprimir el caracter con más 
apariciones del mismo (sin considerar [CHAR_LIM]). Al recibir un paquete vacío ([CHAR_LIM][CHAR_LIM]) debe cerrarse ordenadamente. No considere errores.

# Ejercicio 2
¿Qué función se utiliza para lanzar hilos?¿Qué parámetros tiene y para qué sirven? Ejemplifique.
En c++11 para poder ejecutar/ lanzar un funcion en un hilo se puede hacer mediante std::thread. Los parametros que tiene son la funcion que se quiere ejecutar en ese hilo y los otros parametris corresponden a los parametros de la funcion. 
ej:
void foo(int i){}

int main(){
    std::thread hilo(foo, 1);
}    

# Ejercicio 3
¿Qué finalidad tiene la palabra virtual antepuesta a un método? Ejemplifique.

La palabra virtual lo que indica es si ese metodo va a tener entrada en la tabla virtual del metodos. Los metodos virtuales son metodos que se declaran en una clase base y estos pueden ser redefinidos o no en las clases sub hijas. Si fuese abstracto, es decir virtual puro, ahi las clases hijas tienen que definiarla cada uno pero sino es virtual puro pueden no redefinirlas. Son muy importantes para la la programacion orientada a objetos, para la herencia y el polimorfismo. 
ej:
```
 Class Figura{
        virtual int calcularArea();
 }
 class Triangulo: public Figura{
        int calcularArea(){
            return (base*altura)/2;
       }
}
```

# Ejercicio 4
Implemente una función C++ denominada DUPLICAR que reciba dos listas de elementos y devuelva una nueva lista duplicando los elementos de la primera que están en 
la segunda: std::list Duplicar(std::list a,std::list b);

hecho en otro final como doblesegunda 

# Ejercicio 5
Declare una clase a elección considerando: - Atributos que son necesarios - Accesibilidad a la Clase - Incluir los operadores *, --(pre-decremento), 
++(post-incremento), << (impresión), >>(carga desde consola), functor

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
* a es la declaracion de un array de tamanio 25 de punteros a int. Se inicicalizara en el modulo extener en el que fue declarado y no posee area de memoria ya que es extern, es decir, se encuentra en otro porgrama.
* b es una definicion de un funcion que devuelve int y no recieb parametros. Esta recide en el code segment y tiene un scope local.
* c es una definicion del tipo flote, es una variable static por lo que se ecnuentra en el data segment, esta solo puede ser accedida dentro de la funcion y cuando este termine de ejecutarse termina el lifetime de la varibale. Se inicializa una vez al iniciarse la ejecucion del programa y se inicializa en cero ya que se inicializan con este valor las variables estaticas que no se les asigno un valor al compilarse el programa.
* d es una definicion del tipo char, se encuentra inicializada con el caracter correspondiente al valor 70 de la tabla ascci, esta redice en el stack y tiene un lifetime de lo que dure la ejecucion de la funcion , es decir, cuando se sale de la funcion ya no se puede acceder a esa variable. Tiene un sope local de esa funcion.

# Ejercicio 7
Escriba una rutina que dibuje un rombo verde que ocupe toda la ventana.
HECHO
# Ejercicio 8
¿Qué diferencia existe entre un constructor por copia y uno por movimiento? Ejemplifique.


# Ejercicio 9
Escriba una función ISO C que permita procesar sobre sí mismo (sin generar archivos intermedios ni cargar el archivo completo a memoria) un archivo texto con palabras separadas por espacios. El procesamiento consiste en duplicar las palabras que tengan al menos de 2 vocales.
HECHO

Ejercicio 10
# Ejercicio 10
¿Qué es la compiLación condicional? Ejemplifique

La compilacion condicional es el proceso por el cual se verifica condicionalmente si una parte de un archivo debe ser compilada o no. Esto se sabe por medio de la directivas del compilador #ifndef, #define y #endif. Ej
```
#ifndef   _NUMERO_
#define _NUMERO_
...
...
#endif _NUMERO_
```
Si la clase numero se encuentra definida, directamente ejecuta la directiva endif, sino la define. 
Esto sirve para no tener multiples inclusiones de una clase o para cortar lo includes ciclicios.

 
            

