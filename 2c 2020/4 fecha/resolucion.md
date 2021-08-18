# Ejercicio 1
¿Qué diferencia existe entre un constructor por copia y uno por movimiento? Ejemplifique.

Un constructor por copia para crear un objeto, hace una copia de bit a bit del objeto pasado por parametro, es decir, vamos a tener dos "duenios" ya que ambos objetos apuntan a lo mismo mientras que un constrcutor por movimiento se modifica el ownershit. El objeto creado va a puntar a los atributos del objeto recibido y este ultimo deja de apuntar a ellos y pasa a puntar a null. La gran difreneica es que en rl pirmer caso no se puede modificar el objeto recibido mientras que en el segundo si ya que justamente se cambia el ownershit.

# Ejercicio 2
Escriba una rutina que dibuje un rombo azul del tamaño de la pantalla.

# Ejercicio 3
Escribir un programa ISO C MULTIPLATAFORMA que procese el archivo “bigEndian.dat” sobre sí mismo, leyendo nros. de 4 bytes Big-Endian y triplicando los impares.

# Ejercicio 4
Qué es un Deadlock? Ejemplifique.
Un deadlock es cuando se tienen bloqueados multiples hilos. Un ejemplo muy claro de esto es cuando el hilo 1 toma al recurso A, el hilo 2 Toma al recuros B porque no llego a tomar el A, el hilo 1 termina y esta a la espera de liberen el recurso b para libersr el recurso A y el hilo 2 esta haciendo lo mismo Esta esperando que se libere el recurso A para liberar el B. De esta manera ambos hilos estan bloqueandose mutuamente.
ej:
```
std::mutex m
void funcion(){
     m.lock() // se bloquea a la espera de ser liberado el mutex tomado por el hilo priniciapl
     m.unlock() // nunca se logra liberarlo porque se bloqueo a la espera de que sea liberado el mutex del hilo principal.
}
int main(){
    m.lock() // se bloquea el recurso 
    std::thread hilo(funcion); // se lanza la funcion en el hilo
    hilo.join() // el hilo se queda bloqueado hasta que finalice su ejecucion 
    m.unlock() // si el hilo nunca se desbloquea no se puede liberar el recurso.
    return 0;
}    
```
En este ejemplo en el hilo principial se toma el mutex, luego se lanza una funcion en un hilo donde en ella se bloquea a la espera de que se libere el mutex del hilo principial pero este no se liberanunca ya que luego de lanzar el hilo se hace un join en la cual se bloquea hasta que finalice de ejecutarse el hilo pero el hilo ninca finaliza porque no se desbloqueo el mutex por l que nunca ejecuta el unlock y nunca se libera elmutex del hilo principial porque la liberacion se hace luego del join del hilo lo cual nunca va a suceder.

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
