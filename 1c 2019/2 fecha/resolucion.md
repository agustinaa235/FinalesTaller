1) Declare la clase Número para encapsular una cadena numérica larga. Incluya al menos: Constructor(unsigned long), Constructor default y Constructor 
move; Operador <<, (), =, long y ++(int). Implemente el operador >>.

2) ¿Qué significa que una función es blocante?¿Cómo subsanaría esa limitación en término de mantener el programa ‘vivo’ ?

Cuando una fucnion es bloqueantes signigica que se queda "esperando" a obtener un resultado a obtener un resultado o a que finalice una tarea. Para mantener vivo el programa lo que hace es tener esa funcion en un hilo aparte  de tal forma que ese hilo se quede esperando mientras que otros hilos pueden seguir ejecutandose.

3) Explique qué son los métodos virtuales y para qué sirven. De un breve ejemplo donde su uso sea imprescindible.

Los metodos virtuales son metodos declarados en la clase base y pueden ser re definidos en las clases hijas. La funcion puede estar definida en la clase madre y las clases hijos overrideandolo como tambien cada sub hija puede sobreescribir la funcion. El virtual nos indica si ese metedo va a tener una entrada en la tabla virtual de metodos. Son muy importantes para la programacion oritneta a objetos(poo), sirven para aplicar polimormisfo. Un  ejemplo imprescindible seria cuando queremos modelar una clase figura y de ella queremos que herenden la funcion area en la cual esta debe ser abstracta por si tenes un trianguno y un cuadrado ambas calculan de forma distinta sus area por lo que cada sub hija deberia sobreescribir esa implementacion.

4) Escribir un programa C que procese el archivo “numeros.txt” sobre sí mismo (sin crear archivos intermedios y sin subir el archivo a memoria). 
El procesamiento consiste en leer grupos de 4 caracteres hexadecimales y reemplazarlos por los correspondientes dígitos decimales (que representen el 
mismo número leído pero en decimal).

5) Explique qué se entiende por “compilación condicional”. Ejemplifique mediante código.
Es el proceso por el cual se verifica condicionalemnte si una parte del codigo del archivo funde debe ser compilado o no.
ej:
```
  #ifndef _EJEMPLO_
  #define _EJEMPLO_
  
  
  #endif _EJEMPLO_
 ```
 En este caso si la clase EJEMPLO ya se encuentra definida directamente ejecuta la directiva de endif, sino la define. Una utilidad es evitar la cinlusion multiples del mismo archivo de encabezado. 
 
6) Escriba un programa C que tome 2 cadenas por línea de comandos: A y B; e imprima la cadena A después de haber duplicado todas las ocurrencias de B..
ej.: reemp.exe “Este es el final” final -----> Este es el final final

7) Escriba las siguientes definiciones/declaraciones:
a) Definición de una la función SUMA, que tome dos enteros largos con signo y devuelva su suma. Esta función sólo debe ser visible en el módulo donde se la define.

b) Declaración de un puntero a puntero a entero sin signo.
c) Definición de un caracter solamente visible en el módulo donde se define.
a)
```
static long int suma(long int a, long int b){
      return a + b;
} 
```
b)
```
unsigned int *(*a);
```
c)
```
static char a = ' ';
```
8) ¿Qué valor arroja sizeof(int)? Justifique .
El valor que arroje sizeof(int) depende de la arquitecura y del compilador que se esta utlizando. Si la arquitectia es de 64 bits devuelve 8 bytes pero si la arquitectura es de 32 bits devuelve 4 bytes. 
9) Describa el concepto de loop de eventos (events loop) utilizado en programación orientada a eventos y, en particular, en entornos de interfaz gráfica (GUIs).


10) ¿Qué ventaja ofrece un lock raii frente al tradicional lock/unlock ?
Un lock raii es una lcase que cumple con el patron raii es decir que hace un lock cuando se invoca al constructor de la clase y se hace unlock cuando se invoca al destructor de la clase. Lo que tiene de benificio es que evita que uno se olvide de relizar un unlock cuando termina de usar un recurso y esto es muy peligroso porque puede generarse un dead lock, es decir con un lock raii nos aseguramos que no no quede un hilo bloqueado cosa que podria ocurrir si no se utlizara ya que el programaodr se puede olvidar de hacer un unlock y liberar el recurso. 
