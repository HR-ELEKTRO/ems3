import std; // Zie opmerking 1.
using namespace std;

int main() {
	string naam;
	naam = "Harry"; // Zie opmerking 2.
	println("{}", naam);
	naam = "Willem-Alexander"; // Zie opmerking 3.
	println("{}", naam);
	if (naam == "Willem-Alexander") { // Zie opmerking 4.
		println("Hoi Alex!");
	}
}
