import std;
import stopwatch;
using namespace std;

void vul_met_meerderheids_element(vector<int>& v) {
    default_random_engine eng;
    eng.seed(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<> dist {0, 999};
    auto n {v.size()};
    auto almost_half {v.begin()};
    advance(almost_half, n/2 - (1 - n%2));
    generate(v.begin(), almost_half, [&dist, &eng]{ return dist(eng); });
    fill(almost_half, v.end(), dist(eng));
}

optional<int> zoek_meerderheids_element_methode_1(const vector<int>& v) {
//  Vul hier jouw code in!
    return nullopt;
}

optional<int> zoek_meerderheids_element_methode_2(const vector<int>& v) {
//  Vul hier jouw code in!
    return nullopt;
}

optional<int> zoek_meerderheids_element_methode_3(const vector<int>& v) {
//  Vul hier jouw code in!
    return nullopt;
}

typedef optional<int> (*zoek_meerderheids_element)(const vector<int>& v);

optional<int> test_meerderheids_element(zoek_meerderheids_element fp) {
    vector v0 {3}; // meerderheidselement = 3
    auto result = fp(v0);
    if (!result || *result != 3) {
        println("Test 0 failed!");
        return false;
    }
    vector v1 {3, 4, 3, 2, 4, 4, 4, 5}; // geen meerderheidselement
    if (fp(v1)) {
        println("Test 1 failed!");
        return false;
    }
    vector v2 {3, 4, 3, 2, 4, 4, 4, 4, 5}; // meerderheidselement = 4
    if (!fp(v2) || *fp(v2) != 4) {
        println("Test 2 failed!");
        return false;
    }
    vector v3 {1, 1, 1, 1, 3, 2, 2, 3, 3, 3, 2, 3, 3}; // geen meerderheidselement
    if (fp(v3)) {
        println("Test 3 failed!");
        return false;
    }
    vector v4 {1, 1, 1, 3, 3, 2, 2, 3, 3, 3, 2, 3, 3}; // meerderheidselement = 3
    if (!fp(v4) || *fp(v4) != 3) {
        println("Test 4 failed!");
        return false;
    }
    println("Alle tests geslaagd!");
    return true;
}

int main() {
    zoek_meerderheids_element te_testen_functie {nullptr};
    te_testen_functie = zoek_meerderheids_element_methode_1;
    if (test_meerderheids_element(te_testen_functie)) {
        size_t n {1};
        while (n > 0) {
            print("Geef n ( 0 om te stoppen ): ");
            cin >> n;
            if (n > 0) {
                vector<int> v(n);
                vul_met_meerderheids_element(v);
                if (n <= 100) {
                    println("{}", v);
                }
                Stopwatch sw;
                int res {0};
                sw.start();
                auto result = (*te_testen_functie)(v);
                sw.stop();
                if (result) {
                    println("Meerderheids element gevonden: {}", *result);
                }
                else {
                    println("Geen meerderheids element gevonden.");
                }
                println("Tijdsduur: {}", sw.duration());
            }
        }
    }
}
