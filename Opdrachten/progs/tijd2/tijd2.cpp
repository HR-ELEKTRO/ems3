module tijd2;
import std;
using namespace std;


// De definities van de memberfunctie van de ADT Tijdsduur, oftewel: de implementatie van de ADT Tijdsduur:

// ...

ostream& operator<<(ostream& o, const Tijdsduur& t) {
    if (t.uur == 0) {
        if (t.min == 0) {
            print(o, "{}", t.sec);
        }
        else {
            print(o, "{}:{:02}", t.min, t.sec);
        }
    }
    else {
        print(o, "{}:{:02}:{:02}", t.uur, t.min, t.sec);
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
