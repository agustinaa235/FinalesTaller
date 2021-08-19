# Ejercicio 1
Escriba una rutina (para ambiente gráfico Windows o Linux) que dibuje un triángulo amarillo del tamaño de la ventana.
# Ejercicio 2
Escriba las siguientes definiciones/declaraciones:

Declaración de un puntero a puntero a entero largo con signo.
Definición de una la función RESTA, que tome dos enteros largos con signo y devuelva su resta. Esta función debe ser visible en todos los módulos del programa.
Definición de un caracter solamente visible en el módulo donde se define.

1. ` signed long int *(*p); `
2. ` signed long int RESTA(long int numero1, long int numero2){ return numero1 - numero2 }`
3. ` static char a = 'b';`

                  

# Ejercicio 3
Declare la clase TELEFONO para encapsular una cadena numérica correspondiente a un teléfono. Incluya al menos: Constructor(area, numero), Constructor move y 
Constructor de Copia; Operador <<, ==, =, long y >>. Implemente el operador >>.

```C++
    class Telefono{
        private:  
                int area;
                int numero;
        public:
              Constructor(const int area, const int numero);
              ~Constructor();
              Constructor(Telefono&& otroTel); // por movimeiento
              Constructor(const Telefono& otroTel); // por copia
              bool operator==(Teleno& tel);
              Telefono& operator=(const Telefono& tel);
              operator long() const; 
              std::ostream operator<<(std::ostream output, Telefono& tel);
              std::istream operator>>(std::istream input; Telefono& tel){
                    input >> tel.numero;
                    return input;
              }
   }
```   
# Ejercicio 4
Explique qué se entiende por “compilación condicional”. Ejemplifique mediante código.

La compilacion condicional es un proceso en el cual se verifica condicionalmente si una parte de mi archivo esta definida o no.(Es una falicidad que nos brinda el precompialdor para incluir o excluir determinadas partes del codigo en funcion de constantes conocidas). Esto se hace por medio de las directivas #ifndef, #ifdef, #define y #endif. Eso se verifica en la etapa de precompilacion( ya que ahi se realiza la expancion de las macros y las directivas del precompiador).
ej:
```C
#ifndef _CLASE_
#define _CLASE_
....
....
#endif _CLASE_
```
En este caso si CLASS esta definida, la condicon es falsa y directamente salta a la directiva #endif, sino la condicion es verdadera (CLASS no esta definida) y ahi la define.

# Ejercicio 5
¿Qué significa que una función es blocante?¿Cómo subsanaría esa limitación en término de mantener el programa ‘vivo’ ?
Una funcion es bloqueante cuando no retorna inmediatamnete tras su ejecucuion (se queda como "suspendida"), es cuando la funcion se queda a la espera de un eventto para poder finalizar y retornar. Un ejemplo de funcion bloqueante es accept del sockets donde se queda bloqueando esperando a aceptar clientes y finaliza cuando se cierra el socket del servidor. Como se queda bloqueada, esto traeri probelmas para continuar la ejecucion del resto del programa por lo que para solucionar esto se suele ejecutar la funcion bloqeuante en un hilo aparte ya que este quedaria bloqueado pero el resto del porgrama podria seguir ejecutandose.
# Ejercicio 6
Explique qué son los métodos virtuales puros y para qué sirven. De un breve ejemplo donde su uso sea imprescindible.
Los metodos virtuales puros son los que las clases deribadas estan obligadas a implementar. Cuando una clase base tiene un metodo virtual puro es porque esa clase es abstracta y no se puede instanciar directamente, en ese caso se instancia la clases deribadas que implemneten todos los metodos virtuales puros. Es muy utilizado cuando se quiere aplicar polimorfismo cuando se tienen dintintas clases que deberian implemnetar una funcion de distntas maneras. El tipico ejemplo es del de las figuras.
ej:
```C++
class Figura{
      public:
      virtual int calcularArea() = 0; // es virutal pura, todas las clases que herenden de figura deben implementarlo
}
class Triangulo: public Figura{
    protected:
      int base;
      int altura;
    public:
      int calcularArea(){
          return (base*Altura)/2'
     }
}
class Cuadrado: public Figura{
    protected:
    int base;
    int altura;
    public:
      int calcularArea(){
        return base*Altura;
      }
}
```

# Ejercicio 7
Escribir un programa C que procese el archivo “numeros.txt” sobre sí mismo (sin crear archivos intermedios y sin subir el archivo a memoria). El procesamiento 
consiste en leer nros hexadecimales de 4 símbolos y reemplazarlos por su valor decimal (en texto).

# Ejercicio 8
¿Qué es el polimorfismo? Ejemplifique mediante código.

El polimorfismo es uno de los pilares de la programacion orientada a objetos. Lo que permite es poder responder/resolver un problema de forma distinta. 
Es como distintas clases utilizan la misma funcion pero cada cada resuelve de manera diferente el progrema, de manera poliformica y con esto logramos 
manater el encapsulamiento. 
ej. Puedo tener la clase triangulo y la clase cuadrado y ambos implemenetar la funcion de calcularArea, y cada uno lo hace de forma distinta el cuadrado hace area 
al cuadrado mientras que el triangulo lo hace como base por altura sobre 2. 


# Ejercicio 9
¿Qué función utiliza para esperar la terminación de un thread? Ejemplifique mediante código.

Un hilo es lanzado por medio de std::thread, cuando finaliza su ejecucuion el hilo es joineable y ahi es cuando dentro del hilo que se lanzo el hilo joinable se realiza un join() en la cual permite unir ese hilo al hilo que lo llamo. 
ej:
```
void foo(){
    std::cout << "hola" << std::endl;
}

int main(){
    std::thread hilo(foo);
    hilo.join();
    return 0;
}
```
luego de que se imprima "hola" en el hilo foo, este es joineable porque termino su ejecucuion entonces recine ahi join()( que estaba a la espera de que finalice ese hilo) lo vuelve a unir al hilo que lo llamo y en este caso termina el programa.

# Ejercicio 10
Escriba un programa C que tome 2 cadenas por línea de comandos: A y B; e imprima la cadena A después de haber duplicado todas las ocurrencias de B. ej.: 
reemp.exe “El final está aprobado” aprobado -----> El final está aprobado aprobado

