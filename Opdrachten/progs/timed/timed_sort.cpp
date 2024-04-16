#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <random>
#include <iterator>

#include "stopwatch.h"

using namespace std;

template <typename Iterator>
void bubble_sort(Iterator begin, Iterator end) {
    for (Iterator p {--end}; p != begin; --p) {
        for (Iterator q {begin}; q != p; ++q) {
            Iterator q_next(q);
            q_next++;
            if (*q > *q_next) {
                swap(*q, *q_next);
            }
        }
    }
}

int main() {
    default_random_engine eng;
    eng.seed(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<> dist {0, 999};
    int n;
    do {
        cout << "Geef n (<=0 om te stoppen): ";
        cin >> n;
        if (n > 0) {
            vector<int> v(n);
            generate(v.begin(), v.end(), [&dist, &eng]{ return dist(eng); });
            if (n <= 100) {
                cout << "De random array:\n";
                copy(v.cbegin (), v.cend (), ostream_iterator<int>{cout , " "});
            }
            Stopwatch sw;
            sw.start();
            bubble_sort(v.begin(), v.end());
            //sort(v.begin(), v.end());
            sw.stop();
            if (n <= 100) {
                cout << "\nDe gesorteerde array:\n";
                copy(v.cbegin (), v.cend (), ostream_iterator<int>{cout , " "});
            }
            cout << "Tijdsduur: " << sw << "\n";
        }
    } while (n > 0);
}
