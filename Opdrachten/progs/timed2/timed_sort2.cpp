#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <random>
#include <iterator>

#include "stopwatch.h"

using namespace std;

template <typename Element>
void selection_sort(vector<Element>& v) {
    for (auto p {v.begin()}; p != v.end(); ++p) {
        auto min {p};
        for (auto q {p + 1}; q != v.end(); ++q) {
            if (*q < *min) {
                min = q;
            }
        }
        swap(*p, *min);
    }
}

template <typename Element>
void heap_sort(vector<Element>& v) {
	auto n {v.size()};
    for (decltype(n) i {1}; i < n; ++i) {
        if (v[i] > v[(i - 1) / 2]) {
        	auto j {i};
            while (j > 0 && v[j] > v[(j - 1) / 2]) {
                swap(v[j], v[(j - 1) / 2]);
                j = (j - 1) / 2;
            }
        }
    }
    for (auto i {n - 1}; i > 0; --i) {
        swap(v[0], v[i]);
        decltype(n) j {0}, index;
        do {
            index = (2 * j + 1);
            if (index < (i - 1) && v[index] < v[index + 1])
                index++;
            if (index < i && v[j] < v[index])
                swap(v[j], v[index]);
            j = index;
        } while (index < i);
    }
}

void counting_sort(vector<int>& v) {
    // Voeg hier je code toe
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

            // Uncomment de functie die je wilt testen 
            selection_sort(v);
            //heap_sort(v);
            //counting_sort(v);
            
            sw.stop();
            if (n <= 100) {
                cout << "\nDe gesorteerde array:\n";
                copy(v.cbegin (), v.cend (), ostream_iterator<int>{cout , " "});
            }
            cout << "Tijdsduur: " << sw << "\n";
        }
    } while (n > 0);
}
