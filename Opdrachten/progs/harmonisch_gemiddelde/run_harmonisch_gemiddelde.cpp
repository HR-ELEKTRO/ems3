#include <iostream>
#include <vector>
#include "harmonisch_gemiddelde.h"

using namespace std;

int main() {
    vector<int> weerstanden {100, 200, 300, 400};
    double h {harmonisch_gemiddelde(weerstanden)};
    cout << "100 // 200 // 300 // 400 Ohm kan vervangen worden door:\n";
    cout << h << " // " << h << " // " << h << " // " << h << " Ohm\n";
    vector<double> snelheden {1.0, 1.2};
    cout << "1.0 m/s heen en 1.2 m/s terug geeft gemiddeld: " << harmonisch_gemiddelde(snelheden) << " m/s\n";
}
