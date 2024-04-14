#include <iostream>
#include <iomanip>
#include "freelancer.h"
#include "vaste_kracht.h"
#include "stukwerker.h"
#include "print_maandsalaris.h"

using namespace std;

int main() {
    Freelancer f {1, 25.75}; // werknemer 1 verdient 25.75 per uur
    Vaste_kracht v {2, 1873.53}; // werknemer 2 verdient 1873.53 per maand
    Stukwerker s {3, 1.05}; // werknemer 3 verdient 1.05 per stuk
    
    f.werk_uren(84); // werknemer 1 werkt (deze maand) 84 uren
    s.produceer_stuks(1687); // werknemer 3 produceert (deze maand) 1687 stuks
    
    cout << "Maand 1:\n";
    print_maandsalaris(cout, f);
    print_maandsalaris(cout, v);
    print_maandsalaris(cout, s);
    
    f.werk_uren(13.5); // werknemer 1 werkt (deze maand) 13.5 uren
    s.produceer_stuks(0); // werknemer 3 produceert (deze maand) 0 stuks
    
    cout << "Maand 2:\n";
    print_maandsalaris(cout, f);
    print_maandsalaris(cout, v);
    print_maandsalaris(cout, s);
}
