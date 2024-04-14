#ifndef _HR_BroJZ_Vaste_kracht_
#define _HR_BroJZ_Vaste_kracht_

#include "werknemer.h"

class Vaste_kracht: public Werknemer {
public:
    Vaste_kracht(int n, double s);
    double geef_salaris() const override;
private:
    double maandsalaris;
};

#endif
