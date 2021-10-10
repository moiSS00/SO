#include "OperatingSystem.h"
#include "OperatingSystemBase.h"
#include "MMU.h"
#include "Processor.h"
#include "Buses.h"
#include "Heap.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

// Functions prototypes
void OperatingSystem_PrepareDaemons();
void OperatingSystem_PCBInitialization(int, int, int, int, int);
void OperatingSystem_MoveToTheREADYState(int);
void OperatingSystem_Dispatch(int);
void OperatingSystem_RestoreContext(int);
void OperatingSystem_SaveContext(int);
void OperatingSystem_TerminateProcess();
int OperatingSystem_LongTermScheduler();
void OperatingSystem_PreemptRunningProcess();
int OperatingSystem_CreateProcess(int);
int OperatingSystem_ObtainMainMemory(int, int,int); //[MOISES V4] EJ 6
int OperatingSystem_ShortTermScheduler();
int OperatingSystem_ExtractFromReadyToRun();
void OperatingSystem_HandleException();
void OperatingSystem_HandleSystemCall();
void OperatingSystem_PrintReadyToRunQueue(); //[MOISES V1] EJ 9
void OperatingSystem_SYSCALL_YIELD(); //Maneja la llamada al sistema "syscall_yield"
void OperatingSystem_HandleClockInterrupt(); //[MOISES V2] EJ 2 
void OperatingSystem_SYSCALL_SLEEP(); //Maneja la llamada al sistema "syscall_sleep"
void OperatingSystem_MoveToTheBLOCKEDState(int); //Mueve al estado bloqueado [MOISES V2] EJ 5 
void OperatingSystem_ExtractFromSleepingProcessesQueue(); //Extrae un proceso de la cola de dormidos  [MOISES V2] EJ 5
int OperatingSystem_MaxProirity(); //Devuelve el pid del proceso con mas prioridad [MOISES V2] EJ 6 
void OperatingSystem_ErrorCreateProcess(int,int);
void OperatingSystem_ShutdownCheck(); //[MOISES V3] EJ 4
void OperatingSystem_ReleaseMainMemory(); //[MOISES V4] EJ 8 

// The process table
PCB processTable[PROCESSTABLEMAXSIZE];

// Address base for OS code in this version
int OS_address_base = PROCESSTABLEMAXSIZE * MAINMEMORYSECTIONSIZE;

// Identifier of the current executing process
int executingProcessID=NOPROCESS;

// Identifier of the System Idle Process
int sipID;

//[MOISES V1] EJ 8 
// Initial PID for assignation
int initialPID=PROCESSTABLEMAXSIZE - 1;

// Begin indes for daemons in programList
int baseDaemonsInProgramList; 

//[MOISES V1] EJ 11
// Array that contains the identifiers of the READY processes
heapItem readyToRunQueue[NUMBEROFQUEUES][PROCESSTABLEMAXSIZE];
int numberOfReadyToRunProcesses[NUMBEROFQUEUES] = { 0,0 };

//[MOISES V2] EJ 5
// Heap with blocked processes sort by when to wakeup 
heapItem sleepingProcessesQueue[PROCESSTABLEMAXSIZE]; 
int numberOfSleepingProcesses=0;

// Variable containing the number of not terminated user processes
int numberOfNotTerminatedUserProcesses=0;

//[MOISES V1] EJ 10 
//Estados para el ejercicio 10 de la V1. 
char* statesNames[5] = { "NEW","READY","EXECUTING","BLOCKED","EXIT" };

//Ejercicio 11 de la V1 
char* queueNames[NUMBEROFQUEUES] = { "USER","DAEMONS" };

//Ejercicio 4 de la V2
int  numberOfClockInterrupts = 0; //Variable contador de las interrupciones de reloj.

//Ejercicio 6 de la V4 
int numberMemoryPartitions = 0; 

// Initial set of tasks of the OS
void OperatingSystem_Initialize(int daemonsIndex) {
	
	int i, selectedProcess;
	FILE *programFile; // For load Operating System Code

	// Obtain the memory requirements of the program
	int processSize=OperatingSystem_ObtainProgramSize(&programFile, "OperatingSystemCode");

	// Load Operating System Code
	OperatingSystem_LoadProgram(programFile, OS_address_base, processSize);
	
	// Process table initialization (all entries are free)
	for (i=0; i<PROCESSTABLEMAXSIZE;i++){
		processTable[i].busy=0;
	}
	// Initialization of the interrupt vector table of the processor
	Processor_InitializeInterruptVectorTable(OS_address_base+2);

	//[MOISES V4] EJ 5 
	numberMemoryPartitions = OperatingSystem_InitializePartitionTable(); //Inicializamos particiones y obtenemos el numero de particiones 
		
	// Include in program list  all system daemon processes
	OperatingSystem_PrepareDaemons(daemonsIndex);
	
	// Create all user processes from the information given in the command line
	ComputerSystem_FillInArrivalTimeQueue(); //[MOISES V3] EJ 0  
	OperatingSystem_PrintStatus();
	int process = OperatingSystem_LongTermScheduler();
	if (process == 1) { //[MOISES V3] EJ 4
		OperatingSystem_ShutdownCheck(); 
	}

	
	
	
	if (strcmp(programList[processTable[sipID].programListIndex]->executableName,"SystemIdleProcess")) {
		// Show red message "FATAL ERROR: Missing SIP program!\n"
		OperatingSystem_ShowTime(SHUTDOWN);
		ComputerSystem_DebugMessage(99,SHUTDOWN,"FATAL ERROR: Missing SIP program!\n");
		exit(1);		
	}

	// At least, one user process has been created
	// Select the first process that is going to use the processor
	selectedProcess=OperatingSystem_ShortTermScheduler();

	// Assign the processor to the selected process
	OperatingSystem_Dispatch(selectedProcess);

	// Initial operation for Operating System
	Processor_SetPC(OS_address_base);
}

// Daemon processes are system processes, that is, they work together with the OS.
// The System Idle Process uses the CPU whenever a user process is able to use it
void OperatingSystem_PrepareDaemons(int programListDaemonsBase) {
  
	// Include a entry for SystemIdleProcess at 0 position
	programList[0]=(PROGRAMS_DATA *) malloc(sizeof(PROGRAMS_DATA));
	programList[0]->executableName="SystemIdleProcess";
	programList[0]->arrivalTime=0;
	programList[0]->type=DAEMONPROGRAM; // daemon program

	sipID=initialPID%PROCESSTABLEMAXSIZE; // first PID for sipID

	// Prepare aditionals daemons here
	// index for aditionals daemons program in programList
	baseDaemonsInProgramList=programListDaemonsBase;

}


// The LTS is responsible of the admission of new processes in the system.
// Initially, it creates a process from each program specified in the 
// 			command lineand daemons programs
int OperatingSystem_LongTermScheduler() {
  
	int PID, i,
		numberOfSuccessfullyCreatedProcesses=0;

	int newProgram = OperatingSystem_IsThereANewProgram(); 

	while (newProgram == YES) //[MOISES V3] EJ 2 
	{
		//for (i = 0; programList[i] != NULL && i < PROGRAMSMAXNUMBER; i++) {
		i = Heap_poll(arrivalTimeQueue,QUEUE_ARRIVAL,&numberOfProgramsInArrivalTimeQueue);
		PID = OperatingSystem_CreateProcess(i);
		if (PID < 0) {
			OperatingSystem_ErrorCreateProcess(PID,i);
		}
		else if (processTable[PID].state != READY) {
			numberOfSuccessfullyCreatedProcesses++;
			if (programList[i]->type == USERPROGRAM)
				numberOfNotTerminatedUserProcesses++;
			// Move process to the ready state
			OperatingSystem_MoveToTheREADYState(PID);
		}

		newProgram = OperatingSystem_IsThereANewProgram(); 
	}
	

	if (numberOfSuccessfullyCreatedProcesses > 0) {
		OperatingSystem_PrintStatus();
	}

	// Return the number of succesfully created processes
	return numberOfSuccessfullyCreatedProcesses;
}


// This function creates a process from an executable program
int OperatingSystem_CreateProcess(int indexOfExecutableProgram) {
  
	int PID;
	int processSize;
	int loadingPhysicalAddress;
	int priority;
	FILE *programFile;
	PROGRAMS_DATA *executableProgram=programList[indexOfExecutableProgram];

	//[MOISES V1] EJ 4,5,6,7
	// Obtain a process ID
	PID = OperatingSystem_ObtainAnEntryInTheProcessTable(); //Si no hay entradas libres 
	if (PID == NOFREEENTRY) { 
		return NOFREEENTRY;
	}

	// Obtain the memory requirements of the program
	processSize=OperatingSystem_ObtainProgramSize(&programFile, executableProgram->executableName);	
	if (processSize == PROGRAMDOESNOTEXIST) { //Si el programa no existe 
		return PROGRAMDOESNOTEXIST;
	}
	else if (processSize == PROGRAMNOTVALID) { //Si el programa tiene un tamaño incorrecto 
		return PROGRAMNOTVALID;
	}

	// Obtain the priority for the process
	priority=OperatingSystem_ObtainPriority(programFile); //Si el programa tiene una prioridad incorrecta 
	if (priority == PROGRAMNOTVALID) {
		return PROGRAMNOTVALID;
	}

	//[MOISES V4] EJ 6 
	// Obtain enough memory space
	int partition = OperatingSystem_ObtainMainMemory(processSize, PID, indexOfExecutableProgram); 
	if (partition < 0) { //Si no se encontro particion 
		return partition; //Se devuelve el error correspondiente 
	}
	OperatingSystem_ShowPartitionTable("before allocating memory"); //Imprimimos la tabla de particiones antes de asignarle una particion al proceso  //[MOISES V4] EJ 7 
	partitionsTable[partition].PID = PID; //Si se encontro una particion, la asignamos al proceso
	loadingPhysicalAddress = partitionsTable[partition].initAddress;  //Cargarmos direccion fisica 
	
	// Load program in the allocated memory
	if ((OperatingSystem_LoadProgram(programFile, loadingPhysicalAddress, processSize)) == TOOBIGPROCESS) {
		return TOOBIGPROCESS;
	}
	
	//Mensaje informativo sobre la particion asignada al proceso 
	OperatingSystem_ShowTime(SYSMEM);
	ComputerSystem_DebugMessage(143, SYSMEM, partition, loadingPhysicalAddress, partitionsTable[partition].size, PID, programList[indexOfExecutableProgram]->executableName);

	// PCB initialization
	OperatingSystem_PCBInitialization(PID, loadingPhysicalAddress, processSize, priority, indexOfExecutableProgram);

	OperatingSystem_ShowPartitionTable("after allocating memory"); //Imrime la tabla de particiones despues de la asignacion de la particion a un proceso //[MOISES V4] EJ 7
	
	// Show message "Process [PID] created from program [executableName]\n"
	OperatingSystem_ShowTime(INIT);
	ComputerSystem_DebugMessage(70,INIT,PID,executableProgram->executableName);
	
	return PID;
}


//[MOISES V4] EJ 6 
// Main memory is assigned in chunks. All chunks are the same size. A process
// always obtains the chunk whose position in memory is equal to the processor identifier
int OperatingSystem_ObtainMainMemory(int processSize, int PID, int indexOfExecutableProgram) {

 	//if (processSize>MAINMEMORYSECTIONSIZE)
	//	return TOOBIGPROCESS;

	//Imprime mensaje de solicitud de memoria
	OperatingSystem_ShowTime(SYSMEM); 
	ComputerSystem_DebugMessage(142, SYSMEM, PID, programList[indexOfExecutableProgram]->executableName,processSize);

	int i; //Indice del bucle 
	int bestPartition = -1; //Numero de particion encontrada
	int error = MEMORYFULL; //Variable auxiliar para guardar posible error 
	for (i = 0; i < numberMemoryPartitions; i++) { //Recorremos la tabla de particiones 
		if (partitionsTable[i].PID == NOPROCESS) { //Si esta libre 
			error = TOOBIGPROCESS; //Actualizamos el posible error 
			if (partitionsTable[i].size >= processSize) { //Si el proceso cabe 
				if ((bestPartition == -1) || partitionsTable[bestPartition].size > partitionsTable[i].size) { //Si es la primera encontrada o es mejor (menos fragmentacion interna) que la encontrada anteriormente
					bestPartition = i; //Guardamos indice particion
				}
			}
		}
	}

	//Si no se encontro particion 
	if (bestPartition == -1) {
		return error; //Se devuelve el error correspondiente
	}

	
 	//return PID*MAINMEMORYSECTIONSIZE;
	return bestPartition; //Ahora se devuelve el numero de particion asignada 
}


// Assign initial values to all fields inside the PCB
void OperatingSystem_PCBInitialization(int PID, int initialPhysicalAddress, int processSize, int priority, int processPLIndex) {

	processTable[PID].busy=1;
	processTable[PID].initialPhysicalAddress=initialPhysicalAddress;
	processTable[PID].processSize=processSize;
	
	processTable[PID].state=NEW;
	processTable[PID].priority=priority;
	processTable[PID].programListIndex=processPLIndex;
	//[MOISES V1] EJ 10
	// Daemons run in protected mode and MMU use real address
	if (programList[processPLIndex]->type == DAEMONPROGRAM) {
		processTable[PID].copyOfPCRegister=initialPhysicalAddress;
		processTable[PID].copyOfPSWRegister= ((unsigned int) 1) << EXECUTION_MODE_BIT;
		processTable[PID].queueID = DAEMONSQUEUE;
	} 
	else {
		processTable[PID].queueID = USERPROCESSQUEUE;
		processTable[PID].copyOfPCRegister=0;
		processTable[PID].copyOfPSWRegister=0;
	}

	//[MOISES V1] EJ 10
	OperatingSystem_ShowTime(SYSPROC);
	ComputerSystem_DebugMessage(111, SYSPROC, PID, programList[processTable[PID].programListIndex]->executableName, statesNames[0]);

}


// Move a process to the READY state: it will be inserted, depending on its priority, in
// a queue of identifiers of READY processes
void OperatingSystem_MoveToTheREADYState(int PID) {
	
	int queueID = processTable[PID].queueID;
	if (Heap_add(PID, readyToRunQueue[queueID],QUEUE_PRIORITY ,&numberOfReadyToRunProcesses[queueID] ,PROCESSTABLEMAXSIZE)>=0) {
		//[MOISES V1] EJ 10
		OperatingSystem_ShowTime(SYSPROC);
		ComputerSystem_DebugMessage(110, SYSPROC, PID, programList[processTable[PID].programListIndex]->executableName, statesNames[processTable[PID].state], statesNames[1]);
		processTable[PID].state=READY;
	} 
	
	//OperatingSystem_PrintReadyToRunQueue();
}


// The STS is responsible of deciding which process to execute when specific events occur.
// It uses processes priorities to make the decission. Given that the READY queue is ordered
// depending on processes priority, the STS just selects the process in front of the READY queue
int OperatingSystem_ShortTermScheduler() {
	
	int selectedProcess;

	selectedProcess=OperatingSystem_ExtractFromReadyToRun();
	
	return selectedProcess;
}


// Return PID of more priority process in the READY queue
int OperatingSystem_ExtractFromReadyToRun() {
  
	int selectedProcess=NOPROCESS;

	selectedProcess=Heap_poll(readyToRunQueue[USERPROCESSQUEUE],QUEUE_PRIORITY ,&numberOfReadyToRunProcesses[USERPROCESSQUEUE]);

	if (selectedProcess == NOPROCESS) {
		selectedProcess = Heap_poll(readyToRunQueue[DAEMONSQUEUE], QUEUE_PRIORITY, &numberOfReadyToRunProcesses[DAEMONSQUEUE]);
	}
	
	// Return most priority process or NOPROCESS if empty queue
	return selectedProcess; 
}


// Function that assigns the processor to a process
void OperatingSystem_Dispatch(int PID) {

	// The process identified by PID becomes the current executing process
	executingProcessID=PID;
	// Change the process' state
	processTable[PID].state=EXECUTING;
	//[MOISES V1] EJ 10
	OperatingSystem_ShowTime(SYSPROC);
	ComputerSystem_DebugMessage(110, SYSPROC,PID, programList[processTable[PID].programListIndex]->executableName,statesNames[1],statesNames[2]);
	// Modify hardware registers with appropriate values for the process identified by PID
	OperatingSystem_RestoreContext(PID);
}


// Modify hardware registers with appropriate values for the process identified by PID
void OperatingSystem_RestoreContext(int PID) {
  
	// New values for the CPU registers are obtained from the PCB
	Processor_CopyInSystemStack(MAINMEMORYSIZE-1,processTable[PID].copyOfPCRegister);
	Processor_CopyInSystemStack(MAINMEMORYSIZE-2,processTable[PID].copyOfPSWRegister);
	
	// Same thing for the MMU registers
	MMU_SetBase(processTable[PID].initialPhysicalAddress);
	MMU_SetLimit(processTable[PID].processSize);

	Processor_SetAccumulator(processTable[PID].copyOfRegisterAccumulator);
}


// Function invoked when the executing process leaves the CPU 
void OperatingSystem_PreemptRunningProcess() {

	// Save in the process' PCB essential values stored in hardware registers and the system stack
	OperatingSystem_SaveContext(executingProcessID);
	// Change the process' state
	OperatingSystem_MoveToTheREADYState(executingProcessID);
	// The processor is not assigned until the OS selects another process
	executingProcessID=NOPROCESS;
}


// Save in the process' PCB essential values stored in hardware registers and the system stack
void OperatingSystem_SaveContext(int PID) {
	
	// Load PC saved for interrupt manager
	processTable[PID].copyOfPCRegister=Processor_CopyFromSystemStack(MAINMEMORYSIZE-1);
	
	// Load PSW saved for interrupt manager
	processTable[PID].copyOfPSWRegister=Processor_CopyFromSystemStack(MAINMEMORYSIZE-2);

	processTable[PID].copyOfRegisterAccumulator = Processor_GetAccumulator();
	
}


//[MOISES V4] EJ 2 
// Exception management routine
void OperatingSystem_HandleException() {

	int type = Processor_GetRegisterB(); 

	if (type == INVALIDADDRESS) {
		OperatingSystem_ShowTime(INTERRUPT);
		ComputerSystem_DebugMessage(140, INTERRUPT, executingProcessID, programList[processTable[executingProcessID].programListIndex]->executableName,"invalid address");
	}
	if (type == INVALIDPROCESSORMODE) {
		OperatingSystem_ShowTime(INTERRUPT);
		ComputerSystem_DebugMessage(140, INTERRUPT, executingProcessID, programList[processTable[executingProcessID].programListIndex]->executableName, "invalid processor mode");
	}
	if (type == DIVISIONBYZERO) {
		OperatingSystem_ShowTime(INTERRUPT);
		ComputerSystem_DebugMessage(140, INTERRUPT, executingProcessID, programList[processTable[executingProcessID].programListIndex]->executableName, "division by zero");
	}
	if (type == INVALIDINSTRUCTION) {
		OperatingSystem_ShowTime(INTERRUPT);
		ComputerSystem_DebugMessage(140, INTERRUPT, executingProcessID, programList[processTable[executingProcessID].programListIndex]->executableName, "invalid instruction");
	}

	// Show message "Process [executingProcessID] has generated an exception and is terminating\n"
	//OperatingSystem_ShowTime(SYSPROC);
	//ComputerSystem_DebugMessage(71,SYSPROC,executingProcessID,programList[processTable[executingProcessID].programListIndex]->executableName);
	
	OperatingSystem_TerminateProcess();
	OperatingSystem_PrintStatus();
}


// All tasks regarding the removal of the process
void OperatingSystem_TerminateProcess() {
  
	int selectedProcess;
  	
	processTable[executingProcessID].state=EXIT;

	//[MOISES V1] EJ 10
	OperatingSystem_ShowTime(SYSPROC);
	ComputerSystem_DebugMessage(110, SYSPROC,executingProcessID, programList[processTable[executingProcessID].programListIndex]->executableName,statesNames[2],statesNames[4]);
	OperatingSystem_ReleaseMainMemory();

	if (programList[processTable[executingProcessID].programListIndex]->type==USERPROGRAM) 
		// One more user process that has terminated
		numberOfNotTerminatedUserProcesses--;

	if ((numberOfNotTerminatedUserProcesses==0) && (numberOfProgramsInArrivalTimeQueue == 0)) {
		if (executingProcessID==sipID) {
			// finishing sipID, change PC to address of OS HALT instruction
			OperatingSystem_TerminatingSIP();
			OperatingSystem_ShowTime(SHUTDOWN);
			ComputerSystem_DebugMessage(99,SHUTDOWN,"The system will shut down now...\n");
			return; // Don't dispatch any process
		}
		// Simulation must finish, telling sipID to finish
		OperatingSystem_ReadyToShutdown(); 
	}

	//[MOISES V3] EJ 4 
	OperatingSystem_ShutdownCheck(); 

	// Select the next process to execute (sipID if no more user processes)
	selectedProcess=OperatingSystem_ShortTermScheduler();

	// Assign the processor to that process
	if (selectedProcess != NOPROCESS) {
		OperatingSystem_Dispatch(selectedProcess);
	}
	
}

// System call management routine
void OperatingSystem_HandleSystemCall() {
  
	int systemCallID;

	// Register A contains the identifier of the issued system call
	systemCallID=Processor_GetRegisterA();
	
	switch (systemCallID) {
		case SYSCALL_PRINTEXECPID:
			// Show message: "Process [executingProcessID] has the processor assigned\n"
			OperatingSystem_ShowTime(SYSPROC);
			ComputerSystem_DebugMessage(72,SYSPROC,executingProcessID,programList[processTable[executingProcessID].programListIndex]->executableName);
			break;

		case SYSCALL_END:
			// Show message: "Process [executingProcessID] has requested to terminate\n"
			OperatingSystem_ShowTime(SYSPROC);
			ComputerSystem_DebugMessage(73,SYSPROC,executingProcessID,programList[processTable[executingProcessID].programListIndex]->executableName);
			OperatingSystem_TerminateProcess();
			OperatingSystem_PrintStatus();
			break;

		case SYSCALL_YIELD: //Transfer 
			OperatingSystem_SYSCALL_YIELD();
			break;

		case SYSCALL_SLEEP: //Thrown 
			OperatingSystem_SYSCALL_SLEEP();
			OperatingSystem_PrintStatus();
			break; 

		default:
			//[MOISES V4] EJ 4 
			OperatingSystem_ShowTime(INTERRUPT);
			ComputerSystem_DebugMessage(141, INTERRUPT, executingProcessID, programList[processTable[executingProcessID].programListIndex]->executableName,systemCallID);
			OperatingSystem_TerminateProcess();
			OperatingSystem_PrintStatus(); 
			break;
	}
}

	
//	Implement interrupt logic calling appropriate interrupt handle
void OperatingSystem_InterruptLogic(int entryPoint){
	switch (entryPoint){
		case SYSCALL_BIT: // SYSCALL_BIT=2
			OperatingSystem_HandleSystemCall();
			break;
		case EXCEPTION_BIT: // EXCEPTION_BIT=6
			OperatingSystem_HandleException();
			break;
		case CLOCKINT_BIT: // CLOCKINT_BIT=9
			OperatingSystem_HandleClockInterrupt();
			break; 
	}

}

//FUNCIONES PROPIAS 

//[MOISES V2] EJ 12 
void  OperatingSystem_SYSCALL_YIELD() {

	int actualPID = executingProcessID;
	int queueID = processTable[actualPID].queueID;
	int priority = processTable[actualPID].priority;
	int newProcess = Heap_getFirst(readyToRunQueue[queueID],numberOfReadyToRunProcesses[queueID]);
	
	
	if (newProcess > NOPROCESS) {
		if (priority == processTable[newProcess].priority && newProcess != actualPID) {
			Heap_poll(readyToRunQueue[queueID], QUEUE_PRIORITY, &numberOfReadyToRunProcesses[queueID]); 
			OperatingSystem_ShowTime(SHORTTERMSCHEDULE);
			ComputerSystem_DebugMessage(115, SHORTTERMSCHEDULE, actualPID, programList[processTable[actualPID].programListIndex]->executableName, newProcess, programList[processTable[newProcess].programListIndex]->executableName);
			OperatingSystem_PreemptRunningProcess();
			OperatingSystem_Dispatch(newProcess);
			OperatingSystem_PrintStatus(); //Ej 7 de la V2
		}
		
	}

	
	
}


//[MOISES V1] EJ 9 Y 11
void  OperatingSystem_PrintReadyToRunQueue() {
	
	OperatingSystem_ShowTime(SHORTTERMSCHEDULE);
	ComputerSystem_DebugMessage(112, SHORTTERMSCHEDULE);
	int i; 
	int j; 

	for (i = 0; i < NUMBEROFQUEUES; i++) { //Recorre las dos colas 
		ComputerSystem_DebugMessage(113, SHORTTERMSCHEDULE, queueNames[i]);
		for (j = 0; j < numberOfReadyToRunProcesses[i]; j++) { //Recorre los procesos EXISTENTES de cada cola. 
			int PID = readyToRunQueue[i][j].info;
			if (j == (numberOfReadyToRunProcesses[i] - 1)) { //Si es el ultimo 
				ComputerSystem_DebugMessage(108,SHORTTERMSCHEDULE,PID,processTable[PID].priority,"");
			}
			else { //Si no es el ultimo 
				ComputerSystem_DebugMessage(108, SHORTTERMSCHEDULE, PID, processTable[PID].priority, ",");
			}
		}
		ComputerSystem_DebugMessage(109, SHORTTERMSCHEDULE);
	}
}


//[MOISES V2] EJ 2
void OperatingSystem_HandleClockInterrupt() {
	numberOfClockInterrupts = numberOfClockInterrupts + 1; //Se incrementan las interrupciones 
	OperatingSystem_ShowTime(INTERRUPT); //Se imprime mensaje de numero de interrupcion 
	ComputerSystem_DebugMessage(120,INTERRUPT,numberOfClockInterrupts); //[MOISES V2] EJ 4
	

	//[MOISES V2] EJ 6
	int i;
	int actualSleep = numberOfSleepingProcesses; //Almacena numero actual de procesos dormidos 
	for (i = 0; i < actualSleep; i++) { //Recorre la cola de procesos dormidos 
		if (numberOfClockInterrupts == processTable[sleepingProcessesQueue[i].info].whenToWakeUp) { //Si whenToWakeUp coincide con el numero de interrupciones de reloj 
			OperatingSystem_ExtractFromSleepingProcessesQueue(); //Se extrae de la cola de dormidos 
		}
	}

	int process = OperatingSystem_LongTermScheduler(); //[MOISES V3] EJ 3

	//[MOISES V3] EJ 4
	OperatingSystem_ShutdownCheck();

	if (process > 0 && actualSleep != numberOfSleepingProcesses) { //Si se modificó la cola de dormidos, se imprime el estado del simulador 
		OperatingSystem_PrintStatus();
	}

	if (actualSleep != numberOfSleepingProcesses || process > 0) {
		int newProcess = OperatingSystem_MaxProirity(); //Obtenemos el proceso de mayor prioridad 
		if (newProcess != NOPROCESS) { //Si hay 
			OperatingSystem_ShowTime(SHORTTERMSCHEDULE); //Se imprime el mensaje 
			ComputerSystem_DebugMessage(121, SHORTTERMSCHEDULE, executingProcessID, programList[processTable[executingProcessID].programListIndex]->executableName, newProcess, programList[processTable[newProcess].programListIndex]->executableName);
			OperatingSystem_PreemptRunningProcess(); //Se abandona el proceso actual
			OperatingSystem_ExtractFromReadyToRun(); //El proceso mas prioritario abandona la cola de listos  
			OperatingSystem_Dispatch(newProcess); //Se ejecuta el nuevo proceso 
			OperatingSystem_PrintStatus(); //Se imprime el estado del simulador 
		}
	}
	
}


//[MOISES V2] EJ 5
void OperatingSystem_ExtractFromSleepingProcessesQueue() {
	//numberOfSleepingProcesses--; //Se decrementa el numero de procesos dormidos
	int PID = Heap_poll(sleepingProcessesQueue,QUEUE_WAKEUP,&numberOfSleepingProcesses); //Extrae el proceso 
	if (PID != NOPROCESS) { //Si lo extrae correctamente 
		OperatingSystem_MoveToTheREADYState(PID); //Se mueve el proceso a la lista de listos.
		OperatingSystem_PrintStatus();
	}
}

void OperatingSystem_SYSCALL_SLEEP() {

	int PID = executingProcessID; //Guarda el PID del proceso que se est� ejecutando 
	processTable[PID].whenToWakeUp = abs(Processor_GetAccumulator()) + numberOfClockInterrupts + 1; //Calcula el valor de la variable del PCB "whenToWakeUp"
	OperatingSystem_SaveContext(PID); //Guarda el contenido de los registros del procesador 
	OperatingSystem_MoveToTheBLOCKEDState(PID); //Mueve a la cola de bloqueados el proceso 
	executingProcessID = NOPROCESS;
	int newProcess = OperatingSystem_ShortTermScheduler(); //Extrae el siguiente proceso a ejecutar de la cola de listos
	if (newProcess != NOPROCESS) { //Si hab�a procesos en la cola de listos 
		OperatingSystem_Dispatch(newProcess); // Pasa el nuevo proceso a ejecutarse
	}
}

//[MOISES V2] EJ 5
void OperatingSystem_MoveToTheBLOCKEDState(int PID) {


	int previousState = processTable[PID].state; //Gaurda el anterior estado del proceso 

	if (Heap_add(PID, sleepingProcessesQueue, QUEUE_WAKEUP, &numberOfSleepingProcesses, PROGRAMSMAXNUMBER) >= 0) { //Se a�ade a la cola de procesos bloqueados/dormidos sin errrores 
		processTable[PID].state = BLOCKED; //Actualiza el estado del proceso
		OperatingSystem_ShowTime(SYSPROC); //Se imprime el mensaje de cambio de estado 
		ComputerSystem_DebugMessage(110, SYSPROC, PID, programList[processTable[PID].programListIndex]->executableName, statesNames[previousState], statesNames[BLOCKED]);
	}


}


//[MOISES V2] EJ 6
int OperatingSystem_MaxProirity() {
	int queueID = processTable[executingProcessID].queueID; //Cola del proceso actual 
	int priority = processTable[executingProcessID].priority; //Prioridad del proceso actual 
	int newProcess = Heap_getFirst(readyToRunQueue[USERPROCESSQUEUE],numberOfReadyToRunProcesses[USERPROCESSQUEUE]);
	if (newProcess == NOPROCESS) {
		newProcess = Heap_getFirst(readyToRunQueue[DAEMONSQUEUE], numberOfReadyToRunProcesses[DAEMONSQUEUE]);
	}

	if (newProcess != NOPROCESS) { //Si hay 
		if (queueID == processTable[newProcess].queueID) { //Si pertenecen a la misma cola 
			if (processTable[newProcess].priority >= priority) { //Se comparan por prioridad 
				return NOPROCESS;
			}
			return newProcess;
		}
		else if ((queueID == USERPROCESSQUEUE) && (processTable[newProcess].queueID == DAEMONSQUEUE)) { //Si se esta ejecutando un usuario y quiere entrar un deamon 
			return NOPROCESS;
		}
		else { //Si se esta ejecutando un deamon y quiere entrar un usuario 
			return newProcess;
		}
	}

	return newProcess;
	
}

int OperatingSystem_GetExecutingProcessID() {
	return executingProcessID;
}

//[MOISES V1] EJ 4,5,6,7
void OperatingSystem_ErrorCreateProcess(int PID,int i) {
	if (PID == NOFREEENTRY) {
		OperatingSystem_ShowTime(ERROR);
		ComputerSystem_DebugMessage(103, ERROR, programList[i]->executableName);
	}
	if (PID == PROGRAMDOESNOTEXIST) {
		OperatingSystem_ShowTime(ERROR);
		ComputerSystem_DebugMessage(104, ERROR, programList[i]->executableName, "it does not exist");
	}
	if (PID == PROGRAMNOTVALID) {
		OperatingSystem_ShowTime(ERROR);
		ComputerSystem_DebugMessage(104, ERROR, programList[i]->executableName, "invalid priority or size");
	}
	if (PID == TOOBIGPROCESS) {
		OperatingSystem_ShowTime(ERROR);
		ComputerSystem_DebugMessage(105, ERROR, programList[i]->executableName);
	}
	if (PID == MEMORYFULL) {
		OperatingSystem_ShowTime(ERROR);  
		ComputerSystem_DebugMessage(144, ERROR, programList[i]->executableName);
	}
}

//[MOISES V3] EJ 4 
void OperatingSystem_ShutdownCheck() {
	if (numberOfNotTerminatedUserProcesses <= 0 && numberOfProgramsInArrivalTimeQueue <= 0) { //Si no hay ningun proceso que ejecutar 
		OperatingSystem_ReadyToShutdown(); 
	}
}

//[MOISES V4] EJ 8 
void OperatingSystem_ReleaseMainMemory() {

	OperatingSystem_ShowPartitionTable("before releasing memory"); //Imprime la tabla de memoria antes de borrar 
	int i; //Indice del bucle 
	int nParticion; //Variable auxiliar que amacena el numero de particion a borrar


	for (i = 0; i < numberMemoryPartitions;i++) { //Recorremos las particiones
		if (partitionsTable[i].PID == executingProcessID) { //Encontramos la particion actual 
			partitionsTable[i].PID = NOPROCESS; //La liberamos 
			nParticion = i;  //Almacenamos el numero de particion 
		}
	}

	OperatingSystem_ShowTime(SYSMEM); //Imprimirmos mensaje de particion liberada 
	ComputerSystem_DebugMessage(145, SYSMEM, nParticion,partitionsTable[nParticion].initAddress, partitionsTable[nParticion].size,executingProcessID, programList[processTable[executingProcessID].programListIndex]->executableName);
	OperatingSystem_ShowPartitionTable("after releasing memory"); //Volvemos a imprimir la tabla de particiones despues del borrado 
}