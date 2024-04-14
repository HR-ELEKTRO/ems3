#ifndef _HR_BroJZ_Freelancer_
#define _HR_BroJZ_Freelancer_

#include "werknemer.h"

class Freelancer: public Werknemer {
public:
    Freelancer(int n, double s);
    double geef_salaris() const override;
    void werk_uren(double u);
private:
    double salaris_per_uur;
    double gewerkte_uren;
};

#endif
