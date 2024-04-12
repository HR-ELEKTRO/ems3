#include <vector>
#include "harmonisch_gemiddelde.h"

using namespace std;

double harmonisch_gemiddelde(const vector<double>& v) {
    double totaal {0};
    for (const double& e: v) {
        totaal += 1/e;
    }
    return v.size() / totaal;
}

double harmonisch_gemiddelde(const vector<int>& v) {
    double totaal {0};
    for (const int& e: v) {
        totaal += 1.0/e;
    }
    return v.size() / totaal;
}
