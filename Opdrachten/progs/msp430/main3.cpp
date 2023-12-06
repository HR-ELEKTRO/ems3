#include <cstdint>
#include <msp430.h>
#include "msp430_reg.h"

int main() {
    //watchdog timer uitzetten
    WDTCTL = WDTPW | WDTHOLD;
    //de I/O-class Led gebruiken!
    Led led1 {PORT1, 0}; //led op P1.0
    //de I/O-class Knop gebruiken!
    Knop s2 {PORT1, 3, PULL_UP}; //knop op P1.3 met interne pull-up
    while(1) {
        led1.toggle();
        while(s2.is_pressed()) {
            //niets doen
        }
        __delay_cycles(60000);
    }
}
