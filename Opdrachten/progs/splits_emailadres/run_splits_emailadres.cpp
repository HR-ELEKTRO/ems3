#include <iostream>
#include <string>
#include "splits_emailadres.h"

using namespace std;

int main() {
    cout << "Geef je e-mailadres: ";
    string emailadres;
    cin >> emailadres;
    gesplitst_emailadres res {splits_emailadres(emailadres)};
    if (res.geldig) {
        cout << "Gebruiker: " << res.gebruiker << '\n';
        cout << "Domein:    " << res.domein << '\n';
    }
    else {
        cout << emailadres << " is geen geldig e-mailadres!\n";
    }
}