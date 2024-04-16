#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <random>
#include <iterator>

#include "stopwatch.h"

using namespace std;

template <typename Container>
void vul_met_meerderheids_element(Container& c) {
    default_random_engine eng;
    eng.seed(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<> dist {0, 999};
    auto n {c.size()};
    auto almost_half {c.begin()};
    advance(almost_half, n/2 - (1 - n%2));
    generate(c.begin(), almost_half, [&dist, &eng]{ return dist(eng); });
    fill(almost_half, c.end(), dist(eng));
}

bool zoek_meerderheids_element_methode_1(int& resultaat, const vector<int>& v) {
//  Vul hier jouw code in!
    return false;
}

bool zoek_meerderheids_element_methode_2(int& resultaat, const vector<int>& v) {
//  Vul hier jouw code in!
    return false;
}

bool zoek_meerderheids_element_methode_3(int& resultaat, const vector<int>& v) {
//  Vul hier jouw code in!
    return false;
}

typedef bool (*zoek_meerderheids_element)(int& resultaat, const vector<int>& v);

bool test_meerderheids_element(zoek_meerderheids_element fp) {
    int r {0};
    vector<int> v0 {3}; // meerderheidselement = 3
    if (!(*fp)(r, v0) || r != 3) {
        cout << "Test 0 failed!\n";
        return false;
    }
    vector<int> v1 {3, 4, 3, 2, 4, 4, 4, 5}; // geen meerderheidselement
    if ((*fp)(r, v1)) {
        cout << "Test 1 failed!\n";
        return false;
    }
    vector<int> v2 {3, 4, 3, 2, 4, 4, 4, 4, 5}; // meerderheidselement = 4
    if (!(*fp)(r, v2) || r != 4) {
        cout << "Test 2 failed!\n";
        return false;
    }
    vector<int> v3 {1, 1, 1, 1, 3, 2, 2, 3, 3, 3, 2, 3, 3}; // geen meerderheidselement
    if ((*fp)(r, v3)) {
        cout << "Test 3 failed!\n";
        return false;
    }
    vector<int> v4 {1, 1, 1, 3, 3, 2, 2, 3, 3, 3, 2, 3, 3}; // meerderheidselement = 3
    if (!(*fp)(r, v4) || r != 3) {
        cout << "Test 4 failed!\n";
        return false;
    }
    return true;
}

int main() {
    zoek_meerderheids_element te_testen_functie {nullptr};
    te_testen_functie = zoek_meerderheids_element_methode_1;
    if (test_meerderheids_element(*te_testen_functie)) {
        size_t n {1};
        while (n > 0) {
            cout<<"Geef n ( 0 om te stoppen ): ";
            cin >> n;
            if (n > 0) {
                vector<int> v(n);
                vul_met_meerderheids_element(v);
                if (n <= 100) {
                    copy(v.cbegin (), v.cend (), ostream_iterator<int>{cout , " "});
                    cout << '\n';
                }
                Stopwatch sw;
                int res {0};
                sw.start();
                bool gevonden {(*te_testen_functie)(res, v)};
                sw.stop();
                if (gevonden) {
                    cout << "Meerderheids element gevonden: " << res << '\n';
                }
                else {
                    cout << "Geen meerderheids element gevonden.\n";
                }
                cout << "Tijdsduur: " << sw << '\n';
            }
        }
    }
}
