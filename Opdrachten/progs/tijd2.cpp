#include <iostream>
#include <iomanip>
using namespace std;

// De declaratie van de UDT Tijdsduur:

class Tijdsduur {
public:
    // ...
	friend ostream& operator<<(ostream& o, const Tijdsduur& t);
private:
	void normaliseer();
	int uur;
	int min;
	int sec;
};

// De definities van de memberfunctie van de UDT Tijdsduur, oftewel: de implementatie van de UDT Tijdsduur:

// ...

ostream& operator<<(ostream& o, const Tijdsduur& t) {
	if (t.uur == 0) {
		if (t.min == 0) {
			o << t.sec;
		}
		else {
			o << t.min << ':' << setw(2) << setfill('0') << t.sec;
		}
	}
	else {
		o << t.uur<< ':' << setw(2) << setfill('0') << t.min << ':' << setw(2) << setfill('0') << t.sec;
	}
	return o;
}
		
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
	cout << "t1 = " << t1 << '\n';
	Tijdsduur t2 {3, -122}; // t2 is 3 minuten minus 122 seconden
	cout << "t2 = " << t2 << '\n';
	Tijdsduur t3 {3, 122}; // t3 is 3 minuten plus 122 seconden
	cout << "t3 = " << t3 << '\n';
	const Tijdsduur kwartier {15, 0}; // kwartier is 15 minuten
	cout << "kwartier = " << kwartier << '\n';
	t1 += kwartier; // Tel kwartier bij t1 op
	cout << "t1 = " << t1 << '\n';
	Tijdsduur t4 {t1}; // t4 is een kopie van t1
	cout << "t4 = " << t4 << '\n';
	t4 -= kwartier; // Trek kw van t4 af
	cout << "t4 = " << t4 << '\n';
	t4 *= 7; // Vermenigvuldig t4 met 7;
	cout << "t4 = " << t4 << '\n';
	t1 += t2 += t3; // meerdere operatoren in één expressie
	cout << "t1 = " << t1 << '\n'; // tel t2 en t3 op bij t1
	cout << "t2 = " << t2 << '\n'; // tel t3 op bij t2
	cout << "t3 = " << t3 << '\n'; // t3 is ongewijzigd
	(t1 += t2) += t3; // meerdere operatoren in één expressie
	cout << "t1 = " << t1 << '\n'; // tel t2 en t3 op bij t1
	cout << "t2 = " << t2 << '\n'; // t2 is ongewijzigd
	cout << "t3 = " << t3 << '\n'; // t3 is ongewijzigd
}
