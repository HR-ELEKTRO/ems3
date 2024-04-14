#include "freelancer.h"

Freelancer::Freelancer(int n, double s): Werknemer{n}, salaris_per_uur{s}, gewerkte_uren{0} {
}

double Freelancer::geef_salaris() const {
    double salaris {0};
    // Bepaal hier het salaris van de Freelancer
    return salaris;
}

void Freelancer::werk_uren(double u) {
    gewerkte_uren = u;
}
