# Pregunta 1
Escriba una rutina que procese un archivo binario indicado por parametro sobre si mismo sumarizando los listados de numeros que posee almacenado. La sumarizacion consiste en recorrer los valores enteros de 32 bits con signo grabados en formato big-endian y acumular sus valores hasta encontrar el valor 0xffffffff que se considera un separador entre listados.

Todos los valores enteros detectados son reemplazados por su sumatoria (en el mismo formati) manteniendo luego el elemento separador. Considere archivos bien formados.

# Pregunta 2
Describa con exactitud las siguientes declaraciones/definiciones globales:

extern char (*l)[3];

l es un puntero a un array de tamanio 3 de char. Es extern por lo que hace referencia a una declaracion en un modulo externo.

static float *C[3];

c es un array de tamanio 3 de contiene punteros a numeros del tipo float. Este es static por lo que solo puede ser accedida en el modulo que fue declarado.

static int F(const short *a);
f es una funcion qe recibe como paramteros un puntero a short constante y devuelve un valor del tipo int. La funcion es static por lo que solo puede ser accedida en el modulo que se declaro.

# Pregunta 3
Explique que es y para que sirve una variable de clase (o atributo estatico) en C++. Mediante un ejemplo de uso, indique como se define dicha variable, su inicializacion y el acceso a su valor para realizar una impresion simple dentro de un main.

Una variable de clase o atributo estatico es una vraible que es la misma la para todas las intancias(objetos) de la clase. Esta es inicializada por el porgramador o en cero/NULL si es que no estaba inicializada. La ventaja que permite es que se puede acceder a ellas sin la necesidad de instanciar una clase. Ej:
```
Class Numero{
  public:
    static float pi = 3.14;
}
accedo:
  if (numero > Numero.pi){
    ...
   }
```

# Pregunta 4
Defina una rutina en C que se conecte a la IP 8.8.8.8, al puerto 8192 y reciba un archivo binario. El archivo recibido debe ser descargado a un archivo llamado recibido.bin cuidando el uso de recursos de memoria. El archivo finaliza al detectar conexion cerrada.

# Pregunta 5
Declare la clase Oraciones que almacena una acumulacion de lineas de texto (strings) en cierto orden e incluye las operaciones de agregacion y eliminacion de lineas.

La clase debe poseer los operadores usuales de copia, asignacion, salida a flujo (<<) comparacion (==), agregacion (+), substraccion (-).

Los 2 ultimos operadores deben admitir argumentos del tipo string en formato C (char*) y C++ (std::string).

# Pregunta 6
Escriba una clase template llamada Sumador que reciba por constructor un vector de elementos genericos. La clase Sumador debe incluir un metodo llamado sumar que acumule los valores del tipo recibido y retorne un nuevo objeto del tipo generico.

Que restricciones se le piden al tipo generico en la definicion de Sumador?

# Pregunta 7
Explique la diferencia entre las etapas de compilacion y enlazado (linking). Escriba un breve ejemplo de codigo con errores para cada una de ellas indicandolos de forma clara
Primero esta la etapa de pre compilacion donde se realizan la epancion de las macros y directivas del precompialdor. Aca surgen problemas relacionados a ellos. Luego esta la estapa de compilacion donde se pasa del codigo fuente a codigo objeto aca surgen porblemas del tipo utilizacion de variables no declaradas, ect. Y por ultimo esta la etapa de linkeo que es donde se juntan todos los modulos(archivos objetos) en un unico modulo y asi generea un archivo ejecutable. SE resuelven los problemas de exter y global.
# Pregunta 8
Defina el concepto de Mutex y de un ejemplo de uso. Indique en que casos es necesario.

Un mutex es un objeto que permite proteger a un recurso compratido entre dos o mas hilos. Este tiene las funciones lock y aunlock en donde la primero cuando un hilo toma el recurso se hace un lock que permite que solo ese hilo pueda acceder a el recurso y cuando termina de usarlo se debe invocar a la funcion unlock del mutex para justamente poder liberar al recurso y que otros hilos puedan acceder a el. Es necesario cuando se tiene un recurso compartido como por ejemplo una cola o una lista y se quiere sacar un elemento pero para sacarlo no debe estar vacia.
```
class ListProtegida{
    private:
    std::mutex m;
    std::list<int> list;
  // saca numero positivos y si no se puede sacar devuelve negativs
    int sacarElemento(){
        m.lock()
        int valor = -1;
        if (!lista.is_empty()){
                valor = lista.front();
                lista.pop_front();
        }
        m.unlock();
        return valor;
    }
  ```
# Pregunta 9
Que es un thread? Que funciones se utilizan para manipularlos (lanzarlos, etc)?

Un thread es la ejecucion de una funcion/bloque de codigo. Cuando se tiene multiples hilos es porque se estan ejecutando multiples funciones en simultaneo. En c++11 para poder sanzar un hilo se hace por medio de std::thread donde recibe por paraemros la funcion a ejecutar y los paraemtros de la funcion. Otra funcion que se utiliza es join() se es para cuando el hilo ya termino de ejecutarse entonces se tiene que liberar el recurso.

# Pregunta 10
Escriba una funcion de C llamada strncat_new que reciba tres parametros: dos punteros a caracter constante (S1 y S2) y un entero sin signo (L).

La funcion debe concatenar S1 con S2 y retornar una nueva cadena de caracteres considerando L como tamaño maximo para cualquiera de los elementos (S1, S2 y la nueva cadena).

La funcion debe detectar condiciones de erro respecto de la longitud y retornar NULL en cualquier caso.
