import std;
import freelancer;
import vaste_kracht;
import print_maandsalaris;

using namespace std;

int main() {
    Freelancer f {1, 25.75}; // werknemer 1 verdient 25.75 per uur
    Vaste_kracht v {2, 1873.53}; // werknemer 2 verdient 1873.53 per maand
    
    f.werk_uren(84); // werknemer 1 werkt (deze maand) 84 uren
    
    println("Maand 1:");
    print_maandsalaris(cout, f);
    print_maandsalaris(cout, v);
    
    f.werk_uren(13.5); // werknemer 1 werkt (deze maand) 13.5 uren
    
    println("Maand 2:");
    print_maandsalaris(cout, f);
    print_maandsalaris(cout, v);
}
