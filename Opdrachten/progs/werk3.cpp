#include <iostream>
#include <iomanip>
#include <vector>

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

class Manager: public Werknemer {
public:
//  Definieer hier de benodigde memberfuncties
private:
	vector<const Werknemer*> ondergeschikten;
};

void print_maandsalaris(const Werknemer& w) {
    cout << "Werknemer: " << w.geef_nummer()
         << " verdient: " << setw(8) << setprecision(2) 
	     << fixed << w.geef_salaris() << " Euro.\n";
}

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
    
    print_maandsalaris(s);
    print_maandsalaris(f);
    print_maandsalaris(v1);
    print_maandsalaris(m1);
    print_maandsalaris(v2);
    print_maandsalaris(m2);
}
