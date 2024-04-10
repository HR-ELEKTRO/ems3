#include <iostream>
#include <iomanip>
#include "tijd2.h"

using namespace std;

// De definities van de memberfunctie van de ADT Tijdsduur, oftewel: de implementatie van de ADT Tijdsduur:

// ...

ostream& operator<<(ostream& o, const Tijdsduur& t) {
    if (t.uur == 0) {
        if (t.min == 0) {
            o << t.sec;
        }
        else {
            o << t.min << ':' << setw(2) << setfill('0') << t.sec;
        }
    }
    else {
        o << t.uur<< ':' << setw(2) << setfill('0') << t.min << ':' << setw(2) << setfill('0') << t.sec;
    }
    return o;
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
