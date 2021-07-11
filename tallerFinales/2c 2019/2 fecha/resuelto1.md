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
El lenguaje C ofrece punteros a funciones. Estos permiten llamar a diferentes funciones según el valor del puntero. Un puntero así no apunta a un dato sino a un comportamiento – 
el comportamiento que implementa la función.
Punteros ofrecen, además, apuntar a direcciones de memorias erróneas. Así es posible ejecutar cualquier dato como función. Esto es mal cogio. En c++ se tiene a los functores que 
son clases que tienen sobrecargado el operador(). Esto permite utilizar una instancia de una clase como una función – y sólo una función y no cualquiera. La ventaja de usar 
functores es queofrecen la seguridad de no ejecutar código cualquiera como puede pasar con punteros mal inicializados, que esto sucede con punteros a funciones. 
5) ¿Cómo se logra que 2 threads accedan (lectura/escritura) a un mismo recurso compartido sin que se generen problemas de consistencia? Ejemplifique.
rta en final 2c
6) Describa el concepto de loop de eventos (events loop) utilizado en programación orientada a eventos y, en particular, en entornos de interfaz gráfica (GUIs).
el loop de eventos en un loop que maneja los eventos que se encuentran encolados en la cola de eventos, este intenta manejar cada evento, si se tratase de salir en ese caso termina 
el juego pero si se tratase de otro evento, en este loop se encarga de manejar y ejecutar ese evento y sacarlo de la cola. Esto lo hace mientras halla eventos. Es muy utilizado en 
juegos, en donde se tiene comnados, como por ejemplo el cliente dispara o se mueve entonces del lado del servidor se debe procesar esos comandos de todos los jugadores y ejecuar 
cada uno. 
7) Considere la estructura struct ejemplo { int a; char b;}. ¿Es verdad que sizeof (ejemplo)=sizeof(a) +sizeof(b)? Justifique.
esto es falso, si tomamos por separados el tamnio que ocupa cada variable vemos que b como es un char ocupa un byte y a que se trata de un int ocuparia 4 bytes sumados darian 5
bytes en total pero si se tiene en un struct, estas variables se guardan como multiplos de cuatro por lo que si bien se tiene un char este ocuparia 4 bytes, teniendo asi 8 bytes 
ocupados. 
8) ¿En qué consiste el patrón de diseño RAII? Ejemplifique.
raii consiste en que siempre que tengamos una clase este debe tener un cosntructor y un destructor en la cual en el constructor se inicializa todo los atributos de la clase y se
reserva la memoria necesario y luego en el destructor se liberan todos los recursos reservados de memoria. Esto se debe hacer siempre para poder liberar recursos. 
9) Escribir un programa ISO C que procese el archivo de enteros de 2 bytes bigendian cuyo nombre es recibido como parámetro. El procesamiento consiste en eliminar 
 los número múltiplos de 3, trabajando sobre el mismo archivo (sin archivos intermedios ni en memoria).
10) Implemente una función C++ denominada DobleSiNo que reciba dos listas de elementos y devuelva una nueva lista duplicando los elementos de la primera que no están 
en la segunda:
