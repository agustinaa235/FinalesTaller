# Pregunta 1
Escriba un programa que escriba por salida estandar los numeros entre
0 y 1000 ordenadamente. Se pide que los numeros pares sean escritos por un
hilo mientras los impares sean escritos por otro.
Contemple la correcta sincronizacion entre los hilos y la liberacion de los
recursos utilizados.


# Pregunta 2
Defina un rutina en C que se conecte a la IP 10.9.8.7, puero 7777 y procese
la informacion recibida. El proceso consiste en recibir textos numericos
utilizando '\n' como caracter delimitador.
Para cada entero recibido se debe enviar su valor convertido en 32 bits
big-endian en modo binario sin delimitadores. El proceso finaliza al recibir
el valor 0.

# Pregunta 3
Por que las librerias que usan Templates se publican con todo el codigo
fuente y no como un .h/.o

# Pregunta 4
Escriba una funcion C llamada Agrandar que reciba por parametro 1 cadena (S),
dos indices (I1, I2) y una cantidad (Q).
La funcion debe retornar una copia de S salvo los caracteres entre los indices
I1 y I2 que seran duplicados Q veces en la misma posicion.
Ej: Agrandar("Chau", 1, 2, 3) retorna "Chahahau"

# Pregunta 5
Explique que es y para que sirve un constructor MOVE en C++. Indique como
se comporta el sistema si este no es definido por el desarrollador.

# Pregunta 6
Defina la clase URL para permitir almacenar las siguientes propiedades:
protocolo (http), host (fi.uba.ar), port (80), y file (index.php o resources/img/logo.png)
A su vez se pide que implemente los siguientes operadores: operator<<, operator==
y operator=.

# Pregunta 7
Que es un functor? Ejemplifique.

# Pregunta 8
Describa el concepto de loop de eventos (event loop) utilizado en programacion
orientada a eventos y en particular en entornos de interfaz grafica (GUIs).

# Pregunta 9
Escriba un programa C que reciba por argumento el nombre de un archivo
de numeros binarios de 16 bits y lo procese sobre si mismo.
El procesamiento consiste en repetir los numeros que sean "multiplos de 5 + 1" (6, 11, 16...)
(El archivo se agranda)

# Pregunta 10
Describa las siguientes declaraciones/definiciones globales:
```int (*A)();
char *B(unsigned a, short b) {}
static unsigned **C[3];
```
