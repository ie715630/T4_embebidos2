
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MK66F18.h"
#include "fsl_debug_console.h"
#include <singleton_clock.h>

#define TIC_PERIOD_IN_mS 10

void reload_systick(void) {
  SysTick->LOAD = MSEC_TO_COUNT(TIC_PERIOD_IN_mS, CLOCK_GetCoreSysClkFreq());
  SysTick->VAL = 0;
}

void SysTick_Handler(void) {
	ten_ms_handler();
	reload_systick();
}

int main(void) {

  	/* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
    BOARD_InitDebugConsole();

    SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk |
                    SysTick_CTRL_TICKINT_Msk |
                    SysTick_CTRL_ENABLE_Msk;

    uint8_t inital_secs = 55;
    uint8_t inital_min = 59;
    uint8_t initial_hour = 11;
    my_time_t initial_time = {inital_secs, inital_min, initial_hour};

    uint8_t alarm_sec = 10;
    uint8_t alarm_min = 0;
    uint8_t alarm_hour = 12;
    my_time_t alarm_time = {alarm_sec, alarm_min, alarm_hour};

    set_alarm(alarm_time);

    set_time(initial_time);
    reload_systick();

    while(1) {

    }
    
    return 0 ;
}
