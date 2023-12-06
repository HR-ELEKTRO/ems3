#include <cstdint>
#include <msp430.h>
#include "msp430_reg_herk.h"
#include "timer.h"
#include "led.h"

int main() {
    //watchdog timer uitzetten
    WDTCTL = WDTPW | WDTHOLD;	
    //DCO op 16MHz
    DCOCTL = 0;            
    BCSCTL1 = CALBC1_16MHZ;
    DCOCTL  = CALDCO_16MHZ;
    //led op P1.0	
    Led led1 {PORT1, 0};	
    //prescaler van 8 => 2Mhz
    //compare tick elke 1000 us
    Timer timer0 {TIMER0, 8, 2000}; 
 
    //Onderstaande code laat de led dimmen door de 
    //duty cycle aan te passen. f=1kHz. Max duty = 60%
    std::uint16_t duration_in_us =0;
    bool going_up {true};

    while (1) {
        //wachten op einde ms tick.
        timer0.wait_for_tick();
        //led aan voor aantal us
        led1.turn_on_for(duration_in_us);
        //hysteresis tussen 0us en 600us
        if(duration_in_us > 599) 
            going_up = false;
        if(duration_in_us < 1)
            going_up = true;
        //change duty
        going_up ? duration_in_us++ : duration_in_us--;
    }
}
