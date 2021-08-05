# Ejercicio 1 
Explique breve y concretamente qué es f:

`int *(**f) (short int *, char *[2]);`

SE trata de una delcracion donde f es un puntero a un puntero de una funcion que recibe como parametros un short int puntero y un puntero a un arreglo del tipo 
char de tamanio 2. Devuelve un puntero a un int.

# Ejercicio 2
Explique qué es cada uno de los siguientes, haciendo referencia a su inicialización, su comportamiento y el area de memoria donde residen: 
   1.Una variable global static 
   2. Una variable local static 
   3. Un atributo de clase static.
   
1. Una variableglobal static puede ser accedida por todo el modulo que la declaro pero no puede ser exportada por el linker, es decir, solo puede ser llamada
en ese modulo. El area de memoria en el que se encuentra es el de data segment por ser static y en caso de no ser iniciaizada se la inicializa con un valor NULL
2. Una variable local static puede ser accedida solo en la funcion que fue declarada y su lifetime termine cuando se sale de la funcion. Esta se encuentra en el data 
segment y si no es unicializada se la inicializa con un valor NULL
3. UN atributo de clase puede ser accedida por solo su clase en caso de ser privada o si es protegida tambien por sus clases hijas si es que tiene. 

# Ejercicio 3
 Escribir un programa ISO C que procese el archivo “nros2bytes.dat” sobre sí mismo, duplicando los enteros de 2 bytes múltiplos de 3.
 
 # Archivo binario falta :(
 
# Ejercicio 4
 ¿Cómo se logra que 2 threads accedan (lectura/escritura) a un mismo recurso compartido sin que se generen problemas de consistencia? Ejemplifique.
 
 Para que dos hilos puedan acceder a un mismo recurso compartido sin que ocurra una race condition lo que se debe hacer es proteger al recurso compartido utilizando 
 un mutex, que es unico para el recurso. Lo que se debe hacer es hacer un lock del mutex cuando el hilo va a acceder al recurso para asi si otro hilo quiere acceder 
 este no puede porque ya lo tiene uno y hacer un unlock cuando termine de usar el recurso para que asi otro hilo recien en ese momento pueda acceder al recurso ya 
 que sino lo que sucederia es un dead lock. Ej colaProtegida
 ```C++
    class ColaProtegida{
      private:
            std::quee<int> cola;
            Mutex mutex;
      public:
           int SacarSiNoEstaVacia(){
                int valor_cola = -1;
                mutex.lock()
                if (!cola.is_empty()){
                    valor_cola =  cola.pop();
                }
                mutex.unlock();
                return valor_cola;
           }
 ```
 # Eejercicio 5
Escriba el .H de una biblioteca de funciones ISO C para cadenas de caracteres. Incluya, al menos, 4 funciones.
```C
#ifndef _CADENA_DE_CARACTERES_
#define _CADENA_DE_CARACTERES_

typedef struct Cadena_De_Caracteres{
    char** cadena;
    int tamanio;
}Cadena_de_caracteres;


void inicializarCadena(char** cadena, int tamanio);
int size();
int compararCadenas(char cadena1[Tam], char cadena2[Tam]);
char devolverCaracterEnpos(int pos);
void agregarCaracterEnPos(char character, int pos);
```
# Ejercicio 6
¿Qué es una macro de C? Detalle las buenas prácticas para su definición. Ejemplifique

despues completo, hecho en otro final

# Ejercicio 7
Describa el proceso de transformación de código fuente a un ejecutable. Precise las etapas y las tareas desarrolladas en cada una de ellas.

Como primer estaba esta la del preproceso, que es donde se realiza la expancion y definicion de las macros, es donde se copia y pega el codigo de la macro 
en todo lugar al que fue llamada. Luego esta la estapa de compilacion donde primero se pasa el codigo de c a codigo assembly( de mas bajo nivel) y luego se pasa
de codigo assembly a codigo objeto. Por ultimo se realiza el linkeo, se juntan los distintos codigos objetos(modulos) en un solo modulo y se crea el archivo 
ejecutable.

# Ejercicio 8
 Indique la salida del siguiente programa:
```
class A {
    A(){cout << “A()” << endl;}
    ~A(){ cout << “~A()” << endl;}
}
class B : public A {
    B(){cout << “B()” << endl;}
    ~B(){ cout << “~B()” << endl;}
}
int main () { B b; return 0;}
```
como salida se va a tener 
A()
B()
~B()
~A()
# Ejercicio 9
implemente una función C++ denominada Sacar que reciba dos listas de elementos y devuelva una nueva lista con los elementos de la primera que no están en la 
segunda 

HECHO EN OTRO FINAL

# Ejercicio 10
Escriba un programa que reciba por línea de comandos un Puerto y una IP. El programa debe establecer una unica conexión, quedar en escucha e imprimir en 
stdout todo lo recibido. Al recibir el texto ‘FINAL’ debe finalizar el programa sin imprimir dicho texto.

                
                
                
   
