# Ejercicio 1
Escriba una rutina (para ambiente gráfico Windows o Linux) que dibuje un triángulo amarillo del tamaño de la ventana.
# Ejercicio 2
Escriba las siguientes definiciones/declaraciones:

Declaración de un puntero a puntero a entero largo con signo.
Definición de una la función RESTA, que tome dos enteros largos con signo y devuelva su resta. Esta función debe ser visible en todos los módulos del programa.
Definición de un caracter solamente visible en el módulo donde se define.

1. ` long int *(*p); `
2. `long int RESTA(long int numero1, long int numero2){ return numero1 - numero2 }`
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
              std::ostream operator<<(std::ostream output, Telefono& tel);
              std::istream operator>>(std::istream input; Telefono& tel){
                    input >> tel.numero;
                    return input;
              }
   }
```   
# Ejercicio 4
Explique qué se entiende por “compilación condicional”. Ejemplifique mediante código.

copilacion condicional es cuando de acuerdo a la direciva del compilador compila un codigo o no. SE utiliza la directiva ifndef en la cual si la clase no es 
defina la compila y si lo eta directamente salta al endif Sirve much para cortar las inclusiones de bibliotecas 
ej:
```C
#ifndef _CLASE_
#define _CLASE_
....
....
#endif _CLASE_
```

# Ejercicio 5
¿Qué significa que una función es blocante?¿Cómo subsanaría esa limitación en término de mantener el programa ‘vivo’ ?
Una funcion es bloqueante cuando se queda "esperando" a que termine de realizar una tarea y mientras no se puede ejecutar otra cosa. Para que el programa sigo vivo
utilizara hilos, es decir, la funcion bloqueante la podria en un hilo en la cual por sincronizacion de hilos mientras este hilo se queda esperando a finaliar la tarea
los otros hilos siguen ejecutando el programa. 


# Ejercicio 6
Explique qué son los métodos virtuales puros y para qué sirven. De un breve ejemplo donde su uso sea imprescindible.


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

antes de hacer un join para liberal al hilo lo que se debe preguntar es si el hilo sigue vivo (IS DEAD) y en el caso que lo este es ahi cuando se hace un join 
y ahi se invoca a su destructor. 

# Ejercicio 10
Escriba un programa C que tome 2 cadenas por línea de comandos: A y B; e imprima la cadena A después de haber duplicado todas las ocurrencias de B. ej.: 
reemp.exe “El final está aprobado” aprobado -----> El final está aprobado aprobado

