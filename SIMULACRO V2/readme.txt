Código cambiado: 


En OperatingSystem.h 
// A PCB contains all of the information about a process that is needed by the OS
typedef struct {
	int busy;
	int initialPhysicalAddress;
	int processSize;
	int state;
	int priority;
	int copyOfPCRegister;
	unsigned int copyOfPSWRegister;
	int copyOfRegisterAccumulator;
	int programListIndex;
	int queueID;
	int whenToWakeUp;  // Exercise 5-a of V2
	// Examen-simulacro-2020 
	int createTime; 
	int firstExecution; 
	int enterReady; 
	int readyTime; 
} PCB;


En OperatingSystem.c 

void OperatingSystem_MoveToTheREADYState(int PID) {
	
	int queueID = processTable[PID].queueID;
	if (Heap_add(PID, readyToRunQueue[queueID],QUEUE_PRIORITY ,&numberOfReadyToRunProcesses[queueID] ,PROCESSTABLEMAXSIZE)>=0) {
		OperatingSystem_ShowTime(SYSPROC);
		ComputerSystem_DebugMessage(110, SYSPROC, PID, programList[processTable[PID].programListIndex]->executableName, statesNames[processTable[PID].state], statesNames[1]);
		processTable[PID].state=READY;
		processTable[PID].enterReady = Clock_GetTime(); // Examen-simulacro-2020 
	} 
	
	//OperatingSystem_PrintReadyToRunQueue();
}


// Assign initial values to all fields inside the PCB
void OperatingSystem_PCBInitialization(int PID, int initialPhysicalAddress, int processSize, int priority, int processPLIndex) {

	processTable[PID].busy=1;
	processTable[PID].initialPhysicalAddress=initialPhysicalAddress;
	processTable[PID].processSize=processSize;
	
	processTable[PID].state=NEW;
	processTable[PID].priority=priority;
	processTable[PID].programListIndex=processPLIndex;

	// Examen-simulacro-2020 
	processTable[PID].createTime = Clock_GetTime(); 
	processTable[PID].firstExecution = -1; 

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

	OperatingSystem_ShowTime(SYSPROC);
	ComputerSystem_DebugMessage(111, SYSPROC, PID, programList[processTable[PID].programListIndex]->executableName, statesNames[0]);

}


// Function that assigns the processor to a process
void OperatingSystem_Dispatch(int PID) {

	// The process identified by PID becomes the current executing process
	executingProcessID=PID;
	// Change the process' state
	processTable[PID].state=EXECUTING;
	OperatingSystem_ShowTime(SYSPROC);
	ComputerSystem_DebugMessage(110, SYSPROC,PID, programList[processTable[PID].programListIndex]->executableName,statesNames[1],statesNames[2]);
	// Modify hardware registers with appropriate values for the process identified by PID
	OperatingSystem_RestoreContext(PID);

	// Examen-simulacro-2020 
	if (processTable[PID].firstExecution == -1) {
		processTable[PID].firstExecution = Clock_GetTime(); 
	}
	processTable[PID].readyTime += Clock_GetTime() - processTable[PID].enterReady;
	
}



// All tasks regarding the removal of the process
void OperatingSystem_TerminateProcess() {
  
	int selectedProcess;
  	
	processTable[executingProcessID].state=EXIT;
	
	OperatingSystem_ShowTime(SYSPROC);
	ComputerSystem_DebugMessage(110, SYSPROC,executingProcessID, programList[processTable[executingProcessID].programListIndex]->executableName,statesNames[2],statesNames[4]);


	if (programList[processTable[executingProcessID].programListIndex]->type==USERPROGRAM) 
		// One more user process that has terminated
		numberOfNotTerminatedUserProcesses--;

	// Examen-simulacro-2020
	int resT = processTable[executingProcessID].firstExecution - processTable[executingProcessID].createTime;
	int retT = Clock_GetTime() - processTable[executingProcessID].createTime;
	int wT = processTable[executingProcessID].readyTime; 
	OperatingSystem_ShowTime(SYSPROC);
	ComputerSystem_DebugMessage(550, SYSPROC, "response time", executingProcessID, programList[processTable[executingProcessID].programListIndex]->executableName, resT);
	OperatingSystem_ShowTime(SYSPROC);
	ComputerSystem_DebugMessage(550, SYSPROC, "return time", executingProcessID, programList[processTable[executingProcessID].programListIndex]->executableName, retT);
	OperatingSystem_ShowTime(SYSPROC);
	ComputerSystem_DebugMessage(550, SYSPROC, "waiting time", executingProcessID, programList[processTable[executingProcessID].programListIndex]->executableName, wT);
	
	
	if (numberOfNotTerminatedUserProcesses==0) {
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




	// Select the next process to execute (sipID if no more user processes)
	selectedProcess=OperatingSystem_ShortTermScheduler();

	// Assign the processor to that process
	OperatingSystem_Dispatch(selectedProcess);
}