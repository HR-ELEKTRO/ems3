#ifndef _HR_BroJZ_Tijd2_
#define _HR_BroJZ_Tijd2_

#include <iostream>

// De declaratie van de UDT Tijdsduur:
class Tijdsduur {
public:
    // ...
    friend std::ostream& operator<<(std::ostream& o, const Tijdsduur& t);
private:
    void normaliseer();
    int uur;
    int min;
    int sec;
};

#endif
