1) Explique qué es y para qué sirve un constructor de copia en C++.
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

2) Escriba una función ISO C llamada Replicar que reciba 1 cadena (S), dos índices (I1 e I2) y una cantidad (Q). La función debe retornar una copia de S 
 salvo los caracteres que se encuentran entre los índices I1 e I2 que serán duplicados Q veces.Ej. replicar(“Hola”, 1, 2, 3) retorna “Hololola”.
 HECHO 
3) Describa con exactitud las siguientes declaraciones/definiciones globales:
  1. void (*F)(int i);
   es una declaracion de una funcion f puntero que tiene como paraemtro un int
  2. static void B(float a, float b){} 
    es una definicion de una funcion que no puede ser llamado en otro modulo ya que es estatica 
  3. int *(*C)[5]; 
    se trata de una declaracion de un array de 5 elementos, en cual contiene punteros a int. 
 4) Escribir un programa ISO C que reciba por argumento el nombre de un archivo de texto y lo procese sobre sí mismo (sin crear archivos 
 intermedios ni subiendo todo su contenido a memoria). El procesamiento consiste en eliminar las líneas de 1 sola palabra.  
 
 RESUELTO INCOMPLETAMENTE
 5) Declare una clase de elección libre. Incluya todos los campos de datos requeridos con su correcta exposición/publicación, y los operadores
  ++, -, ==, >> (carga), << (impresión), constructor move y operador float().
 6) ¿Qué es una macro de C? Describa las buenas prácticas para su definición y ejemplifique.
Una macro es una procion de codigo en la cual esta se traduce en tiempo de preprocesamiento, es decir, en el proprocesamiento se copia y pega el codigo en 
todo lugar a que fue llamado. FALTA BUENAS PRACTICAS.
7) Escriba un programa que reciba por línea de comandos un Puerto y una IP. El programa debe aceptar una única conexión e imprimir en stdout la sumatoria de 
los enteros recibidos en cada paquete. Un paquete está definido como una sucesión de números recibidos como texto, en decimal, separados por comas y 
terminado con un signo igual (ej: “27,12,32=”). Al recibir el texto ‘FIN’ debe finalizar el programa ordenadamente liberando los recursos.
FALTA
8) Describa el proceso de transformación de código fuente a un ejecutable. Precise las etapas, las tareas desarrolladas y los tipos de error generados en cada 
una de ellas.
La primer estaba es la de preprocesamiento en la cual en esta estaba se realiza la expacion de macros y directivas del compliador y saltan todos los 
problemas relacioando con la expancion de la macro. Luego esta la etapa de compilacion en la cual en esta se pasa de codigo de texto a codigo objeto primero se 
pasa a un lenguaje de mas bajo nivel (assembly) y luego lo que se hace es tarducir ese lenguaje a codigo de maquina. Aqui surgen los probelmas de si no hay 
variables declaradas, es decir uso una variable que no esta declarada ni definida, entre otros. Y por ultimo se realiza el proceso de linkeo en la cual 
consiste de combinar distintos modulos ya previemiente compilados en un unico modulo para luego generar el archivo ejecutable.
9) ¿Qué ventaja ofrece un lock raii frente al tradicional lock/unlock ?
Cuando se utiliza un lock raii la ventaja que tiene es que realiza un lock cuando se invoca al constructor y un unlock cuando se invoca al destructor. Como se 
esta aplicnaod raii, el destructor se invoca automaticamente generando que se haga un unlock. Esto genera que no suceda el caso de que te quede un hilo colgado 
por no haber hecho un lock ya sea porque el programador se olvido o por una exception. 
10) ¿Qué significa que una función es blocante?¿Cómo subsanaría esa limitación en términos de mantener el programa ‘vivo’ ?
una funcion es bloqueante cuando se queda en estado "suspendido", es decir, esperando a que la tarea que este realizando termine. Para mantener un programa vivo lo 
que se haria es tener esa funcion bloqueante en un hilo aparte para que siga el flujo del programa. 
No se si esta bien.


