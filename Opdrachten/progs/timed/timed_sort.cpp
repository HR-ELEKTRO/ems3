import std;
import stopwatch;
using namespace std;

template <ranges::bidirectional_range Range>
void bubble_sort(Range& range) {
    auto begin = ranges::begin(range);
    auto end = ranges::end(range);
    for (auto p {--end}; p != begin; --p) {
        for (auto q {begin}; q != p; ++q) {
            auto q_next(q);
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
        print("Geef n (<=0 om te stoppen): ");
        cin >> n;
        if (n > 0) {
            vector<int> v(n);
            ranges::generate(v, [&dist, &eng]{ return dist(eng); });
            if (n <= 100) {
                println("De random array: {}", v);
            }
            Stopwatch sw;
            sw.start();
            bubble_sort(v);
            // ranges::sort(v);
            sw.stop();
            if (n <= 100) {
                println("De gesorteerde array: {}", v);
            }
            println("Tijdsduur: {}", sw.duration());
        }
    } while (n > 0);
}
