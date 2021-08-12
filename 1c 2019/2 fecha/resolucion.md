# Ejercicio 1
Declare la clase Número para encapsular una cadena numérica larga. Incluya al menos: Constructor(unsigned long), Constructor default y Constructor 
move; Operador <<, (), =, long y ++(int). Implemente el operador >>.
```C++
class Numero{
      private:
          unsigned long valor;
      public:
          Numero(const unsigned long& unValor); // constructor
          Numero(); // por default
          Numero(Numero&& numero) // por movimiento
          Numero(const Numero& numero) // por copia;
          Numero operador++();
          Numero& operador=(Numero&& numero);
          operator long() conts;
          void operator()();
          std::istream operador>> (std::istream& in, Numero& numero){
              in >> numero.valor;
              return in;
          }
          std::ostream operador<<(std::ostream& out, Numero& numero){
            out << numero.valor;
            return out;
          }
```

          

# Ejercicio 2
¿Qué significa que una función es blocante?¿Cómo subsanaría esa limitación en término de mantener el programa ‘vivo’ ?

Una funcion es bloqueante cuando se ques "suspendia" , es decir, cuando se queda a la espera de que termine de finalizar su tarea o hasta obtener un resultado. Para mantener vivo al programa se utilizan hilos, es decir, se ejecuta la funcion bloquenate en un hilo aparte asi el resto del porgrama puede seguir ejecutandoce mientras que el otro hilo se queda esperando.

# Ejercicio 3
Explique qué son los métodos virtuales y para qué sirven. De un breve ejemplo donde su uso sea imprescindible.

Los metodos virtuales son metodos declarados en la clase base y pueden ser re definidos en las clases hijas. La funcion puede estar definida en la clase madre y las clases hijos overrideandolo como tambien cada sub hija puede sobreescribir la funcion. El virtual nos indica si ese metedo va a tener una entrada en la tabla virtual de metodos. Son muy importantes para la programacion oritneta a objetos(poo), sirven para aplicar polimormisfo. Un  ejemplo imprescindible seria cuando queremos modelar una clase figura y de ella queremos que herenden la funcion area en la cual esta debe ser abstracta por si tenes un trianguno y un cuadrado ambas calculan de forma distinta sus area por lo que cada sub hija deberia sobreescribir esa implementacion.

# Ejercicio 4
Escribir un programa C que procese el archivo “numeros.txt” sobre sí mismo (sin crear archivos intermedios y sin subir el archivo a memoria). 
El procesamiento consiste en leer grupos de 4 caracteres hexadecimales y reemplazarlos por los correspondientes dígitos decimales (que representen el 
mismo número leído pero en decimal).

# Ejercicio 5
Explique qué se entiende por “compilación condicional”. Ejemplifique mediante código.
Es el proceso en el cual se verifica condicionalmente si un bloque de codigo debe compilarse o no. Esto se hace por medio de las directivas del compilador #ifndef, #define y #endif. 
por ej:
```C
 #ifndef _NUMERO_
 #define _NUMERO_
 ...
 ...
 #endif 
 ```
 si la clase numero ya se encuentra definida simplemente ejecuta la directiva endif pero sino se encuentra la declara. Esto sirve para evitar tener multiples includes de una misma libreria. 
 
# Ejercicio 6
Escriba un programa C que tome 2 cadenas por línea de comandos: A y B; e imprima la cadena A después de haber duplicado todas las ocurrencias de B..
ej.: reemp.exe “Este es el final” final -----> Este es el final final

# Ejercicio 7
Escriba las siguientes definiciones/declaraciones:
a) Definición de una la función SUMA, que tome dos enteros largos con signo y devuelva su suma. Esta función sólo debe ser visible en el módulo donde se la define.

b) Declaración de un puntero a puntero a entero sin signo.
c) Definición de un caracter solamente visible en el módulo donde se define.
a)
``` static long int suma(long unNumero, long otroNUmero){
      return (unnumero + otroNumero);
   }
 ```
 
 ` unsigned int *(*a);`
 
 ` static char b = 'a';`
 
# Ejercicio 8
Qué valor arroja sizeof(int)? Justifique .
El valor que arroje sizeof(int) depende de la arquitecura y del compilador que se esta utlizando. Si la arquitectia es de 64 bits devuelve 8 bytes pero si la arquitectura es de 32 bits devuelve 4 bytes. 
# Ejercicio 9 
Describa el concepto de loop de eventos (events loop) utilizado en programación orientada a eventos y, en particular, en entornos de interfaz gráfica (GUIs).
El concepto de loop de eventos es utilizado en la porgramacion orientado a eventos donde constantemente estan llegando distintos tipos de eventos y estos deben ser procesados por el programa. El loop consta de ir sacando de una cola todos los eventos que van llegando e ir porcesandolos de acuerdo al evento que llega y en caso de que ese evento sea finalizar el loop termina de ejercutarse. Es muy util para juegos, con interfaces graficas ya que estos ponene eventos del tipo hacer click, o mover el mouse o pulsar una tecla entonces al programa le llega este evento y ya sabe como procesarlo. 

# Ejercicio 10 
¿Qué ventaja ofrece un lock raii frente al tradicional lock/unlock ?
Un lock raii es una clase que cumple con el patron raii es decir que hace un lock cuando se invoca al constructor de la clase y se hace unlock cuando se invoca al destructor de la clase. Lo que tiene de beneficioso es que evita que uno se olvide de realizar un unlock cuando termina de usar un recurso y esto es muy peligroso porque puede generarse un dead lock, es decir con un lock raii nos aseguramos que no no quede un hilo bloqueado cosa que podria ocurrir si no se utlizara ya que el programaodr se puede olvidar de hacer un unlock y liberar el recurso. 
