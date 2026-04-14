export module tijd1;
import std;
using namespace std;

// De declaratie van de UDT Tijdsduur:
export class Tijdsduur {
public:
    // ...
    friend std::ostream& operator<<(std::ostream& o, const Tijdsduur& t);
private:
    void normaliseer();
    int uur;
    int min;
    int sec;
};

template<>
struct std::formatter<Tijdsduur>: public formatter<string> {
    auto format(const Tijdsduur& t, auto& context) const {
        ostringstream ss;
        ss << t;
        return formatter<string>::format(ss.str(), context);
    }
};
