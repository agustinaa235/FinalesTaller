# Ejercicio 1
¿Qué es un functor? Ejemplifique

Un functor es una clase que actua como funcion y son invocados de la misma forma sintatica que se hace para invocar a una funcion. Para hacer esto tiene 
sobrecargado el operador(). Su ventaja es que permiten que desacoplar el momento en el que se pasan los parametros a una funcion mientras esta es ejecutada. 
ej:
``` C++
class Incrementador{
      int acum = 0;
      Incrementador(int n): acum(n){}
      
      int operator()(int valor){
          return acum + valor;
       }
```      
# Ejercicio 2
Explique qué es cada uno de los siguientes, haciendo referencia a su inicialización, su
comportamiento y el area de memoria donde residen:
a) Una variable global static
b) Una variable local
c) Un atributo de clase static.
# Ejercicio 3
Declare una clase a elección considerando:
 Atributos que son necesarios
 Accesibilidad a la Clase
 Incluir los operadores +, ++, >> (impresión), << (carga desde consola), int
# Ejercicio 4
Escriba un programa que imprima por salida estándar los números entre 1 y 100, en orden
ascendente. Se pide que los números sean contabilizados por una variable global única y que
los pares sean escritos por un hilo mientras que los impares sean escritos por otro.
Contemple la correcta sincronización entre hilos y la liberación de los recursos utilizados.
# Ejercicio 5
¿Qué es la compilación condicional? En qué etapa del proceso de transformación de
código se resuelve. Ejemplifique mediante código C, dando un caso de uso útil.

La compilacion condicional es un proceso por el cual se verifica condicionalmente si un archivo debe ser compilado o no. Esto es util para cuando se tiene multiples inclusiones de un archivo. 
ej:
```C
      #ifndef _CLASS_
      #define _CLASS_
      ...
      ...
      #endif _CLASS_
 ```
 en este caso si CLASS se encuentra definido directamente ejecuta la directiva endif, y sino la define
 Esto se realiza en el precosesamiento donde se exande las macros y se resulven las directivas del precompilador.
# Ejercicio 6
Escriba una función ISO C que permita procesar un archivo texto sobre sí mismo, que
contenga una palabra por línea. El procesamiento consiste en ordenar las palabras (líneas)
alfabéticamente considerando que el archivo no entra en memoria.
# Ejercicio 7
¿Por qué las librerías que usan Templates se publican con todo el código fuente y no como
un .h y .o/.obj

Los templates son plantillas de clases. Sirven para poder tener un mismo codigo que funcione con distintos tipos de datos y con eso nos ahoramos tener codigo duplicado. La librerias Template se publican en todo el codigo ya que el codigo template es exapndia en tiempo de compilacion en la cual el compilador primero determian el tipo de dato antes de expandir la plantilla. La idea costa de que el codigo fuente tenga una funcion generica pero el compilador va a tener distinas copias de la funcion esa.

¿Qué significa la palabra virtual antepuesta a un método de una clase?¿Qué cambios genera
a nivel compilación y al momento de ejecución?

La palabra virtual indica si ese metodo va a tener una entrada en la tabla virtual de metodos.Lo que permite esto es que la decision de que funcion llamar se lleve acabo en tiempo de ejcucion. Esta es utilizada cuando se tiene una clase base y se tiene un metodo declarado y se tiene clases hijas(heredan de la clase madre) donde estan pueden o no redefinir ese metodo de la clase madre. En el caso de que sea virtual puro, las clases hijas estan obligadas a definir ese metodo con su correspondiente implementacion mientras que si es virtual solo las clases hijas pueden redefinir el metodo como no. Los metodos virtualle permite al programa llamar a funciones que capaz no existen al momento de ser compiladas. Es decir se resuelven en tiempo de ejecucion. SE utiliza para aplicar poliformismo yo tengo distntas clases figuras y en mi codigo para mantener el encapsulamiento rebico a una instancia figura y hago figura.calcularArea(), esa funcion se reuelve en tiempo de ejecucion ya que se tiene que ver que instacia se le esta pasando.

# Ejercicio 9
Escriba un programa (desde la inicialización hasta la liberación de los recursos) que reciba
paquetes de texto delimitados por corchetes angulares (“<...>”) y los imprima completos por
pantalla. Al recibir un paquete vacío (“<>”) debe cerrarse ordenadamente. No considere
errores.
# Ejercicio 10
Describa el concepto de loop de eventos (events loop) utilizado en programación
orientada a eventos y, en particular, en entornos de interfaz gráfica (GUIs).

El loop de eventos es un bucle que se encarga de procesar los eventos de la cola de eventos. Es un patron muy utilizado para aplicaciones que poseen interacion con el usuario de forma grafica ya que un evento podria ser hacer click o pulsar una tecla. El patron consiste en un loop en el cual se va ir sacando eventos de la cola de eventos y luego se lo va a ir manejando de acuerdo al tipo de evento que llegue, si el evento es salir se corta el loop y se sale y sino se procesa mediante un manejador de eventos. 

      
