export module tijd3;
import std;
using namespace std;

// De declaratie van de UDT Tijdsduur:
export class Tijdsduur {
public:
    // ...
    void drukaf(std::ostream& out) const;
    // ...
private:
    int sec;
};

