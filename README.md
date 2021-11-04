# **SE_TPs**
Sistemas Embebidos - 86.65 - TPs

# **TP1**

## *Ejercicio 3*

El panel de control tiene tres modos de configuración, en el modo "forma", se utilizan los botones TEC2 (triangular), TEC3 (cuadrada) y TEC4 (senoidal) para elegir la señal y se enciende el LED correspondiente a cada señal (LED1, LED2 y LED3 respectivamente). Luego, en el modo "frecuencia" indicado con LEDG se puede variar la amplitud desde 20Hz hasta 20kHz. Se va incrementando (TEC3) o disminuyendo (TEC2) de forma geométrica (x10) y se indica cuantas veces se multiplica por 10 en binario y utilizando los LEDs: LEDR, LED1 y LED2. Finalmente, está el modo "amplitud" (de 0 V a 10 V) el cual se indica encendiendo el LEDB y se puede variar la amplitud con los botones TEC2 (disminuir) y TEC3 (aumentar), el valor de tensión varía con incrementos de 1 y se indica con cuatro LEDs (LEDR, LED1, LED2 y LED3) en binario.

## *Ejercicio 4*

La puerta corrediza tiene sensor de movimiento, y dos sensores de fin de carreras (una en cada sentido), y por otro lado un motor para abrir y cerrar la puerta. El boton TEC1 representa el sensor de movimiento, TEC2 el fin de carrera (totalmente abierto) y el TEC3 el fin de carrera (totalmente cerrado). Si se detecta presencia, se enciende el motor para abrir la puerta (LED1), hasta que detecta el fin de carrera, y espera unos 5 segundos, y luego comienza a cerrarse (LED2), hasta detectar el fin de carrera. Si durante el cierre de la puerta, se detecta una presencia, se vuelve a "activar" el mecanismo de apertura.

## *Ejercicio 5*

El portón levadizo se maneja con dos botones: TEC1 para cerrar y TEC2 para abrir. Mientras se abre o se cierra (tarda 8s en cada uno) se enciende señalización luminosa (LED3). Si mientras se está cerrando hay alguna obstrucción (representada con TEC3) se vuelve a abrir. En el estado abierto se enciende el LEDG y cerrado el LEDR.


## *Ejercicio 6*

El horno microondas consta de 3 métodos de cocción seleccionable, y con botón de encedido/apagado y apertura de puerta. Con el botón TEC1 se cambia de modo de cocción de manera secuencial, el botón TEC2 es el indicador de apertura de puerta y el botón TEC3 es el botón de encencido/apagado.LED1, LED2, y LED3 indica cada uno un modo distinto, y el LEDR indica si está "cocinando" o no. Si se abre la puerta mientras está "cocinando", se detiene la cocción.

## *Ejercicio 7*

La escalera mecánica (unidireccional) tiene dos velocidades, la primera (la más lenta) cuando no hay nadie subiendo (indicada con LEDG) y la otra (la rápida) cuando hay personas subiendo. El botón TEC1 representa los ingresos y el TEC2 los egresos (podrían ser sensores). Mientras los que hayan ingresado no hayan salido, la escalera va a estar en la segunda velocidad con la señalización luminosa encendida (LED1). Si todos los que ingresaron ya subieron, entonces se apaga la señalización luminosa y se cambia a la primera velocidad.


## *Ejercicio 8*

Se hizo el diagrama de estados para controlar el seteo de los distintos efectos posibles (proyecto Pedal Lucas). Se tienen 3 modos y son seleccionables por los 3 botones.

