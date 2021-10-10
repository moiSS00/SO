#include <stdio.h>
#include <stdlib.h>
#include "ComputerSystem.h"
#include "OperatingSystem.h"
#include "ComputerSystemBase.h"
#include "Processor.h"
#include "Messages.h"
#include "Asserts.h"
#include "Clock.h"

// Functions prototypes
void ComputerSystem_ShowTime(char);

// Array that contains basic data about all daemons
// and all user programs specified in the command line
PROGRAMS_DATA *programList[PROGRAMSMAXNUMBER];

// Powers on of the Computer System.
void ComputerSystem_PowerOn(int argc, char *argv[], int paramIndex) {

	// Obtain a list of programs in the command line
	int daemonsBaseIndex = ComputerSystem_ObtainProgramList(argc, argv, paramIndex);

	// Load debug messages
	int nm=0;
	nm=Messages_Load_Messages(nm,TEACHER_MESSAGES_FILE);
	if (nm<0) {
		ComputerSystem_ShowTime(SHUTDOWN);
		ComputerSystem_DebugMessage(64,SHUTDOWN,TEACHER_MESSAGES_FILE);
		exit(2);
	}
	nm=Messages_Load_Messages(nm,STUDENT_MESSAGES_FILE);

	// Prepare if necesary the assert system
	Asserts_LoadAsserts();

	//Imprrime informacion de los programas de usuario.
	ComputerSystem_PrintProgramList();

	// Request the OS to do the initial set of tasks. The last one will be
	// the processor allocation to the process with the highest priority
	OperatingSystem_Initialize(daemonsBaseIndex);

	// Tell the processor to begin its instruction cycle 
	Processor_InstructionCycleLoop();
	
}

// Powers off the CS (the C program ends)
void ComputerSystem_PowerOff() {
	// Show message in red colour: "END of the simulation\n" 
	ComputerSystem_ShowTime(SHUTDOWN);
	ComputerSystem_DebugMessage(99,SHUTDOWN,"END of the simulation\n"); 
	exit(0);
}

/////////////////////////////////////////////////////////
//  New functions below this line  //////////////////////


void ComputerSystem_PrintProgramList() {
	
	ComputerSystem_ShowTime(INIT);
	ComputerSystem_DebugMessage(101, INIT);
	int i; 
	for (i = 1; i < PROGRAMSMAXNUMBER && programList[i] != NULL; i++) {
		if (programList[i]->type == USERPROGRAM) {
			ComputerSystem_DebugMessage(102, INIT, programList[i]->executableName, programList[i]->arrivalTime);
		}
	}

}

void ComputerSystem_ShowTime(char section) {
	ComputerSystem_DebugMessage(Processor_PSW_BitState(EXECUTION_MODE_BIT) ? 95 : 94, section, Clock_GetTime());
}




