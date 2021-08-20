# Ejercicio 1
Explique qué es y para qué sirve un constructor de copia en C++.
a) Indique cómo se comporta el sistema si éste no es definido por el desarrollador;
b) Explique al menos una estrategia para evitar que una clase particular sea copiable;
c) Indique qué diferencia existe entre un constructor de copia y uno move.

El cosntructor por copia es un tipo de constructor que tiene como parametro de entrada una referencia a otro objeto de la misma clase por lo que se estara creando
un objeto inicializandolo con los valores del objeto que es pasado por refrencia, generando asi una copia.
a) El constructor por copia esta definido por default, es decir, si el programador no lo define el compilador define uno por default. 
b) Una forma de evitar que una clase sea copiable lo que se hace es ponerle delete al lado de la declaracion del constructor por copia y en ese caso cuando se 
cree un nuevo objeto no se podra llamar al constructor por copia. ej: foo(const &foo) delete;
c) La diferencia es que el constructor por copia lo que haces es devolver una copia de la instacia de la clase que recibio por parametro, copia atributo por atributo
mientras que por movimiento lo que hace es mover los punteros/ referencias que se encuentran dentro de la instancia recibida por parametro y esta instancia deja de 
apuntar a esas referencias. 

# Ejercicio 2
Escriba una función ISO C llamada Replicar que reciba 1 cadena (S), dos índices (I1 e I2) y una cantidad (Q). La función debe retornar una copia de S 
 salvo los caracteres que se encuentran entre los índices I1 e I2 que serán duplicados Q veces.Ej. replicar(“Hola”, 1, 2, 3) retorna “Hololola”.
 HECHO 
# Ejercicio 3
Describa con exactitud las siguientes declaraciones/definiciones globales:
  1. void (*F)(int i);
    f es un puntero a una funcion que recibe como parametro el tipo int y devuelve void. 
  2. static void B(float a, float b){} 
    b es una definicion de una funcion que solo puede ser accedida en ese modulo.
  3. int *(*C)[5]; 
    se trata de una declaracion de un array de 5 elementos, en cual contiene punteros a int. 
# Ejercicio 4
Escribir un programa ISO C que reciba por argumento el nombre de un archivo de texto y lo procese sobre sí mismo (sin crear archivos 
 intermedios ni subiendo todo su contenido a memoria). El procesamiento consiste en eliminar las líneas de 1 sola palabra.  
 
 RESUELTO I
 # Ejercicio 5
 Declare una clase de elección libre. Incluya todos los campos de datos requeridos con su correcta exposición/publicación, y los operadores
  ++, -, ==, >> (carga), << (impresión), constructor move y operador float().
 ```C++
 
  clas Numero{
    private:
      std::string valor;
    public:
      Numero& operator++(); // pre incremento
      Numeroo& operator--() // pre descrecimiento
      Numero& operator++(int) post incremento
      Numero& operator--(int) post incremento
      std::istream& operator>>(std::istream& in, Numero& otroNumero);
      std::ostream& operator<<(std::ostream& out, Numero& otroNumero);
      Numero& operador-(Numero& otroNumero);
      Numero& (Numero&& otroNumero); // constructor move
      operator float() const;
```      
      
# Ejercicio 6
¿Qué es una macro de C? Describa las buenas prácticas para su definición y ejemplifique.

Una macro es una instruccion que se realiza en forma de directiva del precompiadlor del compilador c, en la cual tiene como objetivo exapandir todas las apariciones del simbolo aosicado a la macro de forma literal. Estas pueden estar definidas en funcion de variables y como las macros son expandidas de forma literal es importante que las variables se encuentren encerradas dentro de parentesis para asi se evitan errores. Otra buena practica es utilizar nombres descriptivos.
Ej:
``` #define DOBLE(A) 2*(A)```

# Ejercicio 7

Escriba un programa que reciba por línea de comandos un Puerto y una IP. El programa debe aceptar una única conexión e imprimir en stdout la sumatoria de 
los enteros recibidos en cada paquete. Un paquete está definido como una sucesión de números recibidos como texto, en decimal, separados por comas y 
terminado con un signo igual (ej: “27,12,32=”). Al recibir el texto ‘FIN’ debe finalizar el programa ordenadamente liberando los recursos.
FALTA
# Ejercicio 8

Describa el proceso de transformación de código fuente a un ejecutable. Precise las etapas, las tareas desarrolladas y los tipos de error generados en cada 
una de ellas.
La primer etapa es la de preprocesamiento en la cual se realizna la expancion de la macros y directivas del compilador( se inclitesn los archivos .h que se hayan utilizado por medio de la directiva #include). Aca es donde saltan los erroe relacionado con la expancion de la macro y si los includes.
DEspues esta la etapa de compilacion donde se pasa de codigo fuente a codigo objeto. Se realiza un analisis sintactico donde se parcea, se verifica la sintaxis se realiza la traduccion y se ensabla el codgio. En esta etapa surgen los errores como  de sintaxis, cuando no hay una variable declarada, es decir se utiliza una vriable que no fue declarada ect o cuando se usa una funcion no declarada
Por ultimo esta la etapa de linkeo en donde se juntan los distintos modulos en uno solo y aca es donde se genera el archivo ejecutable. Se resuelven referdnicas externas problemas como falta de definiciones (no esta definida una funcion que fue declarada) no se pudo resolver esa referencia externa 

# Ejercicio 9
¿Qué ventaja ofrece un lock raii frente al tradicional lock/unlock ?
Un lock raii es un lock que sigue con el patron raii, es decir, en el constructor se realiza un lock del mutex y cuando se invoca al destructor se realiza un unlock. Esto permite evitar problemas de olvidos de programador de no liberar al mutex cuando termina de utilizar el recurso y tener un codgio mas robuzto.

# Ejercicio 10
¿Qué significa que una función es blocante?¿Cómo subsanaría esa limitación en términos de mantener el programa ‘vivo’ ?

Una funcion es bloqueante cuando no retorna inmediatamente, es decir, se queda a la espera de algun evento o hasta finalizar la tarea. Un ejemplo de funcion bloqueante es la funcion accept de sockets en la cual se queda bloqueada hasta que le llega un cliente para aceptar. Esto es un problema para programas de server/clientes ya que no solo se quiere aceptar clientes sino que tambien procesar sus mensajes (recibir y mandar mensajes) por lo que para mantener el porgrama vivo se tiene la funcion bloqueante en un hilo aparte asi ese hilo se queda a la espera de algun evento y l programa puede seguir ejecutandose en otro hilos. 


