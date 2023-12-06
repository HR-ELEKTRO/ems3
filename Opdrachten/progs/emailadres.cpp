#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "Geef je e-mailadres: ";
    string emailadres;
    cin >> emailadres;
    string::size_type index_aapje {emailadres.find("@")};
    if (index_aapje != string::npos) {
        cout << "Gebruiker: " << emailadres.substr(0, index_aapje) << '\n';
        cout << "Domein:    " << emailadres.substr(index_aapje + 1) << '\n';
    }
    else {
        cout << emailadres << " is geen geldig e-mailadres!\n";
    }
}
