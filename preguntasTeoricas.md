## Preguntas teoricas 

# Indique 2 posibles usos del modificador const. Utilice en cada caso una breve sentencia de código que lo emplee junto con la explicación del 
# significado/consecuencia de su uso.

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
# Explique el concepto de Mutex. Escriba un ejemplo simple de código donde su uso resulte fundamental para garantizar el correcto empleo de recursos en un contexto concurrente. Describa los métodos disponibles y su uso.

El mutx en un objeto  en la cual este posee dos estado bloqueado y liberado. Es utilizado en programas de sincronizacion de hilos o en porblemas de concurrencia
donde se tiene uno mas recursos compartidos y se lo quiere proteger para evitar problemas como race condition entre otros.
Para eso el mutex posee dos funciones lock y unlock. Cuando un hilo toma un recurso dentro del recurso se debe hace mutex.lock() esto lo que hace es bloquear al mutex
y no permitir que otro hilo pueda acceder a ese recurso hasta que este sea liberado. Y la segunda funcion es justamente para liberar al recurso, al mutex, y asi otro
hilo puede acceder a el, cambia al estado liberado. 

# Explique el concepto de referencia en C++. que diferencias hay con respecto a los punteros?

Una referencia en c++ es un tipo de dato que sirve como alias de otra varable mientras que un puntero es simplemente una direccion de memoria, es decir, almacena
direcciones de memoria. Otra diferencia es que una refrencia en c++ es inmutable, puede apuntar a un objeto en toda su vida mientras que los punteros pueden 
ir apuntado a distinas direciones de memoria.

# Explique el concepto de object slicin (objeto recortado). Escriba un breve ejemplo sobre como esto afecta una función que pretende aplicar polimorfismo sobre uno de sus parámetros.

El objet slicn es cuando se le asigna un objeto perteneciente a una clase derivada una instancia de su clase base. Lo que genera es que se pierda parte de su 
informacion ( de ahi sale el nombre objeto recortado). Lo que se pierden son los atributrso extras que posee la clase derivada. 

# Describa el concepto de templates en C++. De un breve ejemplo de una función template.

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
# ¿Describa brevemente el contenedor map de la librería estándar de C++? Ejemplifique su uso.
la clase map de la libreria estandar de c++ es un diccionareo ordenado. Este funciona con templates para poder tener cualquier tipo como clave y cualquier tipo de
dato como valor. Tiene distintas funciones como insertar o tamanio como tambien su iterador.
```C++
int main(){
    std::map<int, char> mapa;
  mapa.insert({1,h}};
   std::cout << mapa['1'] << std::endl;
 }
```
