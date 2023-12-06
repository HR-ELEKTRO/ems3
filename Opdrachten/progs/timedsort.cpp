#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <random>
#include <iterator>

using namespace std;

// class to measure time in ms 
class Stopwatch {
public:
    Stopwatch();
    void start();
    void stop();
private:
    bool running;
    chrono::time_point<chrono::high_resolution_clock> start_time;
    chrono::time_point<chrono::high_resolution_clock> stop_time;
friend ostream& operator<<(ostream& o, const Stopwatch& sw);
};

Stopwatch::Stopwatch(): running{false} {
}

void Stopwatch::start() {
    if (!running) {
        running = true;
        start_time = chrono::high_resolution_clock::now();
    }
}

void Stopwatch::stop() {
    if (running) {
        running = false;
        stop_time = chrono::high_resolution_clock::now();
    }
}

ostream& operator<<(ostream& o, const Stopwatch& sw) {
    auto total_time {chrono::duration_cast<chrono::milliseconds>(sw.stop_time - sw.start_time).count()};
    return o << total_time << " ms";
}

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
            cout << "\nTijdsduur: " << sw << endl;
        }
    } while (n > 0);
}
