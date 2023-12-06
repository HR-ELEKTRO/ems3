#include <iostream>
#include <iomanip>

using namespace std;

class Werknemer {
public:
	explicit Werknemer(int n): nummer{n} {
	}
	virtual ~Werknemer() {
	}
	int geef_nummer() const {
		return nummer;
	}
	virtual double geef_salaris() const =0;
private:
	int nummer;
};

class Freelancer: public Werknemer {
public:
	Freelancer(int n, double s): Werknemer{n}, salaris_per_uur{s}, gewerkte_uren{0} {
	}
	double geef_salaris() const override {
        double salaris {0};
        // Bepaal hier het salaris van de Freelancer
		return salaris;
	}
	void werk_uren(double u) {
		gewerkte_uren = u;
	}
private:
	double salaris_per_uur;
	double gewerkte_uren;
};

class Vaste_kracht: public Werknemer {
public:
	Vaste_kracht(int n, double s): Werknemer{n}, maandsalaris{s} {
	}
	double geef_salaris() const override {
        double salaris {0};
        // Bepaal hier het salaris van de Vaste_kracht
		return salaris;
	}
private:
	double maandsalaris;
};

class Stukwerker: public Werknemer {
public:
//  Definieer hier de benodigde memberfuncties
    void produceer_stuks(int s) {
    //  Vul hier de benodigde code in
	}
private:
//  Definieer hier de benodigde datamembers
};

void print_maandsalaris(const Werknemer& w) {
    cout << "Werknemer: " << w.geef_nummer()
         << " verdient: " << setw(8) << setprecision(2) 
	     << fixed << w.geef_salaris() << " Euro.\n";
}

int main() {
    Freelancer f {1, 25.75}; // werknemer 1 verdient 25.75 per uur
    Vaste_kracht v {2, 1873.53}; // werknemer 2 verdient 1873.53 per maand
    Stukwerker s {3, 1.05}; // werknemer 3 verdient 1.05 per stuk
    
    f.werk_uren(84); // werknemer 1 werkt (deze maand) 84 uren
    s.produceer_stuks(1687); // werknemer 3 produceert (deze maand) 1687 stuks
    
    cout << "Maand 1:\n";
    print_maandsalaris(f);
    print_maandsalaris(v);
    print_maandsalaris(s);
    
    f.werk_uren(13.5); // werknemer 1 werkt (deze maand) 13.5 uren
    s.produceer_stuks(0); // werknemer 3 produceert (deze maand) 0 stuks
    
    cout << "Maand 2:\n";
    print_maandsalaris(f);
    print_maandsalaris(v);
    print_maandsalaris(s);
}
