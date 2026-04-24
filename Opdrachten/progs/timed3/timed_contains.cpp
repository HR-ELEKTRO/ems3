import std;
import stopwatch;
using namespace std;

void vul_random_0_999(vector<int>& v) {
    default_random_engine eng;
    eng.seed(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<> dist {0, 999};
    ranges::generate(v, [&dist, &eng]{ return dist(eng); });
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

bool test_sorted_vector_contains_element_int(const vector<int>& v, function_pointer fp) {
    if (fp(v, v.front() - 1) || fp(v, v.back() + 1)) {
        println("Test 0 failed!");
        return false;
    }
    for (auto i :v) {
        if (!fp(v, i)) {
            println("Test 1 failed!");
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
    function_pointer fp {&contains_element_method_1};
    if (test_sorted_container_contains_element(fp)) {
        size_t n {1};
        while (n > 0) {
            print("Geef n ( 0 om te stoppen ): ");
            cin >> n;
            if (n > 0) {
                vector<int> v(n);
                vul_random_0_999(v);
                ranges::sort(v);
                if (n <= 100) {
                    println("{}", v);
                }
                int s;
                print("Geef element om te zoeken: ");
                cin >> s;
                Stopwatch sw;
                sw.start();
                bool gevonden {fp(v, s)};
                sw.stop();
                if (gevonden) {
                    println("Element {} gevonden.", s);
                }
                else {
                    println("Element {} niet gevonden.", s);
                }
                println("Tijdsduur: {}", sw.duration());
            }
        }
    }
}
