#include <iostream>
#include <iomanip>
using namespace std;

class Time_unit {
public: 
    explicit Time_unit(unsigned long long int v): value{v} {
    }
    virtual ~Time_unit() = default;
    int get_as_int() const {
        return static_cast<int>(value);
    }
private:
    unsigned long long int value;
};

class Hour_unit: public Time_unit {
public:
    explicit Hour_unit(unsigned long long int v): Time_unit{v} {
    }
};

struct Minute_unit: public Time_unit {
    explicit Minute_unit(unsigned long long int v): Time_unit{v} {
    }
};

struct Second_unit: public Time_unit {
    explicit Second_unit(unsigned long long int v): Time_unit{v} {
    }
};

Hour_unit operator""_u(unsigned long long int v) {
    return Hour_unit{v};
}

Minute_unit operator""_m(unsigned long long int v) {
    return Minute_unit{v};
}

Second_unit operator""_s(unsigned long long int v) {
    return Second_unit{v};
}

const Time_unit time_unit_zero{0};

// De declaratie van de UDT Tijdsduur:

class Tijdsduur {
public:
    Tijdsduur(int u = 0, int m = 0, int s = 0);
    Tijdsduur(const Time_unit& u1, const Time_unit& u2 = time_unit_zero, const Time_unit& u3 = time_unit_zero);
    // ...
    void print() const;
    // ...
private:
    void init(const Time_unit& u);
	void normaliseer();
	int uur;
	int min;
	int sec;
};

// De definities van de memberfunctie van de ADT Tijdsduur, oftewel: de implementatie van de ADT Tijdsduur:

Tijdsduur::Tijdsduur(int u, int m, int s): uur{u}, min{m}, sec{s} {
	normaliseer();
}

void Tijdsduur::init(const Time_unit& u) {
    if (dynamic_cast<const Hour_unit*>(&u) != nullptr) {
        uur = u.get_as_int();
    }
    else if (dynamic_cast<const Minute_unit*>(&u) != nullptr) {
        min = u.get_as_int();
    }
    else if (dynamic_cast<const Second_unit*>(&u) != nullptr) {
        sec = u.get_as_int();
    }
}    

Tijdsduur::Tijdsduur(const Time_unit& u1, const Time_unit& u2, const Time_unit& u3): uur{0}, min{0}, sec{0} {
    init(u1);
    init(u2);
    init(u3);
	normaliseer();
}

void Tijdsduur::print() const {
// nog invullen...
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
	cout << "t1 = "; t1.print(); cout << '\n';
    Tijdsduur t2 {3, -122}; // t2 is 3 minuten minus 122 seconden
	cout << "t2 = "; t2.print(); cout << '\n';
	Tijdsduur t3 {3_u, 122_m}; // t3 is 3 uur plus 122 minuten
	cout << "t3 = "; t3.print(); cout << '\n';
	const Tijdsduur kwartier {15_m}; // kwartier is 15 minuten
	cout << "kwartier = "; kwartier.print(); cout << '\n';
	Tijdsduur t4 {121_s, 120_m, 3_u}; // t1 is 3 uur, 120 minuten en 121 seconden
	cout << "t4 = "; t4.print(); cout << '\n';
}