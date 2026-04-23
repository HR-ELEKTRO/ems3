import std;
import freelancer;
import vaste_kracht;
import stukwerker;
import manager;
import print_maandsalaris;

using namespace std;

int main() {
    Stukwerker s(1, 1.05); // werknemer 1 verdient 1.05 per stuk
    Freelancer f(2, 25.75); // werknemer 2 verdient 25.75 per uur
    Vaste_kracht v1(3, 1873.53); // werknemer 3 verdient 1873.53 per maand
    
    Manager m1(4); // werknemer 4 is de manager van:
    m1.geeft_leiding_aan(s); // -  werknemer 1
    m1.geeft_leiding_aan(f); // -  werknemer 2
    m1.geeft_leiding_aan(v1);// -  werknemer 3
    
    Vaste_kracht v2(5, 2036.18); // werknemer 5 verdient 2036,18 per maand
    Manager m2(6); // werknemer 6 is de manager van:
    m2.geeft_leiding_aan(v2); // -  werknemer 5
    m2.geeft_leiding_aan(m1); // -  werknemer 4
    
    s.produceer_stuks(678); // werknemer 1 produceert 678 stuks
    f.werk_uren(84); // werknemer 2 werkt 84 uren
    
    print_maandsalaris(cout, s);
    print_maandsalaris(cout, f);
    print_maandsalaris(cout, v1);
    print_maandsalaris(cout, m1);
    print_maandsalaris(cout, v2);
    print_maandsalaris(cout, m2);
}
