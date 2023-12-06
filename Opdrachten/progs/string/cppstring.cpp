#include <string> // Zie opmerking 1.
#include <iostream>
using namespace std;

int main() {
	string naam;
	naam = "Harry"; // Zie opmerking 2.
	cout << naam << endl;
	naam = "Willem-Alexander"; // Zie opmerking 3.
	cout << naam << '\n';
	if (naam == "Willem-Alexander") { // Zie opmerking 4.
		cout << "Hoi Alex!\n";
	}
}
