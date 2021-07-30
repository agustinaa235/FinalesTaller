1) ¿Qué es una macro de C? Enumere buenas prácticas para su definición.
Es una porcion de codigo en la cual es procesada en la etapa de precompilacion, en la precompilacion lo que se hace es copiar esa porcion de codigo en todo lugar 
al que fue llamado. FALTA BENEFICIOS.
2) Describa el proceso de transformación de código fuente a un ejecutable. Precise las etapas y las tareas desarrolladas en cada una de ellas
para pasar del codigo fuente a un codigo ejecutable tenemos distintas etapas:
 - Preproceso: 
    Es la etapa donde se procesan las macros, lo que se hace es copiar el codigo de la macro en todo lugar al que fue llamado
 - Compilacion: 
    En esta etapa se pasa de codigo fuente c a codigo assembly 
 -  Ensambablado: 
    Una vez generado el codigo assembly, se debe pasar a codigo objeto. En esta etapa consta de dos pasadas. En la primer pasada se crea una tabla de simbolos en 
    la cual se cargan todos los simbolos(variables, ctes, etc) y luego en la segunda pasada es donde se genera el codigo objeto. 
 - Linkeo:
    Una vez generado el codigo objeto, lo que se hace es linkear/juntar los distintos modulos objetos dentro un mismo modulo y generar el archivo .exc
3) Explique breve y concretamente qué es f:
```
  char (*f) (int *, char[3]);
```
es una declaracion de un puntero a una funcion f que devuelve como tipo de dato char y recibe como parametro un dato del tipo int puntero y un vector de 
de tipo de dato char de 3 elementos.

4) Escribir un programa ISO C que procese el archivo “nros_2bytes_bigendian.dat” sobre sí mismo, eliminando los número múltiplos de 7.
5) Implemente una función C++ denominada DobleSegunda que reciba dos listas de elementos y devuelva una nueva lista duplicando los elementos de la primera si 
están en la segunda:
```
std::list<T> DobleSegunda(std::list<T> a,std::list<T> b);
```
6) Escriba un programa que reciba por línea de comandos un Puerto y una IP. El programa debe aceptar una unica conexión e imprimir en stdout todo lo recibido. 
Al recibir el texto ‘FIN’ debe finalizar el programa sin imprimir dicho texto.

7) Escriba el .H de una biblioteca de funciones ISO C para números complejos. Incluya, al menos, 4 funciones.

8) Explique qué es cada uno de los siguientes, haciendo referencia a su inicialización, su comportamiento y el area de memoria donde residen: 
    a) Una variable global static
    b) Una variable local static 
    c) Un atributo de clase static.
9)  ¿Cómo se logra que 2 threads accedan (lectura/escritura) a un mismo recurso compartido sin que se generen problemas de consistencia? Ejemplifique.
 
10)   Indique la salida del siguiente programa: 
```   
   class A { 
   A(){cout << “A()” << endl;} 
   ~A(){ cout << “~A()” << endl;} }
class B : 
  public A { 
      B(){cout << “B()” << endl;}
      ~B(){ cout << “~B()” << endl;} 
      }
      
int main () { B b; return 0;}
```

    
