#include <iostream>
#include <iomanip>
#include "tijd1.h"

using namespace std;

// De definities van de memberfunctie van de ADT Tijdsduur, oftewel: de implementatie van de ADT Tijdsduur:

// ...

void Tijdsduur::print(ostream& out) const {
    if (uur == 0) {
        if (min == 0) {
            out << sec;
        }
        else {
            out << min << ':' << setw(2) << setfill('0') << sec;
        }
    }
    else {
        out << uur<< ':' << setw(2) << setfill('0') << min << ':' << setw(2) << setfill('0') << sec;
    }
}

// ...

void Tijdsduur::normaliseer() {
    min += sec / 60;
    sec = sec % 60;
    if (sec < 0) {
        sec += 60;
        --min;
    }
    uur += min / 60;
    min = min % 60;
    if (min < 0) {
        min += 60;
        --uur;
    }
}
