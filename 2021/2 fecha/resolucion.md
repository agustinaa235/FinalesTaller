# Ejercicio 1
Escriba un programa que reciba por línea de comandos un Puerto y una IP. El programa
debe establecer una unica conexión, y enviar todo el texto ingresado por stdin. Cuando
se ingrese el texto ‘FIN’ debe finalizar el programa sin enviar dicho texto
# Ejercicio 2
 ¿Qué es una Condition Variable? Ejemplifique mediante código.
 Es una varible utilizada en sicronizacion de hilos en la cual permite bloquear un hilo o multiples hilos hasta que le llegue alguna senial. Esta senial puede ser que pase un determiando tiempo o  una notificacion de otro hilo. Basicamente se utiliza para tener una cordinacion entre dos o mas hilos con un mismo recurso. 
 Poseen los metodos de wait() y notyfy_all(, entre otros. El primero lo que hace es decirle al hilo que espere o a que le llegue una senialientras que notyfy_all le avisa al resto de los hilos que ya pueden ser ejecutados, es decir, pasaria a ser la senial. 
 ```C++
 class ColaBloqueante:
    
    std::queue<int> cola
    std::condition_variable cv;
    bool vacia = true;
    
    void pop(){
      while (vacia){
            cv.wait();
       }
       cola.pop();
      }
      
      void push(int elem){
        cola.push(elem);
        cv.notify_all();
       }
 ``` 
 # Ejercicio 3
  Escribir un programa ISO C MULTIPLATAFORMA que procese el archivo “valores.txt” sobre
sí mismo. El procesamiento consiste en leer números separados por 1 espacio que se
encuentran en base 3 y escribirlos en 4 símbolos base hexadecimales, también separados
por 1 espacio.

# Ejercicio 4
Implemente un programa de 2 threads (producer-consumer) que genere e imprima los
números del 100 al 1

# Ejercicio 5
Implemente una función C++ denominada PurgarMapa que reciba un mapa (clave-valor)
por referencia y le quite los elementos cuyos valores están repetidos.
    
