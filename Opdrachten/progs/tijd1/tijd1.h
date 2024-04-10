#ifndef _HR_BroJZ_Tijd1_
#define _HR_BroJZ_Tijd1_

#include <iostream>

// De declaratie van de UDT Tijdsduur:
class Tijdsduur {
public:
    // ...
    void print(std::ostream& out) const;
    // ...
private:
    void normaliseer();
    int uur;
    int min;
    int sec;
};

#endif
