En esta última entrega se realizó desde el ejercicio 5 hasta el 8 (ambos inclusive) . También se arreglaron varios errores de la V2 cometidos en la anterior
entrega parcial. Donde se podrá encontrar tambien el readme.txt correspondiente a la anterior entrega. 

Errores de la anterior entrega parcial solucionados: 

- Se modificó la función "Processor_InitializeInterruptVectorTable()" para incializar correctamente la interrupt vector table con la nueva interrupción.Esto no se había hecho en la 
entrega parcial. 

- Se modificó el archivo "OperatingSystemCode" para que se de soporte a la nueva interrupción.

Ej 5: 
Añadimos una nueva cola para los procesos dormidos en "OperatingSystem.c" y un nuevo campo en el PCB "whenToWakeUp". Los procesos en esta cola se encuntran en estado
BLOCKED y se insertaran por orden creciente del campo whenToWakeUp. Para este ejercicio se crearon las funciones "OperatingSystem_SYSCALL_SLEEP()" y "OperatingSystem_MoveToTheBLOCKEDState(int)".
La primera tiene como objetivo manejar la nueva llamada al sistema "SYSCALL_SLEEP" (y se llama en un nuevo caso en la función "void OperatingSystem_HandleSystemCall()")y la 
segunda es una función auxiliar para mover un proceso a la cola de dormidos. 

Para este ejercicio se modificó tanto el "OperatingSystem.c" como el "OperatingSystem.h".

Ej 6: 

Se modificó la función "OperatingSystem_HandleClockInterrupt()" para que cada vez que se produza una interrupción de reloj, se despierten los procesos cuyo "whenToWakeUp" es igual al número
de interrupciones de reloj dadas hasta el momento. Además, tambien se comprueba si el proceso que se está ejecutando es el de mayor prioridad posible, si no lo es, este abandona el procesador 
y se lo cede al proceso más prioritario. 

Se crearon dos funciones auxiliares para este ejercicio:
-"OperatingSystem_ExtractFromSleepingProcessesQueue()" que extrae un proceso de la cola de dormidos.
-"int OperatingSystem_MaxProirity()" que devuelve el proceso actual con más prioridad.

Todo esto se ralizó sobre el "OperatingSystem.c".

Ej 7 y 8: 

Se añadieron varias llamadas a la función  "OperatingSystem_PrintStatus()" en "OperatingSystem.c" con el objetivo de imprimir información útil del simulador: 

-Cada vez que el planificador a largo plazo cree procesos nuevos. 
-Cada vez que se despierta/n algún/os proceso/s. 
-Cada vez que se cambia el proceso en ejecución. 

Además se comentó la llamada a la función "OperatingSystem_PrintReadyToRunQueue()" que se encontraba en "OperatingSystem_MoveToTheREADYState()" con el objetivo de evitar 
la repetición de información.

Para comprobar los ejercicios se utilizaron principalmente los programas (adjuntos en esta entrega) que se dieron en la entrega del campus virtual (mediante varias combinaciones de estos). 
 
Moisés Sanjurjo Sánchez - UO270824