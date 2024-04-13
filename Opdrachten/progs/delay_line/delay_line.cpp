#include <array>
#include "delay_line.h"

using namespace std;

Delay_line::Delay_line(): buffer{}, index{0}, get_called{false} {
}

int Delay_line::get() {
    get_called = true;
    return buffer[(index + 1) % 9];
}

void Delay_line::put(int sample) {
    if (get_called) {
        if (index == 8) {
            index = 0;
        } else {
            ++index;
        }
        get_called = false;
    }
    buffer[index] = sample;
}
