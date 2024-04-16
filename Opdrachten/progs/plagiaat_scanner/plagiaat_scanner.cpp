#include <iostream>
#include <iterator>
#include <string>

#include "identifier_extractor.h"

using namespace std;

int main(int argc, const char* argv[]) {
    string filename;
    if (argc == 2) {
        filename = argv[1];
    }
    else {
        cout << "Geef filenaam: ";
        cin >> filename;
    }
    Identifier_extractor ie {filename};
    auto ids {ie.get_identifiers()};
    ostream_iterator<string> iout {cout, " "};
    copy(ids.cbegin(), ids.cend(), iout);
    cout << endl;
}
