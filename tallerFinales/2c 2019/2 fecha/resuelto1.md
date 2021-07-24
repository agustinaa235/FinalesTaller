1) Escriba un programa (desde la inicialización hasta la liberación de los recursos) que reciba paquetes de la forma nnn+nn+....+nnnn= (numeros separados por +, seguidos de =) 
e imprima el resultado de la suma de cada paquete por pantalla. Al recibir un paquete vacío (“=”) debe cerrarse ordenadamente. No considere errores.

2) Explique breve y concretamente qué es f:
```
    int (*f) (short *, char[4]);
```

f es la declaracion de un puntero a una funcion, en la cual esta funcion a su vez recibe un puntero.
3) Analice el siguiente código y determine lo que se imprime (valor de Pi)
```
    main(){
    int *Pi=1000;
    Pi++;
    printf(“Pi apunta a la dirección: %l”, (long)Pi);
    }
```

En este codigo tenemos un puntero pi que apunta a la direccion 1000, como se trata de un puntero int cuando se va a incrementar pi este va aumentar en 4 bytes ya que un int 
ocupa 4 bytes por lo que de la posicion 1000 se pasa a la posicion 1100 = 1000 + 100. 
4) ¿Qué es un functor? ¿Qué ventaja ofrece frente a una función convencional? Ejemplifique.
Un functor son objetos que pueden ser tratados como funciones o punteros a funciones, esas son clases que tienen sobre cargado el operador (). Estp nos permite utilizar una instancia de una clase como una funcion y solo una funcion que no es cualquiera, cosa que si se utilizaron punteros esta seguidad no estaria porque justamente al ser punteos estos pueden apuntar a direcciones de memoria erroneas.Su ventaja es que nos dan la seguridad de no ejecutar cualquier codigo, que si sucede con punteros mal inicializados como los punteros a funciones. 
 
5) ¿Cómo se logra que 2 threads accedan (lectura/escritura) a un mismo recurso compartido sin que se generen problemas de consistencia? Ejemplifique.
rta en otro fina. 
6) Describa el concepto de loop de eventos (events loop) utilizado en programación orientada a eventos y, en particular, en entornos de interfaz gráfica (GUIs).
El loop de venteos es aquel el que se encarg de manejar los eventos que se cuentran encolaos en la cola de eventos. En el loop lo que se hace es desencolar el evento y luego lo ejecuta, esto lo hace iterativamente mientras halla eventos en la cola. Es muy utilizado en juegos en la cual se tienen comnaods como disparar o moverse o agarrar comia. DEl lado del servido se desencola esos eventos y los ejecuta a cada uno.
 
7) Considere la estructura struct ejemplo { int a; char b;}. ¿Es verdad que sizeof (ejemplo)=sizeof(a) +sizeof(b)? Justifique.
esto es falso, si tomamos por separados el tamnio que ocupa cada variable vemos que b como es un char ocupa un byte y a que se trata de un int ocuparia 4 bytes sumados darian 5 bytes en total pero si se tiene en un struct, estas variables se guardan como multiplos de cuatro por lo que si bien se tiene un char este ocuparia 4 bytes, teniendo asi 8 bytes ocupados. 
8) ¿En qué consiste el patrón de diseño RAII? Ejemplifique.
raii consiste en que siempre que tengamos una clase este debe tener un cosntructor y un destructor en la cual en el constructor se inicializa todo los atributos de la clase y se reserva la memoria necesaria y luego en el destructor se liberan todos los recursos reservados de memoria. Esto se debe hacer siempre para poder liberar recursos. 
9) Escribir un programa ISO C que procese el archivo de enteros de 2 bytes bigendian cuyo nombre es recibido como parámetro. El procesamiento consiste en eliminar 
 los número múltiplos de 3, trabajando sobre el mismo archivo (sin archivos intermedios ni en memoria).
10) Implemente una función C++ denominada DobleSiNo que reciba dos listas de elementos y devuelva una nueva lista duplicando los elementos de la primera que no están 
