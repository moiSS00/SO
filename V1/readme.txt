En esta última entrega se realizó desde el ejercicio 12 hasta el 15 (ambos inclusive) . También se arreglaron varios errores de la V1 cometidos en las anteriories 
(principalmente el mal funcionamiento de algunos mensajes) dos entregas parciales. Donde se podrá encontrar tambien el readme.txt correspondiente de cada entrega. 

Ej 12:
Se modificó la función "OperatingSystem_HandleSystemCall()" que se encuntra en "OperatingSystem.c", añadiendole un nuevo caso para la nueva llamada al sistema "SYSCALL_YIELD" (también 
se modificó el "OperatingSystem.h" para dar soporte a la nueva llamada al sistema , asignadole el valor 4). Para implementar la función de esta llamada al sistema, se utilió una función
auxiliar propia llamada "OperatingSystem_SYSCALL_YIELD()" que lo que hace es: Extraer de la misma cola que el proceso que se está ejecutando, el siguiente proceso a ejecutar (controlando 
si hay o no más procesos en la lista).Posteriormente se comprueba si la prioridad del proceso actual es igual que la del proceso a meter, si son iguales el proceso actual abandona la 
CPU y la cede al otro, en caso contrario, el proceso se vuelve a menter en la cola. 

Ej 13: 
Se guarda el estado de ambos registro para poder continuar en un futuro con la ejecucuión de un proceso que tuvo que tratar con una llamada
al sistema o una excepción durante su ejecución. Sería también recomendable guardar el reistro acumulador para guardar el resultado de las operaciones aritméticas 
que se huieran realizado antes de la llamada al sistema y continuar con ellas una vez se vuelva al proceso. Para ello se añadió un campo "copyOfRegisterAccumulator" en el PCB y 
se modificaron las funciones "void OperatingSystem_RestoreContext()" y "void OperatingSystem_SaveContext()" para que inicializaran y guardaran el estado del acumulador si es necesario. 

Ej 14: 
Esta funcion finaliza un proceso de usuario cambiando su estado a EXIT y decrementando el numero de procesos de usuario. Si al eliminar un proceso aún quedan procesos por ejecutar 
se ejecuta la función "OperatingSystem_Dispatch(selectedProcess)" que coge el siguiente proceso a usuario a ejecutar o por defecto si no hay ninguno se ejecuta el SIP. Si al llamar a 
esta función el procesos que se está ejectando es el SIP yno queda ningún proceso de usuario, se finaliza el SIP y se apaga el sistema.

Ej 15: 
Se modificó la función "OperatingSystem_Initialize()" en la linea 86 (posteriormente a la llamada a "OperatingSystem_LongTermScheduler()") que comprueba si el número de programas 
de usuario (los programas que se le pasan como parámetro) es menor o igual a 0. Esto debido a que si un programa da un error de algún tipo no se crea y si el simulador no se detiene 
a tiempo, este entrará en bucle infinito.
 
Ej 16: 
Para este ejercicio se modificó la función "Processor_DecodeAndExecuteInstruction()" en el archivo "Processor.c". En la estructura switch-case de esta función, se moficaron los casos 
para las instrucciones HALT , OS e IRRETEsto con el objetivo de que solo se pudieran ejecutar cuando el procesador estaba en modo protegido. Se comprueba si el modo de la CPU es el 
correcto "Processor_PSW_BitState(EXECUTION_MODE_BIT)" (que nos devuelve un booleano , indicando si está o no en protegido) y si es así, ejecuta normalmente la instrucción.En caso 
contrario se lanza una excpción "Processor_RaiseInterrupt(EXCEPTION_BIT)".Uno de los momentos donde se activa o desactiva el modo protegido, se encuentra en la función 
"OperatingSystem_PCBInitialization" donde da el modo protegido a los demonios del sistema.

Moisés Sanjurjo Sánchez - UO270824