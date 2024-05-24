#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <random>
#include <iterator>

#include "stopwatch.h"

using namespace std;

void vul_random_0_999(vector<int>& v) {
    default_random_engine eng;
    eng.seed(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<> dist {0, 999};
    generate(v.begin(), v.end(), [&dist, &eng]{ return dist(eng); });
}

bool contains_element_method_1(const vector<int>& v, int e) {
    for (auto a: v) {
        if (a == e) {
            return true;
        }
    }
    return false;
}

bool contains_element_method_2(const vector<int>& v, int e) {
    // Voeg hier je code toe
    return false;
}

bool contains_element_method_3(const vector<int>& v, int e) {
    // Voeg hier je code toe
    return false;
}

bool contains_element_method_4(const vector<int>& v, int e) {
    // Voeg hier je code toe
    return false;
}

using function_pointer = bool (*)(const vector<int>& v, int e);

bool test_sorted_vector_contains_element_int(const vector<int>& v, function_pointer f) {
    if ((*f)(v, v.front() - 1) || (*f)(v, v.back() + 1)) {
        cout << "Test 0 failed!\n";
        return false;
    }
    for (auto i :v) {
        if (!(*f)(v, i)) {
            cout << "Test 1 failed!\n";
            return false;
        }
    }
    return true;
}

bool test_sorted_container_contains_element(function_pointer f) {
    vector<int> v {3};
    if (test_sorted_vector_contains_element_int(v, f) == false) return false;
    v.push_back(4);
    if (test_sorted_vector_contains_element_int(v, f) == false) return false;
    v.push_back(5);
    if (test_sorted_vector_contains_element_int(v, f) == false) return false;
    return true;
}

int main() {
    function_pointer f {&contains_element_method_1};
    if (test_sorted_container_contains_element(f)) {
        size_t n {1};
        while (n > 0) {
            cout<<"Geef n ( 0 om te stoppen ): ";
            cin >> n;
            if (n > 0) {
                vector<int> v(n);
                vul_random_0_999(v);
                sort(v.begin(), v.end());
                if (n <= 100) {
                    copy(v.cbegin (), v.cend (), ostream_iterator<int>{cout , " "});
                    cout << '\n';
                }
                int s;
                cout<<"Geef element om te zoeken: ";
                cin >> s;
                Stopwatch sw;
                sw.start();
                bool gevonden {(*f)(v, s)};
                sw.stop();
                if (gevonden) {
                    cout << "Element " << s << " gevonden.\n";
                }
                else {
                    cout << "Element " << s << " niet gevonden.\n";
                }
                cout << "Tijdsduur: " << sw << '\n';
            }
        }
    }
}
