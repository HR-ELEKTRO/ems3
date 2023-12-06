#include <cstdint>
#include <msp430.h>
#include "msp430_reg_herk.h"

int main() {
    //watchdog timer uitzetten
    WDTCTL = WDTPW | WDTHOLD;	
    //DCO op 16MHz
    DCOCTL = 0;            
    BCSCTL1 = CALBC1_16MHZ;
    DCOCTL  = CALDCO_16MHZ;
    //led op P1.0
    P1DIR |= 1;     
    
    while(1) {
        P1OUT ^= 1; //P1.0 toggle
        //~1000 ms wachten
        __delay_cycles(160000*1000);
    }
}
