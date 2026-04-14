export module tijd1;
import std;
using namespace std;

// De declaratie van de UDT Tijdsduur:
export class Tijdsduur {
public:
    // ...
    void drukaf(ostream& out) const;
    // ...
private:
    void normaliseer();
    int uur;
    int min;
    int sec;
};
