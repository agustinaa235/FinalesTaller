# Ejercicio 1

Por qué las clases que utilizan templates se declaran y definen en los .h?
Los templates son pantillas de clases. Estos son utilizados para poder escribir codigo generico independiente del tipo que se tenga, en algunos gasos hay que tener algunas precausiones. UN ejmplo seria tener una funcion imprimir que imprime valores sin tener que especificar el tipo de dato. Estos son declarados en el codigo fuente ya que el codigo template es porcesado por el compilador y al tener escrito el codigo fuente con templates vamos a tener una sola funcion generia mientras que el complador va a tener varias funciones con los distintos tipos y es por eso que se deja en todo el codgio fuente ya que el tipo de dato a usar lo resuelve el compilador.

# Ejercicio 2

¿Qué es un functor? Ejemplifique.
Un funtor es una clase que actua como si fuese una funcion. Permite definir objetos que pueden ser llamados como fucniones. Para invocar a un functor se tiene la misma
sintaxis que se utilza para una fincion. Para eso, estas clases deben sobrecargar el operador(). La ventaja que posee es que permiten desacoplar el momento de 
pasajes de parametros a una funcion mientras es ejecutada.
ej:
```C++ 
   class Sumador{
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

1. I es un puntero a un vector de tamanio 3 de eleventos del tipo float. Por ser extern I se encuentra declarado en otro modulo por lo que no se le asigna espacio en la memoria
2. C es un vector de tamanio 3 cuyos elementos son punteros a int. Es una variable statica por lo que se encuentra en el data segment y puede ser accedida por el scope donde fue definida.
3. f es una funcion que recibe como parametros un variable a que es un puntero a un float, en la cual no se puede modificar ese valor) y devuelve el tipo short. La 
funcion es statica por lo que se encuentra en el data segmentement y puede ser accedia en todo el archivo que fue declarada.

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

Una varible de clase o atributo estatico es un atributo comun a todas las instancias(objetos) de la clase(es decir su valor es el mismo para todas las instancias). Esta se encuentra en el data segmente. Su valor es inicializado en cero o null en caso de no estar inicializada por el programador. Se puede acceder a el sin tener una clase instanciada.
ej:
```C++
   class Matematica{
         static float pi = 3.14;
   }      
 ```   
# Ejercicio 6

¿Qué significa que una función es blocante?¿Cómo subsanaría esa limitación en término de
mantener el programa ‘vivo’ ?
Un funcion es bloqueante cuando se queda "suspendida" o a la espera de la finalizacion de una tarea para retornar, es decir, no retorna inmediatamente depsues de ser ejecutada. Un ejemplo de funcion bloqueante es accept en sockes en la cual se 
queda a la espera de clientes. En programas chicos puede que no sea un problema pero para programas mucho mas grandes si porque queda en stanby toda la ejecucion 
del resto del porgrama. Por lo que se sueleve hacer es ejecutar esa funcion bloqueante en un hilo aparte para que el resto del programa pueda seguir ejecutandose.
Esto es de vital imprtancia para programas del tipo server/cliente en la cual se tiene un servidor que esta constantemente aceptando muchisimos clientes y no se 
puede quedar a la espera de que llegue un cliente y no porcesar las comunicaciones con los otros clientes, es por eso que la funcion accept es ejecutada en un hilo
aparte asi se puede seguir procesar los mensajesa de los clientes y rendpoder mientras que al mismo tiempo se siguen acceptando nuevos.

# Ejercicio 7

Explique qué es y para qué sirve un constructor MOVE en C++. Indique cómo se comporta el
sistema si éste no es definido por el desarrollador.
El constructor Move, como lo indica su nombre,permite generar un objeto a partir de otro pero este no realiza una copia de los contenidos, sino que lo que hace es "mover" los contendiso. El objetivo de su implemnetacion es evitar tener copias de recursos ya sea porque es innecesario o porque es incorrecto. LO que haces es mver los atributos de objeto "viejo" al nuevo para luego invalidar los de viejo( en caso de un puntero que apunte a null), es decir, el objeto pasado deja de apuntar a sus recursos y por lo tando deja de ser el duenio y el nuevo duenio pasa a ser el objeto creado. LO que hace es cambiar el ownership. Si el constructor no esta implemnetado por el desarrollador se crea uno por default si no se tiene implementado un constrcutor por copia o operador pro copia o destrcuctres y sino se le indcico con delate (en c++ 11)
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
