import std;
import harmonisch_gemiddelde;
using namespace std;

int main() {
    vector weerstanden {100, 200, 300, 400};
    auto h {harmonisch_gemiddelde(weerstanden)};
    println("100 // 200 // 300 // 400 Ohm kan vervangen worden door: {0} // {0} // {0} // {0} Ohm", h);
    vector snelheden {1.0, 1.2};
    println("1.0 m/s heen en 1.2 m/s terug geeft gemiddeld: {} m/s", harmonisch_gemiddelde(snelheden));

    // vector<string> woorden {"hallo", "wereld"};
    // println("Harmonisch gemiddelde van woorden: {}", harmonisch_gemiddelde(woorden));
    // error zonder concept: no match for 'operator/' (operand types are 'double' and 'const std::__cxx11::basic_string<char>')
    // error met concept: no matching function for call to 'harmonisch_gemiddelde(std::vector<std::__cxx11::basic_string<char> >&)'
    // note: constraints not satisfied
}