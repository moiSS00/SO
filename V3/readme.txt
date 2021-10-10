Se realizaron los ejercicios de la V3 y se comprobó su funcionamiento.

  
Ejercicio 0: 
Se hicieron las modificaciones necesarias, dadas en el enunciado del ejercicio para dar soporte a la "ARRIVALQUEUE".

Ejerccio 1: 
Se creó la función "int OperatingSystem_GetExecutingProcessID()" en "OperatingSystem.c" que devuelve el PID del proceso que se 
está ejecutando actualmente. Esta función se utilizó para que en cada instrucción ejecutada tambien aparaciera el PID del proceso al 
que pertenecia la instruccion. Para ello se creó un nuemo mensaje (número 130) y se utilizó en la función 
"Processor_DecodeAndExecuteInstruction()" localizada en "Processor.c".

Ejercicio 2: 
Se modificó el procesador a largo plazo ("int OperatingSystem_LongTermScheduler()") para que se ejecutara mientras la función
"OperatingSystem_IsThereANewProgram()" dada devolviera YES (constante), indicando que hay programas que han llegado al sistema hasta el 
momento actual.

Se creó también para el código quedara menos engorroso una función auxiliar "void OperatingSystem_ErrorCreateProcess(int,int)" que controla
los errores que se pueden dar al crear un proceso y saca por pantalla los mensajes de aviso.

Ejercicio 3:

Se añadió una nueva llamada al planificador a largo plazo en "OperatingSystem_HandleClockInterrupt()" después de intentar despertar los procesos 
de la cola de dormidos. Tambien se modificó esta función para que comprobara que el proceso que se esta ejecutando es el de mayor prioridad 
cuando se desperta algún proceso O se crea un proceso nuevo por el PLP.

Ejercicio 4: 

Se creo una función auxiliar "void OperatingSystem_ShutdownCheck()" que comprueba si es necesario o no apagar el sistema. La condición para que 
se apage es que no haya más procesos de usuario a ejecutar y que la "arrivalAqueue" este vacía.

Utilizando esta función se cubrieron los 3 casos mencionados en el enunciado que podían dar lugar a un comportamiento incorrecto. 


Para probar esta versión se utilizaron los programas dados en distintas combinaciones y con distintos instantes. De esto a que me diera 
cuenta del error de la V2 comentado por correo en el que se calculaba mal el campo whenToWakeup.  

Moisés Sanjurjo Sánchez - UO270824