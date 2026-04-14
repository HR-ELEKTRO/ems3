module tijd1;
import std;
using namespace std;

// De definities van de memberfunctie van de ADT Tijdsduur, oftewel: de implementatie van de ADT Tijdsduur:

// ...

void Tijdsduur::drukaf(ostream& out) const {
    if (uur == 0) {
        if (min == 0) {
            print(out, "{}", sec);
        }
        else {
            print(out, "{}:{:02d}", min, sec);
        }
    }
    else {
        print(out, "{}:{:02d}:{:02d}", uur, min, sec);
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
