Sanjurjo Sánchez, Moisés 
UO270824

Las pruebas realizadas: 

- Se utilizó el test de la V4 dado por los profesores (para probar el simulador con deamons).
- ./Simulator programV2-a 0 programV2-b 0  programV2-c 0  y ./Simulator programV2-a 8 programV2-b 4 programV2-c 0
----> Esta entrada es la misma que utilizada en las pruebas finales de la V2 y la V3. 
Ayudandome del log de la V2 y V3, queria probar si la V4 tambien funcionaba bien con programas de usuario y hacia los cambios entre programas correctamente.
- ./Simulator pruebas-V2-NoPrioridad 3 y ./Simulator pruebas-V2-Overflow 2 ---> Estas pruebas se utilizaron para ver si se corrigieron algunos errores arrastrados 
desde la V2.En la primera entrada se le pasa un programa con solo peso (anteriormente el simulador quedaba en bucle infinito) y en la segunda linea se le pasa un programa 
donde forzosamente se produce Overflow con la instrucción MEMADD (que antes no se controlaba). Se les pasa el instante 3 y 2 para ver el correcto funcionamiento del simulador
cuando aún hay programas que se ejecutarán en un futuro.
- Se utlizaron los programas progV4-2, progV4-3 y progV4-4 para probar si saltan correctamente determinado tipo de excepciones. El primero causa una excepción por intentar ejecutar 
una instrucción privilegiada en modo usuario, el segundo causa una excepción por tener una instrucción que no existe en nuestro juego de instrucciones y finalmente el tercero causa
una excepción por realizar una llamada al sistema no válida. 

Las pruebas mencionadas anteriormente son las que más se tuvieron en cuenta, las pruebas no mencionadas son los mismos programas pero cambiando el orden y los instantes 
de llegada.


MODIFICACIONES REALIZADAS 

En esta última entrega se corrigieron errores arrastrados de la V2: 
- Control del Overflow de la instruccion MEMADDD. (Processor.c)
- Se solucionó el problema del bucle infinito al pasarle un programa con solo tamaño. (OperatingSystem.c)
- Ahora se coge el "intervalBetweenInterrupts" en vez de el valor por defecto directamente. (Clock.c)  
- Se modificó la función "OperatingSystem_SYSCALL_YIELD()" que manejaba la llamada al siteama TRAP 4. Esto debido a que de la forma en la que estaba implementada daba lugar 
a errores en la V4. (OperatingSystem.c)
- Se modificó la función "OperatingSystem_MaxProirity()" ya que daba errores en esta nueva versión del simulador. (OperatingSystem.c)

* Los dos puntos anteriores se lograron corregir gracias a la función dada "Heap_getFirst"


Los cabios realizados referentes a la V4 respecto a la anterior entrega parcial, son basicamente cambios en el orden de los mensajes y cambios en la MMU (para control de errores). 
También se corrigieron algunos mensajes con espacios o carácteres de más. 
 