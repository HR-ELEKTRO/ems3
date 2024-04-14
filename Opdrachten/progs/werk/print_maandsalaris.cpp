#include <iostream>
#include <iomanip>
#include "werknemer.h"
#include "print_maandsalaris.h"

using namespace std;

void print_maandsalaris(ostream& out, const Werknemer& w) {
    out << "Werknemer: " << w.geef_nummer()
        << " verdient: " << setw(8) << setprecision(2) 
        << fixed << w.geef_salaris() << " Euro.\n";
}
