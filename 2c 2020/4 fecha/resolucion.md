# Ejercicio 1
¿Qué diferencia existe entre un constructor por copia y uno por movimiento? Ejemplifique.

Un constructor por copia para crear un objeto, hace una copia de bit a bit del objeto pasado por parametro, es decir, vamos a tener dos "duenios" ya que ambos objetos apuntan a lo mismo mientras que un constrcutor por movimiento se modifica el ownershit. El objeto creado va a puntar a los atributos del objeto recibido y este ultimo deja de apuntar a ellos y pasa a puntar a null. La gran difreneica es que en rl pirmer caso no se puede modificar el objeto recibido mientras que en el segundo si ya que justamente se cambia el ownershit.

# Ejercicio 2
Escriba una rutina que dibuje un rombo azul del tamaño de la pantalla.

# Ejercicio 3
Escribir un programa ISO C MULTIPLATAFORMA que procese el archivo “bigEndian.dat” sobre sí mismo, leyendo nros. de 4 bytes Big-Endian y triplicando los impares.

# Ejercicio 4
Qué es un Deadlock? Ejemplifique.

Un deadlock es cuando se estan utilizando threads, es el bloque permanente de un conjunto de procesos y sucede cuando  se tiene un recurso compartido donde este posee un mutex para proteger al recurso en donde en el recurso compratido se hace un lock al mutex para que el hilo que lo agarro lo pueda usar sin problema y que otros hilos no puedan acceder al recurso mientras este lo tenga pero el programador se olvido de liberar el recurso, es decir, hacer un unlock al mutex entonces ningun otro hilo puede acceder al recurso y es ahi donde ocurre un deadlock. Si se utilizara un lock raii, una clase que cumple con el patron raii, este problema se evitaria ya que el unlock se hace dentro del destructor por lo que cuando el hilo termine de usar el recurso es inmediato el unlock y no se tendria ese problema.

# Ejercicio 5
Escriba un programa que reciba por línea de comandos un Puerto y una IP. El programa debe conectarse y quedar en escucha de paquetes con la forma 
“d..d+d..d+...=”. El programa debe imprimir en stdout cada suma hasta que la misma sea 0 (cero). En ese caso debe finalizar ordenadamente.

# Ejercicio 6
Describa con exactitud las siguientes declaraciones/definiciones globales: 
  *  `char *(*A)();:` 
  *  `static int *(*C)[5];
  *  ` short *B(){return NULL;}`
* A es una declaracion de un puntero a una funcion que no recibe parametros y devuelve un char puntero.
* C es una definicion de un puntero a un vector de punteros a int de tamanio 5, se trata de una variable static por lo que esta se encuentra en el datasegment y es inicializada en cero cuando arracanca el programa. 
* B es una definicion de una funcion que no recibe parametros y devuelve el tipo short puntero, en ese caso, devuelve siempre NULL. 
# Ejercicio 7
Declare una clase a elección considerando: - Atributos que son necesarios - Accesibilidad a la Clase - Incluir los operadores -, 
++ (post-incremento), --(pre-incremento), >> (impresión), << (carga desde consola), float
```C++
   class Numero{
        private:
             int valor;
        public:
           Numero(int& unValor);
           Numero(const Numero& unNumero);
           Numero operador-(Numero& unNumero);
           Numero operador++();
           Numero operador--();
           std::istream& operador>> (std::istream& in, Numero& unNumero);
           std::ostream& operador<< (std::ostream& in, Numero& unNumero);
           void operador float();
   }
```

# Ejercicio 8
 Implemente una función C++ denominada SoloMuliplos que reciba una lista de elementos numéricos y un elemnto numérico x. La función debe devolver una nueva 
 lista con los elementos de la primera que sean múltiplos de x:
 
 ` std::list<T> SoloMultiplos(std::list<T> a,T x);`
 
# Ejercicio 9 
  ¿Se puede evitar que un objeto de una clase sea copiado?¿y clonado?. En caso afirmativo explique cómo puede hacerse. En caso negativo explique por qué no 
  se puede.
  Si para eso hay que eliminar explicitamente o no permitir que se pueda usar el constructor por copia o el operador = por copia. Lo que se hace es:
  ``` Numero(const Numero& numero) = delate;
  ``` Numero& operador=(const Numero& numero) = delate;
  ```
  
# Ejercicio 10 
 ¿Qué es un thread?¿Qué recursos comparte con otros threads del mismo proceso?¿Cuales son exclusivos (no compartidos)?
Un therad es la ejecucion de una funcion/bloque de codigo, esta se ejeucta por medio de std::thread en c++11. Cuando se tiene multiples hilos es porque se estan ejecutando en simimultaneo multiples funciones. Los recursos que comparten son el data segmnet, el code segmenet y el heap mientras que los que son exclusivos, es decir, propios de cada thread son el stack y los registros.
