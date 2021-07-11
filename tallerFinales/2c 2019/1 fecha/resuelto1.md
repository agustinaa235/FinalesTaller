1) Explique breve y concretamente qué es f:
int (*f) (short int *, char[3]);
2) 2) Explique qué es cada uno de los siguientes, haciendo referencia a su inicialización, su comportamiento y el area de memoria donde residen:
a) Una variable global static. b) Una variable local static. c) Un atributo de clase static.

a) variable global static, es una variable en la cual puede ser accedida durante toda la ejecucion del programa, esta se inicializa al incio del programa en cero si no se le especifica ningun valor 
con el valor correspondiente. El area de memoria que le corresponde es el data segmentent. Su visibilidad es en todo el porgrama, es decir puede ser accedida en cualquier momento.
b) variable local static, es una variable que solo puede ser accedida en el llamado dela funcion que se encuentra, es decir dura el tiempo de ejecucion de la funcion, una vez que 
termina de ejecutarse la funcion, ya no se la puede llamar mas. El area de memoria correspondiente es tambien el data segment y su inicializacion es de todos ceros. 
c) un atributo de clase static

3) Escribir un programa ISO C que procese el archivo “nros2bytes.dat” sobre sí mismo, duplicando los enteros de 2 bytes múltiplos de 3.
4) ¿Cómo se logra que 2 threads accedan (lectura/escritura) a un mismo recurso compartidon sin que se generen problemas de consistencia? Ejemplifique.
Para que no halla probelmas de consistencia entre dos hilos, es decir, no halla una raice condition es necesario proteger al recurso compartido. Esto se hace mediante a un mutex. 
Solo un unico hilo puede tomar al mutex, cuando accede al recurso este hilo hace un lock y solo el puede acceder a el y cuando realice un unlock va a ser cuando el otro hilo va a 
poder acceder al recurso. Es importante tener en cuenta que hay un mutex por recurso. Un ejemplo seria se quiere agregar el numero 3 a una lista si no esta. Un primer hilo pregunta
si esta el numero 3, hace un lock, no esta, hace un un lock y antes de que puede agregarlo se hace un counter switich y se pasa a otro hilo y pregunta lo mismo pero en este caso la
lista esta vacia entoncs cuando pregunta le dice que no hay un 3 por lo que la agrega un 3, se vuelve a hacer un counter switch y el primer hilo agrega el 3, lo cual estara mal porque
ya hay un 3 en la cola entonces tenemos una race condition. Es por eso que hay que proteger al recurso, en este caso la lista, en la cual deveria agregar si no hay ningun elemento. 
5) Escriba el .H de una biblioteca de funciones ISO C para cadenas de caracteres. Incluya, al menos, 4 funciones.
#ifndef _cadena_caracteres_H
#define _cadena_caracteres_H

typedef struc cadena_caracteres{
    vector_t vector;
    int tamanio;
 }cadena_caracteres_t
 
 void inicializar_cadena(int tamanioInicial);
 void destruir_cadena();
 void agregarCaracter(const char caracter);
 int obtenerLargoCadena();
 int sacarCaracter(const char caracter);
 
 #endif _cadena_caracteres_H
 
 6) ¿Qué es una macro de C? Detalle las buenas prácticas para su definición. Ejemplifique
 una macro es una porcion de codigo que se traduce en tiempo de preproceso, antes de que se realiza el proceso de compilacion y pasar el codigo a codigo ensamblador lo que se 
 hace es una expacion de macros en la cual se copia en todo lugar donde fue llamada la macro el codigo definido y luego ahi se pasa a la etapa de compilacion. 
 7) Describa el proceso de transformación de código fuente a un ejecutable. Precise las etapas y las tareas desarrolladas en cada una de ellas.
 Como primer paso está el preprocesamiento donde se realiza la expansión de macros, luego en el proceso de compilación consiste en transformar el código fuente al código 
 assembly, un lenguaje de menor nivel.Antes de pasar a código assembly, el código  creado por el programador pasa por una etapa de parseo en la cual se lleva ese código del 
 programador a código c puro.
 Luego se pasa por el ensamblador que este proceso consiste de dos pasadas. En la primera pasada se crea la tabla de símbolos y luego en la segunda pasada se generará el 
 código objeto utilizando los datos de la tabla de símbolos. Por último, pasamos por el link-edition en la cual su trabajo consiste en linkear(enlazar) distintos código 
 objeto(bibliotecas) dentro de un mismo módulo y generar el archivo ejecutable.
 8) Indique la salida del siguiente programa: class A{ A(){cout << “A()” << endl;} ~A(){ cout << “~A()” << endl;} }
class B : public A { B(){cout << “B()” << endl;} ~B(){ cout << “~B()” << endl;} }
int main () { B b; return 0;}

9) Implemente una función C++ denominada Sacar que reciba dos listas de elementos y devuelva una nueva lista con los elementos de la primera que no están en la 
segunda: std::list Sacar(std::list a,std::list b);**
std::list Sacar(std::list a, std::list b){

10) Escriba un programa que reciba por línea de comandos un Puerto y una IP. El programa debe establecer una unica conexión, quedar en escucha e imprimir en stdout 
todo lo recibido. Al recibir el texto ‘FINAL’ debe finalizar el programa sin imprimir dicho texto.

