import std;
import identifier_extractor;
using namespace std;

int main(int argc, const char* argv[]) {
    string filename;
    if (argc == 2) {
        filename = argv[1];
    }
    else {
        print("Geef filenaam: ");
        cin >> filename;
    }
    Identifier_extractor ie {filename};
    auto ids {ie.get_identifiers()};
    ostream_iterator<string> iout {cout, " "};
    ranges::copy(ids, iout);
    println();
}
