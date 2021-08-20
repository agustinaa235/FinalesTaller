# Preguntas teoricas 

## Indique 2 posibles usos del modificador const. Utilice en cada caso una breve sentencia de código que lo emplee junto con la explicación del 
## significado/consecuencia de su uso.

Un uso es para las variables. Este se usa para decir que la variable es inmutable. Ej: const int a = 1 a no va a poder ser modificada 
otro uso es utilizar con en los metodos. Esto indica que no se va a poder modificar los atributos de la clase, es decir, no se puede modificar al objeto 
ej:
```C++
class Palabra{
      private: 
        std::string nombre;
      public:
        std::string getNombre() const{
            return nombre;
      }
}
```
## Explique el concepto de Mutex. Escriba un ejemplo simple de código donde su uso resulte fundamental para garantizar el correcto empleo de recursos en un contexto concurrente. Describa los métodos disponibles y su uso.

El mutx en un objeto  en la cual este posee dos estado bloqueado y liberado. Es utilizado en programas de sincronizacion de hilos o en porblemas de concurrencia
donde se tiene uno mas recursos compartidos y se lo quiere proteger para evitar problemas como race condition entre otros.
Para eso el mutex posee dos funciones lock y unlock. Cuando un hilo toma un recurso dentro del recurso se debe hace mutex.lock() esto lo que hace es bloquear al mutex
y no permitir que otro hilo pueda acceder a ese recurso hasta que este sea liberado. Y la segunda funcion es justamente para liberar al recurso, al mutex, y asi otro
hilo puede acceder a el, cambia al estado liberado. 

## Explique el concepto de referencia en C++. que diferencias hay con respecto a los punteros?

Una referencia en c++ es un tipo de dato que sirve como alias de otra varable mientras que un puntero es simplemente una direccion de memoria, es decir, almacena
direcciones de memoria. Otra diferencia es que una refrencia en c++ es inmutable, puede apuntar a un objeto en toda su vida mientras que los punteros pueden 
ir apuntado a distinas direciones de memoria.

## Explique los distintos tipos de herencia en c++

La herencia sirve para crear nuevas clase a partir de una clase base. Siempre deben cumplir con el es un. Esto implica que la subclase va a "heredar" todo el compratimiento y los atributos de la clase madre. Sirve para poder lograr un mejor encapsulamiento y abstraccion como tambien evitar tener codigo repetido.
hay 3 tipos de herencia :

* publica: los atributos/metodos publicos y protected se mantiene con la misma visibilidad que la de su clase base.
* protected: los atributos/metodos publicos y protected de la clase base pasan a ser protected en la clase hijas. Entonces el unico que sabe que herendan de la clase base es el hijo y las clases que hereden de el.
* private: los atributos/metodos publicos y protected de la clase base pasan a ser privados en la clase hija. Entonces el unico que sabe que heredan de la clase base es la clase hija. La clases que herendan de la clase hija no poseen los atributos ni los metodos de la clase padre.

## Explique el concepto de object slicin (objeto recortado). Escriba un breve ejemplo sobre como esto afecta una función que pretende aplicar polimorfismo sobre uno de sus parámetros.

El objet slicn es cuando se le asigna un objeto perteneciente a una clase derivada una instancia de su clase base. Lo que genera es que se pierda parte de su 
informacion ( de ahi sale el nombre objeto recortado). Lo que se pierden son los atributrso extras que posee la clase derivada. 

## Describa el concepto de templates en C++. De un breve ejemplo de una función template.

un template son plantillas de clases. Sirven para poder generar codigo/ funciones de forma generica y que no se tenga que estar escribiendo la misma porcion de 
codigo para cada tipo de dato. Es utilizado en casos donde la funcion o el codigo varian en el tipo de dato que se este usando por ejemplo si s quiere hacer una 
funcion que recorra una lista e imprima el contedido
ej:
```C++
  void imprimir(std::list<T> lista){
      for (T& elem: lista){
          std::cout << elem << std::endl;
      }
  }
```
## ¿Describa brevemente el contenedor map de la librería estándar de C++? Ejemplifique su uso.
la clase map de la libreria estandar de c++ es un diccionareo ordenado. Este funciona con templates para poder tener cualquier tipo como clave y cualquier tipo de
dato como valor. Tiene distintas funciones como insertar o tamanio como tambien su iterador.
```C++
int main(){
    std::map<int, char> mapa;
  mapa.insert({1,h}};
   std::cout << mapa['1'] << std::endl;
 }
```
## Que es un método estático (o de clase) en c++? Muestre su manera de empleo mediante un breve ejemplo.

ej:
```C++
      class Foo{
            public:
            static void b();
      }
      int main(){
            Foo::b();
            // tambien es valod 
            Foo x;
            x.b();
       }
```
## Explique que son los metodos virtuales y ejemplifique.

La palabra virtual antepuesta a un método indica que debe tener una entrada en la tabla virtual (vtable) para cada objeto en la cual los nos indica es que ese metodo  se resuelve en tiempo de ejecucion( lo que se conoce como dynamic binding). Esto permite utilizar polimorfismo basado en herencia donde los métodos de las clases derivadas reemplazan a los de la clase base independientemente de cómo se lo acceda (desde un puntero a la base o al tipo derivado).
Los metodos virtuales son declaros en la clase madre y pueden ser refedinidos o no en las clases hijas. Si es virutal puro las clase hijas deben implementar ese metodo mientras que si no es virtual puro no es necesario que lo redefinan.

## Explique cómo se comporta el modificador virtual en C++ y qué relación guarda con las VTables (tablas virtuales). De un breve ejemplo donde su uso sea imprescindible.

El modificado virtual es usado prinipalmente para aplicar el concepto de herencia. Uno de sus propocitos es que sea virtual puro y que las clases deribadas esten 
obligadas a implemnetar la funcion de la clase base. Es muy util para aplicar polimorfismo. Y otro propocito es para evitar tener herencias multiples.
Al tener un metodo como virtual lo que haces es crear una entrada en la Vtable(tabla virtual) de ese metodo en la cual lo que indcara que es emetodo se tiene que 
resolver en tiempo de ejecucion. 
ej:
```C++
class Figura{
            public: 
                  virtual calcularArea() = 0;
     }
     Class Cuadrado: public Figura{
            protected:
                  int base;
                  int altura;
            public:
                  calcularArea(){
                        return base*Altura;
                   } 
```

## Explique el uso de valores por defecto en templates de C++. Escriba un ejemplo.

los templates tiene valores por defecto en la cual son utilizados en caso de que no se defina ningun tipo de dato
ej:
```C++
template<class T = int>
T max(Tx, Ty){
      return (x>y?x:y);
}
```
## Explique qué es y para qué sirve un constructor de copia en C++, Indique cómo se comporta el sistema si éste no es definido por el desarrollador.

Un contructor por copia es un tipo de constructor que devuelve una copia de la instacia pasada por parametros. Este lo que haces una copia de bit a bit del objeto
pasado para crear otro. En el caso que este no este definido por el programador, el compilador crea uno por defecto al menos que el desarolladorador decia borrarlo, es decir, no permite la utilizacion de este. Son basicamante usados cuando una rugumento se pasa por valor y lo que se haces es instanciar a un objeto en base del otro. 
Su uso es importante ya que sino se define, el compliador creara uno por defecto y esto podria llegar a traer probelmas porque justamente lo que haces es inovcar al constructor por copia de todos los miembros del objeto. UN porblema puede ser cuando hay recursos compartidos.
ej:
```C++
      class Numero{
            priavte:
                  int valor;
            Numero(const Numero& otroNumero){
                  this->valor = otroNumero.valor;
                  }
```
## Describa el concepto de loop de eventos (event loop) utilizado en programación orientada a eventos, y en particular, en entornos de interfaz gráfica (GUIs)
El loop de eventos es un patron muy uilizado en aplicaciones con interaccion de usuarios de forma graficas ya que un evento pododria ser hacer un click como pultasr una tecla. El loop de ventos conta en ir porcesando los evntos de la cola de eventos. El patron consta de un while donde se van sacando eventos y asignarse a cada evento su correspodiente handler o manejador de evento, si el evento es salir en ese caso se corta el loop. 
psudo codigo:
      while (!termine){
            evento = sacarEventoDeLaCola
            if (evento == salir){
                  termine = true;
            } else {
                  manejarEvento(evento);
             }     
      }  
## Explique que es y para que sirve una variable de clase (atributo estático) en c++. Mediante un ejemplo, indique como se define dicha variable, su incializacion, y el accesos a su valor para realizar una impresión simple en el main.

la variable de clase o atributo de clase es una variable que es comun a todas las instancias de la clase. SE declara como un atributo normal pero con la palabra reservada static previa. Esta puede estar inicializa por el programador como no. SE puede acceder a ella sin la necesidad de tener una instancia una clase( se puede acceder utilizanod MyClass::varibleEstatica) como tambien se puede acceder por medio de un objeto. Puede ser accedida por todo el programa.
ej:

```C++
      class Foo{
            public:
            static int a; //declaricion
      }
      Foo::a = 2;
      if (Foo::a >= 1){
       
       }
```

## ¿Qué significa que una función es bloqueante? ¿Cómo subsanaría esa limitación en términos de mantener el programa ‘vivo’?

una funcion es blqueante cuando se queda "suspendia", es decir, cuando se queda a la espera de que termine una tarea y no retorna de forma inmediada. Un ejemplo de funcion bloqueantes es la de accept de sockets esta se queda bloqueando esperando a que le llegue nuevas conexciones. Como se queda bloqueada, no es conviniente tenerla en el hilo prinicpail del programa porque ese no se mantedria vivo, es por eso, que se suelen ejecutar en un hilo aparte asi ese hilo se queda bloqueado y el resto del porgrama puede seguir ejecurse.

## Explique qué son los métodos virtuales y para qué sirven. De un breve ejemplo donde su uso sea imprescindible.

Los metodos virtuales son metodos se que declaran en la clase base y estos pueden o so definirse en la clase hija. Son muy utilizada en herencia que es uno de los pilares de la programacion orientada a objetos. Los metodos virtuales pueden ser puros es decir que las clases hijas si o si deben redefinir las clases derivadas o tambien pueden ser virtuales y estar implementadas en la clase madre y que las clases hijas simplemente la overriden. La palabra virtual inidca que ese metodo va a tner una entrada en la tabla virtual lo que nos estaria indicando que ese metodo se resuelve en tiempo de ejecucion. 

## ¿Qué función utiliza para esperar la terminación de un thread? Ejemplifique mediante código.
Para esperar a que un hilo finalice se utiliza la funcion join() que espera a que el hilo lanzado termine la ejecucuion para luego unirlo al hilo que lo llamo.
ej:
```C++
   void foo(int i){
      std::cout << i << std::endl;
   }   
int main(){
      std::thread hilo1(foo,std::ref(1));
      hilo1.join();
      return 0;
}
``` 
## ¿Qué es el polimorfismo? Ejemplifique mediante código
Es la capacidad de que un mismo metodo sea interpretado de distintas maneras segun la clase que lo implemnete. Es muy utilizado cuando se tiene herencia, donde sie tiene una clase base y las clases hijas que redefinen el metodo de la clase madre. Un gran ejemplo es el de las figuras donde se tine la clase base que es figura y el metodo calcularArea() y luego tenemos cada clase hija como triangulo o cuadrado que redefinen el metodo calcularArea segun le corresponda a cada una.

## Describa el proceso de transformación de código fuente a un ejecutable. Precise las etapas, las tareas desarrolladas y los tipos de error generados en cada una de ellas.
El proceso consta de tres estapas:
      * preprocesamiento: Es donde realiza la expancion de las macros y las directivas del precompialdor. Los errores que surgen son por ejmplo macros no definidas,                            dependencias circulares, ect.
      * compilacion: Se realiza un analisis sintatico, donde se parcea se verifica la sintaxis se realiza la traducccion y se ensabla el codigo. SE hace el pasaje 
                     de codigo fuente a codigo obejto. Los errores que pueden surgir por ejemplo son: errores de sintaxis, la utilizacion de variable no declaradas,                      ect.
      * linkeo: En esta ultima etapa se juntan todos los distintos modulos o arhcivos objetos en un unico modulo y genera el archivo ejecutable. SE resuelven los                   problemas como falta de definiicones, o  definiciones multiples de funciones, ect.
## ¿Que función se utiliza para lanzar un thread? Ejemplifique mediante código

un thread es la ejecucion de una funcion o bloque de codigo. En c++ 11 para poder lanzar un hilo se hace por medio del constructor std::thread() donde este recive la funcion a ser ejecutada en el hilo y los parametros que recibe la funcion

## Explique qué usos tiene la palabra reservada static en C++. De un breve ejemplo de uno de ellos.
* funciones static: indica que esa funcion solo puede ser accedida solo en ese mismo archivo
* variable static: ambas reciden en el data segmenten.
      * globales: Solo puede ser accedida desde el archivo que fue definida. Si no fue inicializada por el porgrador esta es inicializa en cero o null. Su lifetime                   es de todo el programa 
      * locales: solo puede ser accedida desde la funcion en la cual fue definida. Si no fue inicializa por el programador esta es inicializa en cero o null. Una                   vez inicializa conserva su valor entre distintos llamados de funciones.
* atributo de clase static: recide en el data segmente y es unico por clase. Si no es inicializada por el porgramador se la inicializa en cero o null. 
* metodo de clase static: Es independiente de las distintas instancia y solo puede acceder a miembros static de una misma clase.

## directivas #define, #include, #ifndef. #ifdef

La directiva #define le asigna un nombre identificable por el preporcesador a un fracmento de codigo en la cual este luego podria ser copiado y pegado en caso de que aparezca en el codigo.
```C++
#define MAX 100

int main(){
      int valor = MAX;
}
```
lo que hace en ese caso es copiar literalmente el valor de la macro al ser encontrado su simbolo.

la directiva #include lo que haces es copiar las declaraciones que se encuentra en el archivo de la directiva en el archivo que se este incluyendo. Esto sirve para cuando se tienen funciones o variables declaras en otro archivo y se quieren utilizarlas asi no se tienen que implementar.
ej:
```C++
# include "misFunciones.h"

int main(){
      // puedo invocar a todas las funciones que se encuentren en el archivo de misFunciones.h
}
```

la directiv #ifndef chequea o verifica si el identificador asociado esta definido, si no lo esta la condiciones verdadera, mientras que la directiva #ifdef es de forma contraria tambien chequea o verifica si el identidicador asociaod esta declarado pero esta condicon es verdadero esi esta definida. 

## Que es la compilación condicional? En que etapa del proceso de transformación de código se resuelve? Ejemplifique mediante un código C dando un caso de uso util.

La compialcion condiciones verifica condicionalmente si una parte del codigo esta definida o no. Esta es resuelta en la estapa de preprocesamiendo ( ya que en esta estapa se resuelven las directivas del precompialdor). 
ej:
```C++
#ifndef _CLASS_
#define _CLASS_
...
...
#endif _CLASS_
```
Si class esta definida entonces salta a la directiva #endif y no la define, sino la define. 

## Cual es el motivo por el cual las clases que utilizan templates se declaran y definen en los .h?
los templates son plantillas de clases y son utilizados para escribir codigo generico para asi no se tenga que tener codigo repertido ya que la variacion del codigo solo depende del tipo de dato que se esta utilizando. Los templates son pblciados por todo el codigo fuente ya que este codigo template es porcesado por el compialdor y se depende del tipo de dato que se este utilizando. Es por eso que se le deja al compilador que deduzca que tipo esta usando y que dicho codigo sea compilado al momento de deducirse el tipo. Los templaes son utilies porque se tiene una unica funcion en el codigo fuente y el compilador tiene multiples funcion de la misma con distintos tipos. 

## Que es un deadlock? Ejemplifique.

un deadlock es cuando un conjuntos de hilos ejecutandose estan bloqueados permanentemente. Esto suele ocurrir cuando se tienen dos hilos y dos recursos. El hilo1 toma el recurso A y lo bloquea y se queda a la espera de que el otro recurso sea liberado para liberara a A, mientrs que el hilo 2 toma el recurso B y se queda a la espera de que el recurso A sea liberado para liberar B por lo que los dos hilos se estan auto bloqueando. Esto genera un deadlock.
otro ejemplo en codigo:
```C++
      std::mutex m;
      void foo(){
            m.lock() // esta funcion se bloquea esperando a que el mutex del hilo priciapl se libere.
            m.unlock();
      }      
      int main(){
            m.lock() // el hilo principal toma al mutex;
            std::thread hilo1(foo);
            hilo.join() // se bloquea hasta que la funcion haya sido ejeuctada pero nunca se va a terminar de ejectar ya que no se libero el mutex
            m.unlock() // nunca se desbloquea porque hasta que la funcion no termine el hilo se queda bloqueado por lo que nunca se ejeucta el unlock pero la                               // funcion foo se queda bloqueada hasta que se desbloque el mutez del hilo principial pero eso nunca sucede. -> deadlock
```

## Que es un thread? Que funciones se utilizan para manipularlos (lanzarlos, etc)?.

UN theread es la ejecuion de una funcion/ bloque de codigo. Cuando se tienen multiples hilos se tienen a multiples funciones corriendo en simultaneo. Estas tiene su propio stack y propio registros y lo que comparten todos los hilos de un programa es el data segmente, code segmenten y el heap.
Las funciones que se utilizan para ejecutarlos son la de lanzamiento que espor medio del constructtor std::thread(fun, arg) y para terminarlo que es por medio de join() que espera a que el hilo termine para luego unirlo al hilo que lo llamo.

## Que es una macro en C?
Una macro es una instruccion que se realiza en forma de directiva del precompilador del compialdor d c, con el objetivo de expandir todas las apariciones del simbolo asociado a la macro de forma literal. Etsas pueden estar en funcion de variables, y como las macros se expanden de forma literal es importante que las variables esten entre parentesis para evitar errores. Tambien es una buena practica asignarle un nombre descriptivo
ej:
```C++
`/MAL EJEMLO DE MACRO 
#define CUBO(A) A*A*A

// BUEN EJEMPLO DE MACRO
#define CUBO(A) ((A)*(A)*(A))

```
si se invoca a la primer macro el el valor de A = 2+ 1 la multiplcacion no va a dar 3 al cubo sino que va a se 2 + 1*2 + 1*2 + 1 = 7
en cambio con la otras su se da 3 al cubo que es 27.

## Que es un functor? Ejemplifique.

Los funciones son clases que sobrecargan al operador(), y se podrian pensar como clases que actuan como funciones. Estas permiten desacoplar el momento en el que se se pasan los paraemtris a una funcion mientras es ejectada. Ora ventaja que traen es que son objetos por lo que ademas de tener el comprotamiento de una funcion pueden ir variando en funcion de la ejecucuion
```c++
class Impresora{
    public:
        Impresora(std::string in):texto(in){}
        void operator() () {
            std::cout<<texto<<std::endl;
        }
    private:
        std::string texto;
}

int main() {
    Impresora impresora("Hola mundo");
    impresora();
    return 0;
}
```
## ¿Qué ventaja ofrece un lock RAII frente al tradicional lock/unlock?
Un lock raii sigue cone el patron raii, logra tener encapsulado el lock y en unclok, el lock se realiza dentro del constructor de la clase lock raii y el unlock se realiza en el destrcutor de la clase. La ventja es que como porgramos uno se "olvida" de tener que hacer lock y unlock manualmente ya que por serr rai sabemos que sebloquea cuando se invoca al constrcutor y se libera cuando se sale del scope al invocarse el destructor. Con esto logramos tener un codgo mas robusto ya que se minimizan los erores de liberacion de mutex o bloquear el mutex.

## ¿Qué valor arroja sizeof(int)? Justifique.
El valor que arroje sizeof(int) depende de la arquitectura de la compu y del compilador. Si se trata de un arquitectura de 32 bits el valor que devuelve es 4 mientras que si la arquitectura es de 64 el valor que devuelve es 8 0 4. (Si compilamos el programa con gcc el mismo vale 4.)

## ¿Qué características debe tener un compilador C para se considerado “portable”?

Un compialdor de c es portable si soporta la sintaxis(y semantica) del lenguage c en un estandar dado y no agrega ninguna sintaxis adicional por fuera de la estandar( de forma tal que un programa compialdo puede ser compilado por otro compilador. Esto incluye tambien el proceso de compilacion estandar(precompilacion , compilacion y linkeo). Ademas debe proveer una implemnetacion a la libreria de c respetando el estandar mencionado anteriormente tal que el programa compialdo en un entrono pueda ser com;ialdo en otro que tenga una libreria de c compatible.
## Explique metodos virtuales puros y para que sirven :

son lo metodos que estan obligados las clases hijas a implementar. Son muy imprtantes para cuando se tiene clases abstractas o interfaces. 
```C++
class Animal{
      public:
      vitual void respirar() = 0; // las clases hijas estan obligadas a implemnetar este metodo, no se puede instanciar la clase animal
}
```
## Considere la estructurastruct ejemplo int a; char b;.¿Es verdad que sizeof(ejemplo)=sizeof(a)+sizeof(b)? Justifique.
es incorrecto. En estructuras no ocupan la suma de sus elementos. En este tipo de estructuras se utiliza un padding para evitar porblemas de alineacion de memoria. Ej si se tiene una arquitectura de 32 bits sizeof(char) = 1 y sizeof(int) = 4 lo cual la suma da 5 pero si se hace sizeof(estrcutra) = 8 porque justamente hay un padding. 

## ¿En qué consiste el patrón de diseño RAII? Ejemplifique.
El patron raii consiste en la encapsulacion de la creacion/destructcion de una clase. En el constructor se inicializan los atributos de la clase dejandola valida para usar y es donde se reserva la memoria necesaria y en el destrcutor en donde se liberan los recursos y la memmoria reservada.
Esto trae una gran cantidad de beneficios, como mayor poder de abstraccion, garantizamos que si la clase logra ser instanciada la misma tiene acceso a los recursos que requiere, garantizamos que los recursos se liberen(gracias al destructor).
