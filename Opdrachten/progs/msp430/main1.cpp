#include <cstdint>
#include <msp430.h>
#include "msp430_reg.h"

int main() {
    //watchdog timer uitzetten
    WDTCTL = WDTPW | WDTHOLD;
    //de I/O-class Port_pin gebruiken!
    Port_pin led1 {PORT1, 0}; //led op P1.0
    led1.set_direction_output();
    Port_pin s2 {PORT1, 3}; //knop op P1.3 met externe pull up
    s2.set_direction_input();
    while(1) {
        led1.toggle();
        while(s2.get_pin_value() == false) {
            //niets doen
        }
        __delay_cycles(60000);
    }
}
