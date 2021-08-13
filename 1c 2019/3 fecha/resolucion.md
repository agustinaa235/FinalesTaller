# Ejercicio 1
Declare una clase a elección considerando:
*** Atributos que son necesarios** *** Accesibilidad a la Clase** *** Incluir los operadores +, ++ (post-incremento), --(pre-incremento), >> (impresión), 
<< (carga desde consola), long**
```C++
class Numero{
         private:
              int valor;
         public:
              Numero(conts int& unValor);// constructor
              Numero& operador=(const Numero& numero) // operador = por copia
              Numero& operador+(const Numero& numero);
              Numero& operador++();
              Numero& operador--();
              std::istream operador>>(std::istream in, Numero& numero);
              std::ostream operador<<(std::ostream out, NUmero& numero);
```

# Ejercicio2 
¿Qué es un functor? ¿Qué ventaja ofrece frente a una función convencional? Ejemplifique.

UN functor es un objeto que tiene sobrecargado el operador () y actua como si fuese una funcion. La ventaja que poseen los functores es que permiten recibir los paraemtros de una vez, al momento de construirse por ejemplo y que la clase ya se los guarde como atributos.
Ej:
```C++
  class Sumador{
       std::list<int> numeros;
       int acumulador;
       public:
        Sumador(std::list<int> numero): numeros(numero); 
        void operador()(){
          for (auto it = numeros.begin(); it != numeros.end(); ++it){
                  acumulador += *it;
          }
          std::cout << acumulador;
       }
}
```


# Ejercicio 3
Escriba un programa que imprima por salida estándar los números entre 1 y 100, en orden ascendente. Se pide que los números sean contabilizados por una variable global única y que los pares sean escritos por un hilo mientras que los impares sean escritos por otro.
Contemple la correcta sincronización entre hilos y la liberación de los recursos utilizados.
# Ejercicio 4
Explique qué es (a), (b), (c) y (d), haciendo referencia a su valor y momento de inicialización, su comportamiento y el area de memoria donde residen:

static int a;
int b()
{
static int c; char d=65;
return c+(int) d;
}
* a: a es una declaracion de una varaible del tipo int, es static por lo que se va a encontrar almacenada en el data segmente y su scope en local del programa, es decir, solo puede ser accedida en ese modulo. Como no se eucnetra inicializada por el programador esta es inicializada en cero cuando se ejecuta el programa. 
* b: b es una definicion de una funcion que deuelven un tipo de dato int y que no recibe parametros. Esta tien scope local y se encuentra en el code segment. 
* c: es una definicio de una variable del tipo int que es static, esta se encuentra en el data segmente y se inicializa en cero cuando comienza el programa y su scope es local a la funcion, es decir, solo puede ser accedida dentro de la funcion. 
* d es una definicion de un variable del tipo char que se inicializa con el valor correspondinte a la tabla ascci de 65. Se encuentra en el stack por encoentrarse declarada en una funcion y scope es local a la funcion. 
# Ejercicio 5
Escriba una rutina que dibuje las dos diagonales de la pantalla en color rojo..
HECHO
# Ejercicio 6
¿Por qué las librerías que usan Templates se publican con todo el código fuente y no como un .h y .o/.obj?.
Los templates son plantillas para generar clases. Se publican con todo el codgio ya que este es porcesado por el compilador y depende del tipo de dato que se este usando en ese momento. or eso podemos especificar el tipo de dato o dejar que el compilador lo deduzca, pero dicho codigo debe compilarse en el momento que se defina el tipo de dato.
# Ejercicio 7
¿Qué características debe tener un compilador C para se considerado “portable”?

Un compilador es condierado portable cuando soporta la sintaxix y semantica del lenguage c dado un estandar y no agrega ninguna sintaxis adicional por fuera de la estandar( y esto permite que el codigo sea compilado por otro compilador). Tambien debe incluir el proceso de compilacion(preprocesamiento, compiladon y linkeo). 
Ademas el compilador debe ofrecer una implementacion de la libreria estandar de c respetando el estadar mencionado anteriormente de tal forma que si un porgrama es compilado en un entorno pueda ser compilado en otro con una libreria de c compatible.
# Ejercicio 8
Escriba un programa (desde la inicialización hasta la liberación de los recursos) que reciba paquetes de la forma [nnn+nn+....+nnnn] (numeros separados por +,
 encerrados entre corchetes) e imprima el resultado de la suma de cada paquete por pantalla. Al recibir un paquete vacío (“[]”) debe cerrarse ordenadamente. 
 No considere errores.
 # Ejercicio 9
 Escriba una función ISO C que permita procesar un archivo texto que contenga frases (1 por línea) sobre sí mismo, sin generar archivos intermedios ni cargar el 
archivo completo a memoria. El procesamiento consiste en eliminar las palabras de más de 3 letras de cada línea.
# Ejercicio 10
¿Qué diferencia existe entre un constructor por copia y uno por movimiento? Ejemplifique.
un constructor copia se duplica o se copia la informacion/bits del objeto pasado por parametro para la creacion de una nuevo mientras que por movimiento se cambia el ownershit, es decir no se va a tener dos duenios sino que el objeto creado pasa a apuntar a lo que apunta el objeto pasado y este deja de apuntar a esa informacion y pasa a apuntar a null. 
