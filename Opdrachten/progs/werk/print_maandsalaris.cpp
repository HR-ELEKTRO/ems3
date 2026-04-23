module print_maandsalaris;
import std;
import werknemer;
using namespace std;

void print_maandsalaris(ostream& out, const Werknemer& w) {
    println(out, "Werknemer: {} verdient: {:>8.2f} Euro.", w.geef_nummer(), w.geef_salaris());
}
