# Ejercicio 1

Por qué las clases que utilizan templates se declaran y definen en los .h?
Los templates son pantillas de clases. Estos son utilizados para poder escribir codigo generico independiente del tipo que se tenga, en algunos gasos hay que tener algunas precausiones. UN ejmplo seria tener una funcion imprimir que imprime valores sin tener que especificar el tipo de dato. Estos son declarados en el codigo fuente ya que el codigo template es porcesado por el compilador y al tener escrito el codigo fuente con templates vamos a tener una sola funcion generia mientras que el complador va a tener varias funciones con los distintos tipos y es por eso que se deja en todo el codgio fuente ya que el tipo de dato a usar lo resuelve el compilador.

# Ejercicio 2

¿Qué es un functor? Ejemplifique.
Un funtor es una clase que actua como si fuese una funcion. Permite definir objetos que pueden ser llamados como fucniones. Para invocar a un functor se tiene la misma
sintaxis que se utilza para una fincion. Para eso, estas clases deben sobrecargar el operador(). La ventaja que posee es que permiten desacoplar el momento de 
pasajes de parametros a una funcion mientras es ejecutada.
ej:
``` class Sumador{
   priavte:
       int valorInicial;
   public:
       Sumador(int valor): valorInicial(valor){}
       ~Sumador();
       int operador()(int otroValor){
          return (otroValor + valorInicial);
       }
}
```

# Ejercicio 3

Describa con exactitud las siguientes declaraciones/definiciones globales:
  * extern float (*I)[3];
  * static int *C[3];
  * static short F(const float *a);

a) I es un puntero a un vector de tamanio 3 de eleventos del tipo float. Por ser extern I se encuentra en otro modulo por lo que no se encuentra en memoria del modulo.
b) C es un vector de tamanio 3 cuyos elementos son punteros a int. Es una variable statica por lo que se encuentra en el data segment y puede ser accedida por todo el modulo que se encuentra. 
c) f es una funcion que recibe como parametros un variable a que es un puntero a un float, en la cual no se puede modificar ese valor) y devuelve el tipo short. La 
funcion es statica por lo que se encuentra en el data segmente. 

# Ejercicio 4

¿Qué es un Deadlock? Ejemplifique.
un Deadlock es una situacion en la cual se tiene bloqueado una serie de procesos/hilos porque cada hilo esta agarrada a un recurso y esta esperando a acceder a otro 
recurso que es poseeido por otro hilo.Por ejmplo hilo 1 posee un recurso 1 y esta esperando a poder acceder un recurso2 mientras que hilo2 posee recurso 2 y esta
esperando a poder adquirir recurso 1. Esto ocurre cuando se tiene mas de un lock que pueden ser adquiridos al mismo tiempo. La soluciones son: tener la mneor cantidad
de locks posibles.

# Ejercicio 5

Explique qué es y para qué sirve una variable de clase (o atributo estático) en C++. Mediante un
ejemplo de uso, indique cómo se define dicha variable, su inicialización y el acceso a su valor para
realizar una impresión simple dentro de un main.
Una variable de clase o atributo estatico es un componente de la clase que es compartida por todas las instancias(objetos) de la clase. Esa es inicialziada por el programador o en cero en caso de no estra inicializada y su valor es el mismo para todas las instancias y no puede ser modificado. La ventaja que brinda es que 
puedo acceder a ese valor sin tener que tener instanciada uan clase. (ej: Matematica.pi 

# Ejercicio 6

¿Qué significa que una función es blocante?¿Cómo subsanaría esa limitación en término de
mantener el programa ‘vivo’ ?
Un funcion es bloqueante cuando se queda "suspendida" o a la espera de la finalizacion de una tarea. Un ejemplo de funcion bloqueante es accept en sockes en la cual se 
queda a la espera de clientes. En programas chicos puede que no sea un problema pero para programas mucho mas grandes si porque queda en stanby toda la ejecucion 
del resto del porgrama. Por lo que se sueleve hacer es ejecutar esa funcion bloqueante en un hilo aparte para que el resto del programa pueda seguir ejecutandose.
Esto es de vital imprtancia para programas del tipo server/cliente en la cual se tiene un servidor que esta constantemente aceptando muchisimos clientes y no se 
puede quedar a la espera de que llegue un cliente y no porcesar las comunicaciones con los otros clientes, es por eso que la funcion accept es ejecutada en un hilo
aparte asi se puede seguir procesar los mensajesa de los clientes y rendpoder mientras que al mismo tiempo se siguen acceptando nuevos.

# Ejercicio 7

Explique qué es y para qué sirve un constructor MOVE en C++. Indique cómo se comporta el
sistema si éste no es definido por el desarrollador.
El constructor por movimiento evita que se genere una copia de la instacia pasada y lo que haces es mover las referencias. Lo que hace es cambiar el ownershipt, 
instacia pasada por referencia es modificada y deja de apuntar los paraemtros y el objeto creado pasa a puntar a ellas. Si el construtor por moviento no esta definido
por el programador y el cmpilador crea uno por default solo si no se encuentra definido el por copia.  

# Ejercicio 8

Escribir un programa ISO C que procese el archivo “valuesword.dat” sobre sí mismo,
eliminando los words (2 bytes) múltiplos de 16.

# Ejercicio 9

Implemente la función void ValorHex(char *hex, int *ent) que interprete la cadena hex (de
símbolos hexadecimales) y guarde el valor correspondiente en el entero indicado por ent.

# Ejercicio 10

Implemente una función C++ denominada Interseccion que reciba dos listas de elementos y
devuelva una nueva lista con los elementos que se encuentran en ambas listas:
 std::list<T> Interseccion(std::list<T> a,std::list<T> b);
