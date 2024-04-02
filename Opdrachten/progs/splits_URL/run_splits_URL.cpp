#include <iostream>
#include <string>
#include "splits_URL.h"

using namespace std;

int main() {
    cout << "Geef een URL: ";
    string URL;
    cin >> URL;
    gesplitste_URL res {splits_URL(URL)};
    if (res.geldig) {
        cout << "Protocol: " << res.protocol << '\n';
        cout << "Domein:   " << res.domein << '\n';
        cout << "Directory: " << res.directory << '\n';
        cout << "File:   " << res.file << '\n';
    }
    else {
        cout << URL << " is geen geldige URL!\n";
    }
}