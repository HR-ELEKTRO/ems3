#include <cstdint>
#include <array>
#include <msp430.h>
#include "msp430_reg.h"

// polymorph function
void blink_n_times(Led_interface& led, unsigned int n) {
    for (int i{0}; i < n*2; ++i) {
        led.toggle();
        __delay_cycles(600000);
    }
}

int main()
{
    //watchdog timer uitzetten
    WDTCTL = WDTPW | WDTHOLD;
    Led led1 {PORT1, 0}; //led op P1.0
    blink_n_times(led1, 5);
    Led led2 {PORT1, 6};
    blink_n_times(led2, 5);

    RGB_led led3 {PORT2, 1, PORT2, 3, PORT2, 5};
    std::array<RGB_led::Color, 7> all_colors {
        RGB_led::Blue, RGB_led::Green, RGB_led::Cyan, RGB_led::Red,
        RGB_led::Magenta, RGB_led::Yellow, RGB_led::White
    };
    for (auto c: all_colors) {
        led3.set_color(c);
        __delay_cycles(600000);
    }

    led3.set_color(RGB_led::White);
    __delay_cycles(600000);
    blink_n_times(led3, 5);
    led3.set_color(RGB_led::Red);
    blink_n_times(led3, 1);
    led3.set_color(RGB_led::Green);
    blink_n_times(led3, 2);
    led3.set_color(RGB_led::Blue);
    blink_n_times(led3, 3);

    led3.set_color(RGB_led::Magenta);
    while (1) {
        led3.toggle();
        __delay_cycles(60000);
    }
}
