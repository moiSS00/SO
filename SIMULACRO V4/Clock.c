#include "Clock.h"
#include "Processor.h"
#include "ComputerSystemBase.h"

int tics=0; //Tics actuales 


//[MOISES V2] EJ 2
void Clock_Update() {
	
	tics++;
	if (tics % intervalBetweenInterrupts == 0) {
		Processor_RaiseInterrupt(CLOCKINT_BIT); //Crea una interrupcion
	}
    // ComputerSystem_DebugMessage(97,CLOCK,tics);
}


int Clock_GetTime() {
	return tics;
}
