//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <SI_EFM8LB1_Register_Enums.h>                // SFR declarations
#include "InitDevice.h"
#include "uHalDelay.h"
#include <SI_EFM8LB1_Register_Enums.h>
//-----------------------------------------------------------------------------
// SiLabs_Startup() Routine
// ----------------------------------------------------------------------------
// This function is called immediately after reset, before the initialization
// code is run in SILABS_STARTUP.A51 (which runs before main() ). This is a
// useful place to disable the watchdog timer, which is enable by default
// and may trigger before main() in some instances.
//-----------------------------------------------------------------------------
void SiLabs_Startup (void)
{
  // Disable the watchdog here
}

//-----------------------------------------------------------------------------
// main() Routine
// ----------------------------------------------------------------------------
// Note: the software watchdog timer is not disabled by default in this
// example, so a long-running program will reset periodically unless
// the timer is disabled or your program periodically writes to it.
//
// Review the "Watchdog Timer" section under the part family's datasheet
// for details. To find the datasheet, select your part in the
// Simplicity Launcher and click on "Data Sheet".
//-----------------------------------------------------------------------------
int main (void)
{
	enter_DefaultMode_from_RESET();
	while (1) {
		P1 &= P1_B0__LOW;
		uHalDelayUsec(3);
		//uHalDelayUsecTimer(200);
		P1 |= P1_B0__HIGH;
		uHalDelayUsec(3);
		//uHalDelayUsecTimer(200);
		P1 &= P1_B0__LOW;
		//uHalDelayUsecTimer(22937);
	}                             // Spin forever
}
