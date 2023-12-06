#include <iostream>
#include <iomanip>
using namespace std;

// De declaratie van de UDT Tijdsduur:

class Tijdsduur {
public:
    // ...
    void print() const;
    // ...
private:
	void normaliseer();
	int uur;
	int min;
	int sec;
};

// De definities van de memberfunctie van de ADT Tijdsduur, oftewel: de implementatie van de ADT Tijdsduur:

// ...

void Tijdsduur::print() const {
    // ...	
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

int main() {
	Tijdsduur t1 {3, 50, 10}; // t1 is 3 uur, 50 minuten en 10 seconden
	cout << "t1 = "; t1.print(); cout << '\n';
	Tijdsduur t2 {3, -122}; // t2 is 3 minuten minus 122 seconden
	cout << "t2 = "; t2.print(); cout << '\n';
	Tijdsduur t3 {3, 122}; // t3 is 3 minuten plus 122 seconden
	cout << "t3 = "; t3.print(); cout << '\n';
	const Tijdsduur kwartier {15, 0}; // kwartier is 15 minuten
	cout << "kwartier = "; kwartier.print(); cout << '\n';
	t1.erbij(kwartier); // Tel kwartier bij t1 op
	cout << "t1 = "; t1.print(); cout << '\n';
	Tijdsduur t4 {t1}; // t4 is een kopie van t1
	cout << "t4 = "; t4.print(); cout << '\n';
	t4.eraf(kwartier); // Trek kw van t4 af
	cout << "t4 = "; t4.print(); cout << '\n';
	t4.maal(7); // Vermenigvuldig t4 met 7;
	cout << "t4 = "; t4.print(); cout << '\n';
}
