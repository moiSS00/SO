#include "Clock.h"
#include "Processor.h"
#include "ComputerSystemBase.h"

int tics=0; //Tics actuales 


void Clock_Update() {

	tics++;
	if (tics % DEFAULT_INTERVAL_BETWEEN_INTERRUPTS == 0) {
		Processor_RaiseInterrupt(CLOCKINT_BIT); //Crea una interrupcion
	}
    // ComputerSystem_DebugMessage(97,CLOCK,tics);
}


int Clock_GetTime() {

	return tics;
}
