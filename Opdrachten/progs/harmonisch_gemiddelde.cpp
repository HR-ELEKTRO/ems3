#include <iostream>
#include <vector>

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

int main() {
//  (te) korte test:
    vector<int> weerstanden {100, 200, 300, 400};
    double h {harmonisch_gemiddelde(weerstanden)};
    cout << "100 // 200 // 300 // 400 Ohm kan vervangen worden door:\n";
    cout << h << " // " << h << " // " << h << " // " << h << " Ohm\n";
    vector<double> snelheden {1.0, 1.2};
    cout << "1.0 m/s heen en 1.2 m/s terug geeft gemiddeld: " << harmonisch_gemiddelde(snelheden) << " m/s\n";
}
